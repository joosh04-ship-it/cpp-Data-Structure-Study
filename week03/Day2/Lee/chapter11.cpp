// chapter11 <<대입 연산자의 오버로딩>>

// <디폴트 대입 연산자의 문제점> 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
using namespace std;

class Person {
private:
    char* name;
    int age;
public:
    Person(const char* myname, int myage) {
        size_t len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }

    void ShowPersonInfo() const {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }

    ~Person() {
        delete[]name;
        cout << "class Person called destructor!" << endl;
    }
    //대입 연산자덕에 객체 2개 완전 소멸!
    
    Person& operator=(const Person& ref) {
        delete[]name; //기존 자원 해제
        size_t len = strlen(ref.name) + 1;
        name = new char[len];
        strcpy(name, ref.name); //깊은 복사
        age = ref.age;
        return *this;
    }

    
};

//자식 클래스에 삽입된 디폴트 대입 연산자가 부모 클래스의 대입 연산자까지 호출함
class First {
private:
    int num1, num2;
public:
    First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2) {}
    void ShowData() { cout << num1 << "," << num2 << endl; }

    First& operator=(const First& ref) {
        cout << "First& operator=" << endl;
        num1 = ref.num1;
        num2 = ref.num2;
        return *this;
    }
};

class Second : public First {
private:
    int num3, num4;
public:
    Second(int n1, int n2, int n3, int n4) : First(n1, n2), num3(n3), num4(n4) {}
    void ShowData() {
        First::ShowData();
        cout << num3 << "," << num4 << endl;
    }
    Second& operator=(const Second& ref) {
        cout << "Second& operator=()" << endl;
        First::operator=(ref); //부모 클래스의 대입 연산자 호출을 명령!
                               //없으면 부모 클래스의 멤버변수가 초기화만 됨
                               //ex) (0,0,333,444)
        num3 = ref.num3;
        num4 = ref.num4;
        return *this;
    }
};
int main()
{
    Person man1("Lee Jinseo", 23);
    Person man2("Joo 승현", 24);
    //대입 연산자가 없어도 디폴트가 있기에 멤버 대 멤버의 복사가 진행된다!
    man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    
    //"called destructor!"이 한번만 뜨게 됨!       [Why?] 하나의 문자열에 두 개의 객체가 동시 참조
                                                        //문자열 "Lee.."를 가리키던 문자열의 주소 값 잃음
                                                        //얕은 복사로 인해 객체 소멸과정에서 지워진 문자열 중복 소멸
                                                        //소멸도 불가능해저 메모리의 누수로 이어짐
                                                        //누수: "Joo 승현"
    //목적: ①깊은 복사 진행하도록 정의 ②누수 발생 않도록 복사 앞서 메모리 해제 과정 거치기
    cout << "-----------------" << endl;
    Second ssrc(111, 222, 333, 444);
    Second scpy(0, 0, 0, 0);
    scpy = ssrc;
    scpy.ShowData();
    return 0;
}


