#include <iostream>
using namespace std;

void BackTracing() {

}


int main() {
	int num;
	cin >> num;
	bool* visited = new bool[num];
	for (int i = 0; i < num; i++) visited[i] = false;
	int** fee = new int* [num];
	for (int i = 0; i < num; i++) {
		fee[i] = new int[num];
		for (int j = 0; j < num; j++) {
			cin >> fee[i][j];
		}
	}

	BackTracing();
}