#include <iostream>
#include <queue>

using namespace std;

long long noiDay(priority_queue<int, vector<int>, greater<int>> pq, int num) {
  long long price = 0;

  while (pq.size() - num + 1) {
    int temp = 0;
    for (int i = 0; i < num; ++i) {
      temp += pq.top();
      pq.pop();      
    }
    price += temp;
    pq.push(temp);
  }

  return price;
}

int main() {
  priority_queue<int, vector<int>, greater<int>> pq;
  
  int t;
  cin >> t;
  
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    
    for (int j = 0; j < n; ++j) {
      int temp;
      cin >> temp;
      pq.push(temp);
    }

    cout << noiDay(pq, 2) << endl;

    while(pq.size()) {
      pq.pop();
    }
  }
  
  return 0;
}