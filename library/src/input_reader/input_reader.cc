#include "input_reader.h"

#include <filesystem>
#include <fstream>
#include <exception>
#include <sstream>
#include <string>
#include <regex>
#include <vector>
#include <memory>
#include <iostream>

namespace input_reader {

InputPracticeProblem::InputPracticeProblem() : style_(R"(\[\d+\]\s+(\w\s*)+\b)", std::regex::ECMAScript) {}

void InputPracticeProblem::ReadFile(std::string_view path) {
    namespace fs = std::filesystem;
    fs::path p(path);

    // Check File Exit
    if (!fs::exists(p)) throw std::runtime_error(std::string("InputPracticeProblem-ReadFile : No Exist Files : ") + std::string(path));

    // Open File
    std::ifstream in(p);
    if (!in.is_open()) throw std::runtime_error(std::string("InputPracticeProblem-ReadFile : Can't open file"));

    // Read All character
    in.seekg(0, std::ios::end);
    size_t size = in.tellg();
    context_.resize(size);
    in.seekg(0, std::ios::beg);
    in.read(&context_[0], size);
}

void InputPracticeProblem::ConstructStream() {
    if (!CheckContextStyle()) throw std::runtime_error(std::string("InputPracticeProblem-ConstructStream : Wrong context style"));

    DivideContext();
}

std::vector<std::unique_ptr<std::stringstream>>& InputPracticeProblem::GetInputData() {
    if (divided_context_list_.empty()) throw std::runtime_error(std::string("InputPracticeProblem-GetInputData : Empty result context"));

    return divided_context_list_;
}

void InputPracticeProblem::DivideContext() {
    if (context_.empty()) throw std::runtime_error(std::string("InputPracticeProblem-DivideContext : No exist context readed"));

    std::smatch match;
    while (std::regex_search(context_, match, style_)) {
        divided_context_list_.push_back(std::make_unique<std::stringstream>(match.str()));

        context_ = match.suffix();
    }
}

bool InputPracticeProblem::CheckContextStyle() {
    if (context_.empty()) throw std::runtime_error(std::string("InputPracticeProblem-CheckContextStyle : No exist context readed"));

    std::smatch match;
    while (std::regex_search(context_, match, style_)) {
        return true;  // exits at least one
    }
    return false;
}

void InputPracticeProblem::PrintFullyExtractedStream() const {
    if (divided_context_list_.empty()) throw std::runtime_error(std::string("InputPracticeProblem-PrintFullyExtractedStream : Empty result context"));

    for (auto& ptr : divided_context_list_) {
        std::string word;

        // Print [number] header
        *ptr >> word;
        std::cout << word << std::endl;

        while (*ptr >> word) {
            std::cout << word << " ";
        }
        std::cout << std::endl
                  << "---------- Stream ----------" << std::endl;
    }

    std::cout << std::endl;
}
}  // namespace input_reader
