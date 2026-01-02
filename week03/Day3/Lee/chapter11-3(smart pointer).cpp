#include <iostream>
using namespace std;

class Point {
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {
        
    }
    ~Point() {
        cout << "Point 객체 소멸!" << endl;
    }
    Point operator+(const Point& pos) const {
        return Point(xpos + pos.xpos, ypos + pos.ypos);
    }
    void SetPos(int x, int y) {
        xpos = x;
        ypos = y;
    }
    friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos) {
    os << "[" << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

//  <스마트 포인터> = "힙에 생성된 객체의 주소를 보관 + 소멸 시 delete 수행"
class SmartPtr {
private:
    //외부에서 생성된 Point 객체를 가리키기 위해 Point*
    
    Point* posptr;
public:

    //*sptr을 가능하게 함
    //둘 다 const가 붙는 이유 -> SmartPtr자체를 변경하진 않겠다!. but, 가리키는 객체는 바뀔 수 있음
    SmartPtr(Point* ptr) : posptr(ptr) {}
    Point& operator*() const {
        return *posptr;
    }
    Point* operator->() const {
        return posptr;
    }
    ~SmartPtr() {
        delete posptr;
    }
};

//()연산자의 오버로딩
class Adder {
public:
    int operator() (const int& n1, const int& n2) {
        return n1 + n2;
    }
    double operator() (const double& e1, const double& e2) {
        return e1 + e2;
    }
    Point operator() (const Point& pos1, const Point& pos2) {
        return pos1 + pos2;
    }
};

int main()
{
    SmartPtr sptr1(new Point(1, 2));
    SmartPtr sptr2(new Point(2, 3));
    Point* sptr4 = new Point(3, 3);
    cout << *sptr1;
    //cout << sptr1.operator*(); -> *posptr
    cout << *sptr2; 

    sptr1->SetPos(10, 20);
    //sptr1.operator->()->SetPos(10, 20);
    //(posptr)->SetPos(10, 20);
    sptr2->SetPos(30, 40);
    cout << *sptr1;
    cout << *sptr2;
    //스마트 포인터는 자동으로 객체 소멸!
    //but sptr4포인터는 소멸안되어서 메모리 누수 발생!
    
    cout << "------------------" << endl;
    Adder adder;
    cout << adder(1, 3) << endl;
    cout << adder(12.23, 123.23) << endl;
    cout << adder(Point(3, 4), Point(7, 9)) << endl;
    Point result = adder(Point(3, 2), Point(40, 60));
    cout << result << endl;
    return 0;
}


