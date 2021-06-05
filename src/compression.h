#include <iostream>
#include <string>

using namespace std;

string readfile(string filename)
{
    fstream target;
	target.open(filename, ios::in);
	if (!target) {
		println("No such file");
        exit(1);
	}
	else {
		char ch;
        string ret;
		while (1) {
			target >> ch;
			if (target.eof())
				break;
			ret += ch;
		}
        return ret;
	}
	target.close();
	return 0;
}

int compress(string filename)
{
    int ret;
    for(char c : readfile(filename))
    {
        ret += int(c);
    }
    return ret;
}