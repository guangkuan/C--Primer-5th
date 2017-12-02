#include <iostream>
#include <fstream>
#include <sstream>	//istringstream
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cctype>

using namespace std;

int main(int argc, char **argv)
{
	ifstream infile (argv[1]);
	if (!infile)
	{
		cerr << "open file error";
		exit(1);
	}

	vector<string> vec;
	map<string, set<vector<string>::size_type>> mw;
	string temp,word;
	while (getline(infile, temp))
	{
		vec.push_back(temp);
		istringstream ist(temp);
		while (ist >> word)
		{
			if (!isalpha(word[0]))
				continue;
			word[0] = tolower(word[0]);
			if (!isalnum(word[word.size() - 1]))
				word.erase(word.size() - 1, 1);
			mw[word].insert(vec.size()-1);
		}
	}
	cout << "enter find word:";
	while (cin >> word)
	{
		if (mw.find(word) == mw.cend())
		{
			cout << "not word!" << endl;
			continue;
		}
		cout << word << " occurs " << mw.size()<< " times" << endl;
		for (auto x : mw[word])
			cout << "(line " << x +1 << ") " << vec[x] << endl;
	}


	//system("pause");
	return 0;
}
