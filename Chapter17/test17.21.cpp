#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::istream;
using std::ostream;
using std::endl;

#include <sstream>
using std::ostringstream;
using std::istringstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <regex>
using std::regex;
using std::sregex_iterator;
using std::smatch;
using std::regex_error;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

string format(const string& s)
{
    return s;
}

bool valid(const smatch& m)
{
    if (m[1].matched)
        return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    else
        return !m[3].matched && m[4].str() == m[6].str();
}

vector<PersonInfo> getData(istream& is)
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    regex r(phone);
    smatch m;
    string line, word;
    vector<PersonInfo> people;

    while(getline(is, line))
    {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        getline(record, line);
        for (sregex_iterator it(line.begin(), line.end(), r), end_it; it != end_it; ++it)
        {
            if (valid(*it))
                info.phones.push_back("V" + it->str());
            else
                info.phones.push_back("I" + it->str());
        }
        people.push_back(info);
    }
    return people;
}

ostream& process(ostream& os, vector<PersonInfo> people)
{
    for(const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto& nums : entry.phones)
        {
            if(nums[0] == 'I')
            {
                badNums << " " << nums.substr(1) << endl;
            }
            else
                formatted << " " << format(nums.substr(1));
        }
        if(badNums.str().empty())
            os << entry.name << endl << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name << " invalid number" << badNums.str() << endl;
    }
    return os;
}

int main()
{
    process(cout, getData(cin));
    /*morgan (201) 555-2368 862-555-0123
    drew (973)555.0130
    lee (609) 555-0132 2015550175 800.555-0000*/

    return 0;
}
