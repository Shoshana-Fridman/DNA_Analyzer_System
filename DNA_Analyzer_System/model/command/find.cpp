//
// Created by mby on 14/09/2020.
//

#include "find.h"
#include "invalidDna.h"

std::string findBySeq(DnaSequence dna, DnaSequence otherDna)
{
    if (!isLonger(dna, otherDna))
    {
        return "Not substring";
    }
    size_t index = dna.find(otherDna);
    if(index == SIZE_MAX)
    {
        return "Not substring";
    }
    return std::to_string(index);
}

std::string Find::execute(std::vector<std::string> &input) {
    if (input.size() < 3)
        input.emplace_back(std::string());

    if(isId(input[1][0]))
    {
        size_t id = std::stoul(input[1].substr(1));
        DnaSequence dna = DnaCollection::getDna(id)->getDnaSequence();
        if(DnaCollection::getDna(id))
        {
            if(!isId(input[2][0]))
            {
                DnaSequence otherDna(input[2]);
                return findBySeq(dna, otherDna);
            }
            else
            {
                size_t otherId = std::stoul(input[2].substr(1, input[2].length()-1));
                DnaSequence otherDna = DnaCollection::getDna(otherId)->getDnaSequence();
                if(!DnaCollection::getDna(otherId))
                    return "Invalid id ,please enter other id";
                return findBySeq(dna, otherDna);
            }
        }
    }
    return "Invalid id ,please enter other id with #";

}

