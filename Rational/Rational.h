//
// Created by Илья Шамрило on 9.10.25.
//

#pragma once
#include <numeric>
#include <iostream>

class Rational {
public:
    void Reduce();

    int getNum() const;
    int getDenom() const;


    Rational(int num = 0, int denom = 1);

    Rational operator+ () const;
    Rational operator- () const;

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;
    Rational operator+(int num) const;
    Rational operator-(int num) const;
    Rational operator*(int num) const;
    Rational operator/(int num) const;

    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator<(const Rational& other) const;
    bool operator>=(const Rational& other) const;
    bool operator<=(const Rational& other) const;

    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);
    Rational& operator+=(int num);
    Rational& operator-=(int num);
    Rational& operator*=(int num);
    Rational& operator/=(int num);

private:
    int num_;
    int denom_;
};