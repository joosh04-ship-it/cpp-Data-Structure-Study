#include <iostream>
#include <cstdlib>

using namespace std;

class point {
	int x, y;
public:
	point(int x, int y) :x(x), y(y){}
	
	/*static*/ void* operator new (size_t size) {					// new 연산자의 오버로딩 (메모리 공간 동적 할당만 오버로딩)
																	// void*형 : 타입 없는 주소
		return ::operator new(size); 								// new,delete 연산자 오버로딩 시 자동으로 static으로 선언되기에
	}																// 객체 생선 전 함수 호출 가능
																	// 전역의 operator new를 가리키기 위해 ::operator new
																	 									
	
	/*static*/ void operator delete (void* adr) {					// new 연산자 오버로딩 시 반드시 delete도 같이 오버로딩
		::operator delete (adr);
	}

	void* operator new[](size_t size) {
		void* adr = malloc(size);									// new[] 연산자 오버로딩 (malloc 활용)
		if (!size) throw bad_alloc();								// c++에서 malloc 실패 시 nullptr을 반환하기에 bad_alloc을 던져야 함 (뭔 소리인지 모르겠음)
		return adr;				
	}
	
	void operator delete[](void* adr) {								// delete[] 연산자 오버로딩 (free 활용)			
		::free(adr);
	}
};