#include <iostream>
#include <string>
#include "Vec.h"

using namespace std;

int main()
{
    Vec<string> vec;
    vec.reserve(6);
    cout << "调用(reserve to 6)的capacity为：" << vec.capacity() << endl;
    vec.reserve(4);
    cout << "调用(reserve to 4)的capacity为：" << vec.capacity() << endl;
    cout << "------------------------>" << endl;

    vec.push_back("hello");
    vec.push_back("world");

    vec.resize(4);
    for (auto i = vec.begin(); i != vec.end(); ++i)
        cout << *i << endl;
    cout << vec[0] << endl;
    cout << "------------------------>" << endl;

    vec.resize(1);
    for (auto i = vec.begin(); i != vec.end(); ++i)
        cout << *i << endl;
    cout << "------------------------>" << endl;

    Vec<string> vec_list{ "hello", "world", "pezy" };/*测试initializer_list版本构造函数*/
    for (auto i = vec_list.begin(); i != vec_list.end(); ++i)
        cout << *i << " ";
    cout << endl;
    cout << "------------------------>" << endl;

    // Test operator==
    const Vec<string> const_vec_list = { "hello", "world", "pezy" };
    if (vec_list == const_vec_list)
        for (const auto &str : const_vec_list)
            cout << str << " ";
    cout << endl;
    cout << "------------------------>" << endl;

    // Test operator<
    const Vec<string> const_vec_list_small = { "hello", "pezy", "ok" };
    cout << (const_vec_list_small < const_vec_list) << endl;

    return 0;
}

//int main()
//{
//    Vec<char> v = {'H', 'e', 'l', 'l', 'o', ',', 'w', 'o', 'r', 'l', 'd', '!'};
//    for(const auto &c : v)
//        cout << c;
//    cout << endl;
//    v.push_back(':');
//    v.push_back(')');
//    cout << v.size() << endl;
//    cout << v.capacity() << endl;
//    for(auto iter = v.begin(); iter != v.end(); ++iter)
//        cout << *iter;
//    cout << endl;
//    return 0;
//}
