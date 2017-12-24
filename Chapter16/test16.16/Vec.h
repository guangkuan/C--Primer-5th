#ifndef STRVEC_H_INCLUDED
#define STRVEC_H_INCLUDED
#include <string>
#include <memory>
#include <utility>
#include <algorithm>
#include <initializer_list>

template <typename T> class Vec;
template <typename T> bool operator==(const Vec<T>& lhs, const Vec<T>& rhs);
template <typename T> bool operator!=(const Vec<T>& lhs, const Vec<T>& rhs);
template <typename T> bool operator<(const Vec<T>& s1, const Vec<T>& s2);
template <typename T> bool operator<=(const Vec<T>& s1, const Vec<T>& s2);
template <typename T> bool operator>(const Vec<T>& s1, const Vec<T>& s2);
template <typename T> bool operator>=(const Vec<T>& s1, const Vec<T>& s2);

template <typename T>
class Vec
{
    friend bool operator==<T>(const Vec<T>& lhs, const Vec<T>& rhs);
    friend bool operator!=<T>(const Vec<T>& lhs, const Vec<T>& rhs);
    friend bool operator< <T>(const Vec<T>& s1, const Vec<T>& s2);
    friend bool operator<=<T>(const Vec<T>& s1, const Vec<T>& s2);
    friend bool operator> <T>(const Vec<T>& s1, const Vec<T>& s2);
    friend bool operator>=<T>(const Vec<T>& s1, const Vec<T>& s2);

public:
    Vec(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    Vec(const Vec&);
    Vec& operator=(const Vec&);
    Vec& operator=(std::initializer_list<T> il);
    T& operator[](size_t n)
    {
        return elements[n];
    }
    const T& operator[](size_t n) const
    {
        return elements[n];
    }

    Vec(Vec&&) noexcept;
    Vec& operator=(Vec &&rhs) noexcept;
    ~Vec();

    void push_back(const T&);
    size_t size() const
    {
        return first_free - elements;
    }
    size_t capacity() const
    {
        return cap - elements;
    }
    T* begin() const
    {
        return elements;
    }
    T* end() const
    {
        return first_free;
    }

    void reserve(size_t n);
    inline void resize(size_t n);
    inline resize(size_t n, const T &s);

    inline Vec(std::initializer_list<T> il)
    {
        auto newdata = alloc_n_copy(il.begin(), il.end());
        elements = newdata.first;
        first_free = cap = newdata.second;
    }

private:
    std::allocator<T> alloc;
    void chk_n_alloc()
    {
        if (size() == capacity()) reallocate();
    }
    std::pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();
    void reallocate();
    void reallocate(size_t newcapacity);
    T* elements;
    T* first_free;
    T* cap;
};

template <typename T>
void Vec<T>::push_back(const T& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T* b, const T* e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free()
{
    if (elements)
    {
        /*for (auto p = first_free; p != elements; )
            alloc.destroy(--p);*/
        std::for_each(elements, first_free, [this](T& s)
        {
            alloc.destroy(&s);
        });
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
Vec<T>::Vec(const Vec& s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::~Vec()
{
    free();
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T>
Vec<T>& Vec<T>::operator=(std::initializer_list<T> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

template <typename T>
Vec<T>::Vec(Vec &&s) noexcept: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

template <typename T>
Vec<T>& Vec<T>::operator=(Vec &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

template <typename T>
bool operator==(const Vec<T>& lhs, const Vec<T>& rhs)
{
    if (lhs.size() != rhs.size())
    {
        return false;
    }

    for (auto itr1 = lhs.begin(), itr2 = rhs.begin(); itr1 != lhs.end() && itr2 != rhs.end(); itr1++, itr2++)
    {
        if (*itr1 != *itr2)
        {
            return false;
        }
    }

    return true;
}

template <typename T>
bool operator!=(const Vec<T>& lhs, const Vec<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const Vec<T>& s1, const Vec<T>& s2)
{
    auto p1 = s1.begin(), p2 = s2.begin();
    for (; p1 != s1.end() && p2 != s2.end(); p1++, p2++)
        if (*p1 < *p2)
            return true;
        else
            return false;
    if (p1 == s1.end() && p2 != s2.end())
        return true;
    return false;
}

template <typename T>
bool operator<=(const Vec<T>& s1, const Vec<T>& s2)
{
    auto p1 = s1.begin(), p2 = s2.begin();
    for (; p1 != s1.end() && p2 != s2.end(); p1++, p2++)
        if (*p1 < *p2)
            return true;
        else if (*p1 > *p2)
            return false;
    if (p1 == s1.end())
        return true;
    return false;
}

template <typename T>
bool operator>(const Vec<T>& s1, const Vec<T>& s2)
{
    auto p1 = s1.begin(), p2 = s2.begin();
    for (; p1 != s1.end() && p2 != s2.end(); p1++, p2++)
        if (*p1 < *p2)
            return true;
        else if (*p1 > *p2)
            return true;
    if (p1 != s1.end() && p2 == s2.end())
        return true;
    return false;
}

template <typename T>
bool operator>=(const Vec<T>& s1, const Vec<T>& s2)
{
    auto p1 = s1.begin(), p2 = s2.begin();
    for (; p1 != s1.end() && p2 != s2.end(); p1++, p2++)
        if (*p1 < *p2)
            return true;
        else if (*p1 > *p2)
            return false;
    if (p2 == s2.end())
        return true;
    return false;
}

template <typename T>
void Vec<T>::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

template <typename T>
void Vec<T>::reallocate(size_t newcapacity)
{
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

template <typename T>
void Vec<T>::reserve(size_t n)
{
    if (n > capacity())
        reallocate(n);
}

template <typename T>
inline void Vec<T>::resize(size_t n)
{
    if (n > size())
    {
        while (size() < n)
            push_back("");
    }
    else if(n < size())
    {
        while (size() > n)
            alloc.destroy(--first_free);
    }
}

template <typename T>
inline Vec<T>::resize(size_t n, const T &s)
{
    if (n > size())
    {
        while (size() < n)
            push_back(s);
    }
}


#endif // STRVEC_H_INCLUDED
