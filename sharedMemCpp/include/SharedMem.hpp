#ifndef SHARED_MEM_HPP
#define SHARED_MEM_HPP

#include <string>

class SharedMem {
public:
  SharedMem(const std::string& fileName);
  ~SharedMem() = default;
  
  /**
   * @brief Returns a + b
   **/
  int64_t sum(int64_t a, int64_t b);

  /**
   * @brief Returns name
   **/
  std::string getFileName();

private:
  std::string fileName_;
};

int64_t ext_sum(int64_t a, int64_t b);

#endif //SHARED_MEM_HPP