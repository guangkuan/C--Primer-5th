#ifndef STRBLOB_H_INCLUDED
#define STRBLOB_H_INCLUDED
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using namespace std;

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
    /*新添入的重载运算符*/
    friend bool operator==(const StrBlob& lhs, const StrBlob& rhs);
    friend bool operator!=(const StrBlob& lhs, const StrBlob& rhs);
    friend bool operator<(const StrBlob& s1, const StrBlob& s2);
    friend bool operator<=(const StrBlob& s1, const StrBlob& s2);
    friend bool operator>(const StrBlob& s1, const StrBlob& s2);
    friend bool operator>=(const StrBlob& s1, const StrBlob& s2);

public:
    typedef vector<string>::size_type size_type;

    StrBlob();
    StrBlob(initializer_list<string> il);

    StrBlob(vector<string>* p);
    StrBlob(StrBlob& s);
    StrBlob& operator=(StrBlob &rhs);
    string& operator[](size_t n);
    const string& operator[](size_t n) const;

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string& t)
    {
        cout << "调用左" << endl;
        data->push_back(t);
    }

    void push_back(string&& t)
    {
        data->push_back(std::move(t));
        cout << "调用右" << endl;
    }

    void pop_back();
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;

    StrBlobPtr begin();
    StrBlobPtr end();
    StrBlobPtr begin() const;
    StrBlobPtr end() const;

private:
    shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string& msg) const;
};

inline StrBlob::StrBlob(): data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) { }

/*定义新添的构造、拷贝构造、拷贝赋值函数*/
inline StrBlob::StrBlob(vector<string>* p): data(p) { }
inline StrBlob::StrBlob(StrBlob& s): data(make_shared<vector<string>> (*s.data)) { }

inline StrBlob& StrBlob::operator=(StrBlob& rhs)
{
    data = make_shared<vector<string>> (*rhs.data);
    return *this;
}

bool operator==(const StrBlob& lhs, const StrBlob& rhs)
{
    return lhs.data == rhs.data;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlob& s1, const StrBlob& s2)
{
    return *s1.data < *s2.data;
}

bool operator<=(const StrBlob& s1, const StrBlob& s2)
{
    return *s1.data <= *s2.data;
}

bool operator>(const StrBlob& s1, const StrBlob& s2)
{
    return *s1.data > *s2.data;
}

bool operator>=(const StrBlob& s1, const StrBlob& s2)
{
    return *s1.data >= *s2.data;
}

inline string& StrBlob::operator[](size_t n)
{
    check(n, "out of range");
    return data->at(n);
}

inline const string& StrBlob::operator[](size_t n) const
{
    check(n, "out of range");
    return data->at(n);
}

inline void StrBlob::check(size_type i, const string& msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

inline string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

inline const string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

inline string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline const string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    return data->pop_back();
}

/*=======================================我是华丽的分割线=========================================================*/

//

//		StrBlobPtr - custom iterator of StrBlob

//

/*=======================================我是华丽的分割线=========================================================*/

class StrBlobPtr/*为了模仿迭代器搞出的操作*/
{
    friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
    friend bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
    friend bool operator<(const StrBlobPtr& s1, const StrBlobPtr& s2);
    friend bool operator<=(const StrBlobPtr& s1, const StrBlobPtr& s2);
    friend bool operator>(const StrBlobPtr& s1, const StrBlobPtr& s2);
    friend bool operator>=(const StrBlobPtr& s1, const StrBlobPtr& s2);
    //friend StrBlobPtr operator+(size_t);
    //friend StrBlobPtr operator-(size_t);

public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob& a, size_t sz = 0): wptr(a.data), curr(sz) { }
    /*新添加的const版本*/
    StrBlobPtr(const StrBlob& a, size_t sz = 0): wptr(a.data), curr(sz) { }

    string& operator[](size_t n);
    const string& operator[](size_t n) const;
    //前缀
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    //后缀
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    StrBlobPtr operator+(size_t);
    StrBlobPtr operator-(size_t);

    string& deref() const;
    string& deref(int off) const;
    StrBlobPtr& incr();
    StrBlobPtr& decr();

private:
    shared_ptr<vector<string>> check(size_t, const string&) const;
    weak_ptr<vector<string>>wptr;
    size_t curr;/*size_t是数组下标类型*/
};

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator<(const StrBlobPtr& s1, const StrBlobPtr& s2);
bool operator<=(const StrBlobPtr& s1, const StrBlobPtr& s2);
bool operator>(const StrBlobPtr& s1, const StrBlobPtr& s2);
bool operator>=(const StrBlobPtr& s1, const StrBlobPtr& s2);

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
        return (!r || lhs.curr == rhs.curr);
    else
        return false;
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr& s1, const StrBlobPtr& s2)
{
    auto l = s1.wptr.lock(), r = s2.wptr.lock();
    if (l == r)
        {
            if (!r)
            {return false;}
        return (s1.curr < s2.curr);
        }
    else
        return false;
}

bool operator<=(const StrBlobPtr& s1, const StrBlobPtr& s2)
{
    auto l = s1.wptr.lock(), r = s2.wptr.lock();
    if (l == r)
        return (!r || s1.curr <= s2.curr);
    else
        return false;
}

bool operator>(const StrBlobPtr& s1, const StrBlobPtr& s2)
{
    auto l = s1.wptr.lock(), r = s2.wptr.lock();
    if (l == r)
        {
            if (!r)
            {return false;}
        return (s1.curr > s2.curr);
        }
    else
        return false;
}

bool operator>=(const StrBlobPtr& s1, const StrBlobPtr& s2)
{
    auto l = s1.wptr.lock(), r = s2.wptr.lock();
    if (l == r)
        return (!r || s1.curr >= s2.curr);
    else
        return false;
}

inline string& StrBlobPtr::operator[](size_t n)
{
    return (*wptr.lock())[n];
}

inline const string& StrBlobPtr::operator[](size_t n) const
{
    return (*wptr.lock())[n];
}

StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
    --curr;
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++(*this);
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --(*this);
    return ret;
}

StrBlobPtr StrBlobPtr::operator+(size_t n)
{
    auto ret = *this;
    ret.curr += n;
    return ret;
}

StrBlobPtr StrBlobPtr::operator-(size_t n)
{
    auto ret = *this;
    ret.curr -= n;
    return ret;
}

inline string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];/*p的解引用是vector<string>类型*/
}

/*偏移量为off*/
inline string& StrBlobPtr::deref(int off) const
{
    auto p = check(curr + off, "dereference past end");
    return (*p)[curr + off];/*p的解引用是vector<string>类型*/
}

inline StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline StrBlobPtr& StrBlobPtr::decr()
{
    --curr;
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}

inline StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

/*新添加的const版本*/
inline StrBlobPtr StrBlob::begin() const
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() const
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}


inline bool eq(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
        return (!r || lhs.curr == rhs.curr);
    else
        return false;
}

inline bool neq(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return !eq(lhs, rhs);
}


#endif // STRBLOB_H_INCLUDED
