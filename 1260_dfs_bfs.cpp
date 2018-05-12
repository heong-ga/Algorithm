#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

vector<int> adj_list[1001];
int visited[1001];

void dfs(int cur) {
	visited[cur] = 1;

	printf("%d ", cur);

	for (int i = 0; i < adj_list[cur].size(); i++) {
		int next = adj_list[cur][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int cur = q.front();
		printf("%d ", cur);
		q.pop();

		for (int i = 0; i < adj_list[cur].size(); i++) {
			int next = adj_list[cur][i];

			if (!visited[next]) {
				visited[next] = 1;
				q.push(next);
			}
		}
	}
}


int main(void) {
	int N, M, V;
	int from, to;

	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &from, &to);

		adj_list[from].push_back(to);
		adj_list[to].push_back(from);
	}

	for (int i = 1; i <= N; i++) {
		sort(adj_list[i].begin(), adj_list[i].end());
	}

	dfs(V);
	printf("\n");
	bfs(V);
	
	return 0;
}