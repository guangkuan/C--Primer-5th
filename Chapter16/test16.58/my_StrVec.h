#ifndef MY_STRVEC_H_INCLUDED
#define MY_STRVEC_H_INCLUDED
#include <iostream>
#include <string>
#include <memory>

class StrVec {
    friend bool operator==(const StrVec& lhs, const StrVec& rhs);
    friend bool operator!=(const StrVec& lhs, const StrVec& rhs);
    friend bool operator<(const StrVec& s1, const StrVec& s2);
    friend bool operator<=(const StrVec& s1, const StrVec& s2);
    friend bool operator>(const StrVec& s1, const StrVec& s2);
    friend bool operator>=(const StrVec& s1, const StrVec& s2);

public:
    template <class... Args> void emplace_back(Args&&... args);

    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    StrVec& operator=(std::initializer_list<std::string> il);
    std::string& operator[](std::size_t n) { return elements[n]; }
    const std::string& operator[](std::size_t n) const { return elements[n]; }

    StrVec(StrVec&&) noexcept;
    StrVec& operator=(StrVec &&rhs) noexcept;
    ~StrVec();

    void push_back(const std::string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string* begin() const { return elements; }
    std::string* end() const { return first_free; }

    void reserve(size_t n);
    inline void resize(size_t n);
    inline resize(size_t n, const std::string &s);

    inline StrVec(std::initializer_list<std::string> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

private:
    std::allocator<std::string> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();
    void reallocate();
    void reallocate(size_t newcapacity);
    std::string* elements;
    std::string* first_free;
    std::string* cap;
};


#endif // MY_STRVEC_H_INCLUDED
