#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    vector<int> v;
    int x;
    
    while (true) {
        cin >> x;
        if (x < 0) {
            break;
        }
        v.push_back(x);
    }
    
    map<int, int> m;
    for (int i = 0; i < v.size(); i++) {
        m[v[i]]++;
    }
    
    cout << m.size() << endl;
    
    return 0;
} 