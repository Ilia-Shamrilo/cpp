//
// Created by Илья Шамрило on 2.10.25.
//

#pragma once
#include <iostream>

class MyString {
public:
    static constexpr size_t npos = -1;

    MyString();
    MyString(size_t count, char charakter);
    MyString(std::initializer_list<char> list);
    explicit MyString(char charakter);
    MyString(const MyString& other);

    MyString& operator=(const MyString& other);
    MyString& operator+=(const MyString& other);
    MyString& operator+=(char charakter);
    MyString operator+(const MyString& other) const;
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>=(const MyString& other) const;

    char& operator[](size_t n);
    const char& operator[](size_t n) const;

    char& front();
    [[nodiscard]] const char& front() const;
    char& back();
    [[nodiscard]] const char& back() const;
    char& at(size_t n);
    [[nodiscard]] const char& at(size_t n) const;
    char* begin();
    [[nodiscard]] const char* begin() const;
    char* end();
    [[nodiscard]] const char* end() const;

    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t length() const;
    void reserve(size_t newCapacity);
    size_t checkCapacity() const;
    void shrink_to_fit();
    void clear();
    void make_space_for_insert(size_t index, size_t count);
    void insert(size_t index, char character);
    void insert(size_t index, size_t count, char character);
    void insert(size_t index, const MyString& str);
    void erase(size_t index, size_t count);
    void erase(size_t index);
    void push_back(char character);
    void pop_back();
    void append(size_t count, char character);
    void append(const MyString& addStr);
    void replace(size_t index, size_t count, const MyString& other);
    void replace(size_t index, size_t count, size_t countChar, char charakter);
    void replace(const MyString& other);
    size_t copy(char* dest, size_t count, size_t index) const;
    void resize(size_t newSize);
    void resize(size_t newSize, char character);
    void swap(MyString& other) noexcept;
    size_t find(char findCharakter, size_t index) const;
    size_t find(char findCharacter) const;
    size_t find(const MyString& substr) const;
    size_t rfind(char findCharakter) const;
    size_t rfind(const MyString& substr) const;
    size_t find_first_of(const MyString& chars) const;
    size_t find_first_not_of(const MyString& chars) const;
    size_t find_last_of(const MyString& chars) const;
    size_t find_last_not_of(const MyString& chars) const;

    int compare(const MyString& other) const;
    MyString substr(size_t start, size_t end = npos);


    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);
    ~MyString();
private:
    char* ptrBegin = nullptr;
    size_t size = 0;
    size_t capacity = 0;
};