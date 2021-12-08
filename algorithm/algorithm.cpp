#include <iostream>
using namespace std;

int n;	//��ҵ��
int** Time;	//��ҵ�����������ϵ�����ʱ��

int ct;	//��ǰ���е���ʱ��
int ct1;	//�ڻ���һ�����н�����ʱ��
int ct2;	//�ڻ����������н�����ʱ��

int bestT = 10000;	//���Ž�
int* x;	//��ҵ����
int* bestX;	//���ŵ���

void BackTrack(int t) {
	if (t == n) {	//����Ҷ�ӽ��
		if (ct < bestT) {	//��¼���Ž�
			bestT = ct;
			for (int i = 0; i < n; i++) bestX[i] = x[i];
			return;
		}
	}

	//�м���
	for (int i = t; i < n; i++) {	//�ҳ���������

		swap(x[i], x[t]);	//������iλ�͵�tλ����µ�����
		ct1 += Time[x[t]][0];	//ct1��¼��ǰ�ڻ���һ�����н�����ʱ�� tΪ�������
		int temp = ct2;
		if (ct1 > ct2) ct2 = ct1 + Time[x[t]][1];
		else ct2 += Time[x[t]][1];	//ct2��¼��ǰ��ҵ�ڻ����������н�����ʱ�� tΪ�������
		ct += ct2;	//ct��¼�����е���ҵ�ڻ����������н�����ʱ��

		BackTrack(t + 1);	//�ݹ�������һ��

		ct -= ct2;
		ct1 -= Time[x[t]][0];
		ct2 = temp;
		swap(x[i], x[t]);	//����
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
	cout << "���Ž��ʱ��Ϊ: ";
	cout << bestT << endl;

	cout << "��������Ϊ: ";
	for (int i = 0; i < n; i++) {
		cout << bestX[i] + 1 << " ";
	}
}