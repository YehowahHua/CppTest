
#include <fmt/format.h>
#include <iostream>
#include <memory>

class Integer {
public:
   // constructor
   Integer(int i) : value{i} {
      std::cout << fmt::format("Constructor for Integer {}\n", value);
   }

   // destructor
   ~Integer() {
      std::cout << fmt::format("Destructor for Integer {}\n", value);
   }

   int getValue() const { return value; } // return Integer value
private:
   int value{0};
};

void unique_ptr_test();