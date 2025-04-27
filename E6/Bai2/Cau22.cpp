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
    
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    
    return 0;
} 