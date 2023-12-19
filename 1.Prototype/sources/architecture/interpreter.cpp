#include <stdexcept> // std::invalid_argument
#include <string>    // std::getline

#include "interpreter.hpp"
#include "parsing.hpp"
#include "algebra.hpp"

auto Database::set(std::string name, std::vector<std::string> values) -> void
{
 return get(name);
}
template <class T>
auto Database::get(std::string name) -> T
{
  return stof(name);
}
// "2"

arch::Interpreter::Interpreter(const path_type &logPath)
    : logPath_(logPath),
      fileStrm_(logPath_), commands_{{"SET", &Interpreter::set},
                                     {"DOT", &Interpreter::dot},
                                     {"OUT", &Interpreter::out},
                                     {"INC", &Interpreter::inc}}
{
  if (!this->fileStrm_.is_open())
  {
    throw std::invalid_argument("wrong log path");
  }
}
// where checking of existence function and logical exception else
auto arch::Interpreter::readCommand() -> void
{ // process of reading, parsing and executing command through this function
  command_type_ cmd;
  std::getline(this->fileStrm_, cmd);
  const auto parsedCmd = syntax::parse(cmd);
  const auto key = parsedCmd.front();
  const auto elems = elements_type_(++parsedCmd.begin(), parsedCmd.end());
  auto temp_function = this->commands_.at(key);
  (this->*temp_function)(elems);
}

auto arch::Interpreter::readLogFile() -> void
{
  command_type_ cmd;
  std::stack<elements_type_> completed_cmds;
  while (getline(this->fileStrm_, cmd))
  {
    const auto parsedCmd = syntax::parse(cmd);
    const auto key = parsedCmd.front();
    const auto elems = elements_type_(++parsedCmd.begin(), parsedCmd.end());
    auto temp_function = this->commands_.at(key);
    (this->*temp_function)(elems);
    completed_cmds.push(cmd);
  }
}
// set x 10
auto arch::Interpreter::set(const elements_type_ &cmdElems) -> void
{
  const auto name = cmdElems.front();
  const auto vals = elements_type_(++cmdElems.begin(), cmdElems.end());
  this->database_.set(name, vals);
}

auto arch::Interpreter::dot(const elements_type_ &cmdElems) -> void
{
  const auto first_name = cmdElems.front();
  const auto second_name = cmdElems.back();
  this->database_.dot(first_name, second_name);
}

auto arch::Interpreter::out(const elements_type_ &cmdElems) -> void
{
  const auto name = cmdElems.front();
  const auto vals = elements_type_(++cmdElems.begin(), cmdElems.end());
  this->database_.out(name, vals);
}
auto arch::Interpreter::inc(const elements_type_ &commandElements) -> void
{
  const auto name = cmdElems.front();
  const auto vals = elements_type_(++cmdElems.begin(), cmdElems.end());
}
