#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

string map[25];
int visited[25][25];

int n;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<int> ans;

void bfs(int x, int y) {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = 1;
	
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}

			if (map[nx][ny] == '1' && visited[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = 1;
				cnt++;
			}
		}
	}

	ans.push_back(cnt);
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1' && visited[i][j] == 0) {
				bfs(i, j);
			}			
		}
	}

	cout << ans.size() << "\n";
	
	sort(ans.begin(), ans.end());

	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}