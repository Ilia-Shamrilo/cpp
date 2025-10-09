//
// Created by Илья Шамрило on 2.10.25.
//

#include "String.h"
#include <iostream>

MyString::MyString(): ptrBegin(nullptr), size(0), capacity(0){}

MyString::MyString(size_t count, char charakter)
        : ptrBegin(new char[count + 1])
        , size(count)
        , capacity(count + 1) {
    memset(ptrBegin, charakter, size);
    ptrBegin[size] = '\0';
}

MyString::MyString(std::initializer_list<char> list): ptrBegin(new char[list.size() + 1]), size(list.size()), capacity(size + 1) {
    std::copy(list.begin(), list.end(), ptrBegin);
    ptrBegin[size] = '\0';
}

MyString::MyString(char charakter): ptrBegin(new char[2]), size(1), capacity(2) {
    ptrBegin[0] = charakter;
    ptrBegin[1] = '\0';
}

MyString::MyString(const MyString& other): ptrBegin(new char[other.size + 1]), size(other.size), capacity(other.capacity) {
    memcpy(ptrBegin, other.ptrBegin, size);
    ptrBegin[size] = '\0';
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        char* newArr = new char[other.capacity];
        std::copy(other.ptrBegin, other.ptrBegin + other.capacity, newArr);

        delete[] ptrBegin;
        ptrBegin = newArr;
        size = other.size;
        capacity = other.capacity;
    }
    return *this;
}

MyString &MyString::operator+=(char charakter) {
    push_back(charakter);
    return *this;
}

MyString& MyString::operator+=(const MyString& other) {
    if (size + other.size >= capacity) {
        reserve(size + other.size + 1);
    }
    memmove(ptrBegin + size, other.ptrBegin, other.size + 1);
    size += other.size;
    return *this;
}

MyString MyString::operator+(const MyString& other) const {
    MyString str;

    size_t allSize = size + other.size;

    str.ptrBegin = new char[allSize + 1];
    str.size = allSize;
    str.capacity = allSize + 1;

    size_t j = 0;
    for (size_t i = 0; i < size; ++i, ++j) {
        str.ptrBegin[j] = ptrBegin[i];
    }

    for (size_t i = 0; i < other.size; ++i, ++j) {
        str.ptrBegin[j] = other.ptrBegin[i];
    }
    str.ptrBegin[allSize] = '\0';

    return str;
}

bool MyString::operator==(const MyString& other) const {
    if (size != other.size) return false;
    for (size_t i = 0; i < size; ++i) {
        if (ptrBegin[i] != other.ptrBegin[i]) return false;
    }
    return true;
}

bool MyString::operator!=(const MyString& other) const {
    return !(*this == other);
}

bool MyString::operator<(const MyString& other) const {
    size_t minSize = std::min(size, other.size);
    for (size_t i = 0; i < minSize; ++i) {
        if (ptrBegin[i] < other.ptrBegin[i]) return true;
        if (ptrBegin[i] > other.ptrBegin[i]) return false;
    }
    return (size < other.size);
}

bool MyString::operator>(const MyString& other) const {
    return !(*this < other) && (*this != other);
}

bool MyString::operator<=(const MyString& other) const {
    return !(*this > other);
}

bool MyString::operator>=(const MyString &other) const {
    return !(*this < other);
}

char& MyString::operator[](size_t n) {
    return ptrBegin[n];
}

const char& MyString::operator[](size_t n) const {
    return ptrBegin[n];
}

char& MyString::front() {
    return ptrBegin[0];
}

const char& MyString::front() const {
    return ptrBegin[0];
}

char& MyString::back() {
    return ptrBegin[size - 1];
}

const char& MyString::back() const {
    return ptrBegin[size - 1];
}

char* MyString::begin() {
    return ptrBegin;
}

const char* MyString::begin() const {
    return ptrBegin;
}

char* MyString::end() {
    return ptrBegin + size;
}

const char* MyString::end() const {
    return ptrBegin + size;
}

char& MyString::at(size_t n) {
    if (n >= size) throw std::out_of_range("Out of range");
    return ptrBegin[n];
}

