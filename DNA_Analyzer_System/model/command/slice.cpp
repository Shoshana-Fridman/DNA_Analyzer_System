//
// Created by mby on 16/09/2020.
//
#include "slice.h"

DnaData* Slice::sliceInPlace(DnaData* dna, size_t start, size_t end) {
    DnaSequence my_dna = dna->getDnaSequence();
    DnaSequence new_dna = my_dna.slice(start, end);
    dna->setSequence(new_dna);
    return dna;
}

DnaData* Slice::createSliced(DnaData* dna, std::string new_name,  size_t start, size_t end) {
    DnaSequence my_dna = dna->getDnaSequence();
    DnaSequence new_dna = my_dna.slice(start, end);

    DnaData* sliced = new DnaData(new_name, (std::string)new_dna.getDnaStr());
    new_dna.~DnaSequence();
    return sliced;
}

std::string Slice::getDefaultName(std::string prev_name)
{
    size_t number = 1;
    std::string new_name = prev_name + "_s";

    /*while (!isName((new_name + std::to_string(number))[0]))
        number++;*/

    new_name += std::to_string(number);
    return new_name;
}

std::string Slice::getOutput(DnaData* dna)
{
    std::string my_dna = dna->getDna();
    if (my_dna.length() < 40)
        return "[" + std::to_string(dna->getId()) + "] " + dna->getName() + ": " + my_dna;
    else
        return "[" + std::to_string(dna->getId()) + "] " + dna->getName() + ": " + my_dna.substr(0, 32) + "..." + my_dna.substr(my_dna.length()-3, 3);
}

std::string Slice::execute(std::vector<std::string> &params) {

    if ((params.size() != 4) && (params.size() != 6)) // too many or too little arguments
        return "Invalid number of arguments";

    DnaData* dna;
    if (isId(params[1][0]))
        dna = DnaCollection::getDna(getId(params[1]));

    else
        dna = DnaCollection::getDnaByName(params[1]);

    if (!dna)
        return "Id is not exist";

    if (params.size() == 4)
    {
        dna = sliceInPlace(dna, stoi(params[2]), stoi(params[3]));
        return getOutput(dna);
    }

    if (params[4] != ":")
        return "Invalid argument expected :";

    std::string new_name = params[5];

    if (new_name[0] != '@')
        return "Invalid argument sequence name";

    if (new_name[1] == '@')
    {
        new_name = getDefaultName(dna->getName());
    }

    else
    {
        new_name = new_name.substr(1);
    }

    DnaData* new_dna = createSliced(dna, new_name, stoi(params[2]), stoi(params[3]));

    if (!new_dna)
        return "Error! index out of range";

    DnaCollection::AddDna(new_dna);
    return getOutput(new_dna);
}