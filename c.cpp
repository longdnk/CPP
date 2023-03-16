#include "bits/stdc++.h"

using namespace std;

class DrawingShape;

class Shape {
protected:
    DrawingShape *drawer;
public:
    Shape(DrawingShape *ds) {
        drawer = ds;
    }

    virtual void draw() = 0;
};

class DrawingShape {
public:
    virtual void draw(Shape *s) = 0;
};

class DrawingCircle : public DrawingShape {
public:
    void draw(Shape *s) {
        cout << "Drawing Circle" << '\n';
    }
};

class DrawingRectangle : public DrawingShape {
    void draw(Shape *s) {
        cout << "Drawing Rectangle" << '\n';
    }
};

class Rectagle : public Shape {
private:
    int x, y, width, height;
public:
    Rectagle(int x, int y, int w, int h, DrawingShape *ds) : Shape(ds) {}

    void draw() {
        cout << "Rectangle" << '\n';
        drawer->draw(this);
    }
};

class Circle : public Shape {
private:
    int x, y, radius;
public:
    Circle(int x, int y, int radius, DrawingShape *ds) : Shape(ds) {}

    void draw() {
        cout << "Circle" << '\n';
        drawer->draw(this);
    }
};

const int maxN = 1e5 + 11;
int f[maxN];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    auto sumOfNum = [&](int n) -> int {
        string s = to_string(n);
        int sum = 0;
        for (int i = 0; s[i] != '\0'; ++i) {
            sum += s[i] - '0';
        }
        return sum;
    };
    int n, res = -1;
    cin >> n;
    fill_n(f + 2, n + 1, 1);
    for (int i = 2; i * i <= n; ++i) {
        if (f[i]) {
            for (int j = i * i; j <= n; j += i) {
                f[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (f[i] && f[sumOfNum(i)]) {
            res = i;
        }
    }
    cout << res << '\n';
//    DrawingShape *d[] = { new DrawingRectangle, new DrawingCircle };
//    Shape *s[] = {
//            new Rectagle(10, 10, 10, 10, d[0]),
//            new Rectagle(20, 20, 20, 20, d[0]),
//            new Circle(30, 30, 30, d[1])
//    };
//    int n = sizeof(s) / sizeof(s[0]);
//    for (int i = 0; i < n; ++i) {
//        s[i]->draw();
//    }
//    vector<DrawingShape *> d = {
//            new DrawingRectangle, new DrawingCircle
//    };
//    vector<Shape *> s = {
//            new Rectagle(10, 10, 10, 10, d[0]),
//            new Rectagle(20, 20, 20, 20, d[0]),
//            new Circle(30, 30, 30, d[1])
//    };
//    for (Shape *item: s) {
//        item->draw();
//    }
}
