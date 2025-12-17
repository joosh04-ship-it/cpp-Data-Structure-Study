#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class shallowStock {
private:
	string Ticker;
	int* price;
public:
	shallowStock(string T, int* p){
		Ticker = T;
		price = new int[5];
		copy(p, p + 5, price);
	}//일반 생성자
	~shallowStock() {
		//delete[] price;//이러면 2중으로 같은 포인터를 delete 하게 되어서 프로그램이 터져버림
	}
	int* getPrice() {
		return price;
	}
	void setPrice(int idx, int p) {
		this->price[idx] = p;
	}
};
class DeepStock {
private:
	string Ticker;
	int* price;
public:
	DeepStock(string T, int* p) {//일반 생성자
		Ticker = T;
		price = new int[5];
		copy(p, p + 5, price);
	}
	//복사생성자
	DeepStock(const DeepStock& stock) {//컨스트 레퍼런스 사용 이유 : 원본의 값을 가져와야하지만, 직접 들고오면 CLASS이기때문에 용량이 커서 주소만 가져오되
										//원본 값의 변경을 허용하지 않기 위함
		Ticker = stock.Ticker;
		price = new int[5];
		copy(stock.price, stock.price + 5, price);
	}
	~DeepStock() {
		delete[] price;
	}
	int* getPrice() {
		return price;
	}
	void setPrice(int idx, int p) {
		this->price[idx] = p;
	}
};
int main(){
//복사생성자
	//이미 존재하는 객체로 새 객체를 만들고자할 때 사용
	//기본 복사 생성자 사용 시  얕은 복사 수행
	//얕은 복사는 레퍼런스나 포인터 복사 시 의도치 않은 문제 발생 시킬 수 있음
	int tslaPrices[5] = { 1,2,3,4,5 };
	shallowStock A("TSLA", tslaPrices);//일반생성자 호출
	shallowStock B = A;//기본 복사생성자 호출
	B.setPrice(2, 100000);
	cout << A.getPrice()[2] << endl;//B의 정보를 바꾸었는데 A도 바뀌어버림
	//깊은 복사
	int nvdaPrices[5] = { 6,7,8,9,10 };
	DeepStock C("NVDA", nvdaPrices);//일반생성자 호출
	DeepStock D = C;//복사생성자 호출
	D.setPrice(1, 0);
	cout << C.getPrice()[1] << endl;//D의 정보를 바꾸었지만 C는 바뀌지 않음
}