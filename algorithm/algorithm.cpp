#include <iostream>
using namespace std;

int sum = 0;	//符号三角形个数
int n = 0;	//第一行有n个符号
int PositiveCount = 0;	//“+”个数
int** x;	//符号三角形矩阵
int half = 0;	//half = n * (n + 1) / 4

void BackTrack(int t) {


	if (PositiveCount > half || ((t + 1) * t / 2 - PositiveCount) > half) return;	//+或-超过总符号数的一半，剪枝

	if (t == n) {	//叶子结点
		sum++;	//到达叶子结点，三角形个数+1
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) cout << " ";
			for (int j = 0; j < n - i; j++) {
				if (x[i][j] == 0)cout << "- ";
				else cout << "+ ";
			}
			cout << endl;
		}
		return;
	}
	for (int i = 0; i < 2; i++) {	//第一行每个结点都有两种可能性 +/-
		x[0][t] = i;
		PositiveCount += i;
		for (int j = 1; j <= t; j++) {	//构造符号三角形
			if (x[j - 1][t - j] == x[j - 1][t - j + 1]) x[j][t - j] = 1;
			else x[j][t - j] = 0;
			PositiveCount += x[j][t - j];
		}
		BackTrack(t + 1);	//第一行下一个结点
		for (int j = 1; j <= t; j++) {
			PositiveCount -= x[j][t - j];
		}
		PositiveCount -= i;	//回溯
	}
}

int main() {
	cin >> n;
	x = new int* [n];
	for (int i = 0; i < n; i++) {
		x[i] = new int[n - i];
		for (int j = 0; j < n - i; j++) x[i][j] = 0;
	}

	half = n * (n + 1) / 4;

	BackTrack(0);

	cout << "符号三角形个数为: " << sum;
}