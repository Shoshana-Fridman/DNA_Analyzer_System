//
// Created by mby on 15/07/2020.
//

#ifndef IMP_NEW_H
#define IMP_NEW_H

#include "icommand.h"

#include <iostream>
#include <sstream>

class New:public Icommand{

public:
    /*vitual*/ std::string execute(std::vector<std::string> &params);

private:
    static size_t s_counter;
};

#endif //IMP_NEW_H
