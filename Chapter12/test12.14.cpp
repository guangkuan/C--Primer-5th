#include <iostream>
#include <memory>

using namespace std;

struct destination{};
struct connection{};

connection connect(destination *pd)
{
    cout << "������" << endl;
    return connection();
}

void disconnect(connection c)
{
    cout << "�ر�����" << endl;
}

void f(destination &d)
{
    cout << "ֱ�ӹ���connect" << endl;
    connection c = connect(&d);
    cout << endl;
}

void fl(destination &d)
{
    cout << "��shared_ptr����connect" << endl;
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
