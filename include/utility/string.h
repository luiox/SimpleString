//
// Created by Canrad on 2023/10/11.
//

#ifndef SIMPLE_STRING_STRING_H
#define SIMPLE_STRING_STRING_H

#include <iostream>

//using size_t = unsigned int;

namespace bcat {
    class string_iterator;

    class string {
    private:
        char *m_str;
        size_t m_length;
        size_t m_capacity;

        // 扩容函数
        void expand(size_t new_capacity);

        // 拷贝函数
        void copy(const char *other);

    public:
        string();

        explicit string(char val);

        explicit string(int val);

        explicit string(const char *str);

        explicit string(const string &str);

        ~string();

        // 获取C风格的字符串指针
        const char *c_str();

        // 获取字符串长度
        [[nodiscard]] size_t length() const;

        // 获取容量
        [[nodiscard]] size_t capacity() const;

        // 拼接字符串
        string &append(const char *str);

        string &append(string &str);

        string &trim();

        [[nodiscard]] bool compare(const string &other) const;

        string &to_lower_case();

        string &to_upper_case();

        string_iterator begin() noexcept;

        string_iterator end() noexcept;

        string &operator=(const char *other);

        string &operator=(const string &other);

        bool operator==(const string &other);

        char &operator[](int index);

        friend std::ostream &operator<<(std::ostream &out, string &other);
    };

////////////////////////////////////////////////////////////////////////////////
    class string_iterator {
    private:
        char *ptr;

    public:
        string_iterator(char *p);

        char &operator*() const;

        string_iterator &operator++();

        bool operator!=(const string_iterator &other) const;
    };
}


#endif //SIMPLE_STRING_STRING_H
