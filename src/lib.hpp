#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void print(string value)
{
    try
    {
        cout << value;
    }
    catch(exception ex)
    {
        return;
    }
}

void println(string value)
{
    cout << value << endl;
    return;
}

string input()
{
    string ret;
    cin >> ret;
    return ret;
}

int clear()
{
    print("\033[2J\033[1;1H");
    return 0;
}

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

int writefile(string filename, string content)
{
    try 
    {
        ofstream target(filename);
        target << content;
        target.close();
        return 0;
    }
    catch (exception ex)
    {
        return 1;
    }
}

namespace ppf_coding_struct
{
    string decode(int* code)
    {
        return "NO";
    }
    string encode(string source)
    {
        int output[5000];
        int i = 0;
        for(char c : source) {
            const int crt = int(c);
            output[i] = crt;
            i++;
        }
        string tmp;
        for(int o : output)
        {
            tmp += to_string(o) + " | ";
        }
        return tmp;
    }
    int encode_file(string filename, string content)
    {
        try 
        {
            const string encoded = encode(content);
            writefile(filename, encoded);
            return 0;
        }
        catch (exception ex)
        {
            return 1;
        }
    }
}