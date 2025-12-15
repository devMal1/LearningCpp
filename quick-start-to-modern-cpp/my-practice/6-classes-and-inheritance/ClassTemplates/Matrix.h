#pragma once

#include <iostream>

// T E M P L A T E  C L A S S E S
/*
Like template functions, allowing generic types for classes.

NOTE: Template Classes must be defined and implemented within the header file.
*/
template <typename T>
class Matrix {
public:
    Matrix();
    Matrix(const T &_a, const T &_b, const T &_c, const T &_d);
    ~Matrix() = default;

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
