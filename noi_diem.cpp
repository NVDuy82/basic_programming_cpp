#include <iostream>
#include <math.h>
#include <limits>

using namespace std;

template <typename T>
struct point {
private:
    T x, y;

public:
    point() {
        x = y = 0;
    }

    point(T x, T y) : x(x), y(y) {}

    friend istream & operator >> (istream & is, point & point) {
        is >> point.x >> point.y;
        return is;
    }

    T getX() const {
        return x;
    }
    void setX(T x) {
        point::x = x;
    }
    T getY() const {
        return y;
    }
    void setY(T y) {
        point::y = y;
    }

    friend double distance(const point a, const point b) {
        T dx = a.x - b.x;
        T dy = a.y - b.y;
        return sqrt(dx*dx + dy*dy);
    }
};

double prims(point<double> * point, int n) {
    double p[n], res = 0;
    for (int i = 1; i < n; ++i) {
        p[i] = numeric_limits<double>::infinity();
    }
    p[0] = 0;
    
    double min;
    int cur = 0;
    int next;
    for (int i = 1; i < n; ++i) {
        min = numeric_limits<double>::infinity();
        for (int j = 1; j < n; ++j) {
            if (p[j] > 0) {
                double d = distance(point[cur], point[j]);
                if (d < p[j]) {
                    p[j] = d;
                }
                if (p[j] < min) {
                    min = p[j];
                    next = j;
                }
            }
        }
        res += min;
        cur = next;
        p[cur] = 0;
    }

    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        point<double> point[n];
        for (int i = 0; i < n; ++i) {
            cin >> point[i];
        }

        printf("%0.6lf\n", prims(point, n));
    }

    return 0;
}
