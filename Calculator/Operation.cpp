#include "Operation.h"

Operation::Operation(const std::function<double(double, double)>& f, const int p) : Func(f), Priority(p)
{
}

double Operation::operator()(const double a, const double b) const
{
    return Func(a, b);
}

bool Operation::operator>(const Operation &other) const
{
    return Priority > other.Priority;
}

bool Operation::IsMaxPriority() const
{
    return Priority == 2;
}

std::optional<Operation> Operation::Parse(const std::string_view & str)
{
    switch (str.front())
    {
    case '+':
        return Operation(std::plus<double>(), 2);
    case '-':
        return Operation(std::minus<double>(), 2);
    case '*':
        return Operation(std::multiplies<double>(), 1);
    case '/':
        return  Operation(std::divides<double>(), 1);
    case '^':
        return Operation((double(*)(const double, const double))std::pow, 0);
    }
    return {};
}
