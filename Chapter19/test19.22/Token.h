#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED
#include "Sales_data.h"

using namespace std;

class Token
{
    friend std::ostream& operator<<(std::ostream&, const Token&);

public:
    Token(): tok(INT), ival(0) {}
    Token(const Token& t): tok(t.tok) { copyUnion(t); }

    Token(Token&& other);
    Token& operator=(Token&& other);

    Token& operator=(const Token&);
    Token& operator=(char);
    Token& operator=(int);
    Token& operator=(double);
    Token& operator=(const Sales_data&);

    ~Token()
    {
        if (tok == SDATA)
            sval.~Sales_data();
    }
private:
    enum {INT, CHAR, DBL, SDATA} tok;
    union
    {
        char cval;
        int ival;
        double dval;
        Sales_data sval;
    };
    void copyUnion(const Token&);
};

#endif // TOKEN_H_INCLUDED
