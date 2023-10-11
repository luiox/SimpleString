#include <iostream>
#include <string>
#include <utility/string.h>
using std::cout;
using std::endl;

int main() {
#if 0
    {
        std::string str1;
        std::string str2("str2");
        std::string str3 = "str3";
        str1 = "str1";
        cout << str2 << str3.length() << endl;
        if(str1 != str2){
            cout << "str2 == str3 is true" << endl;
        }
    }
#endif
    {
        bcat::string str1;
        bcat::string str2("str2");
        bcat::string str3="str3";
        str1 = "str1";
        cout << str2 << str3.length() << endl;
        if(!(str1 == str2)){
            cout << "str2 = str3 is true" << endl;
        }
        cout<< "ok"<<endl;
    }


    return 0;
}