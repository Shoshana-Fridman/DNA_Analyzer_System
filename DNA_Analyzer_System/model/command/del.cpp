//
// Created by mby on 15/09/2020.
//

#include "del.h"

std::string Del::execute(std::vector<std::string> &input)
{
    size_t id = std::stoul (input[1].substr(1),nullptr,0);
    std::string name = DnaCollection::getName(id);

    if (name == "")
    {
        return "Id does not exist please enter again";
    }

    std::cout << "Are you sure you want to delete" << name << " ?" << std::endl;
    std::cout << "Please confirm by 'y' or 'Y', or cancel by 'n' or 'N'." << std::endl;
    ConsoleReader read;
    std::string confirm = read.Read();

    while (1)
    {
        if (confirm == "n" || confirm == "N")
        {
            return "Ok, you can to regret";
        }

        if (confirm == "y" || confirm == "Y")
        {

            if (DnaCollection::deleteDna(id))
            {
                return "Deleted: [" + std::to_string(id )+ "] " + name ;
            }
            return "Id does not exist please enter again";
        }
        std::cout<<"You have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'"<<std::endl;
        confirm = read.Read();
    }
}
