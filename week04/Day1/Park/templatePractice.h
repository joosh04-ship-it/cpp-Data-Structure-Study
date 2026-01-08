#ifndef TAMP
#define TAMP

template<typename T>
class Practice {
public:
	T a, b;
	Practice(T a, T b) :a(a), b(b) {}
	T hamsu1();
	T hamsu2() {
		return a + b;
	}
};

#endif