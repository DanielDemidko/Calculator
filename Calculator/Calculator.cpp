#include <iostream>
#include <string>
#include "Lexer.h"
#include "Vector.h"
#include "Node.h"


int main()
{
    std::string buffer;
    while (std::cout << ">>> ", std::getline(std::cin, buffer))
    {
        const auto expr = Lexer::Split(buffer);
        std::cout << expr << " = " << Node(expr)() << std::endl;
    }
}


