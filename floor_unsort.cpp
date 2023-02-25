#include <iostream>

using namespace std;

int solve(long long a[], int n, long long x) {
  if(a[n/2] == x) return n/2 + 1;
  
  if (n == 1) {
    if (a[0] <= x) return 1;
    else return 0;
  }

  if(x < a[n/2]) return solve(a, n/2, x);
  else return n/2 + solve(a+n/2+1, n-n/2-1, x) + 1;
}

int floor(long long a[], int n, long long x) {
  int res = solve(a, n, x);
  if (res == 0) return -1;
  else return res;
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
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    
    cout << floor(a, n, x) << endl;
  }
  return 0;
}