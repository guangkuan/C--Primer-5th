#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include <algorithm>
#include "String.h"

using std::cout;
using std::endl;
using std::vector;

void String::push_back(const char& s)
{
    chk_n_alloc();
    cout << "添加字符" << endl;
    alloc.construct(first_free++, s);
}

std::pair<char*, char*> String::alloc_n_copy(const char* b, const char* e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void String::free()
{
    if (elements)
    {
        /*for (auto p = first_free; p != elements; )
            alloc.destroy(--p);*/
        std::for_each(elements, first_free, [this](char& s){ alloc.destroy(&s); });
        alloc.deallocate(elements, cap - elements);
    }
}

void String::range_initializer(const char *first, const char *last)
{
    auto newdata = alloc_n_copy(first, last);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

String::String(const char *s)
{
    char *sl = const_cast<char*>(s);
    while (*sl)
        ++sl;
    range_initializer(s, ++sl);
    cout << "调用构造函数" << endl;
}

String::String(const String &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
    cout << "调用拷贝构造函数" << endl;
}

String::~String()
{
    free();
}

String& String::operator=(const String& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    cout << "调用赋值函数" << endl;
    return *this;
}

String::String(String &&s) noexcept: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
    cout << "调用移动构造函数" << endl;
}

String& String::operator=(String &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    cout << "调用移动赋值函数" << endl;
    return *this;
}
void String::reallocate()
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
    cout << "重新分配内存1" << endl;
}

void String::reallocate(size_t newcapacity)
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
    cout << "重新分配内存2" << endl;
}

void String::reserve(size_t n)
{
    if (n > capacity())
        reallocate(n);
}

int main()
{
    String s1("One"), s2("Two");
    cout << s1.size() << " " << s2.size() << endl;
    cout << s1.capacity() << " " << s2.capacity() << endl;
    cout << "--------------------------->" << endl;
    String s3(s2);
    cout << s1.size() << " " << s2.size() << " " << s3.size() << endl;
    cout << s1.capacity() << " " << s2.capacity() << " " << s3.capacity() << endl;
    cout << "--------------------------->" << endl;
    s3 = s1;
    cout << s1.size() << " " << s2.size() << " " << s3.size() << endl;
    cout << s1.capacity() << " " << s2.capacity() << " " << s3.capacity() << endl;
    cout << "--------------------------->" << endl;
    s3 = String("Three");
    cout << s1.size() << " " << s2.size() << " " << s3.size() << endl;
    cout << s1.capacity() << " " << s2.capacity() << " " << s3.capacity() << endl;
    cout << "--------------------------->" << endl;

    vector<String> vs;
    cout << "第一步" <<endl;
    vs.push_back(s1);
    cout << vs.size() << endl;
    cout << vs.capacity() << endl;
    cout << "--------------------------->" << endl;
    cout << "第二步" <<endl;
    vs.push_back(std::move(s2));
    cout << vs.size() << endl;
    cout << vs.capacity() << endl;
    cout << "--------------------------->" << endl;
    cout << "第三步" <<endl;
    vs.push_back(String("Three"));
    cout << vs.size() << endl;
    cout << vs.capacity() << endl;
    cout << "--------------------------->" << endl;
    cout << "第四步" <<endl;
    vs.push_back("Four");
    cout << vs.size() << endl;
    cout << vs.capacity() << endl;
    std::for_each(vs.begin(), vs.end(), [](const String &s){ cout << s.size() << " "; });
    cout << endl;
    std::for_each(vs.begin(), vs.end(), [](const String &s){ cout << s.capacity() << " "; });
    cout << endl;

    return 0;
}
