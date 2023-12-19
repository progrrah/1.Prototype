#include <string>
#include <vector>
#include "syntax.hpp"

#pragma once
template <typename... Types>
class Data;

// Base case: empty Data
template <>
class Data<>
{
};
// Recursive case: Data with one or more elements

template <>
class Data<std::string, float>
{
public:
    auto set(std::string line, std::vector<std::string> elems)
    {
        name_ = line;
        value_ = syntax::convert_float<float>(elems[0]);
    }
    auto inc(std::string line, std::vector<std::string> elems)
    {
        value_++;
    }
    auto out(std::string line, std::vector<std::string> elems)
    {
        std::cout << value_;
    }
    auto getName() { return name_; }

private:
    std::string name_;
    float value_;
};
