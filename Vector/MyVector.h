//
// Created by Илья Шамрило on 30.10.25.
//

#pragma once

#include <iostream>

template <typename T>
class MyVector {
public:
    size_t getCapacity() const;
    size_t getSize() const;

    T* begin() const;
    T* end() const;


    void resize(size_t newSize);
    void reserve(size_t newCap);
    void shrink_to_fit();
    bool empty() const;
    void clear();

    MyVector();
    MyVector(size_t size, T defVal = T{});
    MyVector(std::initializer_list<T> list);
    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& other);

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    T& at(size_t index);
    const T& at(size_t index) const;
    T& front();
    T& back();
    T* data();
    const T* data() const;

    void push_back(const T& newVal);
    void pop_back();
    void insert(size_t index, T& item);
    void erase(size_t index);
    void assign(size_t count, const T& value);
    void swap(MyVector& other);

    bool operator==(const MyVector& other) const;
    bool operator!=(const MyVector& other) const;
    bool operator<(const MyVector& other) const;
    bool operator>(const MyVector& other) const;
    bool operator<=(const MyVector& other) const;
    bool operator>=(const MyVector& other) const;

    ~MyVector();

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const MyVector<U>& vec);
private:
    size_t size_;
    size_t capacity_;
    T* beginPtr_ = nullptr;

    void relocation(size_t newCap);
};

#include "MyVector.tpp"