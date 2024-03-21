#pragma once

#include <array>
#include <cstddef>
#include <initializer_list>
#include <type_traits>
#include <utility>

// Base accessor templates (unused directly, but specialized below)
template <typename VectorType, size_t N>
struct VectorAccessors
{
};

// Specialization for 2D vector
template <typename VectorType>

struct VectorAccessors<VectorType, 2>
{
    decltype(auto) x() const { return static_cast<const VectorType *>(this)->operator[](0); }
    decltype(auto) y() const { return static_cast<const VectorType *>(this)->operator[](1); }
};

// Specialization for 3D vector
template <typename VectorType>
struct VectorAccessors<VectorType, 3> : public VectorAccessors<VectorType, 2>
{
    decltype(auto) z() const { return static_cast<const VectorType *>(this)->operator[](2); }
};

// Specialization for 4D vector
template <typename VectorType>
struct VectorAccessors<VectorType, 4>
{
    decltype(auto) w() const { return static_cast<const VectorType *>(this)->operator[](0); }
    decltype(auto) x() const { return static_cast<const VectorType *>(this)->operator[](1); }
    decltype(auto) y() const { return static_cast<const VectorType *>(this)->operator[](2); }
    decltype(auto) z() const { return static_cast<const VectorType *>(this)->operator[](3); }
};

template <typename T, size_t N>
class Vector : public std::array<T, N>, public VectorAccessors<Vector<T, N>, N>
{
public:
    Vector() : std::array<T, N>() {}

    template <typename... Args>
    Vector(Args &&...args) : std::array<T, N>({std::forward<Args>(args)...}) {}

    Vector(const std::initializer_list<T> &list) : std::array<T, N>()
    {
        size_t i = 0;
        for (auto it = list.begin(); it != list.end() && i < N; ++it, ++i)
        {
            (*this)[i] = *it;
        }
    }

    // Assignment operator for initializer list
    Vector &operator=(const std::initializer_list<T> &list)
    {
        size_t i = 0;
        for (auto it = list.begin(); it != list.end() && i < N; ++it, ++i)
        {
            (*this)[i] = *it;
        }
        return *this;
    }

    // Ensure the array's operator= is visible
    using std::array<T, N>::operator=;

    // No need to redefine the subscript operators since they are inherited
};

// Type aliases for common vector types
using Vector4f = Vector<float, 4>;
using Vector3f = Vector<float, 3>;
using Vector2f = Vector<float, 2>;
using Vector4d = Vector<double, 4>;
using Vector3d = Vector<double, 3>;
using Vector2d = Vector<double, 2>;
