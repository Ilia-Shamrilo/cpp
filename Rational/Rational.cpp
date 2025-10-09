//
// Created by Илья Шамрило on 9.10.25.
//
#include "Rational.h"


void Rational::Reduce() {
    if (denom_ == 0) throw std::invalid_argument("Can't dirived by zero");

    if (denom_ < 0) {
        num_ *= -1;
        denom_ *= -1;
    }

    int g = std::gcd(num_, denom_);
    num_ /= g;
    denom_ /= g;
}

int Rational::getNum() const {
    return num_;
}

int Rational::getDenom() const {
    return denom_;
}

Rational::Rational(int num, int denom): num_(num), denom_(denom) {
    Reduce();
}

Rational Rational::operator+() const {
    return *this;
}

Rational Rational::operator-() const {
    return Rational(-num_, denom_);
}

Rational Rational::operator+(const Rational& other) const {
    return Rational(num_ * other.denom_ + other.num_ * denom_, denom_ * other.denom_);
}

Rational Rational::operator-(const Rational& other) const {
    return Rational (num_ * other.denom_ - other.num_ * denom_,denom_ * other.denom_);
}

Rational Rational::operator*(const Rational& other) const {
    return Rational(num_ * other.num_, denom_ * other.denom_);
}

Rational Rational::operator/(const Rational& other) const {
    if (other.num_ == 0) throw std::invalid_argument("Can't dirived by zero");
    return Rational(num_ * other.denom_, denom_ * other.num_);
}

Rational Rational::operator+(int num) const {
    return Rational(num_ + num * denom_, denom_);
}

Rational Rational::operator-(int num) const {
    return Rational(num_ - num * denom_, denom_);
}

Rational Rational::operator*(int num) const {
    return Rational(num_ * num, denom_);
}

Rational Rational::operator/(int num) const {
    if (num == 0) throw std::invalid_argument("Can't dirived by zero");
    return  Rational(num_, denom_ * num);
}

bool Rational::operator==(const Rational& other) const {
    if (num_ * other.denom_ == other.num_ * denom_) return true;
    return false;
}

bool Rational::operator!=(const Rational& other) const {
    return !(*this == other);
}

bool Rational::operator>(const Rational& other) const {
    return (num_ * other.denom_ > other.num_ * denom_);
}

bool Rational::operator<(const Rational& other) const {
    return (num_ * other.denom_ < other.num_ * denom_);
}

bool Rational::operator>=(const Rational& other) const {
    return !(*this < other);
}

bool Rational::operator<=(const Rational& other) const {
    return !(*this > other);
}

Rational& Rational::operator+=(const Rational& other) {
    num_ = num_ * other.denom_ + other.num_ * denom_;
    denom_ *= other.denom_;
    Reduce();
    return *this;
}

Rational& Rational::operator-=(const Rational& other) {
    num_ = num_ * other.denom_ - other.num_ * denom_;
    denom_ *= other.denom_;
    Reduce();
    return *this;
}

Rational& Rational::operator*=(const Rational& other) {
    num_ = num_ * other.num_;
    denom_ *= other.denom_;
    Reduce();
    return *this;
}

Rational& Rational::operator/=(const Rational& other) {
    num_ = num_ * other.denom_;
    denom_ *= other.num_;
    Reduce();
    return *this;
}

Rational& Rational::operator+=(int num) {
    num_ += num * denom_;
    Reduce();
    return *this;
}

Rational& Rational::operator-=(int num) {
    num_ -= num * denom_;
    Reduce();
    return *this;
}

Rational& Rational::operator*=(int num) {
    num_ *= num;
    Reduce();
    return *this;
}

Rational& Rational::operator/=(int num) {
    denom_ *= num;
    Reduce();
    return *this;
}