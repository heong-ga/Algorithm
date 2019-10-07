/*
#include<iostream>
#include<algorithm>

using namespace std;

int p[301];
int d[301];

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	d[2] = p[1] + p[2];
	d[1] = p[1];

	for (int i = 3; i <= n; i++) {
		d[i] = max(p[i] + p[i - 1] + d[i - 3], p[i] + d[i - 2]);
	}

	cout << d[n] << '\n';

	return 0;
}*/