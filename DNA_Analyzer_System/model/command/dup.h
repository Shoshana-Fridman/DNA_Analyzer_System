//
// Created by mby on 14/09/2020.
//

#ifndef IMPLEMENT_DUP_H
#define IMPLEMENT_DUP_H

#include <icommand.h>


class Dup:public Icommand
{
public:
    /*virtual*/ std::string execute(std::vector<std::string> &);
};


#endif //IMPLEMENT_DUP_H
