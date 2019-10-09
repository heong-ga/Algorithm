#include<iostream>

using namespace std;

int a[101][101];
int b[101][101];
int N, L;

bool solve(int a[]) {
	int t[100] = { false, };

	for (int i = 0; i < N - 1; i++) {
		if (a[i] == a[i + 1]) {
			continue;
		}
		else if (a[i] == a[i + 1] + 1) {
			if (L == 1) {
				if (t[i+1] == true) {
					return false;
				}
				else {
					t[i+1] = true;
				}
			}
			else {
				for (int j = i + 1; j < i + L; j++) {
					if (j >= N) return false;

					if (a[j] != a[j + 1]) {
						return false;
					}
					else {
						if (t[j] == false && t[j + 1] == false) {
							t[j] = true;
						}
						else {
							return false;
						}
					}
				}
				t[i + L] = true;
			}
		}
		else if (a[i] + 1 == a[i + 1]) {
			if (L == 1) {
				if (t[i] == true) {
					return false;
				}
				else {
					t[i] = true;
				}
			}
			else {
				for (int j = i; j > i + 1 - L; j--) {
					if (j < 0) return false;

					if (a[j] != a[j - 1]) {
						return false;
					}
					else {
						if (t[j] == false && t[j - 1] == false) {
							t[j] = true;
						}
						else {
							return false;
						}
					}
				}
				t[i + 1 - L] = true;
			}
		}
		else {
			return false;
		}
	}
	return true;
}

int main(void) {
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			b[i][j] = a[j][i];
		}
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		ans += solve(a[i]);
		ans += solve(b[i]);
	}
	
	cout << ans << "\n";

	return 0;
}