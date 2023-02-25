#include <iostream>

using namespace std;

int floor(long long a[], int n, long long x) {
  int res = -1;
  bool working = true;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] > x && working) {
      res = i;
      working = false;
    }
  }

  if (res) return res;
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    long long x;
    cin >> n >> x;
    long long a[n];
    
    cout << floor(a, n, x) << endl;
  }
  return 0;
}