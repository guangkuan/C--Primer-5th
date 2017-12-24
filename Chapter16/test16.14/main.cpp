#include <iostream>
#include "tScreen.h"
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    Screen<5, 3> myScreen;
    myScreen.display(cout);
    myScreen.move(4, 0).set('#');

    Screen<5, 5> nextScreen('X');
    nextScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    cout << "0-------------4------------------------9--------" << endl;
    nextScreen.display(cout);
    cout << endl;
    cout << "0-------------4---------------------------------" << endl;

    const Screen<5, 3> blank;
    myScreen.set('#').display(cout);
    cout << endl;
    cout << "0-------------4---------------------------------" << endl;
    blank.display(cout);
    cout << endl;
    cout << "0-------------4---------------------------------" << endl;

    myScreen.clear('Z').display(cout);
    cout << endl;
    cout << "0-------------4---------------------------------" << endl;

    myScreen.move(4, 0);
    myScreen.set('#');
    myScreen.display(cout);
    cout << endl;
    cout << "0-------------4---------------------------------" << endl;

    myScreen.clear('Z').display(cout);
    cout << endl;
    cout << "0-------------4---------------------------------" << endl;

    Screen<5, 3> temp = myScreen.move(4, 0);
    temp.set('#');
    myScreen.display(cout);
    cout << endl;
    cout << "0-------------4---------------------------------" << endl;

    cout << myScreen << endl << nextScreen << endl << temp << endl;
    cout << "0-------------4---------------------------------" << endl;

    std::cin >> myScreen;
    cout << myScreen << endl;

    return 0;
}
