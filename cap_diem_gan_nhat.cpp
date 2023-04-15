#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

double min(double a, double b) {
  return (a < b) ? a : b;
}

double min(double a, double b, double c) {
  return min(min(a, b), c);
}

typedef struct Point {
  double x;
  double y;
  
  Point(double x = 0, double y = 0) {
    this->x = x;
    this->y = y;
  }
  
  friend istream & operator >> (istream & is, Point & p) {
    is >> p.x >> p.y;
    return is;
  }
  
  friend ostream & operator << (ostream & os, Point p) {
    os << "(" << p.x << "; " << p.y << ")";
    return os;
  }
  
  void operator = (const Point & p) {
    x = p.x;
    y = p.y;
  }

  Point operator - () const {
    return Point(-this->x, -this->y);
  }
  
  Point operator + (const Point & p) const {
    return Point(this->x + p.x, this->y + p.y);
  }
  
  Point operator - (const Point & p) const {
    return *this + (-p);
  }
  
  double abs() const {
    return sqrt(x*x + y*y);
  }
  
  double to(const Point & p) const {
    return (*this - p).abs();
  }
} point;

bool cmp_x(const Point & a, const Point & b) {
  return a.x < b.x;
}

bool cmp_y(const Point & a, const Point & b) {
  return a.y < b.y;
}

double find(point * p, int l, int r) {
  double res = 1e20;
  
  if (l == r) return res;
  if (l == r - 1) {
    res = p[l].to(p[r]);
    sort(p+l, p+r+1, cmp_y);
    return res;
  }
  
  int m = (l + r) / 2;
  double mid_x = p[m].x;
  res = min(res, find(p, l, m), find(p, m+1, r));
  sort(p+l, p+r+1, cmp_y);

  static point temp[100000];
  int len = 0;
  for (int i = l; i < r+1; ++i) if (abs(p[i].x - mid_x) < res) {
    for (int j = 0; (j < len) && (abs(p[i].y - temp[j].y) < res); ++j) {
      res = min(res, p[i].to(temp[j]));
    }
    temp[len++] = p[i];
  }
  
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    point p[n];
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    sort(p, p+n, cmp_x);
    printf("%.6lf\n", find(p, 0, n-1));
  }
}