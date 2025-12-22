// <<가상 함수>>

#include <iostream>
using namespace std;

class Base {
public:
    void BaseFunc() { cout << "Base Function" << endl; }
    void Cry() { cout << "나는 Base야 ㅠㅠ" << endl; }
    virtual void Happy() { cout << "나는 Base당 ㅋㅋ" << endl; }
    virtual void Attack() = 0; //순수 가상함수(몸체x,자식이 반드시 구현해야 하는 가상함수)
    //부모는 개념만 제공, 이 함수가 하나라도 있으면 추상 클래스!
};

class Derived : public Base {
public:
    void DerivedFunc() { cout << "Derived Function" << endl; }
    void Cry() { cout << "나는 Derived야 ㅠㅠ" << endl; }
    virtual void Happy() override { cout << "나는 Derived당 ㅋㅋ" << endl; }
    void Attack() { cout << "Derived로 공격!!!" << endl; }
};

class Yerived : public Base { //가상함수 설명 용 class
public:
    void Attack() { cout << "Yerived로 공격!!!" << endl; }
};

class Plus : public Derived {
public:
    void PlusFunc() { cout << "Plus Function" << endl; }
    void Cry() { cout << "나는 Plus야 ㅠㅠ" << endl; }
    virtual void Happy() { cout << "나는 Plus당 ㅋㅋ" << endl; }
};

int main()
{
    Base* bptr2 = new Derived();
    //Derived * dptr=bptr2; 컴파일 ERROR! <WHY?> bptr2가 가리키니는 대상은 Base 객체일 수도 있다고 판단해서
    Derived* dptr3 = new Derived();
    Base* bptr3 = dptr3; //Derived 포인터 변수이기에 직접 혹은 간접적으로 base 클래스를 상속하겠구나! 라고 판단

    Plus* pptr = new Plus();
    Derived* dptr = pptr;
    Base* bptr = dptr;

    pptr->BaseFunc();
    pptr->DerivedFunc();
    pptr->PlusFunc();

    //<WHY?> 실제 객체가 Plus 라는 건 컴파일러가 고려 안함
    dptr->BaseFunc();
    dptr->DerivedFunc();
    //dptr->PlusFunc(); (x)

    bptr->BaseFunc();
    //bptr->DerivedFunc(); (x)
    //bptr->PlusFunc(); (x)

    //virtual은 아니기에 포인터의 타입(자료형)에 따라 호출될 함수 결정
    pptr->Cry();
    dptr->Cry();
    bptr->Cry();

    //포인터 변수가 실제로 가리키는 객체를 참조하여 호출의 대상 결정
    pptr->Happy();
    dptr->Happy();
    bptr->Happy();

    dptr3->Happy();
    bptr3->Happy();

    Base* wa1 = new Derived();
    Base* wa2 = new Yerived();
    // Base* what = new Base(); // 추상 클래스는 인스턴스화할 수 없음

    wa1->Attack();
    wa2->Attack();
    //다형성 : “같은 부모 타입으로 호출해도, 실제 객체 타입에 따라 서로 다른 동작을 하는 것

}


