#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class HasPtr
{
public:
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);

    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &hp): ps(new std::string(*hp.ps)), i(hp.i) { }
    HasPtr& operator=(HasPtr tmp)
    {
        this->swap(tmp);
        return *this;
    }

    ~HasPtr()
    {
        delete ps;
    }

    void swap(HasPtr &rhs)
    {

        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        std::cout << "µ÷ÓÃ swap(HasPtr &rhs)" << std::endl;
    }

    void show() const
    {
        std::cout << *ps << std::endl;
    }

private:
    std::string *ps;
    int i;
};

void swap(HasPtr& lhs, HasPtr& rhs)
{
    lhs.swap(rhs);
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
    return *lhs.ps < *rhs.ps;
}

int main(void)
{
    HasPtr s{ "3" }, a{ "2" }, c{ "1" },b{ "3" }, d{ "2" }, e{ "1" },\
    h{ "3" }, k{ "2" }, m{ "1" },o{ "3" }, g{ "2" }, f{ "1" },\
    x{ "3" }, j{ "2" }, q{ "1" },n{ "3" }, r{ "2" }, i{ "1" },\
    y{ "3" }, l{ "2" }, p{ "1" },w{ "3" }, u{ "2" }, t{ "1" };
    std::vector<HasPtr> vec{ s, a, c, b, d, e, h, k, m, o, g, f, x, j, q, n, r, i, y, l, p, w, u, t};
    std::sort(vec.begin(), vec.end());
    for (auto const& elem : vec) elem.show();

    return 0;
}
