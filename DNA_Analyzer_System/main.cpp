//
// Created by mby on 15/07/2020.
//
/*#include <system/consoleReader.h>
#include <system/consoleWriter.h>*/

#include <consoleWriter.h>
#include <consoleReader.h>
#include "manager.h"

int main()
{
    ConsoleReader read;
    ConsoleWriter write;
    Mamager manager(&read, &write);
    manager.Run();
    return 1;
};