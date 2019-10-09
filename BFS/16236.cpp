#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n;
int map[20][20];
int visited[20][20];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue<pair<int, int>> q;

int shark_size = 2;
int shark_x, shark_y;
int eat;
int ans;


bool bfs() {
	memset(visited, 0, sizeof(visited));
	visited[shark_x][shark_y] = 1;
	int flag = 0;
	vector<pair<int, int>> v;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			if (visited[nx][ny] == 0 && map[nx][ny] <= shark_size) {
				if (flag == 0) {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = visited[cx][cy] + 1;
				}
				if (map[nx][ny] != 0 && map[nx][ny] < shark_size) {
					if (flag == 0) {
						v.push_back(make_pair(nx, ny));
						visited[nx][ny] = visited[cx][cy] + 1;
						flag = visited[nx][ny];
					}
					else {
						if (flag > visited[cx][cy]) {
							v.push_back(make_pair(nx, ny));
							visited[nx][ny] = visited[cx][cy] + 1;
							flag = visited[nx][ny];
						}
					}
				}
			}
		}
	}

	if (flag != 0 ) {
		sort(v.begin(), v.end());
		shark_x = v[0].first; shark_y = v[0].second;
		ans += visited[shark_x][shark_y]-1;
		eat++;

		if (shark_size == eat) {
			shark_size++;
			eat = 0;	
		}
		return true;
	}
	else {
		return false;
	}
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 9) {
				q.push(make_pair(i, j));
				map[i][j] = 0;
				shark_x = i, shark_y = j;
				visited[i][j] = 1;
			}
		}
	}

	while (true) {
		if (bfs() == false) {
			break;
		}
		
		q.push(make_pair(shark_x, shark_y));
		map[shark_x][shark_y] = 0;
	}

	cout << ans << '\n';

	return 0;
}