#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int map[8][8];
int tempMap[8][8];
int visited[8][8];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m;

queue<pair<int, int>> q;
queue<pair<int, int>> temp_q;

void bfs() {
	memset(visited, 0, sizeof(visited));

	while (!temp_q.empty()) {
		int cx = temp_q.front().first;
		int cy = temp_q.front().second;
		temp_q.pop();
		visited[cx][cy] = 1;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (visited[nx][ny] == 0 && tempMap[nx][ny] == 0) {
				temp_q.push(make_pair(nx, ny));
				visited[nx][ny] = 1;
				tempMap[nx][ny] = 2;
			}
		}
	}
}

int cntZero() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tempMap[i][j] == 0) {
				cnt++;
			}
		}
	}

	return cnt;
}

void copyMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tempMap[i][j] = map[i][j];
		}
	}
}

int main(void) {	
	cin >> n >> m;

	vector<pair<int, int>> clean_q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			
			if (map[i][j] == 0) {
				clean_q.push_back(make_pair(i, j));
			}
			if (map[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < clean_q.size() - 2; i++) {
		for (int j = i+1; j < clean_q.size() - 1; j++) {
			for (int k = j+1; k < clean_q.size(); k++) {
				copyMap();
				temp_q = q;
				
				tempMap[clean_q[i].first][clean_q[i].second] = 1;
				tempMap[clean_q[j].first][clean_q[j].second] = 1;
				tempMap[clean_q[k].first][clean_q[k].second] = 1;

				bfs();

				ans = max(ans, cntZero());

			}
		}
	}

	cout << ans << "\n";
	
	return 0;
}