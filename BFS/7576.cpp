#include<iostream>
#include<queue>

using namespace std;

int map[1001][1001];
int visited[1001][1001];
int dx[4] = { 1, -1, 0,0 };
int dy[4] = { 0, 0, 1,-1 };

queue<pair<int, int>> q;

int main(void) {
	int m, n;
	int ans = 0;
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (visited[nx][ny] != 1 && map[nx][ny] == 0) {
				visited[nx][ny] = 1;
				q.push(make_pair(nx, ny));				
				map[nx][ny] = map[cx][cy] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans < map[i][j]) {
				ans = map[i][j];
			}
			if (map[i][j] == 0) {
				cout << "-1\n";
				return 0;
			}
		}
	}

	cout << ans - 1 <<'\n';

	return 0;
}