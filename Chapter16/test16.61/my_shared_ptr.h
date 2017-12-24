#ifndef MY_SHARED_PTR_H_INCLUDED
#define MY_SHARED_PTR_H_INCLUDED
#include <iostream>

using namespace std;

template <typename T>
class SP
{
public:
    SP(): p(nullptr), use(nullptr) {}
    explicit SP(T* pt): p(pt), use(new size_t(1)) {}
    SP(const SP& sp): p(sp.p), use(sp.use) { if (use) ++*use; }
    SP& operator=(const SP&);
    ~SP();
    T& operator*() { return *p; }
    T& operator*() const { return *p; }

private:
    T* p;
    size_t* use;
};

template <typename T>
SP<T>::~SP()
{
    if (use && --*use == 0)
    {
        delete p;
        delete use;
    }
}

template <typename T>
SP<T>& SP<T>::operator=(const SP<T>& rhs)
{
    if (rhs.use)
        ++*rhs.use;
    if (use && --*use == 0)
    {
        delete p;
        delete use;
    }
    p = rhs.p;
    use = rhs.use;
    return *this;
}

template <typename T, class... Args>
SP<T> make_SP(Args&&... args)
{
    return SP<T>(new T(std::forward<Args>(args)...));
}


#endif // MY_SHARED_PTR_H_INCLUDED
