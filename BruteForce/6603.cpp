#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
	while (true) {
		int n;
		cin >> n;

		if (n == 0) break;

		vector<int> a(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		vector<int> v(n);
		for (int i = 6; i < n; i++) {
			v[i] = 1;
		}

		do {
			for (int i = 0; i < n; i++) {
				if (v[i] == 0) {
					cout << a[i] << " ";
				}
			}
			cout << '\n';
		} while (next_permutation(v.begin(), v.end()));
		cout << '\n';
	}


	return 0;
}