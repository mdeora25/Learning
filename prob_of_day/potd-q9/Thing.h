#pragma once

#include <string>

namespace potd {
  class Thing {
  public:
    Thing(int size);
    Thing(const Thing & s);
    Thing & operator=(const Thing &other);
    ~Thing();
    int set_property(std::string,std::string);
    std::string get_property(std::string);

  private:

    void _copy(const Thing &);
    void _destroy();

    std::string *properties_;
    std::string *values_;
    int props_ct_;
    int props_max_;
  };
  
}
