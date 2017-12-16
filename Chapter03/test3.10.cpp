#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string s, result;
    int i = 0;
    cout << "ÇëÊäÈëÒ»¸ö×Ö·û´®£º" << endl;
    getline(cin, s);
        //for(decltype(s.size()) i = 0 ; i < s.size(); ++i)
        //{
            //if (!ispunct(s[i]))
                //result += s[i];
        //}
        for (auto c : s)
        {
            if (!ispunct(c))
                cout << c;
        }
    //cout << result << endl;
    cout << endl;
    return 0;
}
