/* command.cpp */
#include "command.h"
#include <sstream>
#include <string>

char * Command::GetCommandPath(){
    return Command::arg_list[0];
}

char ** Command::GetArgList(){
    return Command::arg_list;
}

void Command::append(std::string arg){
    Command::arg_list[Command::arg_count] = new char[arg.size() + 1];  
    std::copy(arg.begin(), arg.end(), Command::arg_list[Command::arg_count]);
    Command::arg_list[Command::arg_count][arg.size()] = '\0';
    Command::arg_count++;
    Command::arg_list[Command::arg_count] = nullptr;
}


Command::Command(std::string raw_command){
    std::string token; 
    int size = 0;
    std::istringstream stream(raw_command), count_stream(raw_command); 
    while(count_stream >> token)
        size++;
    Command::arg_list = new char*[size + 1]; 
    while(stream >> token)
        Command::append(token);
}

Command::~Command(){
    delete[] Command::arg_list;
}
