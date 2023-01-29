//
#include <bits/stdc++.h>

using namespace std;

class IScaler {
public:
    virtual auto Fit(double arr[]) -> void { }

    virtual auto Transform(double arr[]) -> vector<double> { }

    virtual auto Inverse(double arr[]) -> vector<double> { }

    virtual auto FitTransform(double arr[]) -> vector<double> { }
};

class MinMaxScaler: public IScaler {
protected:
    double min, max;
public:
    auto Fit(double arr[]) -> void {
        min = arr[0];
        max = arr[0];
        int length = sizeof(arr) / sizeof(arr[0]);
        for (int i = 0; i < length; ++i) {
            if (min > arr[i]) {
                min = arr[i];
            }
            if (max < arr[i]) {
                max = arr[i];
            }
        }

    }

    auto Transform(double arr[]) -> vector<double> {
        int length = sizeof(arr) / sizeof(arr[0]);
        vector<double> tmp(length + 1);
        for (int i = 0; i < length; ++i) {
            tmp[i] = (arr[i] - min) / (max - min);
        }
        return tmp;
    }

    auto Inverse(double arr[]) -> vector<double> {
        int length = sizeof(arr) / sizeof(arr[0]);
        vector<double> tmp(length + 1);
        for (int i = 0; i < length; ++i) {
            tmp[i] = arr[i] * (max - min) + min;
        }
        return tmp;
    }

    auto FitTransform(double arr[]) -> vector<double> {
        Fit(arr);
        return Transform(arr);
    }
};

class MaxAbsScaler: public IScaler {
protected:
    double maxAbs;
public:
    auto findMax(double arr[]) -> double {
        maxAbs = arr[0];
        int length = sizeof(arr) / sizeof(arr[0]);
        for (int i = 0; i < length; ++i) {
            if (maxAbs < arr[i]) {
                maxAbs = arr[i];
            }
        }
        return maxAbs;
    }

    auto Fit(double arr[]) -> void { }

    auto Transform(double arr[]) -> vector<double> {
        double xMax = findMax(arr);
        int length = sizeof(arr) / sizeof(arr[0]);
        vector<double> tmp(length + 1);
        for (int i = 0; i < length; ++i) {
            tmp[i] = arr[i] / xMax;
        }
        return tmp;
    }

    auto Inverse(double arr[]) -> vector<double> {
        double xMax = findMax(arr);
        int length = sizeof(arr) / sizeof(arr[0]);
        vector<double> tmp(length + 1), res = Transform(arr);
        for (int i = 0; i < length; ++i) {
            tmp[i] = res[i] * xMax;
        }
        return tmp;
    }

    auto FitTransform(double arr[]) -> vector<double> { }
};


int32_t main() { }
class Shape {
protected:
    const float pi = 2.0 * acos(0.0);
public:
    virtual auto input() -> void { }

    virtual auto calcArea() -> void { }

    virtual auto calcPerimeter() -> void { }
};

class Ellipse: public Shape {
protected:
    float a, b;
public:
    Ellipse(float a, float b): a(a), b(b) {
        this->a = a;
        this->b = b;
    }

    Ellipse() { }

    auto input() -> void {
        cout << "Input a, b: ";
        cin >> a >> b;
    }

    auto calcArea() -> void {
        cout << "Area: " << (double) pi * a * b << '\n';
    }

    auto calcPerimeter() -> void {
        cout << "Perimeter: " << (double) pi * (a + b) << '\n';
    }
};

class Circle: public Shape {
protected:
    float r;
public:
    explicit Circle(float r): r(r) {
        this->r = r;
    }

    Circle() { }

    auto input() -> void {
        cout << "Input r: ";
        cin >> r;
    }

    auto calcArea() -> void {
        cout << "Area: " << (double) pi * r * r << '\n';
    }

    auto calcPerimeter() -> void {
        cout << "Perimeter: " << (double) 2 * pi * r << '\n';
    }
};

int32_t main() {
    //    ios::sync_with_stdio(false);
    //    cin.tie(nullptr);
    //    cout.tie(nullptr);
        // XỬ DỤNG tính đa xạ
    Shape *s[5];
    s[0] = new Ellipse();
    s[0]->input();
    s[0]->calcPerimeter();
    s[0]->calcArea();

    s[1] = new Circle();
    s[1]->input();
    s[1]->calcPerimeter();
    s[1]->calcArea();

    s[2] = new Ellipse(20, 30);
    s[2]->calcPerimeter();
    s[2]->calcArea();

    s[3] = new Circle(15);
    s[3]->calcPerimeter();
    s[3]->calcArea();

    // giải phóng dung lượng
    for (int i = 0; i < 4; ++i) {
        delete (s[i]);
    }
}