const char& MyString::at(size_t n) const {
    if (n >= size) throw std::out_of_range("Out of range");
    return ptrBegin[n];
}

bool MyString::empty() const {
    return size == 0;
}

size_t MyString::length() const {
    return size;
}

void MyString::reserve(size_t newCapacity) {
    if (newCapacity > capacity) {
        char* newPtr = new char[newCapacity];
        memcpy(newPtr, ptrBegin, size + 1);

        delete[] ptrBegin;
        ptrBegin = newPtr;
        capacity = newCapacity;
    }
}

size_t MyString::checkCapacity() const {
    return capacity;
}

void MyString::shrink_to_fit() {
    if (capacity > size + 1) {
        char* newPtr = new char[size + 1];
        memcpy(newPtr, ptrBegin, size + 1);

        delete[] ptrBegin;
        ptrBegin = newPtr;
        capacity = size + 1;
    }
}

void MyString::clear() {
    if (!this->empty()) {
        delete[] ptrBegin;
        ptrBegin = new char[1];
        ptrBegin[0] = '\0';
        size = 0;
        capacity = 1;
    }
}

void MyString::make_space_for_insert(size_t index, size_t count) {
    if (index > size) {
        throw std::out_of_range("Out of range");
    }
    if (size + count >= capacity) {
        reserve(size + count + 1);
    }
    memmove(ptrBegin + index + count, ptrBegin + index, size - index + 1);
    size += count;
}

void MyString::insert(size_t index, char character) {
    make_space_for_insert(index, 1);
    ptrBegin[index] = character;
}

void MyString::insert(size_t index, size_t count, char charakter) {
    make_space_for_insert(index, count);
    memset(ptrBegin + index, charakter, count);
}

void MyString::insert(size_t index, const MyString& str) {
    make_space_for_insert(index, str.size);
    memmove(ptrBegin + index, str.ptrBegin, str.size);
}

void MyString::erase(size_t index, size_t count) {
    if (index + count > size) {
        throw std::out_of_range("Out of range");
    }
    memmove(ptrBegin + index, ptrBegin + index + count, size - index - count + 1);
    size -= count;
}

void MyString::erase(size_t index) {
    erase(index, size - index);
}

void MyString::push_back(char character) {
    insert(size, character);
}

void MyString::pop_back() {
    if (!this->empty()) {
        erase(size - 1, 1);
    }
}

void MyString::append(size_t count, char character) {
    insert(size, count, character);
}

void MyString::append(const MyString& addStr) {
    insert(size,addStr);
}

void MyString::replace(size_t index, size_t count, const MyString& other) {
    erase(index, count);
    insert(index, other);
}

void MyString::replace(size_t index, size_t count, size_t countChar, char charakter) {
    erase(index, count);
    insert(index, countChar, charakter);
}

void MyString::replace(const MyString& other) {
    erase(0);
    insert(0, other);
}

size_t MyString::copy(char* dest, size_t count, size_t index) const {
    if (index > size) {
        throw std::out_of_range("Out of range");
    }
    size_t rcount = std::min(count, size - index);
    for (size_t i = 0; i < rcount; ++i, ++index) {
        dest[i] = ptrBegin[index];
    }
    return rcount;
}

void MyString::resize(size_t newSize, char character) {
    if (newSize > size) {
        if (newSize >= capacity) {
            reserve(newSize + 1);
        }
        insert(size, newSize - size, character);
    } else if (newSize < size) {
        erase(newSize);
    }
}

void MyString::resize(size_t newSize) {
    resize(newSize, '\0');
}

void MyString::swap(MyString& other) noexcept {
    std::swap(ptrBegin, other.ptrBegin);
    std::swap(size, other.size);
    std::swap(capacity, other.capacity);
}

size_t MyString::find(char findCharacter, size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Out of range");
    }
    for (; index < size; ++index) {
        if (ptrBegin[index] == findCharacter) return index;
    }
    return npos;
}

size_t MyString::find(char findCharakter) const {
    return find(findCharakter, 0);
}

