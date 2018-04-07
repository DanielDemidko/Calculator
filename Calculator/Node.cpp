#include "Node.h"
#include "Operation.h"
#include "Parser.h"
#include <string>

double Node::operator()() const
{
    if (Value.type() == typeid(Operation))
    {
        return std::any_cast<Operation>(Value)((*Left)(), (*Right)());
    }
    return std::any_cast<double>(Value);
}

inline Node::Node(const double val) : Value(val)
{
}

inline Node::Node(const std::vector<std::string>& source)
{
    if (source.empty())
    {
        Value = 0;
        return;
    }
    const auto[operation, iter] = Parser::MaxPriorityOperation(source);
    if (!operation.has_value())
    {
        Value = std::stod(source.front());
        return;
    }
    Value = operation.value();
    Left = ((iter == source.cbegin()) ?
        std::make_shared<Node>(0) : std::make_shared<Node>(Node({ source.cbegin(), iter })));
    Right = ((iter == source.cend() - 1) ?
        std::make_shared<Node>(0) : std::make_shared<Node>(Node({ iter + 1, source.cend() })));
}
