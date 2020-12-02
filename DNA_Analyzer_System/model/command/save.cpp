//
// Created by mby on 16/07/2020.
//

#include "save.h"
#include <dnaCollection.h>

#include <fstream>
#include <iostream>

std::string Save::execute(std::vector<std::string> & input)
{
    std::ofstream myfile;
    if (input.size() < 3)
    {
        input.emplace_back(std::string());
    }
    myfile.open(getDefName(input).c_str());
    if (myfile.is_open())
    {
        myfile<<(DnaCollection::getDna(std::stoul (input[1],nullptr,0))->getDna());
        myfile.close();
    }
    else
    {
        throw std::ifstream::failure("opening file failed");
    }
    return "seq saved";
}


std::string Save::getDefName(std::vector<std::string>& name)
{
    if(name[2].empty())
    {
        return  name[1]+".rawdna";
    }
    else
    {
        return name[2];
    }
}