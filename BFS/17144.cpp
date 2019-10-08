/*
#include<iostream>
#include<queue>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int ccw[4] = { 2,1,3,0 };
int cw[4] = { 2,0,3,1 };

int r, c, t;
int map[51][51];
int tempMap[51][51];

queue<pair<int, int>> q;

void bfs() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) {
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		int dust = map[cx][cy] / 5;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
				continue;
			}

			if (map[nx][ny] != -1) {
				tempMap[nx][ny] += dust;
				tempMap[cx][cy] -= dust;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] = tempMap[i][j];
		}
	}
}

void circulate(int startX, int startY, int dir[]) {
	int cx = startX;
	int cy = startY + 1;

	for (int i = 0; i < 4; i++) {
		while (true) {
			int nx = cx + dx[dir[i]];
			int ny = cy + dy[dir[i]];

			if (nx == startX && ny == startY) break;

			if (nx < 0 || ny < 0 || nx >= r || ny >= c) break;

			tempMap[nx][ny] = map[cx][cy];
			cx = nx;
			cy = ny;
		}
	}

	tempMap[startX][startY+1] = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] = tempMap[i][j];
		}
	}
}

int main(void) {	
	cin >> r >> c >> t;

	int cleanerX = 0, cleanerY = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			tempMap[i][j] = map[i][j];

			if (map[i][j] == -1) {
				cleanerX = i, cleanerY = j;
			}
		}
	}

	for (int k = 0; k < t; k++) {

		bfs();
		circulate(cleanerX - 1 , cleanerY, ccw);
		circulate(cleanerX, cleanerY, cw);
	}

	int ans = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != -1) {
				ans += map[i][j];
			}			
		}
	}
	
	cout << ans << '\n';

	return 0;
}

*/