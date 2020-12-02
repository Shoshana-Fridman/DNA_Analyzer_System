//
// Created by mby on 15/07/2020.
//

#ifndef __CLI_H__
#define __CLI_H__

#include "commandCollection.h"
/*#include <system/iReader.h>
#include <system/iWriter.h>*/

#include <iostream>
#include <vector>
#include <sstream>


class CLI{
public:
    void ExucateCommand(IReader*, IWriter*);

private:
    std::vector<std::string> SplitStringToParams(std::string str);
};

inline std::vector<std::string> CLI::SplitStringToParams(std::string str){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    std::vector<std::string> arr;
    current=strtok (cstr," ");

    while (current!=NULL){

        arr.push_back (current);
        current=strtok (NULL," ");
    }
    return arr;
}

inline void CLI::ExucateCommand(IReader* read, IWriter* write)
{
    CommandCollection cmd;
    while(true)
    {
        std::string output;
        std::string command = read->Read();
        std::vector<std::string> cmd_param=SplitStringToParams(command);
        Icommand * i_cmd = cmd.getCommand(cmd_param[0]);
        if(i_cmd)
        {
            output = (i_cmd)->execute(cmd_param);
            write->Write(output);
        }
        else
        {
            write->Write("Command not valid! please enter again");
        }
    }
}
#endif //CLI_H
