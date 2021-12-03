#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define WIDTH 16

int CheckBoard[WIDTH + 1][WIDTH + 1] = { 0 };

//���ߵİ˸�����
int nextStepX[8] = { -2,-2,-1,-1,1,1,2,2 };
int nextStepY[8] = { -1,1,-2,2,2,-2,-1,1 };

typedef struct Point {
	int dir;	//Ѳ�η���
	vector<int> moves;	//��һ��Ѳ�ο��ߵķ���

	//���� < ����������������
	bool operator < (const Point& x) const
	{
		return moves.size() < x.moves.size();
	}
}Point;

//��֦����
bool judgePrune(int x, int y) {
	//�����߳������Ҹõ�δ�߹�
	return (x >= 1 && x <= WIDTH && y >= 1 && y <= WIDTH && CheckBoard[x][y] == 0);
}

//��õ�ǰλ�ÿ�Ѳ�εķ���
vector<int> getMoves(int x, int y) {
	vector<int> next_moves;
	for (int i = 0; i < 8; i++) {
		if (judgePrune(x + nextStepX[i], y + nextStepY[i])) 
			next_moves.push_back(i);
	}
	return next_moves;
}

void print(int CheckBoard[WIDTH+1][WIDTH+1]) {
	for (int i = 1; i <= WIDTH; i++) {
		for (int j = 1; j <= WIDTH; j++) {
			cout << CheckBoard[i][j] << "\t";
			if (j == WIDTH)cout << endl;
		}
	}
}

//void travel(int x, int y, int step) {
//	int next_x;
//	int next_y;
//
//	CheckBoard[x][y] = step;
//
//	if (step == WIDTH * WIDTH) {
//		print(CheckBoard);
//		return;
//	}
//
//	for (int i = 0; i < 8; i++) {
//		next_x = x + nextStepX[i];
//		next_y = y + nextStepY[i];
//		if (judgePrune(next_x, next_y)) travel(next_x, next_y, step + 1);
//	}
//	CheckBoard[x][y] = 0;
//	return;
//}

//Ѳ�κ��� pre��¼��ǰλ��(x,y)��Ѳ�εķ���
void travel(int x, int y, int step, Point pre) {
	vector<Point> next_point;

	CheckBoard[x][y] = step;

	//Ѳ�ν������
	if (step == WIDTH * WIDTH) {
		print(CheckBoard);
		return;
	}

	//û�п�Ѳ�εķ��򣬻���
	if (pre.moves.size() == 0) return;

	for (int i = 0; i < pre.moves.size(); i++) {
		Point point;	
		point.dir = pre.moves[i];
		point.moves = getMoves(x + nextStepX[point.dir], y + nextStepY[point.dir]);
		next_point.push_back(point);	//�����п�Ѳ�η������һ����Ѳ�εķ������next_point������
	}

	//����һ����Ѳ�η���������С��������
	sort(next_point.begin(), next_point.end());
	//ѡ����һ����Ѳ�η������ٵķ������Ѳ��
	travel(x + nextStepX[next_point[0].dir], y + nextStepY[next_point[0].dir], step + 1, next_point[0]);

	//�ָ�״̬ ����
	CheckBoard[x][y] = 0;
	return;
}

int main() {
	Point point;
	int x, y;
	cout << "��������ʼλ��x����:(1-8) ";
	cin >> x;
	cout << "��������ʼλ��y����:(1-8) ";
	cin >> y;
	point.moves = getMoves(x, y);
	travel(x, y, 1, point);
}