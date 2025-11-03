//
// Created by Илья Шамрило on 30.10.25.
//

template<typename T>
size_t MyVector<T>::getCapacity() const {
    return capacity_;
}

template<typename T>
size_t MyVector<T>::getSize() const {
    return size_;
}

template<typename T>
T* MyVector<T>::begin() const {
    return beginPtr_;
}

template<typename T>
T *MyVector<T>::end() const {
    return beginPtr_ + size_;
}

template<typename T>
void MyVector<T>::relocation(size_t newCap) {
    T* newPtr = new T[newCap];

    for (size_t i = 0; i < size_; ++i) {
        newPtr[i] = beginPtr_[i];
    }

    delete[] beginPtr_;
    beginPtr_ = newPtr;
    capacity_ = newCap;
}

template<typename T>
void MyVector<T>::resize(size_t newSize) {
    if (newSize > capacity_) {
        relocation(newSize * 2);
    }

    if (newSize > size_) {
        for (size_t i = size_; i < newSize; ++i) beginPtr_[i] = T{};
    }

    size_ = newSize;
}

template<typename T>
void MyVector<T>::reserve(size_t newCap) {
    if (newCap > capacity_) relocation(newCap);
}

template<typename T>
void MyVector<T>::shrink_to_fit() {
    if (capacity_ > size_) {
        relocation(size_);
    }
}

template<typename T>
bool MyVector<T>::empty() const {
    return size_ == 0;
}

template<typename T>
void MyVector<T>::clear() {
    for (size_t i = 0; i < size_; ++i) {
        beginPtr_[i] = T{};
    }

    size_ = 0;
}

template<typename T>
MyVector<T>::MyVector(): size_(0), capacity_(0), beginPtr_(nullptr) {}

template<typename T>
MyVector<T>::MyVector(size_t size, T defVal): size_(size){

    size_ == 0 ? capacity_ = 1 : capacity_ = size_ * 2;
    beginPtr_ = new T[capacity_];

    for (size_t i = 0; i < size; ++i) {
        beginPtr_[i] = defVal;
    }
}

template<typename T>
MyVector<T>::MyVector(std::initializer_list<T> list)
        : size_(list.size())
        , capacity_(list.size() * 2)
        , beginPtr_(new T[capacity_]){
    std::ranges::copy(list, beginPtr_);
}

template<typename T>
MyVector<T>::MyVector(const MyVector& other)
        :size_(other.size_)
        ,capacity_(other.capacity_)
        ,beginPtr_(new T[other.capacity_]){
    std::copy(other.begin(), other.end(), beginPtr_);
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
    if (this != &other) {
        delete[] beginPtr_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        beginPtr_ = new T[capacity_];
        std::copy(other.begin(), other.end(), beginPtr_);
    }
    return  *this;
}

template<typename T>
T& MyVector<T>::operator[](size_t index) {
    return beginPtr_[index];
}

template<typename T>
const T& MyVector<T>::operator[](size_t index) const {
    return beginPtr_[index];
}

template<typename T>
T& MyVector<T>::at(size_t index) {
    if (index >= size_) throw std::invalid_argument("Out of range");
    return beginPtr_[index];
}

template<typename T>
const T& MyVector<T>::at(size_t index) const {
    if (index >= size_) throw std::invalid_argument("Out of range");
    return beginPtr_[index];
}

template<typename T>
T& MyVector<T>::front() {
    if (empty()) throw std::out_of_range ("Empty vector");
    return beginPtr_[0];
}

template<typename T>
T& MyVector<T>::back() {
    if (empty()) throw std::out_of_range ("Empty vector");
    return beginPtr_[size_ - 1];
}

template<typename T>
T* MyVector<T>::data() {
    return beginPtr_;
}

template<typename T>
const T* MyVector<T>::data() const {
    return beginPtr_;
}

template<typename T>
void MyVector<T>::push_back(const T& newVal) {
    if (size_ == capacity_) relocation(capacity_ == 0 ? 1 : capacity_ * 2);
    beginPtr_[size_++] = newVal;
}

template<typename T>
void MyVector<T>::pop_back() {
    if (size_ > 0) {
        --size_;
        beginPtr_[size_] = T{};
    }
}

template<typename T>
void MyVector<T>::insert(size_t index, T& item) {
    if (index > size_) throw std::invalid_argument("Out of range");

    if (size_ == capacity_) relocation(capacity_ * 2);

    for (size_t i = size_; i > index; --i) {
        beginPtr_[i] = beginPtr_[i - 1];
    }
    beginPtr_[index] = item;
    ++size_;
}

template<typename T>
void MyVector<T>::erase(size_t index) {
    if (index >= size_) throw std::invalid_argument("Out of range");

    for (size_t i = index; i < size_ - 1; ++i) {
        beginPtr_[i] = beginPtr_[i + 1];
    }
    --size_;
}

template<typename T>
void MyVector<T>::assign(size_t count, const T& value) {
    clear();
    if (count > capacity_) relocation( count * 2);

    for (size_t i = 0; i < count; ++i) {
        beginPtr_[i] = value;
    }

    size_ = count;
}

template<typename T>
void MyVector<T>::swap(MyVector<T>& other) {
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(beginPtr_, other.beginPtr_);
}

template<typename T>
bool MyVector<T>::operator==(const MyVector& other) const {
    if (size_ != other.size_) return false;
    for (size_t i = 0; i < size_; ++i) {
        if (beginPtr_[i] != other.beginPtr_[i]) return false;
    }
    return true;
}

template<typename T>
bool MyVector<T>::operator!=(const MyVector& other) const {
    return !(*this == other);
}

template<typename T>
bool MyVector<T>::operator<(const MyVector& other) const {

    for (size_t i = 0; i < size_; ++i) {
        if (beginPtr_[i] < other.beginPtr_[i]) return true;
        if (beginPtr_[i] > other.beginPtr_[i]) return false;
    }

    if (size_ < other.size_) return true;

    return false;
}

template<typename T>
bool MyVector<T>::operator>(const MyVector& other) const {
    return !(*this == other) && other < *this;
}

template<typename T>
bool MyVector<T>::operator<=(const MyVector& other) const {
    return !(*this > other);
}

template<typename T>
bool MyVector<T>::operator>=(const MyVector& other) const {
    return !(*this < other);
}

template<typename T>
MyVector<T>::~MyVector() {
    delete[] beginPtr_;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& vec) {
    os << '[';
    for (size_t i = 0; i < vec.size_; ++i) {
        os << vec.beginPtr_[i];
        if (i != vec.size_ - 1) {
            os << ", ";
        }
    }
    os << ']';
    return os;
}
