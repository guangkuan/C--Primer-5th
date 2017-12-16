#ifndef _HEAD_H_
#define _HEAD_H_
#include <string>
#include <iostream>
class Screen
{
	typedef std::string::size_type pos;
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream &os)const{ os << contents; }
public:
	Screen() = default;
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c){}
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht*wd, ' '){}
	char get()const{ return contents[cursor]; }
	char get(pos ht, pos wd)const
	{
		return contents[ht*width + wd];
	}
	Screen &move(pos r, pos c);
	Screen &set(char ch);
	Screen &set(pos r, pos col, char ch);
	Screen &display(std::ostream &os){ do_display(os); return *this; }
	const Screen &display(std::ostream &os)const{ do_display(os); return *this; }
};
Screen &Screen::move(pos r, pos c)
{
	cursor = r*width + c;
	return *this;
}
Screen &Screen::set(char ch)
{
	contents[cursor] = ch;
	return *this;
}
Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
}
#endif
int main()
{
    using namespace std;
    Screen myScreen(5,5,'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
}
