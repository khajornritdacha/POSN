#include <cstdio>
#include <vector>
#include <unordered_set>
#include <utility>
#include "testlib.h"

using namespace std;

using ll = long long;
using pii = pair<int, int>;

/**
 * Union-find Disjoint Set with Path Compression
 */
class disjoint_set {
    private:
    int size;
    int merge_count;
    vector<int> parent;
    public:
    disjoint_set(int n) : size(n), parent(n) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int count_component() {
        return size-merge_count;
    }
    int root(int u) {
        if (parent[u] == u) return u;
        return parent[u] = root(parent[u]);
    }
    bool merge(int u, int v) {
        u = root(u), v = root(v);
        if (u == v) return false;
        parent[v] = u;
        ++merge_count;
        return true;
    }
};

/**
 * ==============================================
 * Distribution functions
 * ==============================================
 */

/**
 * Return k random elements from set {0, 1, 2, ..., n-1}.
 * The output is not sorted in any ways.
 */
template<typename T>
vector<T> pick_set(T n, int k)
{
    ensure(k >= 0 && k <= n);
    unordered_set<T> used;
    vector<T> ret;
    ret.reserve(k);
    for (T r = n-k; r < n; ++r) {
        T v = rnd.next((T)0, r);
        if (used.count(v))
            v = r;
        used.insert(v);
        ret.push_back(v);
    }
    return ret;
}

/**
 * Return k random elements from set {min_n, min_n+1, ..., max_n-1, max_n}
 * The output is not sorted in any ways.
 */
template<typename T>
vector<T> pick_set(T min_n, T max_n, int k)
{
    ensure(min_n <= max_n && k >= 0 && k <= max_n-min_n+1);
    T sz = max_n-min_n+1;
    vector<T> s = pick_set(sz, k);
    for (int i = 0; i < k; ++i)
        s[i] += min_n;
    return s;
}

/**
 * ==============================================
 * Graph generation functions
 * ==============================================
 */

/**
 * Get corresponding undirected edge to an index
 */
pii get_undirected_edge(ll n, ll m, ll x)
{
    ll a = 1;
    ll b = -2*n + 1;
    ll c = 2*x;
    ll u = floor((-b - sqrt(b*b - 4*a*c) ) / 2*a);
    ll fx = u*n - u*(u+1)/2;
    ll v = (u+1) + (x-fx);
    return pii(u, v);
}

/**
 * Generate edge list of random simple undirected graph with n vertices and m edges
 * Vertices are indexed from 0 to n-1
 */
vector<pii> gen_undirected_graph(int n, int m)
{
    ensure(m >= 0 && m <= n*1LL*(n-1)/2);
    vector<ll> s = pick_set(n*1LL*(n-1)/2, m);
    shuffle(s.begin(), s.end());
    vector<pii> edges(m);
    for (int i = 0; i < m; ++i) {
        edges[i] = get_undirected_edge(n, m, s[i]);
        if (rnd.next(2))
            swap(edges[i].first, edges[i].second);
    }
    shuffle(edges.begin(), edges.end());
    return edges;
}

/**
 * Generate parent list of a tree with n vertices, rooted at 0.
 * Vertices are indexed from 0 to n-1. Root will have parent -1.
 * For all 0 <= i < j <= n-1, depth of vertex i is less than depth of vertex j.
 * min_k, max_k will determine the result of k in each iteration of generation algorithm.
 * If k is small, tree will be quite deep. If k is large, tree will be quite shallow.
 */
vector<int> gen_min_vertex_tree(int n, int min_k, int max_k)
{
    ensure(min_k <= max_k && min_k >= 1 && max_k <= n);
    vector<int> parents(n);
    parents[0] = -1;
    for (int i = 1; i < n; ++i) {
        int k;
        if (i < min_k) k = rnd.next(1, i);
        else if (i < max_k) k = rnd.next(min_k, i);
        else k = rnd.next(min_k, max_k);
        parents[i] = i-k;
    }
    return parents;
}

/**
 * Like above, but there are no conditions on depth of vertex
 * and the tree will be rooted at vertex r.
 * If r = -1, r will be chosen at random.
 */
vector<int> gen_parent_tree(int n, int min_k, int max_k, int r=-1)
{
    if (r == -1) r = rnd.next(n);
    vector<int> parents = gen_min_vertex_tree(n, min_k, max_k);

    vector<int> new_label = pick_set(n, n);
    shuffle(new_label.begin(), new_label.end());
    vector<int>::iterator it = find(new_label.begin(), new_label.end(), r);
    swap(*new_label.begin(), *it);

    vector<int> new_parents(n);
    for (int i = 0; i < n; ++i)
        new_parents[new_label[i]] = parents[i] == -1 ? -1 : new_label[parents[i]];

    return new_parents;
}

/**
 * Generate edge list of a tree with n vertices, rooted at r
 * Vertices are numbered from 0 to n-1
 * min_k, max_k will determine the result of k in each iteration of generation algorithm.
 * If k is small, tree will be quite deep. If k is large, tree will be quite shallow
 */
vector<pii> gen_edge_tree(int n, int min_k, int max_k)
{
    vector<int> parents = gen_parent_tree(n, min_k, max_k);
    vector<pii> edges;
    edges.reserve(n-1);
    for (int i = 0; i < n; ++i) {
        if (parents[i] != -1)
            edges.push_back(pii(i, parents[i]));
    }
    shuffle(edges.begin(), edges.end());
    return edges;
}

/**
 * Generate edge list of a connected undirected graph
 * Vertices are numbered from 0 to n-1
 */
vector<pii> gen_connected_graph(int n, int m)
{
    ensure(m >= n-1 && m <= n*1LL*(n-1)/2);
    ll max_m = n*1LL*(n-1)/2;
    vector<ll> s = pick_set(max_m, min<ll>(m+(n-1), max_m));
    shuffle(s.begin(), s.end());

    set<pii> edges;
    vector<pii> spnt = gen_edge_tree(n, 1, n);
    for (pii e : spnt)
        edges.insert(minmax(e.first, e.second));

    while (edges.size() < m) {
        ll x = s.back(); s.pop_back();
        pii e = get_undirected_edge(n, m, x);
        if (!edges.count(e))
            edges.insert(e);
    }

    vector<pii> ret;
    for (auto e : edges) {
        if (rnd.next(2))
            swap(e.first, e.second);
        ret.push_back(e);
    }
    shuffle(ret.begin(), ret.end());
    return ret;
}

/**
 * Get corresponding directed edge to an index
 */
pii get_directed_edge(int n, int m, ll x)
{
    ll u = x/(n-1);
    ll d = x - u*(n-1);
    ll v = d + (d>=u ? 1 : 0);
    return pii(u, v);
}

/**
 * Generate edge list of random directed graph with n vertices and m edges
 * Vertices are indexed from 0 to n-1
 */
vector<pii> gen_directed_graph(int n, int m)
{
    ensure(m >= 0 && m <= n*1LL*(n-1));
    vector<ll> s = pick_set(n*1LL*(n-1), m);
    shuffle(s.begin(), s.end());
    vector<pii> edges(m);
    for (int i = 0; i < m; ++i) {
        edges[i] = get_directed_edge(n, m, s[i]);
    }
    shuffle(edges.begin(), edges.end());
    return edges;
}
