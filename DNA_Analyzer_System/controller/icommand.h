//
// Created by mby on 15/07/2020.
//

#ifndef IMP_ICOMMAND_H
#define IMP_ICOMMAND_H

//#include "cli.h"

#include <vector>
#include <string>


class Icommand{

public:
    virtual std::string execute(std::vector<std::string>&) = 0;
};

#endif //IMP_ICOMMAND_H
