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

typedef struct {
	int cost;
	int front;
	int back;
}Link;

int Vit[MAX_N];

int N, L;
int Dit[MAX_N];
map<int, vector<pair<int,int>>> Path;
priority_queue<Link> Pq;
bool operator<(Link a, Link b) {
	return a.cost > b.cost;
}

int main(void) {
	for (int i = 0; i < MAX_N; i++) {
		Dit[i] = INF;
	}
	
	scanf("%d %d", &N, &L);
	for (int i = 0; i < L; i++) {
		int front, back, cost;
		scanf("%d %d %d", &front, &back, &cost);
		pair<int, int> value = make_pair(cost, back);
		Path[front].push_back(value);
	}
	int start, end;
	scanf("%d %d", &start, &end);

	Dit[start] = 0;
	Vit[start] = 1;
	for (int i = 0; i < Path[start].size(); i++) {
		Link link;
		link.front = start;
		link.cost = Path[start][i].first;
		link.back = Path[start][i].second;
		Pq.push(link);
	}

	while (!Pq.empty()) {
		int front = Pq.top().front;
		int back = Pq.top().back;
		int cost = Pq.top().cost;
		Pq.pop();

		cost += Dit[front];
		Dit[back] = (Dit[back] < cost) ? Dit[back] : cost;
		for (int i = 0; i < Path[back].size(); i++) {
			Link link;
			link.front = back;
			link.cost = Path[back][i].first;
			link.back = Path[back][i].second;
			if (Vit[link.back] == 1) continue;
			Pq.push(link);
		}

		//if (back == end) break;
	}

	printf("%d\n", Dit[end]);
}

