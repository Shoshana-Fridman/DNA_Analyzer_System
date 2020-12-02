//
// Created by mby on 16/07/2020.
//

#include "load.h"

#include <fstream>

size_t Load::seq_num = 1;

std::string Load::execute(std::vector<std::string> & input)
{
    std::string line;
    std::string sequenceFromFile;
    std::fstream myfile(input[1]);
    if (myfile.is_open())
    {
        while (getline(myfile,line))
        {
            sequenceFromFile += line;
        }
        myfile.close();
    }
    else
    {
        throw std::ifstream::failure("opening file failed");
    }
    if (input.size() < 3)
    {
        input.emplace_back(std::string());
    }
    DnaData* dna = new DnaData(getDefName(input), sequenceFromFile);
    DnaCollection::AddDna(dna);
    return "["+dna->getStringId()+"] "+dna->getName() + ": " + sequenceFromFile;
}

std::string Load::getDefName(std::vector<std::string> & name)
{
    if(name[2].empty())
    {
        std::stringstream str;
        str << seq_num;
        seq_num++;
        size_t pos=name[1].find('.');

        return name[1].substr(0, pos) + "_" + str.str();
    }
    else
    {
        return name[2].substr(1, name[2].length()-1);
    }
}

