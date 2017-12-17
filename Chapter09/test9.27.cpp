#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> iflist = {0,1,2,3,4,5,6,7,8,9};
    auto prev = iflist.before_begin();
    auto curr = iflist.begin();

    while(curr != iflist.end())
    {
       if(!(*curr % 2))
        {
            curr = iflist.erase_after(prev);
        }
        else
        {
            prev = curr;
            curr++;
        }
    }


    for(curr = iflist.begin(); curr != iflist.end(); ++curr)
        cout << *curr << " ";
    cout << endl;

    return 0;
}
