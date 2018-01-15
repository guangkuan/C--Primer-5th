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
    Query_base *qb = new Query_base;
    try
    {
        dynamic_cast<AndQuery&>(*qb);
        cout << "success" << endl;
    }
    catch (bad_alloc& bc)
    {
        cout << "failure" << endl;
    }

    return 0;
}
