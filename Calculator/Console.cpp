#include "Console.h"
#include <iostream>
#include <string>
#include "Lexer.h"
#include "Vector.h"

std::vector<std::string> Console::ReadExpression()
{
    std::cout << ">>> ";
    std::string buf;
    std::getline(std::cin, buf);
    return Lexer::Split(buf);
}

void Console::PrintResult(const std::vector<std::string>& vec, const double res)
{
    if (vec.empty())
    {
        std::cout << "0 = 0" << std::endl;
        return;
    }
    std::cout << vec << " = " << res << std::endl;
}
