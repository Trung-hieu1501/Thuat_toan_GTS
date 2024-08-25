#include <iostream>
#include <cmath>
#include<iomanip> 
using namespace std;

int n; // bậc của đa thức

// Tính giá trị fx tại x0 
double fx(double a[], double x) {
	double tong = 0;
	for (int i = 0; i <= n; i++) {
		tong += a[i] * pow(x, i);
	}
	return tong;
}

// Tính giá trị f'x tại x0
double daoham(double a[], double x) {
	double tong = 0;
	for (int i = 1; i <= n; i++) {
		tong += a[i] * (i)*pow(x, i-1);
	}
	return tong;
}

// Tính giá trị f"x tại x0
double daoham2(double a[], double x) {
	double tong = 0;
	for (int i = 2; i <= n; i++) {
		tong += a[i] * (i - 1) * i * pow(x, (i - 2));
	}
	return tong;
}

// Nghiem xi
double nghiem(double a[], double x) {
	double x1 = (-fx(a, x) / daoham(a, x)) + x;
	return x1;
}


int main() {
	cout << "nhap bac cua da thuc: ";
	cin >> n;
	double a[100];
	for (int i = 0; i <= n; i++) {
		cout << "nhap he so cua x^" << i << ": \n";
		cin >> a[i];
	}

	double a0, a1, saiso;
	cout << "nhap khoang phan ly: ";
	cin >> a0 >> a1;
	cout << "nhap sai so: ";
	cin >> saiso;
	double x[30];
	//Tìm xấp xỉ đầu x0
	/*x[0] = 0;*/
	for (double i = a0; i <= a1; i = i + 0.001) {
		if (fx(a, i) * daoham2(a, i) > 0) {
			x[0] = i;
			break;
		}
	}
	cout << "x[0]= " << x[0] << endl;
	// Tìm min của f'x
	double m = abs(daoham(a, a0));
	for (double i = a0; i <= a1; i += 0.0001) {
		if (abs(daoham(a, i)) < m && abs(daoham(a, i)) >0) {
			m = abs(daoham(a, i));
		}
	}
	cout << "m= " << m << endl;
	// TÌm max của f"x
	double M = abs(daoham2(a, a0));
	for (double i = a0; i <= a1; i += 0.0001) {
		if (abs(daoham2(a, i)) > m) {
			m = abs(daoham2(a, i));
		}
	}
	cout << "M= " << M <<endl;
	// Lặp
	int i = 1;

	for (;;) {
		x[i] = nghiem(a, x[i-1]);
		if (M * abs(x[i] - x[i - 1]) / (2 * m)< saiso) {
			break;
		}
	/*	if (i == 20) {
			x[7] = x[18];
			x[8] = x[19];
			x[9] = x[20];
			i = 9;
		}*/
		i++;
	}
	
	/*cout << "nghiem la: " << setprecision(9) << fixed << x[i] << endl;*/

	// Tính sai số
	// |Xn - X*| <= (M/2m) * (X[n] - X[n-1])^2
	// M = max(f'x)
	// m = min(f'x)
	for (int k = 1; k < 4; k++) {
		cout << x[k] << " ";
	}
	cout << endl << endl;
	for (int k = i-2; k <=i; k++) {
		cout << x[k] << " ";
	}

	return 0;
}
