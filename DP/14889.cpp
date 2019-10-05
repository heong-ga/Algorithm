#include<iostream>

using namespace std;

int n;
int S[21][21];
int checked[21];
int ans = 0xfffffff;

void dfs(int idx, int cnt) {
	if (cnt == n / 2) {
		int start = 0, link = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (checked[i] && checked[j])  start += S[i][j];
				if (!checked[i] && !checked[j]) link += S[i][j];
			}
		}

		int temp = abs(start - link);
		if (ans > temp) ans = temp;
		return;
	}

	for (int i = idx; i < n; i++) {
		checked[i] = true;
		dfs(i + 1, cnt + 1);
		checked[i] = false;
	}
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> S[i][j];
		}
	}

	dfs(0, 0);

	cout << ans << '\n';
	return 0;
}








