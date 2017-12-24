#ifndef BLOBPTR_H_INCLUDED
#define BLOBPTR_H_INCLUDED
#include "Blob.h"
#include <vector>
#include <memory>

template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> BlobPtr<T> operator+(const BlobPtr<T>&, typename Blob<T>::difference_type);
template <typename T> BlobPtr<T> operator-(const BlobPtr<T>&, typename Blob<T>::difference_type);
template <typename T> typename Blob<T>::difference_type operator-(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> class BlobPtr
{
    friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator< <T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator<=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator><T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator>=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend BlobPtr<T> operator+<T>(const BlobPtr<T>&, typename Blob<T>::difference_type);
    friend BlobPtr<T> operator-<T>(const BlobPtr<T>&, typename Blob<T>::difference_type);
    friend typename Blob<T>::difference_type operator-<T>(const BlobPtr<T>&, const BlobPtr<T>&);

public:
    typedef typename std::vector<T>::size_type size_type;

    BlobPtr(): curr(0) {}
    BlobPtr(Blob<T>& a, size_t sz = 0): wptr(a.data), curr(sz) {}

    T& operator*() const;
    T& operator[](size_type);
    const T& operator[](size_type) const;
    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);
//    BlobPtr<T> operator+<T>(const BlobPtr<T>&, typename Blob<T>::difference_type);
//    BlobPtr<T> operator-<T>(const BlobPtr<T>&, typename Blob<T>::difference_type);
    BlobPtr& operator+=(typename Blob<T>::difference_type);
    BlobPtr& operator-=(typename Blob<T>::difference_type);

private:
    std::shared_ptr<std::vector<T>>
    check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(size_t i, const std::string& msg) const
{
    auto ret = wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound BlobPtr");
    if(i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

template <typename T>
T& BlobPtr<T>::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template <typename T>
T& BlobPtr<T>::operator[](size_type n)
{
    auto p = check(curr + n, "subscript past end");
    return (*p)[curr + n];
}

template <typename T>
const T& BlobPtr<T>::operator[](size_type n) const
{
    auto p = check(curr + n, "subscript past end");
    return (*p)[curr + n];
}

// relational operator
template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return lhs.curr < rhs.curr;
}

template <typename T>
bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return (lhs < rhs || lhs == rhs);
}

template <typename T>
bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(lhs < rhs || lhs == rhs);
}

template <typename T>
bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(lhs < rhs);
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
    auto p = check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
    --curr;
    auto p = check(curr, "decrement past begin of BlobPtr");
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    auto ret = *this;
    --*this;
    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator+=(typename Blob<T>::difference_type n)
{
    curr += n;
    check(curr, "pointer addition past end of BlobPtr");
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator-=(typename Blob<T>::difference_type n)
{
    curr -= n;
    check(curr, "pointer subtraction past begin of BlobPtr");
    return *this;
}

// addition and subtraction
template <typename T>
BlobPtr<T> operator+(const BlobPtr<T> &sp, typename Blob<T>::difference_type n)
{
    auto sum = sp;
    sum += n;
    return sum;
}

template <typename T>
BlobPtr<T> operator-(const BlobPtr<T> &sp, typename Blob<T>::difference_type n)
{
    auto sum = sp;
    sum -= n;
    return sum;
}

template <typename T>
typename Blob<T>::difference_type operator-(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return lhs.curr - rhs.curr;
}

#endif // BLOBPTR_H_INCLUDED
