#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define WIDTH 16

int CheckBoard[WIDTH + 1][WIDTH + 1] = { 0 };

//可走的八个方向
int nextStepX[8] = { -2,-2,-1,-1,1,1,2,2 };
int nextStepY[8] = { -1,1,-2,2,2,-2,-1,1 };

typedef struct Point {
	int dir;	//巡游方向
	vector<int> moves;	//下一次巡游可走的方向

	//重载 < 操作符，方便排序
	bool operator < (const Point& x) const
	{
		return moves.size() < x.moves.size();
	}
}Point;

//剪枝函数
bool judgePrune(int x, int y) {
	//不会走出棋盘且该点未走过
	return (x >= 1 && x <= WIDTH && y >= 1 && y <= WIDTH && CheckBoard[x][y] == 0);
}

//获得当前位置可巡游的方向
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

//巡游函数 pre记录当前位置(x,y)可巡游的方向
void travel(int x, int y, int step, Point pre) {
	vector<Point> next_point;

	CheckBoard[x][y] = step;

	//巡游结束输出
	if (step == WIDTH * WIDTH) {
		print(CheckBoard);
		return;
	}

	//没有可巡游的方向，回溯
	if (pre.moves.size() == 0) return;

	for (int i = 0; i < pre.moves.size(); i++) {
		Point point;	
		point.dir = pre.moves[i];
		point.moves = getMoves(x + nextStepX[point.dir], y + nextStepY[point.dir]);
		next_point.push_back(point);	//将所有可巡游方向的下一步可巡游的方向放入next_point容器中
	}

	//将下一步可巡游方向容器由小到大排序
	sort(next_point.begin(), next_point.end());
	//选择下一步可巡游方向最少的方向进行巡游
	travel(x + nextStepX[next_point[0].dir], y + nextStepY[next_point[0].dir], step + 1, next_point[0]);

	//恢复状态 回溯
	CheckBoard[x][y] = 0;
	return;
}

int main() {
	Point point;
	int x, y;
	cout << "请输入起始位置x坐标:(1-8) ";
	cin >> x;
	cout << "请输入起始位置y坐标:(1-8) ";
	cin >> y;
	point.moves = getMoves(x, y);
	travel(x, y, 1, point);
}