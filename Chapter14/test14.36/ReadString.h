#ifndef READSTRING_H_INCLUDED
#define READSTRING_H_INCLUDED
#include <iostream>

class ReadString
{
public:
    ReadString(std::istream& is = std::cin): is(is) {}
    std::string operator()()
    {
        std::string line;
        if (!getline(is, line))
        {
            line = " ";
        }

        return line;
    }
    void testReadString();

private:
    std::istream& is;
};


#endif // READSTRING_H_INCLUDED
