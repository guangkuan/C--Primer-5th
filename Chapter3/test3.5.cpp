#include <iostream>
#include <string>
using namespace std;
int main()
{
    /*���ҳ���*/
    //string s1,s2,s3;
   // cin >> s1 >> s2;
    //s3 = s1+s2;
    //cout << s3 << endl;
    //return 0;

    /*��1*/
    //string s,result;
    //while (cin >> s)
    //result += s;
    //cout << result << endl;
    //return 0;

    /*��2*/
    char cont = 'y';
    string s, result;
    cout << "�������һ���ַ�����" << endl;
    while(cin >> s)
    {
        if(!result.size())
            result += s;
        else
            result = result + " " +s;
        cout << "�Ƿ����(y or n)?" << endl;
        cin >> cont;
        if (cont == 'y' || cont == 'Y')
            cout << "��������һ���ַ���:" << endl;
        else
            break;
    }
    cout << "ƴ�Ӻ���ַ����ǣ�" << result << endl;
    return 0;
}
