#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Sales_data.h"

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in("sales_data.txt");
    //�Ķ��ط�������һ��Sales_data.txt
    Sales_data total;
    if(read(in, total)){
    //read(cin,total); ��Ϊread(in,total);
        Sales_data trans;
        while(read(in,trans)){
        //read(cin, total); ��Ϊread(in,total);
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(cout,total) << endl;
                total = trans;
            }
        }
    print(cout,total) << endl;
    } else{
        cerr << "No data?!" << endl;
    }
}
