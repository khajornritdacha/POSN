#include "onepath.h"
#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 10;

set<int> road;
bool inc[MXN];
int ep[MXN];

bool has_cycle_btw(int u, int v) {
	int k = MXN;
	auto it = road.lower_bound(u);
	if (it != road.end())
		k = *it;

	// assert(k != inc[v]);
	return (v > k);
}

bool is_dangerous(int u, int v)
{
	if (u > v)
		swap(u, v);

	if (inc[u] and inc[v]) {

		if (ep[u] == -1 and ep[v] == 1) {
			return !has_cycle_btw(u, v);
		} else {
			return false;
		}
	} else if (!inc[u] and !inc[v]) {
		return !has_cycle_btw(u, v);
	} else {
		if (ep[u] != 0)
		{
			if (ep[u] == 1)
			{
				return false;
			}
			else if (ep[u] == -1)
			{
				return true;
			}
		}
		else if (ep[v] != 0)
		{
			if (ep[v] == 1)
			{
				return true;
			}
			else if (ep[v] == -1)
			{
				return false;
			}
		} else {
			return false;
		}
	}
	// assert(0);
	return false;
}

void build_road(int u, int v)
{
	if (u > v)
		swap(u, v); // let u < v
	for (int i = u; i <= v; i++){
		assert(inc[i] == false);
		inc[i] = true;
	}
	ep[u] = 1;	// 1 for left
	ep[v] = -1; //-1 for right
	road.insert(u);
	return;
}

void initialize(int N, int M, int Q, vector<pair<int, int>> R)
{

	return;
}
