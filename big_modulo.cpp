#include <iostream>

using namespace std;

long long modulo(int n, int k, int d) {
  long long r, res;

  res = 1;
  r = n % d;

  // Sơ đồ nhân Ai Cập
  while (k > 0) {
    if (k & 1) {
      res = (res * r) % d;
    }

    r = (r * r) % d;
    k >>= 1;
  }

  return res;
}

int main() {
  // Test
  // 11^59 % 100
  cout << modulo(11, 59, 100) << "\n";
  return 0;
}
