//
// Created by mby on 15/07/2020.
//

#ifndef IMP_MANAGER_H
#define IMP_MANAGER_H

//#include <view/cli.h>

#include <cstring>
#include <map>
#include <cli.h>

class Mamager{
public:
    Mamager(IReader*, IWriter*);
    void Init();
    void Run();
    void ShutDwon();

private:
    CLI* cli;
    IReader* m_preader;
    IWriter* m_pwriter;
};

inline Mamager::Mamager(IReader* read, IWriter* write): m_preader(read), m_pwriter(write) {
}

inline void Mamager::Run(){
   cli->ExucateCommand(m_preader, m_pwriter);
}


#endif //IMP_MANAGER_H
