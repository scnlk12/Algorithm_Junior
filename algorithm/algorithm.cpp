#include <iostream>
using namespace std;

int n;	//作业数
int** Time;	//作业在两个机器上的运行时间

int ct;	//当前运行的总时间
int ct1;	//在机器一上运行结束的时间
int ct2;	//在机器二上运行结束的时间

int bestT = 10000;	//最优解
int* x;	//作业调度
int* bestX;	//最优调度

void BackTrack(int t) {
	if (t == n) {	//到达叶子结点
		if (ct < bestT) {	//记录最优解
			bestT = ct;
			for (int i = 0; i < n; i++) bestX[i] = x[i];
			return;
		}
	}

	//中间结点
	for (int i = t; i < n; i++) {	//找出所有排列

		swap(x[i], x[t]);	//交换第i位和第t位获得新的序列
		ct1 += Time[x[t]][0];	//ct1记录当前在机器一上运行结束的时间 t为搜索深度
		int temp = ct2;
		if (ct1 > ct2) ct2 = ct1 + Time[x[t]][1];
		else ct2 += Time[x[t]][1];	//ct2记录当前作业在机器二上运行结束的时间 t为搜索深度
		ct += ct2;	//ct记录已运行的作业在机器二上运行结束的时间

		BackTrack(t + 1);	//递归搜索下一层

		ct -= ct2;
		ct1 -= Time[x[t]][0];
		ct2 = temp;
		swap(x[i], x[t]);	//回溯
	}

}

int main() {
	cin >> n;
	Time = new int* [n];
	x = new int[n] {0};
	bestX = new int[n] {0};
	for (int i = 0; i < n; i++) x[i] = i;
	for (int i = 0; i < n; i++) {
		Time[i] = new int[2];
		for (int j = 0; j < 2; j++) cin >> Time[i][j];
	}

	BackTrack(0);
	cout << "最优解的时间为: ";
	cout << bestT << endl;

	cout << "调度序列为: ";
	for (int i = 0; i < n; i++) {
		cout << bestX[i] + 1 << " ";
	}
}