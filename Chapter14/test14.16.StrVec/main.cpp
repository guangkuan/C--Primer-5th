#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <algorithm>
#include <initializer_list>
#include "StrVec.h"

using namespace std;

void StrVec::push_back(const std::string& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string* b, const std::string* e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements)
    {
        /*for (auto p = first_free; p != elements; )
            alloc.destroy(--p);*/
        for_each(elements, first_free, [this](std::string& s){ alloc.destroy(&s); });
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec& s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

    StrVec& StrVec::operator=(std::initializer_list<std::string> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

StrVec::StrVec(StrVec &&s) noexcept: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept
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

bool operator==(const StrVec& lhs, const StrVec& rhs)
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

bool operator!=(const StrVec& lhs, const StrVec& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrVec& s1, const StrVec& s2)
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

bool operator<=(const StrVec& s1, const StrVec& s2)
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

bool operator>(const StrVec& s1, const StrVec& s2)
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

bool operator>=(const StrVec& s1, const StrVec& s2)
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

void StrVec::reallocate()
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

void StrVec::reallocate(size_t newcapacity)
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

void StrVec::reserve(size_t n)
{
    if (n > capacity())
        reallocate(n);
}

inline void StrVec::resize(size_t n)
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

inline StrVec::resize(size_t n, const std::string &s)
{
    if (n > size())
    {
        while (size() < n)
            push_back(s);
    }
}

int main()
{
    StrVec vec;
    vec.reserve(6);
    std::cout << "调用(reserve to 6)的capacity为：" << vec.capacity() << std::endl;
    vec.reserve(4);
    std::cout << "调用(reserve to 4)的capacity为：" << vec.capacity() << std::endl;
    cout << "------------------------>" << endl;

    vec.push_back("hello");
    vec.push_back("world");

    vec.resize(4);
    for (auto i = vec.begin(); i != vec.end(); ++i)
        std::cout << *i << std::endl;
    cout << "------------------------>" << endl;

    vec.resize(1);
    for (auto i = vec.begin(); i != vec.end(); ++i)
        std::cout << *i << std::endl;
    cout << "------------------------>" << endl;

    StrVec vec_list{ "hello", "world", "pezy" };/*测试initializer_list版本构造函数*/
    for (auto i = vec_list.begin(); i != vec_list.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;
    cout << "------------------------>" << endl;

    // Test operator==
    const StrVec const_vec_list = { "hello", "world", "pezy" };
    if (vec_list == const_vec_list)
        for (const auto &str : const_vec_list)
            std::cout << str << " ";
    std::cout << std::endl;
    cout << "------------------------>" << endl;

    // Test operator<
    const StrVec const_vec_list_small = { "hello", "pezy", "ok" };
    std::cout << (const_vec_list_small < const_vec_list) << std::endl;

    return 0;
}
