#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    //int i = 0;
    //cin >> s;
    //cout << endl;
    //for (i = 0; i != s.size(); i++)
        //s[i] = 'x';
        //cout << s <<endl ;
    //return 0;


    /*���д�*/
    cout << "������һ���ַ��������԰����ո�" << endl;
    getline(cin,s);
    //for(auto &c : s)
    //{
        //c = 'X';
    //}
    //cout << s << endl;
    //return 0;

    /*��whileʵ��*/
    int i = 0;
    while (s[i] != '\0' )
    {
        s[i] = 'X';
        ++i;
    }
    cout << s << endl;
    return 0;
}
