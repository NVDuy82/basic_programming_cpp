#include <iostream>
#include <queue>

using namespace std;
const long long mod = 1e9+7;

unsigned long long int noiDay(priority_queue<long long, vector<long long>, greater<long long>> pq, int num) {
  unsigned long long int price = 0;
  
  while (pq.size() - num + 1) {
    int temp = 0;
    for (int i = 0; i < num; ++i) {
      temp += pq.top();
      pq.pop();
    }
    price += temp;
    pq.push(temp % mod);
  }
  
  return price % mod;
}

int main() {
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  
  int t;
  cin >> t;
  
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    
    for (int j = 0; j < n; ++j) {
      long long temp;
      cin >> temp;
      pq.push(temp % mod);
    }
    
    cout << noiDay(pq, 2) << endl;
    
    while(pq.size()) {
      pq.pop();
    }
  }
  
  return 0;
}