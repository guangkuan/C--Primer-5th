#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "Blob.h"
#include "BlobPtr.h"

using namespace std;

int main()
{
    int ia[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<long> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    list<const char*> w = { "now", "is", "the", "time" };

    Blob<int> a1(begin(ia), end(ia));
    Blob<int> a2(vi.begin(), vi.end());
    Blob<string> a3(w.begin(), w.end());

    for(typename Blob<int>::size_type i = 0; i != a1.size(); ++i)
        cout << a1[i] << " ";
    cout << endl;
    for(typename Blob<int>::size_type i = 0; i != a2.size(); ++i)
        cout << a2[i] << " ";
    cout << endl;
    Blob<string> b3(w.begin(), w.end());
    for (auto p = w.begin(); p != w.end(); ++p)
        cout << *p << endl;

    return 0;
}
