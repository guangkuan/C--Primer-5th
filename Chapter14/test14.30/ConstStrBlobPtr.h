#ifndef CONSTSTRBLOBPTR_H_INCLUDED
#define CONSTSTRBLOBPTR_H_INCLUDED
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using namespace std;

class ConstStrBlobPtr;

class StrBlob
{
    friend class ConstStrBlobPtr;

public:
    typedef vector<string>::size_type size_type;

    StrBlob();
    StrBlob(initializer_list<string> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string& t) { data->push_back(t); }

    void pop_back();
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;

    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;

private:
    shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string& msg) const;
};

inline StrBlob::StrBlob(): data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) { }

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

class ConstStrBlobPtr/*为了模仿迭代器搞出的操作*/
{
    friend bool eq(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

public:
    ConstStrBlobPtr(): curr(0) { }
    ConstStrBlobPtr(const StrBlob& a, size_t sz = 0): wptr(a.data), curr(sz) { }

    string& deref() const;
    ConstStrBlobPtr& incr();
    ConstStrBlobPtr& decr();

    const std::string& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    const std::string* operator->() const
    {
        return& (this->operator*());
    }

private:
    shared_ptr<vector<string>> check(size_t, const string&) const;
    weak_ptr<vector<string>>wptr;
    size_t curr;/*size_t是数组下标类型*/
};

inline shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string& msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

inline string& ConstStrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];/*p的解引用是vector<string>类型*/
}

inline ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline ConstStrBlobPtr& ConstStrBlobPtr::decr()
{
    --curr;
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}

inline ConstStrBlobPtr StrBlob::begin() const
{
    return ConstStrBlobPtr(*this);
}

inline ConstStrBlobPtr StrBlob::end() const
{
    auto ret = ConstStrBlobPtr(*this, data->size());
    return ret;
}

inline bool eq(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
        return (!r || lhs.curr == rhs.curr);
    else
        return false;
}

inline bool neq(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
    return !eq(lhs, rhs);
}


#endif // CONSTSTRBLOBPTR_H_INCLUDED
