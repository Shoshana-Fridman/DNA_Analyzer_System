//
// Created by mby on 15/07/2020.
//

#ifndef IMP_WRITETOFILE_H
#define IMP_WRITETOFILE_H

#include <dnaSequence.h>
#include "iWriter.h"

class FileWriter:public IWriter{
public:
    /*virtual*/void Write(DnaSequence & dna){};
};

#endif //IMP_WRITETOFILE_H
