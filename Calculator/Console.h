#pragma once
#include <vector>

namespace Console

{
    std::vector<std::string> ReadExpression();
    void PrintResult(const std::vector<std::string> &expr, const double res);
}