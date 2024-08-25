#include <iostream>
#include <cmath>

using namespace std;

const double saiso = 1e-9;  // Độ chính xác
int n;
// Hàm tính giá trị của đa thức tại điểm x
double fx(double a[], double x) {
    double tong = 0;
    for (int i = 0; i <= n; i++) {
        tong += a[i] * pow(x, i);
    }
    return tong;
}

// Hàm tìm khoảng phân ly nghiệm của đa thức
void kpl(double a[]) {
    double left = -1000.0;  // Giới hạn trái của khoảng giá trị x
    double right = 1000.0;  // Giới hạn phải của khoảng giá trị x
    double step = 0.1;      // Bước nhảy để kiểm tra các điểm x

    double y1 = fx(a, left);
    for (double x = left + step; x <= right; x += step) {
        double y2 = fx(a, x);
        if (y1 * y2 < 0) {
            // Tìm được một khoảng phân ly nghiệm
            cout << "[" << left << ", " << x << "]" << endl;
        }
        if (fabs(y2) <= saiso) {
            // Điểm x là một nghiệm chính xác
            cout << "Nghiem la: " << x << endl;
        }
        left = x;
        y1 = y2;
    }
}

int main() {
    cout << "Nhap bac cua da thuc: ";
    cin >> n;

    double a[100];
    for (int i = 0; i <= n; i++) {
        cout << "Nhap he so x^" << i << ": ";
        cin >> a[i];
    }

    kpl(a);

    return 0;
}
