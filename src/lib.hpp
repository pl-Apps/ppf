#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

const char alpchars[28] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '\n'};


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
    typedef int* encoded_string;
    string decode(encoded_string code)
    {
        char ret[size_t(code)];
        int recchars[28];
        for(int i = 0; i < size_t(recchars); i++)
        {
            recchars[i] = int(alpchars[i]);
        }
        for(int i = 0; i < size_t(code); i++)
        {
            for(int z = 0; z < size_t(recchars); z++)
            {
                if(code[i] == recchars[z])
                {
                    ret[i] = alpchars[z];
                }
            }
        }
    }
    string encode(string source)
    {
        int output[source.length()];
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
    encoded_string read_encoded_file(string filename)
    {
        const string text = readfile(filename);
        encoded_string ret;
        char* tmp;
        int o = 0;
        for(int i = 0; i < sizeof(text); i++)
        {
            tmp += text[i];
            if(text[i] == '|')
            {
                ret[o] = int(tmp);
                tmp = "";
            }
            o++;
        }
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
    int decode_file(string filename, encoded_string content)
    {
        try
        {
            const string decoded = decode(content);
            writefile(filename, decoded);
            return 0;
        }
        catch (exception ex)
        {
            return 1;
        }
    }
}