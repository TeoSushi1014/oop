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
    
    map<int, vector<int>> m;
    for (int i = 0; i < v.size(); i++) {
        m[v[i]].push_back(i);
    }
    
    for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << " ";
        for (int i = 0; i < it->second.size(); i++) {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
} 