size_t MyString::find(const MyString& substr) const{
    if (substr.size == 0) return 0;
    if (substr.size > size) return npos;
    for (size_t i = 0; i <= size - substr.size; ++i) {
        size_t j = 0;
        for (; j < substr.size; ++j) {
            if (ptrBegin[i + j] != substr.ptrBegin[j])
                break;
        }
        if (j == substr.size) return i;
    }
    return npos;
}

size_t MyString::rfind(char findCharakter) const {
    for (int i = size - 1; i >= 0; --i) {
        if (ptrBegin[i] == findCharakter) return i;
    }
    return npos;
}

size_t MyString::rfind(const MyString& substr) const{
    if (substr.size == 0) return size - 1;
    if (substr.size > size) return npos;
    for (int i = size - substr.size; i >= 0; --i) {
        int j = 0;
        for (;j < static_cast<int>(substr.size); ++j) {
            if (ptrBegin[i + j] != substr.ptrBegin[j]) break;
        }
        if (j == static_cast<int>(substr.size)) return i;
    }
    return npos;
}

size_t MyString::find_first_of(const MyString& chars) const {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < chars.size; ++j) {
            if (ptrBegin[i] == chars.ptrBegin[j]) return i;
        }
    }
    return npos;
}

size_t MyString::find_first_not_of(const MyString& chars) const {
    for (size_t i = 0; i < size; ++i) {
        size_t j = 0;
        for (; j < chars.size; ++j) {
            if (ptrBegin[i] == chars.ptrBegin[j]) break;
        }
        if (j == chars.size) return i;
    }
    return npos;
}

size_t MyString::find_last_of(const MyString& chars) const {
    for (int i = static_cast<int>(size) - 1; i >= 0; --i) {
        for (size_t j = 0; j < chars.size; ++j) {
            if (ptrBegin[i] == chars.ptrBegin[j]) return  i;
        }
    }
    return npos;
}

size_t MyString::find_last_not_of(const MyString& chars) const {
    if (chars.size == 0) return size - 1;
    for (int i = size - 1; i >= 0; --i) {
        size_t j = 0;
        for (; j < chars.size; ++j) {
            if (ptrBegin[i] == chars.ptrBegin[j]) break;
        }
        if (j == chars.size) return  i;
    }
    return npos;
}

int MyString::compare(const MyString& other) const {
    int minSize = std::min(size, other.size);
    for (int i = 0; i < minSize; ++i) {
        if (ptrBegin[i] > other.ptrBegin[i]) return 1;
        if (ptrBegin[i] < other.ptrBegin[i]) return -1;
    }
    if (size == other.size) return 0;
    if (size > other.size) return 1;
    return -1;
}

MyString MyString::substr(size_t start, size_t end) {
    /*
    if (end == npos) end = size - 1;
    MyString temp;

    temp.ptrBegin = new char[end - start + 2];
    temp.size = end - start + 1;
    temp.capacity = end - start + 2;

    memcpy(temp.ptrBegin, ptrBegin + start, end - start + 1);
    temp.ptrBegin[end - start + 1] = '\0';

    return temp;
    */

    if (start > end) throw std::invalid_argument("Start is greater end.");

    MyString str;

    const size_t n = end == npos ? size - 1 : end;
    const size_t delta = n - start;

    str.ptrBegin = new char[delta + 2];
    str.size = delta + 1;
    str.capacity = delta + 2;

    size_t i = 0;
    for (size_t j = start; j <= n; ++j, ++i) {
        str[i] = ptrBegin[j];
    }
    str[i] = '\0';

    return str;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    return os << str.ptrBegin;
}

std::istream& operator>>(std::istream& is, MyString& str) {
    // Временно буфер для чтения
    char buffer[1024];

    // Читаем слово (до пробела)
    is >> buffer;

    if (!is) return is;

    // Очистка предыдущих данных
    delete[] str.ptrBegin;

    // Вычисляем длину
    size_t len = std::strlen(buffer);

    // Выделяем память под новую строку (+1 для '\0')
    str.ptrBegin = new char[len + 1];

    // Копируем
    std::memcpy(str.ptrBegin, buffer, len + 1);

    // Обновляем размер и вместимость
    str.size = len;
    str.capacity = len + 1;

    return is;
}

MyString::~MyString() {
    delete[] ptrBegin;
}

