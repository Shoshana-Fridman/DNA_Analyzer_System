//
// Created by mby on 16/07/2020.
//

#ifndef IMP_CONSOLEREADER_H
#define IMP_CONSOLEREADER_H

#include "iReader.h"

class ConsoleReader: public IReader
{
public:
    /*virtual*/std::string Read();
};

inline std::string ConsoleReader::Read()
{
    std::string command;
    std::cout<<">> ";
    getline(std::cin, command);
    return command;
}
#endif //IMP_COMMANDREADER_H
