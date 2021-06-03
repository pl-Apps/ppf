#include "lib.hpp"

int main(int argc, char* argv[])
{
    mainmenu:
    clear();
    println("█▀█ █▀█ █▀▀\n█▀▀ █▀▀ █▀\n");
    println("[1] Unpack ppackfile");
    println("[2] Pack ppackfile\n");
    const string choice = input();
    if(choice == "1")
    {
        clear();
        print("Packed file: ");
        const string targetpack = input();
        
    }
    else if(choice == "2")
    {
        clear();
        print("New pack file name: ");
        const string newpack = input();
    }
    else
    {
        goto mainmenu;
    }
}