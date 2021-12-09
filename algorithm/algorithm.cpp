#include <iostream>
using namespace std;

int sum = 0;	//���������θ���
int n = 0;	//��һ����n������
int PositiveCount = 0;	//��+������
int** x;	//���������ξ���
int half = 0;	//half = n * (n + 1) / 4

void BackTrack(int t) {


	if (PositiveCount > half || ((t + 1) * t / 2 - PositiveCount) > half) return;	//+��-�����ܷ�������һ�룬��֦

	if (t == n) {	//Ҷ�ӽ��
		sum++;	//����Ҷ�ӽ�㣬�����θ���+1
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
	for (int i = 0; i < 2; i++) {	//��һ��ÿ����㶼�����ֿ����� +/-
		x[0][t] = i;
		PositiveCount += i;
		for (int j = 1; j <= t; j++) {	//�������������
			if (x[j - 1][t - j] == x[j - 1][t - j + 1]) x[j][t - j] = 1;
			else x[j][t - j] = 0;
			PositiveCount += x[j][t - j];
		}
		BackTrack(t + 1);	//��һ����һ�����
		for (int j = 1; j <= t; j++) {
			PositiveCount -= x[j][t - j];
		}
		PositiveCount -= i;	//����
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

	cout << "���������θ���Ϊ: " << sum;
}