#include<iostream>
#include<queue>

using namespace std;

class Node {
public:
  short a[10];
  
  Node() {
  }
  
  Node(short a0, short a1, short a2, short a3, short a4, short a5, short a6, short a7, short a8, short a9) {
    a[0] = a0;
    a[1] = a1;
    a[2] = a2;
    a[3] = a3;
    a[4] = a4;
    a[5] = a5;
    a[6] = a6;
    a[7] = a7;
    a[8] = a8;
    a[9] = a9;
  }
  
  friend istream & operator >> (istream & is, Node &node) {
    for (int i = 0; i < 10; ++i) {
      is >> node.a[i];
    }
    return is;
  }
  
  friend ostream & operator << (ostream & os, Node node) {
    os << "[ ";
    for (int i = 0; i < 3; ++i) {
      os << node.a[i] << " ";
    }
    os << endl;
    for (int i = 3; i < 7; ++i) {
      os << node.a[i] << " ";
    }
    os << endl;
    for (int i = 7; i < 10; ++i) {
      os << node.a[i] << " ";
    }
    os << "]";
    
    return os;
  }
  
  void operator = (const Node &v) {
    for (int i = 0; i < 10; ++i) {
      a[i] = v.a[i];
    }
  }
  
  bool operator == (const Node &v) const {
    for (int i = 0; i < 10; ++i) {
      if (a[i] != v.a[i]) {
        return false;
      }
    }
    return true;
  }
  
  bool operator != (const Node &v) const {
    return !(*this == v);
  }
  
  bool isRoot() {
    if (a[0] != 1) return false;
    if (a[1] != 2) return false;
    if (a[2] != 3) return false;
    if (a[3] != 8) return false;
    if (a[4] != 0) return false;
    if (a[5] != 0) return false;
    if (a[6] != 4) return false;
    if (a[7] != 7) return false;
    if (a[8] != 6) return false;
    if (a[9] != 5) return false;
    
    return true;
  }
  
  Node left() {
    return {a[3], a[0], a[2], a[7], a[4], a[1], a[6], a[8], a[5], a[9]};
  }
  
  // trang thai 2 lay tam ben phai de quay
  Node right() {
    return {a[0], a[4], a[1], a[3], a[8], a[5], a[2], a[7], a[9], a[6]};
  }
};

Node solve(Node node) {
  queue<pair<Node, short>> q;
  pair<Node, short> p;
  if (node.isRoot()) {
    cout << "0" << endl;
    return Node();
  }
  q.push(make_pair(node.left(), 1));
  q.push(make_pair(node.right(), 1));
  while (!q.empty()) {
    p = q.front();
    q.pop();
    node = p.first;
    if (node.isRoot()) {
      cout << p.second << endl;
      return q.back().first;
    } else {
      q.push(make_pair(node.left(), p.second + 1));
      q.push(make_pair(node.right(), p.second + 1));
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int t;
  cin >> t;
  while (t--) {
    Node node;
    cin >> node;
    solve(node);
  }
}