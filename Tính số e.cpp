#include <iostream>
#include <cmath>
#include<iomanip> 
using namespace std;

int n; // bậc của đa thức

// Tính giá trị fx tại x0 
double fx(double x) {
	double tong = log(x) - 1;
	return tong;
}

// Tính giá trị f'x tại x0
double daoham(double x) {
	double tong = 1 / x;
	return tong;
}

// Tính giá trị f"x tại x0
double daoham2(double x) {
	double tong = -1 / (x * x);
	return tong;
}

// Nghiem xi
double nghiem(double x) {
	double x1 = (-fx(x) / daoham(x)) + x;
	return x1;
}


int main() {
	double a0, a1, saiso;
	// KPL
	a0 = 2.7;
	a1 = 2.8;
	cout << "nhap sai so: ";
	cin >> saiso;
	double x[30];
	//Tìm xấp xỉ đầu x0
	x[0] = 0;
	for (double i = a0; i <= a1; i = i + 0.001) {
		if (fx(i) * daoham2(i) > 0) {
			x[0] = i;
			break;
		}
	}
	cout << "x[0]= " << x[0] << endl;
	// Tìm min của f'x
	double m = abs(daoham(a0));
	for (double i = a0; i <= a1; i += 0.0001) {
		if (abs(daoham(i)) < m && abs(daoham(i)) > 0) {
			m = abs(daoham(i));
		}
	}
	cout << "m= " << m << endl;
	// TÌm max của f"x
	double M = abs(daoham2(a0));
	for (double i = a0; i <= a1; i += 0.0001) {
		if (abs(daoham2(i)) > m) {
			m = abs(daoham2(i));
		}
	}
	cout << "M= " << M << endl;
	// Lặp
	int i = 1;

	for (;;) {
		x[i] = nghiem(x[i - 1]);
		if (M * abs(x[i] - x[i - 1]) / (2 * m) < saiso) {
			break;
		}
		if (i == 20) {
			x[7] = x[18];
			x[8] = x[19];
			x[9] = x[20];
			i = 9;
		}
		i++;
	}

	cout << "nghiem la: " << setprecision(9) << fixed << x[i] << endl;

	return 0;
}
