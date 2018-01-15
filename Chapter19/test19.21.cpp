class Token
{
public:
    Token(): tok(INT), ival{0} {}
    Token(const Token& t): tok(t.tok) { copyUnion(t); }
    Token& operator=(const Token&);
    Token& operator=(char);
    Token& operator=(int);
    Token& operator=(double);

private:
    enum {INT, CHAR, DBL} tok;
    union
    {
        char cval;
        int ival;
        double dval;
    };
    void copyUnion(const Token&);
};

int main()
{
    return 0;
}
