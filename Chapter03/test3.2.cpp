#include <iostream>
#include <string>
#include <vector>
//using std::string;
//using std::cout;
//using std::cin;
//using std::endl;
using namespace std;
int main()
{
    string line;
    vector<string> vString;
    //char word;
    //cin >> line;
    //while (cin >> line)
    /*��һ����ʽ*/
    while (cin >> line)
        vString.push_back(line);
    cout << "��һ����ʽ��" << endl;
    for(auto iter = vString.begin(); iter != vString.end(); ++iter)
        cout << *iter << " " ;
        cout << endl;

    cout << "�ڶ�����ʽ��" << endl;
    for(auto iter = vString.begin(); iter != vString.end(); ++iter)
        cout << *iter << " " << endl;

    cout << "��������ʽ��" << endl;
    for(auto iter = vString.begin(); iter != vString.end(); ++iter)
        cout << *iter << " " << endl;
        cout << endl;

  /*�ڶ�����ʽ*/

   /* while (getline(cin, line))
        vString.push_back(line);
    cout << "��һ����ʽ��" << endl;
    for(auto iter = vString.begin(); iter != vString.end(); ++iter)
        cout << *iter << " " ;
        cout << endl;

    cout << "�ڶ�����ʽ��" << endl;
    for(auto iter = vString.begin(); iter != vString.end(); ++iter)
        cout << *iter << " " << endl;

    cout << "��������ʽ��" << endl;
    for(auto iter = vString.begin(); iter != vString.end(); ++iter)
        cout << *iter << " " << endl;
        cout << endl;
*/

    return 0;
}
