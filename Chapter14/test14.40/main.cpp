#include <iostream>
#include <fstream>
#include "Biggies.h"

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in (argv[1]);
    if(!in)
    {
        cout << "�ļ�������" << endl;
        exit(1);
    }

    vector<string> words;
    string word;
    while(in >> word)
        words.push_back(word);
    biggies(words, 4);

    return 0;
}
