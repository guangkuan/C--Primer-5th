#include <iostream>
#include <memory>

using namespace std;

struct destination{};
struct connection{};

connection connect(destination *pd)
{
    cout << "打开连接" << endl;
    return connection();
}

void disconnect(connection c)
{
    cout << "关闭连接" << endl;
}

void f(destination &d)
{
    cout << "直接管理connect" << endl;
    connection c = connect(&d);
    cout << endl;
}

void fl(destination &d)
{
    cout << "用shared_ptr管理connect" << endl;
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [](connection *p) { disconnect(*p); });
    cout << endl;
}

int main()
{
    destination d;
    f(d);
    fl(d);

    return 0;
}
