//
// Created by Canrad on 2023/10/11.
//

#ifndef SIMPLE_STRING_STRING_H
#define SIMPLE_STRING_STRING_H

#include <iostream>

//using size_t = unsigned int;

namespace bcat {
    class string {
    private:
        char *m_str;
        size_t m_length;
        size_t m_capacity;
    public:
        string();
        explicit string(const char *str);
        ~string();

        const char* c_str();
        [[nodiscard]] size_t length() const;
        string& append(const char* str);
        string& append(string& str);

        string& trim();

        string& operator =(const char* other);
        bool operator==(const string&other);
        friend std::ostream &operator<<(std::ostream &out,string&other);
    };

}

#endif //SIMPLE_STRING_STRING_H
