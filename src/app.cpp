#include "lib.hpp"

int main(int argc, char* argv[])
{
    if(argc >= 2)
    {
        println("Too arguments");
        exit(1);
    }
    mainmenu:
    clear();
    println("█▀█ █▀█ █▀▀\n█▀▀ █▀▀ █▀\n");
    println(" ____________________ ");
    println("|       Files        |");
    println("| [1] Decode file    |");
    println("| [2] Encode file    |");
    println("|       String       |");
    println("| [3] Decode string  |");
    println("| [4] Encode string  |");
    println("|____________________|\n");
    const string choice = input();
    if(choice == "1")
    {
        clear();
        print("Packed file: ");
        const string targetname = input() + ".ppf";
        clear();
        print("Output file: ");
        const string outtargetname = input();
        clear();
        ppf_coding_struct::decode_file(outtargetname, ppf_coding_struct::read_encoded_file(targetname));
    }
    else if(choice == "2")
    {
        clear();
        print("New pack file name: ");
        const string newpack = input() + ".ppf";
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