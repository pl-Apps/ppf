#include "lib.hpp"

int main(int argc, char* argv[])
{
    clear();
    mainmenu:
    print("1) UnPack packfile\n");
    print("2) Pack packfile\n\n");
    const string choice = input();
    if(choice == "1")
    {

    }
    else if(choice == "2")
    {

    }
    else
    {
        goto mainmenu;
    }
}