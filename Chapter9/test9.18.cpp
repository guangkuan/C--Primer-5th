#include <iostream>
//#include <string>
#include <deque>

using namespace std;

int main()
{
    string s;
    deque<string> sdeque;
    while(cin >> s)
        sdeque.push_front(s);
    for(auto it = sdeque.begin(); it != sdeque.end(); ++it)
        cout << *it << " ";
        cout << endl;

    return 0;
}
