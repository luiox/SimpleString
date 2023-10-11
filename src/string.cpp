//
// Created by Canrad on 2023/10/11.
//
#include <cstring>
#include <utility/string.h>

namespace bcat {
    string::string()
            : m_str(nullptr),
              m_length(0),
              m_capacity(0) {

    }

    string::string(const char *str) {
        m_length = strlen(str);
        m_capacity = m_length + 1;
        m_str = new char[m_capacity];
        strcpy(m_str, str);
    }

    string::~string() {
        delete[] m_str;
    }

    const char* string::c_str()
    {
        m_str[m_length] = '\0';
        return m_str;
    }

    size_t string::length() const {
        return m_length;
    }

    void string::operator =(const char* other)
    {
        if (m_str == nullptr) {
            m_length = strlen(other);
            m_capacity = m_length + 1;
            m_str = new char[m_capacity];
        }
        else if(m_capacity-1 < strlen(other)){ // 需要扩容
            // 回收旧内存
            delete[] m_str;
            // 计算需要的新内存大小
            m_length = strlen(other);
            m_capacity = (m_capacity * 2 > m_length + 1) ? m_capacity * 2 : m_length + 1;
            m_str = new char[m_capacity];
  
        }
        strcpy(m_str, other);
    }

    bool string::operator==(const string &other) {
        return m_length == other.length() && strcmp(m_str, other.m_str) == 0;
    }

    std::ostream &operator<<(std::ostream &out, string &other) {
        std::cout << other.m_str;
        return out;
    }




}


