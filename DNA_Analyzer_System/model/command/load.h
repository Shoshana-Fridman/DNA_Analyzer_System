//
// Created by mby on 15/07/2020.
//

#ifndef IMP_LOAD_H
#define IMP_LOAD_H

#include "icommand.h"
/*#include <model/dna/dnaData.h>
#include <model/dna/dnaCollection.h>*/

#include <sstream>
#include <iostream>
#include <dnaData.h>
#include <dnaCollection.h>

class Load:public Icommand
{
public:
    static size_t seq_num;
    /*vitual*/std::string execute(std::vector<std::string>& str);
private:
    std::string getDefName(std::vector<std::string> & name);
    std::string printDna(DnaData* dna);
};


#endif //IMP_LOAD_H
