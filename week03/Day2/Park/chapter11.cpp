//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//
//using namespace std;
//class shallowStock {
//public:
//	int price;
//	char* name;
//	shallowStock(int price, char* name) : price(price){
//		int len = strlen(name) + 1;
//		this->name = new char[len];
//		strcpy(this -> name, name);
//	}
//	~shallowStock() {
//		cout << "얕은대입소멸~"<<endl;
//		delete[] name;//얕은 복사를 이용하였기에, 같은 메모리 주소를 반환하게 되고, 오류 발생! -> 깊은 복사 이용 시 해결가능
//		//깊은 복사 이용하려면 -> 대입 연산자 오버로딩
//	}
//};
//
//class deepStock {
//public:
//	int price;
//	char* name;
//	deepStock(int price, char* name) : price(price) {
//		int len = strlen(name) + 1;
//		this->name = new char[len];
//		strcpy(this->name, name);
//	}
//	~deepStock() {
//		cout << "깊은대입소멸~" << endl;
//		delete[] name;
//	}
//	deepStock& operator= (deepStock& ref) {//깊은 대입 연산자를 만드는 대입연산자 오버로딩
//		this->price = ref.price;
//		delete[] name;
//		name = new char[strlen(this->name) + 1];
//		strcpy(this->name, ref.name);
//		return *this;
//	}
//};
//int main()
//{
////연산자 오버로딩 2
//	//대입 연산자의 오버로딩 필요성
//	//객체를 대입 하는 경우
//	char str1[] = "엔비디아";
//	//shallowStock nvidia(1,str1);
//	//shallowStock nvda(2,str1);
//	//shallowStock nvd = nvda;//복사연산
//	//nvidia = nvda;//대입연산
//	char str2[] = "구글";
//	deepStock google(1, str2);
//	deepStock goog(2, str2);
//	//deepStock googl = goog;//복사연산 -> 대입연산만 깊은 복사로 바꾼거라 아직 프로그램 터짐
//	google = goog;//대입연산
//}
