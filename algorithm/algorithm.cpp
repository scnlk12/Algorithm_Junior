#include <iostream>
using namespace std;

/// <summary>
/// 动态规划实现函数
/// </summary>
/// <param name="w">物品重量数组</param>
/// <param name="v">物品价值数组</param>
/// <param name="m">m[i][j]表示背包容量为j时放入物品i的最大价值</param>
/// <param name="c">背包容量</param>
/// <param name="n">物品个数</param>
/// <returns>背包容量为c时放入n个物品的最大价值</returns>

int Knapsack(int* w, int* v, int** m, int c, int n) {
	for (int i = 0; i <= c; i++) m[0][i] = 0;	//不放入物品时的价值
	for (int i = 0; i < n + 1; i++) m[i][0] = 0;	//背包容量为0时的价值

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j <= c; j++) {
			if (j < w[i]) m[i][j] = m[i - 1][j];	//无法放入当前物品时的价值
			else {
				m[i][j] = m[i - 1][j];
				int t = m[i - 1][j - w[i]] + v[i];
				if (m[i][j] < t) m[i][j] = t;	//当前物品可放入时，选择放入或不放入更大的一个
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
