// <<배열의 인덱스 연산자 오버로딩>>
//  const의 선언유무도 함수 오버로딩 조건에 해당!!!


#include <iostream>
#include <cstdlib> //exit() 함수 사용하기 위해
using namespace std;

class BoundCheckIntArray {
private:
    int* arr; //실제 정수 배열
    int arrlen; //배열길이

    //복사 생성자&대입 연산자를 private에
    //[Why?]객체 복사를 금지하기 위해서
    //      얕은 복사라 전 챕터 코드와 같이 double delete 위험있음
    BoundCheckIntArray(const BoundCheckIntArray& arr) {}
    BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}

public:
    BoundCheckIntArray(int len) : arrlen(len) {
        arr = new int[len]; //len 크기의 int 배열 동적 할당
                            //배열 길이를 반드시 알아야하기에 생성자 필수
    }

    //쓰기 가능한 버전
    //&를 쓰는 이유는 왼쪽에 저장공간이 와야하기에
    int& operator[] (int idx) {
        //잘못된 인덱스면 즉시 프로그램 종료
        if (idx < 0 || idx >= arrlen) {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        
        return arr[idx];
    }

    //읽기 전용 버전 - 왜 따로 만들었을까?
    //[Why?] class 밖에 ShowAllData에서 ref는 const 객체
    //       const 객체는 const 멤버 함수만 호출가능
    //       그래서 const 버전 operator[]가 필요

    //객체가 const냐 ?
    //    ├─ YES → const 멤버 함수만 허용
    //    └─ NO  → const / non - const 둘 다 가능
    //                       → non - const 우선
    
    int& operator[] (int idx) const {
        if (idx < 0 || idx >= arrlen) {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        
        return arr[idx];
    }
    int GetArrLen() const { return arrlen; }
    ~BoundCheckIntArray() { delete[]arr; }
};

void ShowAllData(const BoundCheckIntArray& ref) { 
    int len = ref.GetArrLen();
    //ref[idx] ->const 버전 operator[]호출
    //값만 읽음
    for (int idx = 0; idx < len; idx++) {
        cout << ref[idx] << endl;
    }
}

int main()
{
    BoundCheckIntArray arr(5);
    for (int i = 0; i < 5; i++) {
        arr[i] = (i + 1) * 11; //operator[] 호출
    }
    ShowAllData(arr); //const버전 operator[] 호출
    return 0;
    //BoundCheckIntArray b = arr; 컴파일 에러
    //b = a; 컴파일 에러
}


