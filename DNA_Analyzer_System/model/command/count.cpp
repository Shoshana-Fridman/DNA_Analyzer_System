//
// Created by mby on 16/09/2020.
//

#include <dnaData.h>
#include "count.h"
#include <checkParam.h>
#include <dnaCollection.h>


std::string Count::execute(std::vector<std::string>&params) {

    if (params.size() != 3) // too many or too little arguments
        return "Invalid number of arguments";
    DnaData *dna;

    if (isId(params[1][0])) // get DNA to find in
        dna = DnaCollection::getDna(std::stoul(params[1].substr(1, params[1].length()-1)));

    else
        dna = DnaCollection::getDnaByName(params[1].substr(1, params[1].length()-1));

    if (!dna)
        return "DNA not exist";

    DnaSequence dna_seq = dna->getDnaSequence();
    std::string sub; // get subsequence

    if (isId(params[2][0]))
        sub = DnaCollection::getDna(std::stoul(params[2].substr(1, params[2].length()-1)))->getDna();

    else
        sub = params[2];

    //size_t index = dna_seq.count(sub);
    size_t index = 0;
    std::string output(std::to_string(index));
    return output;
}