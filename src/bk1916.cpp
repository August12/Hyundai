// bk1916 Dijkstra
using namespace std;

#include <stdio.h>
#include <queue>
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>

#define MAX_N 1001
#define INF 0x7fffffff

int N, L;
int Dit[MAX_N], Vit[MAX_N];
map<int, vector<pair<int,int>>> Path;
priority_queue<pair<int, int>> Pq;

int main(void) {
	memset(Dit, INF, sizeof(Dit));
	
	scanf("%d %d", &N, &L);
	for (int i = 0; i < L; i++) {
		int front, back, cost;
		scanf("%d %d %d", &front, &back, &cost);
		pair<int, int> value = make_pair(back, cost);
		Path[front].push_back(value);
	}
}

