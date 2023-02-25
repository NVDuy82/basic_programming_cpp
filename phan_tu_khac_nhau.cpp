#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long a[n];
    long long b[n-1];
    int res = -1;
    
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    for (int i = 0; i < n-1; ++i) {
      cin >> b[i];
      if (res == -1 && b[i] != a[i]) {
        res = i + 1;
      }
    }
    cout << res << endl;
  }
  return 0;
}