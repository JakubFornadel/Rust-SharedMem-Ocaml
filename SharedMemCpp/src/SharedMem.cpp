#include <SharedMem.hpp>

SharedMem::SharedMem(const std::string& fileName) {
    fileName_ = fileName;
}

int64_t SharedMem::sum(int64_t a, int64_t b) {
    return a + b;
}

std::string SharedMem::getFileName() {
    return fileName_;
}
