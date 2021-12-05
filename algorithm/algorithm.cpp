#include <iostream>
using namespace std;

int Knapsack(int* w, int* v, int** m, int c, int n) {
	for (int i = 0; i <= c; i++) m[0][i] = 0;
	for (int i = 0; i < n + 1; i++) m[i][0] = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j <= c; j++) {
			if (j < w[i]) m[i][j] = m[i - 1][j];
			else {
				m[i][j] = m[i - 1][j];
				int t = m[i - 1][j - w[i]] + v[i];
				if (m[i][j] < t) m[i][j] = t;
			}
		}
	}
	return m[n][c];
}

int main() {
	int n, c;	//n为物品个数，c为背包容量

	cin >> n;
	cin >> c;

	int* w = new int[n + 1];
	int* v = new int[n + 1];

	int** m = new int*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		m[i] = new int[c + 1];
		for (int j = 0; j < c + 1; j++) m[i][j] = 0;
	}

	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

	int maxV = Knapsack(w, v, m, c, n);


	cout << maxV;
	
}