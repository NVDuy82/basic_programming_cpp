#include <iostream>

using namespace std;

// move A to B
void move(char a, char b) {
  cout << a << " -> " << b << endl;
}

// move A to C
void thapHaNoi(int n, char a, char b, char c) {
  if (n == 1) {
    move(a, c);
  } else {
    thapHaNoi(n - 1, a, c, b);
    move(a, c);
    thapHaNoi(n - 1, b, a, c);
  }
}

int main() {
  int n;
  cin >> n;
  thapHaNoi(n, 'A', 'B', 'C');
  return 0;
}