//
// Created by mby on 16/09/2020.
//

#ifndef IMPLEMENT_REPLACE_H
#define IMPLEMENT_REPLACE_H


#include "icommand.h"

class Replace : public Icommand
{
public:
    static size_t seq_num;

    /*virtual*/ std::string execute(std::vector<std::string> &);
    std::string getDefName(std::vector<std::string> & name);
};


#endif //IMPLEMENT_REPLACE_H
