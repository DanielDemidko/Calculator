#pragma once
#include <optional>
#include <functional>

class Operation
{
private:
    const std::function<double(const double, const double)> Func;
    const int Priority;
    explicit Operation(const std::function<double(double, double)> &f, const int p);

public:
    double operator()(const double a, const double b) const;
    bool operator>(const Operation &other) const;
    bool IsMaxPriority() const;
    static std::optional<Operation> Parse(const std::string_view &str);

    Operation(const Operation &other) : Func(other.Func), Priority(other.Priority) {}
};