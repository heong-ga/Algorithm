#include<iostream>
#include<queue>

using namespace std;

int box[1001][1001];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;


int main(void) {
	int M, N;
	int result = 0;
	bool flag = false;

	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &box[i][j]);
			
			if (box[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;

			if (box[nx][ny] == 0) {
				box[nx][ny] = box[x][y] + 1;
				q.push(make_pair(nx, ny));

				if (result < box[nx][ny]) {
					result = box[nx][ny];
				}
			}
		}
	}

	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<M; j++)
		{
			if (box[i][j] == 0)
				flag = true;
		}
	}
	
	if (flag == true) {
		printf("-1");
	}
	else if (result == 0) {
		printf("0");
	}
	else{
		printf("%d\n", result-1);
	}
	
	

}