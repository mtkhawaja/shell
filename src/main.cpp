#include "shell/shell.h"
#include "command/command.h"

int main (int argc, char ** argv){
    Shell shell;
    while(shell.ShouldRun()){
        shell.PrintPrompt();
        Command command = shell.ReadCommand();
        shell.ExecCommand(command); 
    }
}