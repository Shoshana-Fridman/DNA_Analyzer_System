//
// Created by mby on 14/09/2020.
//

#ifndef IMPLEMENT_FIND_H
#define IMPLEMENT_FIND_H

#include <icommand.h>
#include <dnaSequence.h>
#include <dnaCollection.h>
#include "checkParam.h"

class Find: public Icommand {
public:

    /*virtual*/ std::string execute(std::vector<std::string>&);
};

inline bool isLonger(DnaSequence dna, DnaSequence otherDna)
{
    return strlen(dna.getDnaStr()) >= strlen(otherDna.getDnaStr());
}





#endif //IMPLEMENT_FIND_H
