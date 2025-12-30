#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1 = "I like ";
    string str2 = "string class";
    string str3 = str1 + str2;
    string* str5 = new string();

    cout << str3 << endl;

    str1 += str2;
    if (str1 == str3)
        cout << "동일 문자열!" << endl;
    else
        cout << "동일하지 않은 문자열!" << endl;

    string str4;
    cout << "문자열 입력: ";
    getline(cin, str4);
    cout << "입력한 문자열: " << str4 << endl;
}


