// <<그 이외의 연산자 오버로딩>>

#include <iostream>
using namespace std;

class Point {
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    friend ostream& operator<<(ostream& os, const Point& pos);

    //operator new, delete 멤버함수는 static함수이기에 객체가 완성되자 않았음에도 호출 가능
    //언제 쓰는가?   ①메모리 사용 추적 / 디버깅
    //               ②커스텀 메모리 풀 사용 - 미리 확보한 큰 메모리 덩어리에서 잘라 쓰기
    //                      ㄴex)게임 엔진, 실시간 시스템
    //               ③할당/해제 정책 통일



    void* operator new (size_t size) {
        cout << "operator new: " << size << endl;
        //반환값은 char* 이지만 void*로 받음
        //      └타입 없는 메모리 덩어리라는 의미
        void* adr = malloc(size);
        return adr;
    }
    void* operator new[] (size_t size) {
        cout << "operator new[]: " << size << endl;
        //원래 안에서 new를 쓰면 안 되는 이유: 무한 재귀 가능성 때문
        void* adr = new char[size];
        return adr;
        //return::operator new(size); new 쓰고 싶으면
    }

    void operator delete (void* adr) {
        cout << "operator delete ()" << endl;
        free(adr);
    }
    void operator delete[] (void* adr) {
        cout << "operator delete[] ()" << endl;
        delete[]adr;
    }
};

ostream& operator<<(ostream& os, const Point& pos) {
    os << "[" << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

int main()
{
    Point* ptr = new Point(3, 4);
    Point* arr = new Point[3];
    cout << *ptr;
    
    delete ptr;
    delete[]arr;
    return 0;
}


