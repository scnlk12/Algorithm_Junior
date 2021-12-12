#include <iostream>
using namespace std;

int n;	//n件工作，n个人
int** c;	//费用数组
int currc;	//当前费用
int bestc = 9999;	//费用最优解
int* x;	//当前工作分配方式

void BackTrack(int t) {
	if (t == n) {
		if(currc<bestc) bestc = currc;
		return;
	}

	for (int i = t; i < n; i++) {
		swap(x[i], x[t]);
		currc += c[t][x[t]];
		BackTrack(t + 1);
		currc -= c[t][x[t]];
		swap(x[i], x[t]);
	}
}

int main() {
	cin >> n;
	c = new int* [n];
	x = new int[n];
	for (int i = 0; i < n; i++) x[i] = i;
	for (int i = 0; i < n; i++) {
		c[i] = new int[n];
		for (int j = 0; j < n; j++) cin >> c[i][j];
	}
	BackTrack(0);
	cout << bestc;
}