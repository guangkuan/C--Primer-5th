#ifndef MY_QUERY_BASE_H_INCLUDED
#define MY_QUERY_BASE_H_INCLUDED
#include <iostream>
#include <memory>
#include <algorithm>
#include "my_TextQuery.h"
#include "my_QueryResult.h"

using namespace std;

class Query_base
{
    friend class Query;

protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
};

class WordQuery: public Query_base
{
    friend class Query;
    WordQuery(const string& s): query_word(s) {}
    QueryResult eval(const TextQuery& t) const { return t.query(query_word); }
    string rep() const { return query_word; }
    string query_word;
};

class Query
{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

public:
    Query(const std::string& s) : q(new WordQuery(s))
    {
        std::cout << "Query::Query(const std::string& s) where s = " << s << "\n";
    }
    QueryResult eval(const TextQuery& t) const { return q->eval(t); }
    string rep() const { return q->rep(); }

private:
    Query(shared_ptr<Query_base> query): q(query) {}
    shared_ptr<Query_base> q;
};

inline ostream& operator<<(const ostream& os, const Query& query)//必须是非成员函数
{
    return os << query.rep();
}

class NotQuery: public Query_base
{
    friend Query operator~(const Query&);
    NotQuery(const Query& q): query(q) {}
    string rep() const { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery&) const;
    Query query;
};

inline Query operator~(const Query& operand)
{
    return shared_ptr<Query_base>(new NotQuery(operand));
}

QueryResult NotQuery::eval(const TextQuery& text) const
{
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file().size();
    for (size_t n = 0; n != sz; ++n)
    {
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

class BinaryQuery: public Query_base
{
protected:
    BinaryQuery(const Query& l, const Query& r, string s): lhs(l), rhs(r), opSym(s) {}
    string rep() const { return "( " + lhs.rep() + " " + opSym + " " + rhs.rep() + " )"; }
    Query lhs, rhs;
    string opSym;
};

class AndQuery: public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& left, const Query& right): BinaryQuery(left, right, "&") {}
    QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query& lhs, const Query& rhs)
{
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

QueryResult AndQuery::eval(const TextQuery& text) const
{
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

class OrQuery: public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& left, const Query& right): BinaryQuery(left, right, "|") {}
    QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery& text) const
{
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

#endif // MY_QUERY_BASE_H_INCLUDED
