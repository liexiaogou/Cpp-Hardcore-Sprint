#pragma once
#include <cmath>
#include <iostream>

template <typename T>
class Vector3 {
public:
    T x, y, z;
    Vector3(T _x = 0, T _y = 0, T _z = 0) : x(_x), y(_y), z(_z) {}

    // 向量加法
    Vector3<T> operator+(const Vector3<T>& other) const {
        return Vector3<T>(x + other.x, y + other.y, z + other.z);
    }

    // 向量减法
    Vector3<T> operator-(const Vector3<T>& other) const {
        return Vector3<T>(x - other.x, y - other.y, z - other.z);
    }

    // 向量缩放
    Vector3<T> operator*(T scalar) const {
        return Vector3<T>(x * scalar, y * scalar, z * scalar);
    }

    // 计算长度（模长）
    T length() const {
        return static_cast<T>(std::sqrt(x * x + y * y + z * z));
    }

    // 🚀 这里使用 U 来避免和类的 T 冲突
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Vector3<U>& v);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector3<T>& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}