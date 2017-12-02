#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void remove_author(multimap<string, string> &books, const string author)
{
    auto pos = books.equal_range(author);
    if (pos.first == pos.second)
    {
        cout << "没有要找的作者。" << endl;
        cout << "请留意书目如下：" << endl;
        cout << endl;
    }

    else
        books.erase(pos.first, pos.second);
}

void print_books(multimap<string, string> &books)
{
    for (auto w : books)
    {
        cout << w.first << "的作品有： " << "《" << w.second << "》" << endl;
        cout << endl;
    }
    cout << "=================================================" << endl;
}

void remove_author2(multimap<string, string> &books, pair<string, string> author)
{
    auto it = books.find(author.second);
    int v = books.count(author.second);
    while(v--)
    {
        if(author.second == it->second)
        {
            books.erase(it);
            break;
        }
        it++;
    }
}

void remove_author3(multimap<string, string> &books, const string &author)
{
    auto entries = books.count(author);
    auto iter = books.find(author);
    while (entries)
    {
        cout << iter->second << endl;
        ++iter;
        --entries;
    }
}
int main(int argc, char *argv[])
{
    multimap<string, string> books;
    books.insert({"Barth, John", "Sot-Weed Factor"});
    books.insert({"Barth, John", "Lost in the Funhouse"});
    books.insert({"金庸", "射雕英雄传"});
    books.insert({"金庸", "天龙八部"});

    print_books(books);

    remove_author(books, "张三");
    print_books(books);

    remove_author(books,"Barth, John");
    cout << "第一种方法：" << endl;
    print_books(books);

    remove_author2(books, {"Barth, John", "Sot-Weed Factor"});
    cout << "第二种方法：" << endl;
    print_books(books);

    remove_author3(books, "Barth, John");
    cout << "第三种方法：" << endl;
    print_books(books);

    return 0;
}
