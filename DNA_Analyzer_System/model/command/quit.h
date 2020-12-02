//
// Created by mby on 14/09/2020.
//

#ifndef IMPLEMENT_QUIT_H
#define IMPLEMENT_QUIT_H
#include "icommand.h"
#include <consoleReader.h>

#include <iostream>

class Quit : public Icommand
{
public:
    /*virtual*/ std::string execute(std::vector<std::string> &vec);
};


#endif //IMPLEMENT_QUIT_H
