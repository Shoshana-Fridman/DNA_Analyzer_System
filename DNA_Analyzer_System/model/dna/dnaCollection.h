//
// Created by mby on 15/07/2020.
//

#ifndef IMP_DNACOLLECTION_H
#define IMP_DNACOLLECTION_H

#include "dnaData.h"
#include <map>


class DnaCollection{

public:
    static DnaData* getDna(size_t);
    static DnaData* getDnaByName(std::string);
    static void AddDna(DnaData*);
    static vector<size_t> getAllID();
    static void reId(std::size_t ,std::size_t );
    static bool setName(size_t id, std::string newName);
    static bool deleteDna(size_t);
    static std::string getName(size_t);

private:
    static bool deleteNameDna(size_t id);
    static bool deleteIdName(size_t id);

    static std::map<size_t, std::string> s_id_name;
    static std::map<std::string, DnaData*> s_id_dna_seq;
};

inline DnaData* DnaCollection::getDna(size_t id)
{
    if(s_id_dna_seq.find(s_id_name[id])!=s_id_dna_seq.end())
        return s_id_dna_seq[s_id_name[id]];
    return NULL;
}

inline DnaData* DnaCollection::getDnaByName(std::string name)
{
    if(s_id_dna_seq.find(name)!=s_id_dna_seq.end())
        return s_id_dna_seq[name];
    return NULL;
}

inline  vector<size_t> DnaCollection::getAllID()
{
    vector<size_t> key;
    std::map<size_t, std::string>::iterator it;

    for( it = s_id_name.begin(); it != s_id_name.end(); ++it) {
        key.push_back(it->first);
    }
    return key;
}

inline void DnaCollection::reId(std::size_t new_id,std::size_t old_id)
{
    DnaData* dna=getDna(old_id);
    s_id_name.erase(old_id);
    s_id_name[new_id]=dna->getName();
    dna->reId(new_id);
}

inline std::string DnaCollection::getName(size_t id)
{
    if(s_id_name.find(id)!=s_id_name.end())
        return s_id_name[id];
    return "";
}

inline bool DnaCollection::setName(size_t id, std::string newName)
{
    if(s_id_dna_seq.find(s_id_name[id])!=s_id_dna_seq.end())
    {
        DnaData *dna=getDna(id);        deleteNameDna(id);
        s_id_dna_seq.insert({newName, dna});
    }
        //if id does not exist in map id-name
    else
    {
        return false;
    }
    if(s_id_name.find(id)!=s_id_name.end())
    {
        s_id_name[id] = newName;
    }
        //if name does not exist in map name-dna
    else
    {
        return false;
    }    return true;
}

inline bool DnaCollection::deleteDna(size_t id)
{
    if (deleteNameDna(id) && deleteIdName(id))
    {
        return true;
    }
    return false;
}

inline bool DnaCollection::deleteNameDna(size_t id)
{
    if(s_id_dna_seq.find(s_id_name[id])!=s_id_dna_seq.end())
    {
        s_id_dna_seq.erase(s_id_name[id]);
        return true;
    }
    return false;
}

inline bool DnaCollection::deleteIdName(size_t id)
{
    if(s_id_name.find(id)!=s_id_name.end())
    {
        s_id_name.erase(id);
        return true;
    }
    return false;
}

#endif //IMP_DNACOLLECTION_H
