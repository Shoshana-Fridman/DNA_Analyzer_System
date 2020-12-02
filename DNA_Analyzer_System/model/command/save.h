//
// Created by mby on 16/07/2020.
//

#ifndef IMP_SAVE_H
#define IMP_SAVE_H

#include "icommand.h"

class Save:public Icommand
{
public:
    /*vitual*/std::string execute(std::vector<std::string>&);
private:
    std::string getDefName(std::vector<std::string>&);
};

#endif //IMP_SAVE_H
