#include <iostream>
#include <cmath>

using namespace std;

unsigned long long int f[94];

char daySauFibonacci(int n, unsigned long long int i) {
  while (n > 2) {
    if (i <= f[n-2]) {
      n -= 2;
    } else {
      i -= f[n-2];
      n -= 1;
    }
  }
  
  if (n == 1) return 'A';
  else return 'B';
}

int main() {
  f[1] = 1;
  f[2] = 1;
  for (int i = 3; i < 94; ++i) {
    f[i] = f[i-2] + f[i-1];
  }
    
  int t;
  cin >> t;
  while (t--) {
    int n;
    unsigned long long int i;
    cin >> n >> i;
    cout << daySauFibonacci(n, i) << endl;
  }
  
  return 0;
}
