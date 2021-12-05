#include <iostream>
using namespace std;

int n;	//��Ʒ����
int W;	//����������
int* w;	//ÿ����Ʒ������
int* v;	//ÿ����Ʒ�ļ�ֵ
bool* x;	//ÿ����Ʒ�Ƿ���뱳��
int cw = 0, cv = 0;		//��ǰ���뱳���������ͼ�ֵ
int bestv = 0;	//��ǰ���Ž⣬����ǰ��ֵ�����ֵ
bool* bestx;	//��ǰ���Ž⣬ÿ����Ʒ�Ƿ���뱳����0Ϊ�����룬1Ϊ���룩


int Bound(int t) {
	int rv = 0;	//��¼ʣ����Ʒ���ȫ���뱳�����ܼ�ֵ
	for (int i = t; i < n; i++) rv += v[i];
	return cv + rv;
}

void BackTracking(int t) {
	if (t == n) {	//����Ҷ�ӽڵ�ʱ����¼���Ž�
		for (int i = 0; i < n; i++) bestx[i] = x[i];
		bestv = cv;
		return;
	}
	if (cw + w[t] <= W) {	//�����ǰ��Ʒ���Է��뱳���������cw��cv
		x[t] = 1;
		cw += w[t];
		cv += v[t];
		BackTracking(t + 1);	//�ݹ�������һ����Ʒ
		cw -= w[t];
		cv -= v[t];	//����
	}
	if (Bound(t + 1) > bestv) {
		x[t] = 0;	//��ǰ��Ʒ�����뱳��������x���飬������cw��cv
		BackTracking(t + 1);	//�ݹ�������һ����Ʒ
	}
}

int main() {

	//cout << "��������Ʒ����:";
	cin >> n;	//������Ʒ����
	//cout << "�����뱳������:";
	cin >> W;	//���뱳������

	//cout << "������ÿ����Ʒ�������ͼ�ֵ:\n";

	w = new int[n];
	v = new int[n];
	x = new bool[n];
	bestx = new bool[n] {0};

	for (int i = 0; i < n; i++) {
		cin >> w[i];
		cin >> v[i];	//������Ʒ�������ͼ�ֵ
	}

	int sumw = 0;
	for (int i = 0; i < n; i++)sumw += w[i];	//�����������Ʒȫ�����뱳�����������
	if (sumw <= W) {
		int sumv = 0;
		for (int i = 0; i < n; i++) {
			sumv += v[i];
		}
		//cout << "���뱳�����ܼ�ֵΪ��" << sumv << endl;
		cout << sumv;
	}
	else {
		BackTracking(0);
		//cout << "���뱳�����ܼ�ֵΪ: " << bestv << endl;
		cout << bestv;
		//for (int i = 0; i < n; i++) cout << bestx[i] << " ";
	}
}