#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	vector<int> a(202);
	for (int j = 0; j < t; j += 1) {
		int n, x;
		int p;
		int v = 0;
		for (int i = 0; i < 202; i += 1) {
			a[i] = 0;
		}
		cin >> n >> x;
		for (int i = 0; i < n; i += 1) {
			cin >> p;
			a[p] = 1;
		}
		for (int i = 1; i < 202; i += 1) {
			if (a[i] == 1) {
				v += 1;
			}
			else if (x != 0) {
				a[i] = 1;
				x -= 1;
				v += 1;
			}
			else {
				break;
			}
		}
		cout << v << "\n";
	}
	return 0;
}
