#include <iostream>

using namespace std;

int gapDoiDaySo(int n, long long k) {
  if (k & 1) return 1;
  else return 1 + gapDoiDaySo(n-1, k/2);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long k;
    cin >> n >> k;
    cout << gapDoiDaySo(n, k) << endl;
  }
  
  return 0;
}