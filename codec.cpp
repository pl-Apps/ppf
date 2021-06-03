#include <string>
#include <printf.h>
#include <iostream>

using namespace std;

string main(void)
{
    const string input = "ciao io sono peppo";
    int output[500];
    int i = 0;
    for(char c : input) {
        const int crt = int(c);
        output[i] = crt;
        i++;
    }
    string tmp;
    for(int o : output)
    {
        tmp += to_string(o);
    }
    return tmp;
}