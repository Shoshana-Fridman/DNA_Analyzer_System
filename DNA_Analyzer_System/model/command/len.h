//
// Created by mby on 14/09/2020.
//

#ifndef IMPLEMENT_LEN_H
#define IMPLEMENT_LEN_H

#include <icommand.h>
#include <string>
#include <dnaCollection.h>
#include "checkParam.h"

class Len: public Icommand {
public:

    /*virtual*/ std::string execute(std::vector<std::string>&);
};

inline std::string Len::execute(std::vector<std::string>& input)
{
    if(!isId(input[1][0]))
        return "Invalid id ,please enter other id with #";
    return std::to_string(DnaCollection::getDna(std::stoul (input[1].substr(1, input[1].length()-1),nullptr,0))->getDna().length());
}
#endif //IMPLEMENT_LEN_H
