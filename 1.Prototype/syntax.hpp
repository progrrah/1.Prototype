#pragma once

#include <string>

// #include "library.hpp"

namespace syntax
{
    std::vector<std::pair<int, int>> parseCoord(std::string line, char sep = ' ');

    std::vector<std::string> parse(std::string line);
    std::string convert_caps(std::string line);

    template <typename T>
    T convert_int(const std::string &line);
    template <typename T>
    T convert_float(const std::string &line);

}
