#include <iostream>
#include <cmath>
#include<iomanip> 
using namespace std;

int n; // bậc của đa thức

// Tính giá trị fx tại x0 
double fx(double x) {
	double tong = tan(x/4)-1;
	return tong;
}

// Tính giá trị f'x tại x0
double daoham(double x) {
	double tong = 1/ (4*cos(x/4)*cos(x/4));
	return tong;
}

// Tính giá trị f"x tại x0
double daoham2(double x) {
	double tong = sin(x / 4) / (8 * pow(cos(x / 4), 3));
	return tong;
}


int main() {
	double a0, a1, saiso;
	a0 = 3.1;
	a1 = 3.2;
	cout << "nhap sai so: ";
	cin >> saiso;


	double d;		// điểm fourier và f'x min
	double x[100];
	// Tìm fourier
	for (double i = a0; i <= a1; i = i + 0.001) {
		if (fx(i) * daoham2(i) > 0) {
			d = i;
			break;
		}
	}
	cout <<"d: "<< d;
	double fd = fx(d);

	// Tìm nghiệm đầu x0
	for (double i = a0; i <= a1; i += 0.001) {
		if (fx(i) * daoham2(i) < 0) {
			x[0] = i;
			break;
		}
	}
	cout << endl <<"x0: "<< x[0] << endl;
	// Tìm m
	double m = abs(daoham(a0));
	for (double i = a0; i <= a1; i += 0.0001) {
		if (abs(daoham(i)) < m && abs(daoham(i)) >0) {
			m = abs(daoham(i));
		}
	}
	cout << m << endl;

	/* lặp*/
	int i = 1;
	double fxn;
	for (;;) {
		fxn = fx(x[i - 1]);
		if ((abs(fxn) / m) < saiso) {
			break;
		}
		x[i] = x[i - 1] - ((fxn * (d - x[i - 1])) / (fd - fxn));
		if (i == 15) {
			x[9] = x[i];
			i = 9;
		}
		i++;
	}
	cout << "nghiem la: " << setprecision(9) << fixed << x[i - 1];

	return 0;
}