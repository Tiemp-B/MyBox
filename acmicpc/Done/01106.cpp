#include <iostream>
#include <queue>

#define CITIZEN 3001

using namespace std;



struct city {
	int customer;
	int price;
};

int INT_MX = 2147483647;
int C, N;

city cities[20];
int mat[21][CITIZEN];

void printMap(int s, int e) {
	printf("99: ");
	for (int i = s; i < e; i++) printf("%3d ", i);
	cout << endl;

	for (int i = 0; i < N; i++) {
		printf("%2d: ", i);
		for (int j = s; j < e; j++) {
			printf("%3d ", mat[i][j]);
		}
		cout << endl;
	}
	cout << endl;
	printf("20: ");
	for (int j = s; j < e; j++) {
		printf("%3d ", mat[20][j]);
	}
	cout << endl;

}

int main() {
	cin >> C >> N;

	for (int i = 0, C, P; i < N; i++) {
		cin >> P >> C;
		cities[i].customer = C;
		cities[i].price = P;
	}

	for (int j = 1; j < CITIZEN; ++j) {
		int min_dat = INT_MX;
		for (int i = 0; i < N; ++i) {
			if (j < cities[i].customer) continue;// �߰� �Ұ� 
			if (mat[20][j - cities[i].customer] == 0 && (j != cities[i].customer)) continue;
			mat[i][j] = mat[20][j - cities[i].customer] + cities[i].price;
			if (mat[i][j] == 0)continue;
			if (mat[i][j] < min_dat) min_dat = mat[i][j];
		}
		if (min_dat == INT_MX) continue;
		mat[20][j] = min_dat;
	}
	int ans = INT_MX;

	//printMap(0, 10);

	for (int i = C; i < CITIZEN; ++i) {
		if(mat[20][i] == 0 ) continue;
		if (mat[20][i] < ans) ans = mat[20][i];
	}

	cout << ans;

	return 0;
}
