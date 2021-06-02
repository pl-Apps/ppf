#include <iostream>
#include <string>
#include <filesystem>

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
    try
    {
        cout << value << endl;
    }
    catch(exception ex)
    {
        return;
    }
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
}