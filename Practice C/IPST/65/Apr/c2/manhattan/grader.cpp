#include "manhattan.h"

int main() {
  int N, M, G, L;
  scanf("%d%d%d%d", &N, &M, &G, &L);
  std::vector<int> x, y, u, v, w, g, l;
  int xi, yi;
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &xi, &yi);
    x.push_back(xi);
    y.push_back(yi);
  }
  for (int i = 0; i < M; i++) {
    int ui, vi, wi;
    scanf("%d%d%d", &ui, &vi, &wi);
    u.push_back(ui);
    v.push_back(vi);
    w.push_back(wi);
  }
  for (int i = 0; i < G; i++) {
    int gi;
    scanf("%d", &gi);
    g.push_back(gi);
  }
  for (int i = 0; i < L; i++) {
    int li;
    scanf("%d", &li);
    l.push_back(li);
  }
  printf("%lld\n", minimum_capacity(N, M, G, L, x, y, u, v, w, g, l));
  return 0;
}