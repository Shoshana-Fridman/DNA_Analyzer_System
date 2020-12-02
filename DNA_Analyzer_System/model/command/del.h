//
// Created by mby on 15/09/2020.
//

#ifndef IMPLEMENT_DEL_H
#define IMPLEMENT_DEL_H

#include <icommand.h>
#include <dnaCollection.h>
#include <consoleReader.h>

#include <iostream>

class Del: public Icommand {
public:

    /*virtual*/ std::string execute(std::vector<std::string>&);
};

#endif //IMPLEMENT_DEL_H
