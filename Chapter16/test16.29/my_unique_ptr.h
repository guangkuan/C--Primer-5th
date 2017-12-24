#ifndef MY_UNIQUE_PTR_H_INCLUDED
#define MY_UNIQUE_PTR_H_INCLUDED
#include <iostream>

using namespace std;

template <typename T>
class UP
{
public:
    UP(): p(nullptr) {}
    UP(const UP&) = delete;
    explicit UP(T* pt): p(pt) {}
    UP& operator=(const UP&) = delete;
    ~UP();
    T* release();
    void reset(T* new_p);
    T& operator*() { return *p; }
    T& operator*() const { return *p; }

private:
    T* p;
    T* new_p = nullptr;
};

template <typename T>
UP<T>::~UP()
{
    if (p)
        delete p;
}

template <typename T>
void UP<T>::reset(T* new_p)
{
    if (p)
        delete p;
    p = new_p;
}

template <typename T>
T* UP<T>::release()
{
    T* q = p;
    p = nullptr;
    return q;
}


#endif // MY_UNIQUE_PTR_H_INCLUDED
