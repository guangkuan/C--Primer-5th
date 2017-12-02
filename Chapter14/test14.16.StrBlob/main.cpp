#include <iostream>
#include "StrBlob.h"

using namespace std;

//测试1
int main(int argc, char* argv[])
{
    StrBlob b1;/*b1与b2共享内存b2删除但b1保存下来了内容*/
    {
        StrBlob b2 = { "World", "of", "Warcraft" };
        b1 = b2;/*拷贝赋值*/
        cout << "b1大小为" << b1.size() << endl;
        cout << "b1首尾元素为" << b1.front() << " " << b1.back() << endl;
        cout << endl;

        b2.push_back("III");/*push成员会对对其元素进行拷贝初始化*/
        cout << "b2大小为" << b2.size() << endl;
        cout << "b2首尾元素为" << b2.front() << " " << b2.back() << endl;
        cout << endl;
    }

    cout << "b1大小为" << b1.size() << endl;
    cout << "b1首尾元素为" << b1.front() << " " << b1.back() << endl;
    cout << "----------------------------->" << endl;

    StrBlob b3 = b1;/*拷贝构造*/
    b3.push_back("ova");
    cout << "b3大小为" << b3.size() << endl;
    cout << "b3首尾元素为" << b3.front() << " " << b3.back() << endl;
    cout << "b3的全部元素：" << endl;
    for (auto it = b3.begin(); neq(it, b3.end()); it.incr())
        cout << it.deref() << " ";
    cout << endl;
    cout << endl;

    cout << "b1大小为" << b1.size() << endl;
    cout << "b1的全部元素：" << endl;
    for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
        cout << it.deref() << " ";
    cout << endl;
    cout << "----------------------------->" << endl;

    StrBlob b4 = b3;
    cout << "b4的全部元素：" << endl;
    for (auto it = b4.begin(); neq(it, b4.end()); it.incr())
        cout << it.deref() << " ";
    cout << endl;
    cout << endl;
    b4 = b1;
    cout << "b4的全部元素：" << endl;
    for (auto it = b4.begin(); neq(it, b4.end()); it.incr())
        cout << it.deref() << " ";
    cout << endl;
    cout << "----------------------------->" << endl;

    StrBlob b5{ "int", "double", "float" };
    StrBlob b6 = b5;
    b6[2] = "char";
    cout << "如果b5大于b6，则b5的全部元素：" << endl;
    if (b5 > b6)//功能没有那么完整
    {
        for (auto it = b5.begin(); neq(it, b5.end()); it.incr())
            cout << it.deref() << " ";
        cout << endl;
    }
    cout << "----------------------------->" << endl;

    StrBlobPtr iter(b6);
    std::cout << (iter + 2).deref() << std::endl;

    return 0;
}
