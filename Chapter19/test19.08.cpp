#include <iostream>
#include <typeinfo>

using namespace std;

class Query_base
{
public:
    Query_base() {}
    virtual ~Query_base() {}
    // ...
};

class BinaryQuery : public Query_base
{
public:
    BinaryQuery() {}
    virtual ~BinaryQuery() {}
    // ...
};

class AndQuery : public BinaryQuery
{
public:
    AndQuery() {}
    virtual ~AndQuery() {}
    // ...
};

int main()
{
    Query_base *qb1 = new Query_base;
    Query_base *qb2 = new AndQuery;

    if (typeid(*qb1) == typeid(*qb2))
    {
        cout << "success." << endl;
    }
    else
    {
        cout << "failure." << endl;
    }

    if (typeid(*qb1) == typeid(AndQuery))
    {
        cout << "success." << endl;
    }
    else
    {
        cout << "failure." << endl;
    }

    return 0;
}
