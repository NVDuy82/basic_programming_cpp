#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> a(m+n);
    for (int i = 0; i < m+n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << a[k-1] << endl;
  }
  return 0;
}