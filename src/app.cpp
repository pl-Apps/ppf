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
        clear();
        print("Output file: ");
        const string outtargetname = input();
        clear();
        ppf_coding_struct::decode_file(outtargetname, readfile(targetname));
    }
    else if(choice == "2")
    {
        clear();
        print("New pack file name: ");
        const string newpack = input();
        clear();
        print("Source file: ");
        const string source_filename = input();
        clear();
        ppf_coding_struct::encode_file(newpack, readfile(source_filename));
    }
    else
    {
        goto mainmenu;
    }
}