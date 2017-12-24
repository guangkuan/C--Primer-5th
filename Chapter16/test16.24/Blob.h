#ifndef BLOB_H_INCLUDED
#define BLOB_H_INCLUDED
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <utility>
#include <stdexcept>

template <typename T> class BlobPtr;
template <typename T> class Blob;
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator!=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>=(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob
{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator!=<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator< <T>(const Blob<T>&, const Blob<T>&);
    friend bool operator<=<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator><T>(const Blob<T>&, const Blob<T>&);
    friend bool operator>=<T>(const Blob<T>&, const Blob<T>&);

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    typedef typename std::vector<T>::difference_type difference_type;

    Blob();
    Blob(std::initializer_list<T> il);
    template <typename It>
    Blob(It b, It e);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T& t) { data->push_back(t); }
    void push_back(T&& t) { data->push_back(std::move(t)); }
    void pop_back();

    T& front();
    T& back();
    const T& front() const;
    const T& back() const;

    BlobPtr<T> begin();
    BlobPtr<T> end();

    T& at(size_type);
    const T& at(size_type) const;

    T& operator[](size_type i);
    const T& operator [](size_type i) const;

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string& msg) const;
};

template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il): data(std::make_shared<std::vector<T>>(il)) {}

template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e): data(std::make_shared<std::vector<T>> (b, e)) { }

template <typename T>
void Blob<T>::check(size_type i, const std::string& msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::front()
{
    check(0, "front on empty Blob");
    data->front();
}

template <typename T>
const T& Blob<T>::front() const
{
    check(0, "front on empty Blob");
    data->front();
}

template <typename T>
T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template<typename T>
const T& Blob<T>::back() const
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::at(size_type i)
{
    check(i, "index out of range");
    return data->at(i);
}
template <typename T>
const T& Blob<T>::at(size_type i) const
{
    check(i, "index out of range");
    return data->at(i);
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
const T& Blob<T>::operator [](size_type i) const
{
    // if i is too big, check function will throw, preventing access to a nonexistent element
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}
template <typename T>
inline bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return *lhs.data == *rhs.data;
}

template <typename T>
inline bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
inline bool operator<(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return *lhs.data < *rhs.data;
}

template <typename T>
inline bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return (lhs < rhs || lhs == rhs);
}

template <typename T>
inline bool operator>(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return !(lhs < rhs || lhs == rhs);
}

template <typename T>
inline bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return !(lhs < rhs);
}


#endif // BLOB_H_INCLUDED
