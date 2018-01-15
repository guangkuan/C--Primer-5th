#include "Token.h"

using namespace std;

Token::Token(Token&& other): tok(INT), ival(0)
{
    tok = other.tok;
    ival = other.ival;
    other.tok = INT;
    other.ival = 0;
}

Token& Token::operator=(Token&& other)
{
    if (this != &other)
    {
//        delete tok;
        tok = other.tok;
        ival = other.ival;
        other.tok = INT;
        other.ival = 0;

    }
    return *this;
}

Token& Token::operator=(int i)
{
    if (tok == SDATA )
        sval.~Sales_data();
    ival = i;
    tok = INT;
    return *this;
}

Token& Token::operator=(char c)
{
    if (tok == SDATA)
        sval.~Sales_data();
    cval = c;
    tok = CHAR;
    return *this;
}

Token& Token::operator=(double d)
{
    if (tok == SDATA)
        sval.~Sales_data();
    dval = d;
    tok = DBL;
    return *this;
}

Token& Token::operator=(const Sales_data& sd)
{
    if (tok == SDATA)
        sval = sd;
    else
        new(&sval) Sales_data(sd);
    tok = SDATA;
    return *this;
}

void Token::copyUnion(const Token& t)
{
    switch (t.tok)
    {
    case Token::INT:
        ival = t.ival;
        break;
    case Token::CHAR:
        cval = t.cval;
        break;
    case Token::DBL:
        dval = t.dval;
        break;
    case Token::SDATA:
        new(&sval) Sales_data(t.sval);
        break;
    }
}

Token& Token::operator=(const Token& t)
{
    if (tok == SDATA && t.tok != SDATA)
        sval.~Sales_data();

    if (tok == SDATA && t.tok == SDATA)
        sval = t.sval;
    else
        copyUnion(t);
    tok = t.tok;
    return *this;
}

std::ostream& operator<<(std::ostream &os, const Token &t)
{
    switch(t.tok) {
        case Token::INT:
            os << t.ival;
            break;
        case Token::CHAR:
            os << t.cval;
            break;
        case Token::DBL:
            os << t.dval;
            break;
        case Token::SDATA:
            os << t.sval;
            break;
    }
    return os;
}
