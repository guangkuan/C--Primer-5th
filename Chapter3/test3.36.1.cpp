#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    const int sz = 5;
    int i;
    vector<int> a,b;
    srand((unsigned) time (NULL));
    for(i = 0; i < sz; i++)
        a.push_back(rand() % 10);
    cout << "������������ɣ��뿪ʼ��ı���" << endl;
    cout << "������������ǣ�" << endl;
    int uVal;
    for(i = 0; i < sz; i++)
        if(cin >> uVal)
            b.push_back(uVal);
    cout << "�������յ��ǣ�" << endl;
    for(auto val : a)
        cout << val << " ";
    cout << endl;
    cout << "����Ĵ�" << endl;
    for(auto val : b)
        cout << val << " ";
    cout << endl;
    auto it1 = a.begin(),it2 = b.begin();
    while (it1 != a.cend() && it2 != b.cend())
    {
        if(*it1 != *it2)
        {
            cout << "�´��ˣ����ϡ�" << endl;
            return -1;
        }
        ++it1;
        ++it2;
    }
    cout << "�߹�ʺ���ˡ�" << endl;

    return 0;
}
