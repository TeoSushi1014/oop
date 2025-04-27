#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>
class Point {
private:
    T x;
    T y;

public:
    Point() : x(0), y(0) {}
    
    Point(T x1, T y1) : x(x1), y(y1) {}
    
    T getx() const {
        return x;
    }
    
    T gety() const {
        return y;
    }
    
    void print() const {
        cout << "(" << x << ", " << y << ")";
    }
    
    double distance(const Point<T>& other) const {
        T dx = x - other.x;
        T dy = y - other.y;
        return sqrt(dx*dx + dy*dy);
    }
    
    double kc_o() const {
        Point<T> origin(0, 0);
        return distance(origin);
    }
};

bool ss(const Point<int>& a, const Point<int>& b) {
    return a.kc_o() < b.kc_o();
}

int main() {
    srand(time(0));
    
    vector<Point<int>> points;
    
    for (int i = 0; i < 20; i++) {
        int x = rand() % 100 - 50;
        int y = rand() % 100 - 50;
        points.push_back(Point<int>(x, y));
    }
    
    cout << "Danh sach 20 diem ngau nhien:" << endl;
    for (int i = 0; i < 20; i++) {
        points[i].print();
        cout << " - khoang cach den goc toa do: " << points[i].kc_o() << endl;
    }
    
    sort(points.begin(), points.end(), ss);
    
    cout << "\nDanh sach sau khi sap xep theo khoang cach den goc toa do tang dan:" << endl;
    for (int i = 0; i < 20; i++) {
        points[i].print();
        cout << " - khoang cach den goc toa do: " << points[i].kc_o() << endl;
    }
    
    return 0;
} 