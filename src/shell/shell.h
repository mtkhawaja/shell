#pragma once
#include <string>
#include "../command/command.h"

class Shell{
    private:
        int should_run = 1;
        std::string shell_prompt = "shell>";
        void ExitShell(); 
    public:
        void PrintPrompt();
        Command ReadCommand();
        int ExecCommand(Command&);
        bool ShouldRun();
};