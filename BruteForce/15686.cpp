#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
int a[51][51];
int ans = 0xfffffff;

vector<pair<int, int>> house, chicken;

int distance(int hx, int hy, int cx, int cy) {
	return abs(cx - hx) + abs(cy - hy);
}

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];

			if (a[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (a[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	vector<int> v(chicken.size());
	for (int i = 0; i < m; i++) {
		v[i] = 1;
	}
	sort(v.begin(), v.end());

	do {
		int temp = 0;
		for (int i = 0; i < house.size(); i++) {
			int dist = 0xfffffff;

			for (int j = 0; j < chicken.size(); j++) {
				if (v[j] == 1) {
					dist = min(dist, distance(house[i].first, house[i].second, chicken[j].first, chicken[j].second));
				}
			}
			temp += dist;
		}
		ans = min(ans, temp);
	} while (next_permutation(v.begin(), v.end()));

	cout << ans << "\n";

	return 0;
}
