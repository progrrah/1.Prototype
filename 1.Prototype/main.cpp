#include <iostream>
#include "interpreter.cpp"
#include "data.cpp"
#include "syntax.cpp"

int main()
{
    const std::string path = "C:\\Users\\user\\Desktop\\1.Prototype\\1.Prototype\\log.txt";
    arch::Interpreter interpret(path);
    interpret.readCommand();
    interpret.readCommand();
    interpret.readCommand();

    return 0;
}