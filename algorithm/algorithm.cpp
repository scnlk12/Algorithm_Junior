#include <iostream>
using namespace std;

//���ߵ�8������
int dx[8] = { 1,-1,0,0,1,-1,1,-1 };	
int dy[8] = { 0,0,1,-1,1,1,-1,-1 };

int n, m;	//nΪ�Թ�������mΪ�Թ�����
int k;	//��շ�����
int** board;	//�Թ�
int** bestRoute;	//��¼һ�����Ž�
int Rx, Ry;	//����ŷλ��
int Jx, Jy;	//����Ҷλ��
int routeCount = 0;	//·����
int d = 0;	//��ǰ�н�����
int dir = 0;	//��ǰת����
int bestdir = 9999;	//��Сת����
int step = 1;	//�߹��ķ����� ��������

//�ж��Ƿ�������Ƿ����Ƿ��Ѿ��߹�
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
	int a, b;	//��շ�������������
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		board[a - 1][b - 1] = -1;
	}
	cin >> Rx >> Ry;
	cin >> Jx >> Jy;	

	//���鶨����ʼλ��Ϊ(0,0)
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
