#include <iostream>
#include <string>
using namespace std;
int main()
{
    /*自我尝试*/
    //string s1,s2,s3;
   // cin >> s1 >> s2;
    //s3 = s1+s2;
    //cout << s3 << endl;
    //return 0;

    /*答案1*/
    //string s,result;
    //while (cin >> s)
    //result += s;
    //cout << result << endl;
    //return 0;

    /*答案2*/
    char cont = 'y';
    string s, result;
    cout << "请输入第一个字符串：" << endl;
    while(cin >> s)
    {
        if(!result.size())
            result += s;
        else
            result = result + " " +s;
        cout << "是否继续(y or n)?" << endl;
        cin >> cont;
        if (cont == 'y' || cont == 'Y')
            cout << "请输入下一个字符串:" << endl;
        else
            break;
    }
    cout << "拼接后的字符串是：" << result << endl;
    return 0;
}
