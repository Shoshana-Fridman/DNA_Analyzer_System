//
// Created by mby on 15/07/2020.
//

#ifndef __COMMAND_COLLECTION_H__
#define __COMMAND_COLLECTION_H__

#include <cstring>
#include <map>

#include "icommand.h"
#include "new.h"
#include "load.h"
#include "save.h"
#include "len.h"
#include <find.h>
#include <dup.h>
#include <quit.h>
#include <rename.h>
#include <del.h>
#include <reenum.h>
#include <slice.h>
#include <replace.h>
#include <count.h>
#include <findAll.h>

class CommandCollection{
public:
    CommandCollection();
    ~CommandCollection();
    Icommand* getCommand(std::string);

private:
    CommandCollection(CommandCollection &);
    CommandCollection operator=(CommandCollection &);
    std::map <std::string, Icommand*> m_map_command;
};

inline Icommand* CommandCollection::getCommand(std::string command){
    if(m_map_command.find(command)!=m_map_command.end())
        return m_map_command[command];
    return NULL;
}

inline CommandCollection::CommandCollection(): m_map_command({{"new", new New()}, {"load", new Load()}, {"save", new Save()}, {"len", new Len()}, {"find", new Find()}, {"dup", new Dup()}, {"quit", new Quit()}, {"rename", new  Rename()}, {"del", new Del()}, {"reenum", new ReeNum()}, {"slice", new Slice()}, {"replace", new Replace()}, {"findAll", new FindAll()}, {"count", new Count()}}){};

inline CommandCollection::~CommandCollection() {
    map<std::string, Icommand*>::iterator it;

    for ( it = m_map_command.begin(); it != m_map_command.end(); it++ )
    {
         delete it->second;//delete Icommand
    }
}

#endif //COMMAND_COLLECTION_H
