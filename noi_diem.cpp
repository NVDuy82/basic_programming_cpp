#include <iostream>
#include <math.h>
#include <limits>

using namespace std;

template <typename T>
struct node {
private:
    T x, y;

public:
    node() {
        x = y = 0;
    }

    node(T x, T y) : x(x), y(y) {}

    friend istream & operator >> (istream & is, node & node) {
        is >> node.x >> node.y;
        return is;
    }

    T getX() const {
        return x;
    }
    void setX(T x) {
        node::x = x;
    }
    T getY() const {
        return y;
    }
    void setY(T y) {
        node::y = y;
    }

    friend double distance(const node a, const node b) {
        T dx = a.x - b.x;
        T dy = a.y - b.y;
        return sqrt(dx*dx + dy*dy);
    }
};

double prims(node<double> * node, int n) {
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
                double d = distance(node[cur], node[j]);
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
        node<double> node[n];
        for (int i = 0; i < n; ++i) {
            cin >> node[i];
        }

        printf("%0.6lf\n", prims(node, n));
    }

    return 0;
}