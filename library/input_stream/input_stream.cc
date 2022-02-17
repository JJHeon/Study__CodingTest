#include "input_stream.h"

#include <filesystem>

InputStream::InputStream(const std::string& path)
    : path_(path) {
}

bool InputStream::IsExitsFile() const {
    namespace fs = std::filesystem;
    fs::path p(this.path_);

    if (fs::exits(p)) {
        return true;
    } else
        return false;
}

bool InputStream::ReadFile() {
    if (!IsExitsFile()) return false;

    try {
    } catch (...) {
    }

    return true;
}

std::ostream& InputStream::GetStream() {
}