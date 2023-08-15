#include <iostream>

using namespace std;

inline string replace(string &s, string &x, string &y) {
    string res;
    string temp; // save old character
    int correct = 0;
    
    for (char c : s) {
        temp += c;
        
        // check if characters are equals
        if (c == x[correct]) {
            ++correct; // equal characters increases
            
            // all characters are equal ?
            if (correct == x.length()) {
                res += y;
                temp.clear();
                correct = 0;
            }
        } else {
            // not the character to replace
            res += temp;
            temp.clear();
            correct = 0;
        }
    }
    res += temp;
    
    return res;
}

int main() {
    string s, x, y;
    
    getline(cin, s);
    getline(cin, x);
    getline(cin, y);
    
    cout << replace(s, x, y) << endl;
    return 0;
}
