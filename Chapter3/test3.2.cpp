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
    /*第一种形式*/
    while (cin >> line)
        vString.push_back(line);
    cout << "第一种形式：" << endl;
    for(auto iter = vString.begin(); iter != vString.end(); ++iter)
        cout << *iter << " " ;
        cout << endl;

    cout << "第二种形式：" << endl;
    for(auto iter = vString.begin(); iter != vString.end(); ++iter)
        cout << *iter << " " << endl;

    cout << "第三种形式：" << endl;
    for(auto iter = vString.begin(); iter != vString.end(); ++iter)
        cout << *iter << " " << endl;
        cout << endl;

  /*第二种形式*/

   /* while (getline(cin, line))
        vString.push_back(line);
    cout << "第一种形式：" << endl;
    for(auto iter = vString.begin(); iter != vString.end(); ++iter)
        cout << *iter << " " ;
        cout << endl;

    cout << "第二种形式：" << endl;
    for(auto iter = vString.begin(); iter != vString.end(); ++iter)
        cout << *iter << " " << endl;

    cout << "第三种形式：" << endl;
    for(auto iter = vString.begin(); iter != vString.end(); ++iter)
        cout << *iter << " " << endl;
        cout << endl;
*/

    return 0;
}
