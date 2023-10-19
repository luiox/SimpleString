#include <iostream>
#include <string>
#include <utility/string.h>

using std::cout;
using std::endl;

int main() {
    bcat::string str1("12三四");
    bcat::string str2('a');
    bcat::string str3(1234);
    bcat::string str4{1234};
    bcat::string str5{'a'};
    bcat::string str6 = "1234";

    {
        cout << "str1.c_str = " << str1.c_str() << endl;
        cout << "str1.length = " << str1.length() << endl;
        cout << "str1.byte_length = " << str1.byte_length() << endl;
        cout << "str1.capacity = " << str1.capacity() << endl;
        str1.resize(20);
        cout << "after resize, str1.capacity = " << str1.capacity() << endl;
        str1.append("56").append(str2);
        cout << "after append, str1 = " << str1 << endl;
        str1.insert("0", 0);
        cout << "after insert, str1 = " << str1 << endl;
        str1.insert(str2, 0);
        cout << "after insert, str1 = " << str1 << endl;
        str1.erase(0);
        cout << "after erase, str1 = " << str1 << endl;
        str1.erase(0, 2);
        cout << "after erase, str1 = " << str1 << endl;
        str1.replace("2", "1");
        cout << "after replace, str1 = " << str1 << endl;
        cout << "str1.substr(0,4) = " << str1.substr(0, 4) << endl;
        str1.insert("     ", 0);
        str1.append("                 ").append("1");
        cout << "after insert and append, str1 = " << str1 << endl;
        str1[str1.byte_length() - 1] = ' ';
        cout << "after str1[str1.byte_length() - 1]=' ' str1 = " << str1 << endl;
        cout << "after trim, str1 = " << str1.trim() << endl;
        cout << "after to_upper_case, str1 = " << str1.to_upper_case() << endl;
        cout << "after to_lower_case, str1 = " << str1.to_lower_case() << endl;
        str1.clear();
        cout << "after clear, str1 = " << str1 << endl;
    }

#if 0
    {
        bcat::string str("洛兮1");
        // str.insert("1", 0);
        auto it = str.find("洛兮");
        auto sub = str.substr(0, 3);
        cout << it << endl << sub;
        // str.replace("洛兮", "暮秋");
        cout << str << endl;
        cout << "length:" << str.length() << "  byte_lenth:" << str.byte_length() << endl;

        bcat::string str1{ 2103450345 };
        str1.insert("aaa", 3);
        str1.insert("bbb", 3);
        str1.erase(3, 3);
        str1.erase(3, 3);

        str1[2] = '1';
        cout << "str1[2]:" << str1[2] << endl;
        for (auto i : str1) {
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

        bcat::string str12{ str1 };
        cout << "str12:" << str12 << endl;
        str12 = "123";
        cout << "str12:" << str12 << endl;
    }
#endif // 0

    return 0;
}