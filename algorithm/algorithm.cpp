#include <iostream>
using namespace std;

//可走的8个方向
int dx[8] = { 1,-1,0,0,1,-1,1,-1 };	
int dy[8] = { 0,0,1,-1,1,1,-1,-1 };

int n, m;	//n为迷宫行数，m为迷宫列数
int k;	//封闭房间数
int** board;	//迷宫
int** bestRoute;	//记录一个最优解
int Rx, Ry;	//罗密欧位置
int Jx, Jy;	//朱丽叶位置
int routeCount = 0;	//路径数
int d = 0;	//当前行进方向
int dir = 0;	//当前转弯数
int bestdir = 9999;	//最小转弯数
int step = 1;	//走过的方格数 结束条件

//判断是否出界且是否封闭是否已经走过
bool Bound(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 0) return true;
	return false;
}

void BackTrack(int x, int y,int d) {
	if (step == n * m - k) {
		if (x == Jx && y == Jy) {
			if (dir <= bestdir) {
				if (dir < bestdir) {
					routeCount = 1;
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							bestRoute[i][j] = board[i][j];
						}
					}
				}
				else routeCount++;
				bestdir = dir;
			}
		}

		
		return;
	}
	for (int i = 0; i < 8; i++) {
		if (Bound(x + dx[i], y + dy[i])) {
			x += dx[i];
			y += dy[i];
			if (d != i) dir++;
			step++;
			board[x][y] = step;
			BackTrack(x, y, i);
			board[x][y] = 0;
			x -= dx[i];
			y -= dy[i];
			if (d != i) dir--;
			step -= 1;

			

		}
	}
}

int main() {
	cin >> n >> m >> k;
	board = new int* [n];
	bestRoute = new int* [n];
	for (int i = 0; i < n; i++) {
		board[i] = new int[m];
		bestRoute[i] = new int[m];
		for (int j = 0; j < m; j++) {
			board[i][j] = 0;
			bestRoute[i][j] = 0;
		}
	}
	int a, b;	//封闭房间行数和列数
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		board[a - 1][b - 1] = -1;
	}
	cin >> Rx >> Ry;
	cin >> Jx >> Jy;	

	//数组定义起始位置为(0,0)
	Rx -= 1;
	Ry -= 1;
	Jx -= 1;
	Jy -= 1;

	board[Rx][Ry] = step;

	BackTrack(Rx, Ry, 0);

	if (routeCount != 0) {
		cout << bestdir << endl;
		cout << routeCount << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << bestRoute[i][j];
				if (j != m - 1) cout << " ";
				
			}
			cout << endl;
		}
	}
	else cout << "No Solution!";
}
