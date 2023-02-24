#include <iostream>
#include <string>
using namespace std;

const int N = 20;

void input(int list[], int n, int a[][N]) {
  /*
  // n = length(list)
  // Sort : Alphabet
  // a : 
  */
  int entry[n];
  string temp;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    entry[i] = atoi(temp.c_str());
    int k;
    for (k = i; k > 0; --k) {
      if (temp < to_string(list[k-1])) {
        list[k] = list[k-1];

        for (int row = 0; row < n; ++row) {
          if (row != k-1) {
            a[row][k] = a[row][k-1];
          }
        }
        
        for (int col = 0; col < n; ++col) {
          if (col != k-1) {
            a[k][col] = a[k-1][col];
          }
        }
      } else {
        break;
      }
    }
    list[k] = entry[i];

    for (int row = 0; row < n; ++row) {
      if (list[row] < list[k]) {
        a[row][k] = 1;        
      } else {
        a[row][k] = 0;
      }
    }
    
    for (int col = 0; col < n; ++col) {
      a[k][col] = 0;
    }
  }

  for (int i = 0; i < n; ++i) {
    a[i][i] = 0;
  }
}

void go(int list[], int i, int n, int a[][N], string s) {
  for (int j = 0; j < n; ++j) {
    if (a[i][j]) {
      cout << s << " " + to_string(list[j]) << endl;
      go(list, j, n, a, s + " " + to_string(list[j]));
    }
  }
}

void dayConTangDan(int list[], int n, int a[][N]) {
  for (int i = 0; i < n; ++i) {
    go(list, i, n, a, to_string(list[i]));
  }
}

int main() {
  int n;
  cin >> n;
  int list[n];
  int a[n][N];

  input(list, n, a);

  dayConTangDan(list, n, a);
  
  return 0;
}