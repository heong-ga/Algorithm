#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

vector<int> graph[1001];
int visited[1001];

void dfs(int cur) {
	visited[cur] = 1;
	cout << cur << " ";

	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	memset(visited, 0, sizeof(visited));
	queue<int> q;

	visited[start] = 1;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];

			if (!visited[next]) {
				q.push(next);
				visited[next] = 1;
			}
		}
	}
	cout << "\n";
}

int main(void) {
	int n, m, v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;

		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 0; i < n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	cout << "\n";
	bfs(v);

	return 0;
}