//
// Created by mby on 14/09/2020.
//

#ifndef IMPLEMENT_CHECKPARAM_H
#define IMPLEMENT_CHECKPARAM_H

inline bool isId(char param)
{
    return param == '#';
}

inline bool isName(char param)
{
    return param == '@';
}

inline size_t getId(std::string input)
{
    return std::stoul (input.substr(1),nullptr,0);
}

#endif //IMPLEMENT_CHECKPARAM_H
