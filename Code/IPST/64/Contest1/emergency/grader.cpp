#include "emergency.h"
#include <cstdio>

static const int MAX_N = 200010;
static int N, H, K;
static int roads[MAX_N][2];
static int lengths[MAX_N];
static int hospitals[MAX_N];
static int centers[MAX_N];

int main()
{
  scanf("%d %d %d",&N,&H,&K);
  for(int i=0; i<H; i++) {
    scanf("%d",&hospitals[i]);
  }
  for(int i=0; i<K; i++) {
    scanf("%d",&centers[i]);
  }
  for(int i=0; i<N-1; i++) {
    scanf("%d %d %d",&roads[i][0], &roads[i][1], &lengths[i]);
  }
  printf("%d\n",furthest(N, H, K,
			 roads, lengths,
			 hospitals, centers));
}
