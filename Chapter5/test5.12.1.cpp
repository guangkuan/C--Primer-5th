#include <iostream>

using namespace std;

int main()
{
    unsigned int ffCnt = 0,flCnt = 0,fiCnt = 0;
    char ch,prech = '\0';
    cout << "请输入一段文本：" << endl;
    while(cin >> ch)
    {
        bool bl = true;
        if(prech == 'f')
        {
            switch(ch)
            {
            case 'f':
                ++ffCnt;
                bl = false;
                break;
            case 'l':
                ++flCnt;
                break;
            case 'i':
                ++fiCnt;
                break;
            }
        }
        if(!bl)
            prech = '\0';
        else
            prech = ch;/*直到这语句第一次正常执行，因此prech是前一个读取的ch，pre的'ch'，艹*/
    }
    cout << "ff的数量是：" << ffCnt << endl;
    cout << "fl的数量是：" << flCnt << endl;
    cout << "fi的数量是：" << fiCnt << endl;

    return 0;
}
