//
// Created by mby on 16/09/2020.
//

#ifndef IMPLEMENT_COUNT_H
#define IMPLEMENT_COUNT_H

#include <icommand.h>

class Count: public Icommand {
public:
    /*virtual*/ std::string execute(std::vector<std::string>&);
};

#endif //IMPLEMENT_COUNT_H
