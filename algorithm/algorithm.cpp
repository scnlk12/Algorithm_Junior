#include <iostream>
using namespace std;

int n;	//物品总数
int W;	//背包总容量
int* w;	//每个物品的重量
int* v;	//每个物品的价值
bool* x;	//每个物品是否放入背包
int cw = 0, cv = 0;		//当前放入背包的容量和价值
int bestv = 0;	//当前最优解，即当前价值的最大值
bool* bestx;	//当前最优解，每个物品是否放入背包（0为不放入，1为放入）


int Bound(int t) {
	int rv = 0;	//记录剩余物品如果全放入背包的总价值
	for (int i = t; i < n; i++) rv += v[i];
	return cv + rv;
}

void BackTracking(int t) {
	if (t == n) {	//到达叶子节点时，记录最优解
		for (int i = 0; i < n; i++) bestx[i] = x[i];
		bestv = cv;
		return;
	}
	if (cw + w[t] <= W) {	//如果当前物品可以放入背包，则更新cw和cv
		x[t] = 1;
		cw += w[t];
		cv += v[t];
		BackTracking(t + 1);	//递归搜索下一个物品
		cw -= w[t];
		cv -= v[t];	//回溯
	}
	if (Bound(t + 1) > bestv) {
		x[t] = 0;	//当前物品不放入背包，更新x数组，不更新cw和cv
		BackTracking(t + 1);	//递归搜索下一个物品
	}
}

int main() {

	//cout << "请输入物品个数:";
	cin >> n;	//输入物品个数
	//cout << "请输入背包容量:";
	cin >> W;	//输入背包容量

	//cout << "请输入每个物品的重量和价值:\n";

	w = new int[n];
	v = new int[n];
	x = new bool[n];
	bestx = new bool[n] {0};

	for (int i = 0; i < n; i++) {
		cin >> w[i];
		cin >> v[i];	//输入物品的重量和价值
	}

	int sumw = 0;
	for (int i = 0; i < n; i++)sumw += w[i];	//计算如果将物品全部放入背包所需的容量
	if (sumw <= W) {
		int sumv = 0;
		for (int i = 0; i < n; i++) {
			sumv += v[i];
		}
		//cout << "放入背包的总价值为：" << sumv << endl;
		cout << sumv;
	}
	else {
		BackTracking(0);
		//cout << "放入背包的总价值为: " << bestv << endl;
		cout << bestv;
		//for (int i = 0; i < n; i++) cout << bestx[i] << " ";
	}
}