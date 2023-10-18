//
// Created by Canrad on 2023/10/11.
//
#include <cstring>
#include <cctype>
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

    size_t string::capacity() const
    {
        return m_capacity;
    }

    string& string::operator =(const char* other)
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
        return *this;
    }

    bool string::operator==(const string &other) {
        return compare(other);
    }

    std::ostream &operator<<(std::ostream &out, string &other) {
        std::cout << other.m_str;
        return out;
    }

    string &string::append(const char *str) {
        size_t n = strlen(str);
        if (m_length + n > m_capacity) {
            size_t new_capacity = m_length + n + 1;
            auto new_ptr = new char[new_capacity];
            strcpy(new_ptr, m_str);
            delete[] m_str;
            m_str = new_ptr;
        }
        strcat(m_str, str);
        return *this;
    }

    string &string::append(string &str) {
        append(str.c_str());
        return *this;
    }

    string &string::trim() {
        if (m_length == 0) {
            return *this; // 空字符串，无需操作
        }

        auto start = 0;
        int end = static_cast<int>(m_length) - 1;

        // 从开头找到第一个非空白字符
        while (start < m_length && isspace(m_str[start])) {
            start++;
        }

        // 从结尾找到第一个非空白字符
        while (end >= 0 && isspace(m_str[end])) {
            end--;
        }

        // 更新字符串的长度和内容
        m_length = end - start + 1;
        memmove(m_str, m_str + start, m_length);
        m_str[m_length] = '\0';
        return *this;
    }

    bool string::compare(const string& other) const
    {
        return m_length == other.length() && strcmp(m_str, other.m_str) == 0;
    }

    string& string::to_lower_case()
    {
        for (int i = 0; i < m_length; i++) {
            if (isalpha(static_cast<int>(m_str[i]))) {
                m_str[i] = static_cast<char>(tolower(static_cast<int>(m_str[i])));
            }
        }
    }

    string& string::to_upper_case()
    {
        for (int i = 0; i < m_length; i++) {
            if (isalpha(static_cast<int>(m_str[i]))) {
                m_str[i] = static_cast<char>(toupper(static_cast<int>(m_str[i])));
            }
        }
    }

    string_iterator string::begin() noexcept
    {
        return {m_str};
    }
    
    string_iterator string::end() noexcept
    {
        return {m_str+m_length};
    }


////////////////////////////////////////////////////////////////////////////////
    string_iterator::string_iterator(char* p) : ptr(p) {}
    char& string_iterator::operator*() const {
        return *ptr;
    }

    string_iterator& string_iterator::operator++() {
        ++ptr;
        return *this;
    }

    bool string_iterator::operator!=(const string_iterator& other) const {
        return ptr != other.ptr;
    }
}


