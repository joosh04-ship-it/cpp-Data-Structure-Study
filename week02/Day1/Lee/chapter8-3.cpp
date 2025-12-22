// <<가상소멸자와 참조자의 참조가능성>>

#include <iostream>
using namespace std;

class Base {
public:
    void BaseFunc() { cout << "Base Function" << endl; }
    void Cry() { cout << "나는 Base야 ㅠㅠ" << endl; }
    virtual void Happy() { cout << "나는 Base당 ㅋㅋ" << endl; }
    virtual void Attack() = 0; //순수 가상함수(몸체x,자식이 반드시 구현해야 하는 가상함수)
    //부모는 개념만 제공, 이 함수가 하나라도 있으면 추상 클래스!

    ~Base() { cout << "Base가 삭제 당했당께!" << endl; }
    
};

class Base2 {
public:
    void BaseFunc() { cout << "Base Function" << endl; }
    void Cry() { cout << "나는 Base야 ㅠㅠ" << endl; }
    virtual void Happy() { cout << "나는 Base당 ㅋㅋ" << endl; }
    virtual void Attack() = 0; //순수 가상함수(몸체x,자식이 반드시 구현해야 하는 가상함수)
    //부모는 개념만 제공, 이 함수가 하나라도 있으면 추상 클래스!

    
    virtual ~Base2() { cout << "Base2가 삭제 당했당께!" << endl; }
};

class Derived : public Base2 {
public:
    void DerivedFunc() { cout << "Derived Function" << endl; }
    void Cry() { cout << "나는 Derived야 ㅠㅠ" << endl; }
    virtual void Happy() { cout << "나는 Derived당 ㅋㅋ" << endl; }
    void Attack() { cout << "Derived로 공격!!!" << endl; }

    ~Derived() { cout << "Derived가 삭제 당했당께!" << endl; }
};

class Yerived : public Base { //가상함수 설명 용 class
public:
    void Attack() { cout << "Yerived로 공격!!!" << endl; }
    ~Yerived() { cout << "Yerived가 삭제 당했당께!" << endl; }
};

class Plus : public Derived {
public:
    void PlusFunc() { cout << "Plus Function" << endl; }
    void Cry() { cout << "나는 Plus야 ㅠㅠ" << endl; }
    virtual void Happy() { cout << "나는 Plus당 ㅋㅋ" << endl; }
    virtual ~Plus() { cout << "Plus가 삭제 당했당께!" << endl; }
    void Attack() { cout << "Plus로 공격!!!" << endl; }
};

int main() {
    Base* ptr = new Yerived();
    delete ptr; //Base만 삭제당함(메모리의 누수 발생!!)

    Base2* ptr2 = new Plus();
    delete ptr2; //자식 → 부모 순서로 안전하게 소멸
    //부모 클래스를 “다형적으로” 사용할 가능성이 있으면
    //소멸자는 무조건 virtual

    //<참조자의 참조 가능성> - 참조자가 ‘무엇을 가리킬 수 있느냐’의 범위

    Derived d; //Base로 참조자 예시 하고 싶었는데 순수 가상 함수로 인해 불가;;
    Plus p;
    
    Derived& r1 = d;
    Derived & r2 = p;
    r1.Attack();
    r2.Attack();
    cout << "-------------------" << endl;

    return 0;
}
