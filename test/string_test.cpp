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
        cout << str2 << str3.byte_length() << endl;
        if(str1 != str2){
            cout << "str2 == str3 is true" << endl;
        }
    }
#endif
    {
        bcat::string str("洛兮1");
        cout << "length:" << str.length() << "  byte_lenth:" << str.byte_length() << endl;

        bcat::string str1{2103450345};
        str1.insert("aaa", 3);
        str1.insert("bbb", 3);
        str1.erase(3, 3);
        str1.erase(3, 3);
        str1[2] = '1';
        cout << "str1[2]:" << str1[2] << endl;
        for (auto i: str1) {
            cout << i << endl;
        }
        bcat::string str2("   str2      ");
        str2.trim();
        cout << str1 << endl;
        cout << str2 << endl;
        str2.to_upper_case();
        cout << str2 << endl;
        str2.to_lower_case();
        cout << str2 << endl;
        cout << "capacity:" << str2.capacity() << endl;
        bcat::string str3("str3");
        str1 = "str1";
        str1 = "str2";
        cout << str2 << str3.byte_length() << endl;
        if (str1 == str2) {
            cout << "str2 = str3 is true" << endl;
        }
        bcat::string s("12");
        str1.append(str2).append(str3).append("str");
        cout << "append:" << str1;
        cout << "ok" << endl;
        printf("%s", str1.c_str());

        bcat::string str12{str1};
        cout << "str12:" << str12 << endl;
        str12 = "123";
        cout << "str12:" << str12 << endl;
    }


    return 0;
}