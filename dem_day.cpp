#include <iostream>

using namespace std;

const long long mod = 123456789;
long long modulo(long long n, long long k) {
  if (k == 1) return n % mod;
  long long temp = modulo(n, k >> 1);
  if (!(k & 1)) return (temp * temp % mod);
  return (temp * temp % mod) * n % mod;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long k = 0, m = n;
    while (m) {
      k = 10*k + m%10;
      m /= 10;
    }
    cout << modulo(2, n-1) << endl;
  }
  return 0;
}