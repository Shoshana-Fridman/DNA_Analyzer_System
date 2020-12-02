//
// Created by mby on 15/07/2020.
//

#ifndef IMP_DNADATA_H
#define IMP_DNADATA_H

#include "dnaSequence.h"

#include <cstdio>
#include <cstring>
#include <iostream>

class DnaData{

public:
    DnaData(std::string, std::string);
    size_t getId()const ;
    std::string getStringId();
    std::string getName()const ;
    std::string getDna();
    DnaSequence getDnaSequence();
    void reId(size_t);
    void setSequence(DnaSequence& dna);

private:
    size_t m_id;
    static size_t s_count_id;
    std::string m_name;
    DnaSequence m_dna;
};

inline void DnaData::setSequence(DnaSequence& dna)
{
    m_dna = dna;
}

inline DnaSequence DnaData::getDnaSequence()
{
    return m_dna;
}

inline DnaData::DnaData(std::string name, std::string dna):m_id(s_count_id), m_name(name), m_dna(dna){
    s_count_id++;
}

inline std::string DnaData::getStringId()
{
    return std::to_string(m_id);
}

inline size_t DnaData::getId() const {
    return m_id;
}

inline std::string DnaData::getName() const {
    return m_name;
}

inline std::string DnaData::getDna() {
    return m_dna.getDnaStr();
}

inline void DnaData::reId(size_t id)
{
    m_id=id;
}

#endif //IMP_DNADATA_H