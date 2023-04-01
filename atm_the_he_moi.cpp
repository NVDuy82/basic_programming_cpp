#include <iostream>

using namespace std;

long long int pow(long long int n, long long int k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  
  if (k & 1) return n * pow(n*n, k/2);
  else return pow(n*n, k/2);
}

typedef struct Money {
  string money;
  int len;
  
  friend istream & operator >> (istream & is, struct Money &money) {
    is >> money.money;
    money.len = money.money.size();
    return is;
  }
  
  friend ostream & operator << (ostream & os, struct Money &money) {
    os << "[" << money.money << ", " << money.len << "]";
    return os;
  }
  
  int size() {
    return len;
  }
  
  int head() {
    return money[0] - '0';
  }
  
  void set_head(char head) {
    money[0] = head + '0';
  }
  
  int pop() {
    int head = this->head();
    money = &money[1];
    len--;
    return head;
  }
} money;

class Atm {
  long num;
  long way;
  bool out_of_money;
  
  public:
    Atm(money w, int c) {
      num = 0;
      way = 0;
      out_of_money = true;
      
      way = greedy(w, c + 4);
    }
    
    int greedy(money w, int c) {
      if (w.size() >= c + 2) {
        num += 2 * pow(10, w.size() - c - 1) * w.pop();
        return greedy(w, c);
      } else if (w.size() == c + 1) {
        num += 2 * w.pop();
        if (w.head() == 1 || w.head() == 4) {
          num -= 1;
          w.set_head(w.head() + 5);
        }
        return greedy(w, c);
      } else if (w.size() > 3){
        /* head - num - way
         * h n w
         * 1 1 1
         * 2 1 1
         * 3 1 1
         * 4 2 2
         * 5 1 1
         * 6 2 2
         * 7 2 1
         * 8 2 1
         * 9 3 2
         */
        int num_way[10][2] = {0,1,
                               1,1,
                              1, 1,
                              1,1,
                              2,2,
                              1,1,
                              2,2,
                              2,1,
                              2,1,
                              3,3};
        num += num_way[w.head()][0];
        return num_way[w.pop()][1] * greedy(w, c);
      } else if (w.size()) {
        if (w.pop() == 0) return greedy(w, c);
        else out_of_money = false;
      }
      return 1;
    }
    
    friend ostream & operator << (ostream & os, Atm atm) {
      if (atm.out_of_money) {
        os << atm.num << " " << atm.way;
      } else {
        os << "0";
      }
      return os;
    }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int t;
  cin >> t;
  
  int test = 1;
  
  while (t--) {
    money w;
    int c;
    cin >> w >> c;
    
    Atm atm = Atm(w, c);
    
    cout << atm << endl;
  };
  
  return 0;
}