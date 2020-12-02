//
// Created by mby on 15/09/2020.
//

#ifndef IMPLEMENT_RENAME_H
#define IMPLEMENT_RENAME_H

#include <dnaCollection.h>
#include "icommand.h"


class Rename: public Icommand {
public:

    /*virtual*/ std::string execute(std::vector<std::string>&);
};

inline std::string Rename::execute(std::vector<std::string>& input)
{
    size_t id = std::stoul (input[1].substr(1, input[1].length()-1),nullptr,0);
    std::string oldName = DnaCollection::getName(id);

    if (oldName == "")
    {
        return "Id does not exist please enter again";
    }

    DnaCollection::setName(id, input[2].substr(1, input[2].length()-1));
    return oldName + " rename to " + DnaCollection::getName(id);
}

#endif //IMPLEMENT_RENAME_H
