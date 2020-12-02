//
// Created by mby on 16/07/2020.
//
#include "dnaCollection.h"

std::map<size_t, std::string> DnaCollection::s_id_name = {};
std::map<std::string, DnaData*> DnaCollection::s_id_dna_seq = {};

void DnaCollection::AddDna(DnaData* dna)
{
    s_id_name.insert({dna->getId(), dna->getName()});
    s_id_dna_seq.insert({dna->getName(), dna});
}

