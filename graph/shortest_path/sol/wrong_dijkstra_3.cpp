#include <vector>
#include <queue>
#include <utility>
#include <stdint.h>
#include <algorithm>
#include "../fastio.h"

#define INF 1000000000000000000

template<typename T> using pqueue_inv = std::priority_queue<T, std::vector<T>, std::greater<T> >;

int main() {
	int n = ri();
	int m = ri();
	int s = ri();
	int t = ri();
	std::vector<std::vector<std::pair<int, int> > > hen(n);
	for (int i = 0; i < m; i++) {
		int a = ri();
		int b = ri();
		int c = ri();
		hen[a].push_back({b, c});
	}
	std::vector<bool> inqueue(n, false);
	std::vector<int64_t> dist(n, INF);
	std::vector<int> from(n, -1);
	pqueue_inv<std::pair<int64_t, int> > que;
	que.push({dist[s] = 0, s});
	inqueue[s] = true;
	while (que.size()) {
		auto i = que.top();
		que.pop();
		inqueue[i.second] = false;
		for (auto j : hen[i.second]) if (dist[j.first] > dist[i.second] + j.second) {
			dist[j.first] = dist[i.second] + j.second;
			from[j.first] = i.second;
			if (!inqueue[j.first]) inqueue[j.first] = true, que.push({dist[j.first], j.first});
		}
	}
	if (dist[t] == INF) println("-1");
	else {
		std::vector<int> path;
		for (int cur = t; cur != -1; cur = from[cur]) path.push_back(cur);
		std::reverse(path.begin(), path.end());
		println(dist[t], ' ', path.size() - 1);
		for (int i = 0; i + 1 < (int) path.size(); i++) println(path[i], ' ', path[i + 1]);
	}
	return 0;
}
