#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool get_status()
{
    return false;
}

int main()
{
    bool b;
    cout << "dafault bool values: " << true << " " << false << " nalpha bool values: " << boolalpha << true << " " << false << endl;
    cout << "-------------------------------------------------------1" << endl;

    bool bool_val = get_status();
    cout << boolalpha << bool_val << noboolalpha;
    cout << endl;
    cout << "-------------------------------------------------------2" << endl;

    const int ival = 15, jval = 1024;

    cout << "default: " << 20 << " " << 1024 << endl;
    cout << "octal: " << oct << 20 << " " << 1024 << endl;
    cout << "hex: " << hex << 20 << " " << 1024 << endl;
    cout << "decimal: " << dec << 20 << " " << 1024 << endl;
    cout << "-------------------------------------------------------3" << endl;

    cout << showbase;
    cout << "default: " << 20 << " " << 1024 << endl;
    cout << "in octal: " << oct << 20 << " " << 1024 << endl;
    cout << "in hex: " << hex << 20 << " " << 1024 << endl;
    cout << "in decimal: " << dec << 20 << " " << 1024 << endl;
    cout << noshowbase;
    cout << "-------------------------------------------------------4" << endl;

    cout << 10.0 << endl;
    cout << showpoint << 10.0 << noshowpoint << endl;
    cout << "-------------------------------------------------------5" << endl;

    cout << showpos << 10.0 << endl;
    cout << noshowpos << 10.0 << endl;
    cout << "-------------------------------------------------------6" << endl;

    cout << uppercase << showbase << hex << "printed in hexadecimal: " << 20 << " " << 1024 << nouppercase << noshowbase << dec << endl;
    cout << "-------------------------------------------------------7" << endl;

    int i = -16;
    double d = 3.14159;

    cout << "i: " << setw(12) << i << "next col" << '\n' << "d: " << setw(12) << d << "next col" << '\n';
    cout << "-------------------------------------------------------8" << endl;

    cout << left << "i: " << setw(12) << i << "next col" << '\n' << "d: " << setw(12) << d << "next col" << '\n' << right;
    cout << "-------------------------------------------------------9" << endl;

    cout << right << "i: " << setw(12) << i << "next col" << '\n' << "d: " << setw(12) << d << "next col" << '\n';
    cout << "-------------------------------------------------------10" << endl;

    cout << internal << "i: " << setw(12) << i << "next col" << '\n' << "d: " << setw(12) << d << "next col" << '\n';
    cout << "-------------------------------------------------------11" << endl;

    cout << setfill('#') << "i: " << setw(12) << i << "next col" << '\n' << "d: " << setw(12) << d << "next col" << '\n' << setfill(' ');
    cout << "-------------------------------------------------------12" << endl;

    cout << unitbuf;
    cout << "default format: " << 100 * sqrt(2.0) << '\n'
         << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
         << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
         //<< "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
         //<< "use defaults: " << defaultfloat << 100 * sqrt(2.0)
         << '\n\n';
    cout << endl;
    cout << nounitbuf;
    cout << "-------------------------------------------------------14" << endl;

    cout << "hi!" << endl;
    cout << "hi!" << flush;
    cout << "hi!" << ends;
    cout << endl;
    cout << "-------------------------------------------------------15" << endl;

    char ch;
    cin >> noskipws;
    while (cin >> ch)
        cout << ch;
    cin >> skipws;

    return 0;
}
