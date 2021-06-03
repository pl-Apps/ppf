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
        const string targetname = input();
        const string targetcontent = readfile(targetname);
        println(targetcontent);
    }
    else if(choice == "2")
    {
        clear();
        print("New pack file name: ");
        const string newpack = input();
        clear();
        print("Source file: ");
        const string source_filename = input();
        ppf_coding_struct::encode_file(newpack, readfile(source_filename));
    }
    else
    {
        goto mainmenu;
    }
}