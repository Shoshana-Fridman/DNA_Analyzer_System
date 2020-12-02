//
// Created by mby on 16/07/2020.
//

#include "new.h"
#include "dnaCollection.h"

size_t New::s_counter = 1;

std::string New::execute(std::vector<std::string> &params)
{
    std::string name;
    std::stringstream convert_counter_to_string, convert_id_to_string;

    if(3 == params.size()){
        name = params[2].substr(1, params[2].length()-1);
    }
    else{
        convert_counter_to_string<<s_counter;
        name = "seq" + convert_counter_to_string.str();
        s_counter++;
    }

    DnaData* dna = new DnaData(name , params[1]);
    convert_id_to_string << dna->getId();
    std::string str_new = "[" + convert_id_to_string.str() + "] " + dna->getName() + ": " + dna->getDna();
    DnaCollection::AddDna(dna);
    return str_new;
}

