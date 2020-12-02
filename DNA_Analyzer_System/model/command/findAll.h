//
// Created by mby on 16/09/2020.
//

#ifndef IMPLEMENT_FINDALL_H
#define IMPLEMENT_FINDALL_H

#include <string>
#include <icommand.h>


class FindAll: public Icommand {
public:

    /*virtual*/ std::string execute(std::vector<std::string>&);
};


#endif //IMPLEMENT_FINDALL_H
