#pragma once

#include <iostream>

template <typename T>
class Matrix {
public:
    Matrix();
    Matrix(const T &_a, const T &_b, const T &_c, const T &_d);
    ~Matrix() = default;

    // O P E R A T O R  O V E R L O A D
    Matrix<T> operator+(const Matrix<T> &right) const;
    Matrix<T> &operator+=(const Matrix<T> &right);
    Matrix<T> operator-(const Matrix<T> &right) const;
    Matrix<T> &operator-=(const Matrix<T> &right);
    Matrix<T> operator*(const Matrix<T> &right) const;

    void print_matrix() const;

    T get_a() const;
    T get_b() const;
    T get_c() const;
    T get_d() const;

    void set_a(const T &new_a);
    void set_b(const T &new_b);
    void set_c(const T &new_c);
    void set_d(const T &new_d);

private:
    T a;
    T b;
    T c;
    T d;
};

template <typename T>
Matrix<T>::Matrix(): a(T{}), b(T{}), c(T{}), d(T{}) {};

template <typename T>
Matrix<T>::Matrix(const T &_a, const T &_b, const T &_c, const T &_d): a(_a), b(_b), c(_c), d(_d) {};

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &right) const {
    auto result = Matrix<T>{};

    // You can use the this pointer to access the current instances members (this->get_a())
    result.set_a(get_a() + right.get_a());
    result.set_b(get_b() + right.get_b());
    result.set_c(get_c() + right.get_c());
    result.set_d(get_d() + right.get_d());

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &right) {
    set_a(get_a() + right.get_a());
    set_b(get_b() + right.get_b());
    set_c(get_c() + right.get_c());
    set_d(get_d() + right.get_d());

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &right) const {
    auto result = Matrix<T>{};

    result.set_a(get_a() - right.get_a());
    result.set_b(get_b() - right.get_b());
    result.set_c(get_c() - right.get_c());
    result.set_d(get_d() - right.get_d());

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &right) {
    set_a(get_a() - right.get_a());
    set_b(get_b() - right.get_b());
    set_c(get_c() - right.get_c());
    set_d(get_d() - right.get_d());

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &right) const {
    auto result = Matrix<T>{};

    result.set_a(get_a() * right.get_a());
    result.set_b(get_b() * right.get_b());
    result.set_c(get_c() * right.get_c());
    result.set_d(get_d() * right.get_d());

    return result;
}


template <typename T>
void Matrix<T>::print_matrix() const {
    std::cout << a << " " << b << std::endl;
    std::cout << c << " " << d << std::endl << std::endl;
}

template <typename T>
T Matrix<T>::get_a() const {
    return a;
}

template <typename T>
T Matrix<T>::get_b() const {
    return b;
}

template <typename T>
T Matrix<T>::get_c() const {
    return c;
}

template <typename T>
T Matrix<T>::get_d() const {
    return d;
}

template <typename T>
void Matrix<T>::set_a(const T &new_a) {
    a = new_a;
}

template <typename T>
void Matrix<T>::set_b(const T &new_b) {
    b = new_b;
}

template <typename T>
void Matrix<T>::set_c(const T &new_c) {
    c = new_c;
}

template <typename T>
void Matrix<T>::set_d(const T &new_d) {
    d = new_d;
}
