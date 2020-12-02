//
// Created by mby on 14/09/2020.
//
#include "quit.h"


std::string Quit::execute(std::vector<std::string> &vec)
{
    std::cout<<"Are you sure you want to quit?"<<std::endl;
    std::cout<<"Please confirm by 'y' or cancle by 'n'"<<std::endl;
    ConsoleReader read;
    std::string confirm = read.Read();

    if (confirm == "y")
    {
        std::cout<<"Thank you for using DnaAnalyzer"<<std::endl;
        std::cout<<"Goodbye!"<<std::endl;
        exit(0);
    }
    return "Ok you don't exit from the program";
}
