#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    /*自编*/
    //string s;
    //vector<string> text;
    //cout << "请输入一组字符串：" ;
    //getline (cin, s);
    //text.push_back(s);
    //for (auto result : text)
    //cout << result << endl;
    //return 0;


    vector<string> vString;
    string s;
    char cont = 'y';
    cout << "请输入一组字符串：" << endl;
    while(cin >> s)
    {
        vString.push_back(s);
        cout << "是否继续（y or n）？" << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
    }
    for (auto mem : vString)
        cout << mem << " ";
    cout << endl;
    return 0;
}
