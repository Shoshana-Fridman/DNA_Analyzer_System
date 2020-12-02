//
// Created by mby on 15/09/2020.
//

#include "reenum.h"
#include <string>
#include <map>
#include <dnaCollection.h>

std::string ReeNum::execute(std::vector<std::string> &params)
{
    vector<size_t> ids=DnaCollection::getAllID();
    vector<size_t>::iterator it;
    size_t id=1;
    for( it = ids.begin(); it != ids.end(); ++it) {
        DnaCollection::reId(id,*it);
        std::cout<<*it<<std::endl;
        id++;
    }
    return "the reenum complete";
}