/* command.h */
#pragma once
#include <iostream>
#include <string>

class Command  {
    private:
        int arg_count = 0;
        char** arg_list;
        void append(std::string);        
    public:
        Command(std::string);
        char * GetCommandPath();
        char ** GetArgList();
        ~Command();
};

