#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<unsigned> vUS(11);
    auto it = vUS.begin();
    int iVal,i = 0;
    cout << "������һ��˻���0~100����" << endl;
    while(cin >> iVal)
        if(iVal < 101)
        {
            ++*(it + iVal / 10);/*����Ӧ�ֶε�λ�ü�1*/
            ++i;
        }
    cout << "�ܼ�������" << i << "���ɼ�" << endl;
    cout << "���ֶε������ֲ�ʽ���ɼ��ӵ͵��ߣ���" << endl;
    for(it = vUS.begin(); it != vUS.end(); it++)
    {
        cout << *it << endl;
    }
    cout << endl;
    return 0;
}
