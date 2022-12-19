#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> s(n);
	bool not_in = true;
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}
	for (int i = n - 1; i > -1; i -= 1) {
		not_in = true;
		for (int j = 0; j < n; j += 1) {
			if (s[j] == a[i]) {
				not_in = false;
			}
		}
		if (not_in == true) {
			s[i] = a[i];
		}
	}
	int cnt = 0;
	for (int i = n - 1; i > -1; i -= 1) {
		if (s[i] != 0) {
			cnt += 1;
		}
	}
	cout << cnt << '\n';
	for (int i = 0; i < n; i += 1) {
		if (s[i] != 0) {
			cout << s[i] << ' ';
		}
	}
	return 0;
}
