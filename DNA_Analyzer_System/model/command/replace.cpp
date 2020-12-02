//
// Created by mby on 16/09/2020.
//

#include "replace.h"
#include "new.h"
#include <sstream>
#include <dnaCollection.h>
#include <checkParam.h>

size_t Replace::seq_num = 1;

std::string Replace::execute(std::vector<std::string> &params)
{
    std::string name=getDefName(params);
    std::string dna=DnaCollection::getDnaByName(params[1].substr(1, params[1].length()-1))->getDna();
    int stop;
    if (isName(params[params.size()-1][0]))
        stop=params.size()-1;

    else
        stop=params.size();

    for(int i=2; i != params.size();i+=2) {

        if (std::stoul (params[i],nullptr,0) > dna.size()-1)
            return "index not exist";

        dna[std::stoul (params[i],nullptr,0)]=params[i+1][0];
    }
    std::vector<std::string> input;
    input.push_back("new");
    input.push_back(dna);
    input.push_back(name);
    std::cout<<name<<std::endl;
    New *newCommand = new New();
    std::string output = newCommand->execute(input);
    delete newCommand;
    return output;

}

std::string Replace::getDefName(std::vector<std::string> & name)
{
    if(!isName(name[name.size()-1][0]))
    {
        std::stringstream str;
        str << seq_num;
        seq_num++;

        return name[1]+ "_r" + str.str();
    }
    else
    {
        return name[name.size()-1];
    }
}
