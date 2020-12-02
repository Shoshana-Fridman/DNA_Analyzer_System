//
// Created by mby on 16/09/2020.
//

#ifndef IMPLEMENT_SLICE_H
#define IMPLEMENT_SLICE_H

#include "icommand.h"
#include "dnaData.h"
#include "checkParam.h"
#include "dnaCollection.h"
#include "dnaSequence.h"

class Slice:public Icommand
{
public:
    /*virtual*/ std::string execute(std::vector<std::string> &);

private:
    std::string getDefaultName(std::string);
    static DnaData* sliceInPlace(DnaData*, size_t, size_t);
    static DnaData* createSliced(DnaData*, std::string, size_t, size_t);
    static std::string getOutput(DnaData*);
};


#endif //IMPLEMENT_SLICE_H
