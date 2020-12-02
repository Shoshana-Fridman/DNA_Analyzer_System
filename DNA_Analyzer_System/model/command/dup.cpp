//
// Created by mby on 14/09/2020.
//
#include <stdexcept>
#include <sstream>
#include <dnaData.h>
#include <dnaCollection.h>
#include "dup.h"

#include "new.h"

std::string Dup::execute(std::vector<std::string> &input)
{
    if (input.size() < 2)
    {
        input.emplace_back(std::string());
    }
    DnaData *oldDna = DnaCollection::getDna(std::stoul(input[1].substr(1, input[1].length()-1)));
    std::string name = "";
    if (3 == input.size())
    {
        name = input[2];
    }

    else
    {
        name = oldDna->getName();
        name = name[1]+name + "_1";
        input.push_back(name);
    }
    input[1] = std::string(oldDna->getDnaSequence().getDnaStr());
    std::cout<< input[1] <<std::endl;
    New *newCommand = new New();
    std::string output = newCommand->execute(input);
    delete newCommand;
    return output;
}