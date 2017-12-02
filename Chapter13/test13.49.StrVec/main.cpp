#include <iostream>
#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <algorithm>
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
    cout << "Hello world!" << endl;
    return 0;
}
