#include <iostream>

using namespace std;

class Animal {                          // 부모 클래스
    string name;
    int age;
public:
    Animal() : name(""),age(0) {                                                  // 부모 클래스의 기본 생성자
        cout << "I dont have animal"<<endl;                   
    }
    Animal(string aniname, int age) :name(aniname),age(age) {}
    void speak() {
        cout << "동물이 소리를 낸다" << endl;
    }
    ~Animal() {
        cout << "ByeBye animal" << endl;
    }
};

class Dog : public Animal {             // 자식 클래스 (Animal을 상속)
    string breed;
public:
    Dog() { cout << "I dont have dog" << endl;};                           //부모 클래스의 기본 생성자 호출-> 자식클래스의 기본 생성자 호출

    Dog(string dogname, int dogage, string dogbreed) : Animal(dogname, dogage),breed(dogbreed) {}   // 생성자로 상속받은 멤버까지 초기화
    void bark() {                                                                                   // 부모클래스의 생성자를 호출해서 초기화
        cout << "개가 짖는다" << endl;                                                              // 부모클래스의 private에는 직접적으로 접근 불가능
    }                                                                                               
    Dog(string dogbreed) :breed(dogbreed) {
        cout << breed;
    }                   // 부모클래스 기본 생성자 호출 -> 자식클래스 생성자 호출

    ~Dog() {
        cout << "ByeBye Dog" << endl;                       // 소멸 순서는 생성 순서의 역순( 자식 클래스 -> 부모 클래스 순으로 소멸)
    }
};

int main() {
    Dog dog("choco");
    
    
    dog.speak(); // 부모 클래스의 함수
    dog.bark();  // 자식 클래스의 함수

    return 0;
}
