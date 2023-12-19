#pragma once

#include <fstream> // std::ifstream
#include <map>     // std::map
#include <vector>
#include <string>
#include <stack>

#include "data.hpp"
#include "syntax.hpp"



namespace arch
{
  class Interpreter
  {
  public:
    using path_type = std::string;         // std::string
    Interpreter(const path_type &logPath); // initial file when we have all command
    // ~Interpreter();                        // 2023.12.12 // not yet created

    auto readCommand() -> void; // read one command from one line
    auto readLogFile() -> void; // 2023.12.12 // read all command from logFile

    using file_stream_type_ = std::ifstream;
    using key_type_ = std::string;
    using elements_type_ = std::vector<std::string>;
    using commands_type_ =
        std::map<key_type_, void (Interpreter::*)(const elements_type_ &)>; // map consists std::string and function pointer with definite signature

    using command_type_ = std::string;

    // variables
    
    const path_type logPath_; 
    file_stream_type_ fileStrm_;
    const commands_type_ commands_;
    Data<std::string, float> db_;




    auto set(const elements_type_ &commandElements) -> void;
    auto dot(const elements_type_ &commandElements) -> void;
    auto out(const elements_type_ &commandElements) -> void;
    auto inc(const elements_type_ &commandElements) -> void;

    using type_1 = std::string;
    using type_2 = std::vector<float>;
    using type_3 = float;

  };
} 