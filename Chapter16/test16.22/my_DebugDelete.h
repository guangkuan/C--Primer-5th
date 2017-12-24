#ifndef MY_DEBUGDELETE_H_INCLUDED
#define MY_DEBUGDELETE_H_INCLUDED
#include <iostream>

class DebugDelete
{
public:
    DebugDelete(std::ostream& s = std::cerr): os(s) {}
    template <typename T>
    void operator()(T* p) const
    {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }

private:
    std::ostream& os;
};

#endif // MY_DEBUGDELETE_H_INCLUDED
