#include <bits/stdc++.h>
using namespace std;

int partition_vec(vector<int> &a, int lo, int hi) {
	int pivot = a[hi];
	int i = lo;
	for (int j = lo; j < hi; ++j) {
		if (a[j] <= pivot) {
			swap(a[i], a[j]);
			++i;
		}
	}
	swap(a[i], a[hi]);
	return i;
}

void quickSort(vector<int> &a, int lo, int hi) {
	if (lo < hi) {
		int p = partition_vec(a, lo, hi);
		quickSort(a, lo, p - 1);
		quickSort(a, p + 1, hi);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	if (!(cin >> n)) return 0;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	if (n > 0) quickSort(a, 0, n - 1);

	for (int i = 0; i < n; ++i) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << '\n';
	return 0;
}
