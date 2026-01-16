#include <iostream>
using namespace std;

template<typename T>
class Stack {
private:
    T *data;
    int idx = 0;
    int size;
public:
    Stack(int size) : idx(0), size(size <= 0 ? 1 : size) {
        if (size <= 0) {
            cout << "size는 0이하가 될 수 없습니다!(size 1로 교체)" << endl;
        }
        data = new T[this->size];
    }


    Stack(const Stack& other) {
        size = other.size;
        idx = other.idx;

        data = new T[size];
        for (int i = 0; i < idx; i++) {
            data[i] = other.data[i];
        }
    }

    Stack& operator=(const Stack& other) {
        if (this == &other)
            return *this;

        delete[] data;   // 기존 메모리 해제

        size = other.size;
        idx = other.idx;

        data = new T[size];
        for (int i = 0; i < idx; i++) {
            data[i] = other.data[i];
        }

        return *this;
    }

    /*
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;
    */



    bool empty() const {
        if (idx == 0)
            return true;
        else
            return false;
    }

    void DynamicStack() {
        if (idx >= size) {
            size *= 2;
            T* newdata = new T[size];
            for (int i = 0; i < idx; i++) {
                newdata[i] = data[i];
            }

            delete[] data;
            data = newdata;
            

        }
    }

    void Push(T val) {
        DynamicStack();
        data[idx] = val;
        idx++;
        
    }

    T Pop() {
        if (empty()) {
            cout << "스택이 이미 비어있습니다!(Pop불가)" << endl;
            return T();
        }
        return data[--idx];
    }
    
    T Top() const {
        if (empty()) {
            cout << "스택이 이미 비어있습니다!(Top불가)" << endl;
            return T();
        }
        return data[idx-1];
    }
    int checksize() const{
        return idx;
    }

    ~Stack() {
        delete[] data;
    }
    
};

int main()
{
    Stack<int> s(0);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    s.Push(6);
    cout << s.Pop(); 
    cout << endl;
    cout<<s.Top();
}


