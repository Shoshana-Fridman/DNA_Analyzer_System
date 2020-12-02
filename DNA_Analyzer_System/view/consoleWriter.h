//
// Created by mby on 16/07/2020.
//

#ifndef IMP_CONSOLEWRITER_H
#define IMP_CONSOLEWRITER_H

#include "iWriter.h"

#include <string>
#include <iostream>

class ConsoleWriter:public IWriter{
public:
    /*virtual*/ void Write(std::string );
};

inline void ConsoleWriter::Write(std::string str) {
    std::cout<<str<<std::endl;
}
#endif //IMP_CONSOLEWRITER_H
