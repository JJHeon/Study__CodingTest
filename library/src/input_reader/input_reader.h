/*
@Title		: Input Reader for CodingTest example problems
@Version	: 1.0
@Revision1	: 22.02.21 created
@ETC		:
*/

#ifndef INPUT_READER_H_
#define INPUT_READER_H_

#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <memory>

namespace input_reader {

class InputPracticeProblem {
   public:
    InputPracticeProblem();
    void ReadFile(std::string_view path);
    void ConstructStream();
    std::vector<std::unique_ptr<std::stringstream>>& GetInputData();
    void PrintFullyExtractedStream() const;

   private:
    std::string context_;
    std::vector<std::unique_ptr<std::stringstream>> divided_context_list_;
    const std::regex style_;

    bool CheckContextStyle();
    void DivideContext();
};

}  // namespace input_reader

#endif
