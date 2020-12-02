//
// Created by mby on 15/09/2020.
//

#ifndef IMPLEMENT_REENUM_H
#define IMPLEMENT_REENUM_H

#include <icommand.h>

class ReeNum:public Icommand
{
public:
    /*virtual*/ std::string execute(std::vector<std::string> &);
};

#endif //IMPLEMENT_REENUM_H
