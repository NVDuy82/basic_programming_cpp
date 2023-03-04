#include <iostream>

using namespace std;

const long long mod = 1e9+7;
long long f[2][2];
long long a[2][2];
int n;

void mul(long long x[2][2], long long y[2][2]) {
  // | a  y |
  // | c  d |
  int a = x[0][0] * y[0][0] % mod + x[0][1] * y[1][0] % mod;
  int b = x[0][0] * y[0][1] % mod + x[0][1] * y[1][1] % mod;
  int c = x[1][0] * y[0][0] % mod + x[1][1] * y[1][0] % mod;
  int d = x[1][0] * y[0][1] % mod + x[1][1] * y[1][1] % mod;
  
  x[0][0] = a % mod; x[0][1] = b % mod;
  x[1][0] = c % mod; x[1][1] = d % mod;
}

void pow(long long f[2][2], int n) {
  if (n <= 1) return;
  
  pow(f, n/2);
  mul(f, f);
  if(n & 1) mul(f, a);
}

long long day_so_vo_han(int n) {
  if (n == 0) return 0;
  
  pow(f, n-1);
  return f[0][0];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int t;
  cin >> t;
  
  while (t--) {
    cin >> n;
    
    f[0][0] = f[1][0] = f[0][1] = 1;
    f[1][1] = 0;
  
    a[0][0] = a[1][0] = a[0][1] = 1;
    a[1][1] = 0;
    
    cout << day_so_vo_han(n) << endl;
  }
  
  return 0;
}