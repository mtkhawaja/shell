#include "shell.h"
#include "../command/command.h"
#include <iostream>
#include <ostream>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>

void Shell::PrintPrompt(){
    std::cout << Shell::shell_prompt << ' ' << std::flush;
    return;
}

Command Shell::ReadCommand(){
    std::string line;
    std::getline(std::cin, line);
    return Command(line); 
}

int Shell::ExecCommand(Command& command){
    pid_t pid = fork();
    if (pid < 0){
        std::cout << "Error while forking child process." << std::endl;
    } else if (pid == 0){
        execvp(command.GetCommandPath(), command.GetArgList());
        std::cout << "Unable to execute shell command." << std::endl;
        return -1;
    } 
    wait(NULL);
    return 0; 
}

bool Shell::ShouldRun(){
    return Shell::should_run;
}

void Shell::ExitShell(){
    Shell::should_run = 0;
    return;
}