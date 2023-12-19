#pragma once

#include <fstream> // std::ifstream
#include <map>     // std::map

// #include "variables.hpp"
#include "Data.hpp"



namespace arch
{
  class Interpreter
  {
  public:
    using path_type = libs::line_type;     // std::string
    Interpreter(const path_type &logPath); // initial file when we have all command
    ~Interpreter();                        // 2023.12.12 // not yet created

    auto readCommand() -> void; // read one command from one line
    auto readLogFile() -> void; // 2023.12.12 // read all command from logFile

  private:
    using file_stream_type_ = std::ifstream;
    using key_type_ = libs::line_type;
    using elements_type_ = libs::lines_type;
    using commands_type_ =
        std::map<key_type_, void (Interpreter::*)(const elements_type_ &)>; // map consists std::string and function pointer with definite signature

    using command_type_ = libs::line_type;

    const path_type logPath_; // logPath save a history of running the program
    file_stream_type_ fileStrm_;
    const commands_type_ commands_;
    // daba::Database<key_type_, float> database_;

    auto set(const elements_type_ &commandElements) -> void;
    auto dot(const elements_type_ &commandElements) -> void;
    auto out(const elements_type_ &commandElements) -> void;
    auto inc(const elements_type_ &commandElements) -> void;

    using type_1 = std::string;
    using type_2 = std::vector<float>;
    Database<type_1, type_2> db;
  };
} // namespace arch
// set x 10
