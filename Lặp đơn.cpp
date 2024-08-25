#include<iostream>
using namespace std;

int tong(int a[][10], int b[][10], int n, int m) {
	int c = 0;
	for (int j = 0; j < 4; j++) {
		c += a[n][j] * b[j][m];
	}
	return c;
}

int main() {
	int a[10][10];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a[i][j];
		}
	}
	int b[10][10];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			b[i][j] = a[j][i];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl << endl;

	int c[100][100];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			c[i][j] = tong(a, b, i, j);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl << endl;
}