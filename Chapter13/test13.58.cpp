#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo{
public:
    Foo sorted() &&;
    Foo sorted() const &;

private:
    vector<int> data;
};

Foo Foo::sorted() &&
{
    cout << "��ֵ���ð汾" << endl;
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const &
{
    cout << "��ֵ���ð汾" << endl;
    Foo ret(*this);
    return ret.sorted();
}

int main(int argc, char* argv[])
{
    Foo f;
    f.sorted();

    return 0;
}
