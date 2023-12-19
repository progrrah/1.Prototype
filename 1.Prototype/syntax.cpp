#include "syntax.hpp"

#include <algorithm>
#include <vector>
#include <string>

std::vector<std::pair<int, int>> syntax::parseCoord(std::string line, char sep)
{
    std::vector<std::pair<int, int>> temp_array;
    temp_array.reserve(line.size());
    std::size_t k{0}, j{0};
    for (std::size_t i{0}; i < line.size(); i++)
    {
        if (line.at(i) == sep || line.at(i) == ';')
        {
            temp_array.push_back(std::pair<int, int>{j, i - 1});
            j = i + 1;
        }
    }
    temp_array.shrink_to_fit();
    return temp_array;
}
std::vector<std::string> syntax::parse(std::string line)
{
    auto coords = parseCoord(line);
    auto size = coords.size();
    std::vector<std::string> temp_line(size, std::string());
    std::size_t k{0}, j{0};
    for (std::size_t i{0}; i < size; i++)
    {
        auto size_coordI = coords[i].second - coords[i].first;
        temp_line[i] = line.substr(coords[i].first, size_coordI + 1);
    }
    return temp_line;
}
// set x 10;
template <typename T>
T syntax::convert_int(const std::string &line) // string to int
{
    return std::stoi(line);
}
template <typename T>
T syntax::convert_float(const std::string &line) // string to float
{
    return std::stof(line);
}

// bool syntax::isBounded(std::string line, char bound)
// {
//     if (line[0] == bound)
//     {
//         return true;
//     }
//     return false;
// }