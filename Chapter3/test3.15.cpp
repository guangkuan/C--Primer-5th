#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    /*�Ա�*/
    //string s;
    //vector<string> text;
    //cout << "������һ���ַ�����" ;
    //getline (cin, s);
    //text.push_back(s);
    //for (auto result : text)
    //cout << result << endl;
    //return 0;


    vector<string> vString;
    string s;
    char cont = 'y';
    cout << "������һ���ַ�����" << endl;
    while(cin >> s)
    {
        vString.push_back(s);
        cout << "�Ƿ������y or n����" << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
    }
    for (auto mem : vString)
        cout << mem << " ";
    cout << endl;
    return 0;
}
