#ifndef INTCOMPARE_H_INCLUDED
#define INTCOMPARE_H_INCLUDED

class IntCompare
{
public:
    IntCompare(int v): val(v) {}
    bool operator()(int v) { return val == v; }
private:
    int val;
};

#endif // INTCOMPARE_H_INCLUDED
