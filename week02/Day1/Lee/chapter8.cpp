//<<객체 포인터>>


#include <iostream>
using namespace std;
//객체 포인터 변수(IS-A 관계의 성립으로 인해)
//부모형 포인터는 부모 객체만 아니라 자식 객체도 가리킬 수 있다.(자식의 자식도 간접적으로 상속하기에 가능) 
class Person {
public:
    void Sleep() { cout << "잔당" << endl; }
};

class Student : public Person {
public:
    void Study() { cout << "공부한당" << endl; }
    void Sleep() { cout << "공부하다가 잔당" << endl; }
};

class Parttimestudent : public Student {
public:
    void Work() { cout << "일한당" << endl; }
};
///"Student는 Person 객체의 일종이다" "파트타임학생은 학생 객체의 일종이다" -> "파트타임학생은 인간의 일종이다."


int main()
{
    Person * ptr1 = new Student();
    Person* ptr2 = new Parttimestudent();
    Student* ptr3 = new Parttimestudent();

    ptr1->Sleep(); //Person 클래스에 정의된 Sleep이 시행됨 (Student에도 같은 함수가 있으나)\
    //ptr1->Study(); =>컴파일 ERROR! Person형 포인터이기에 (C++은 포인터 연산의 가능성 여부를 포인터의 자료형을 기준으로 판단)
    ptr2->Sleep();
    ptr3->Study();

    return 0;
}


