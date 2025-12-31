#include <biology/Mammal.h>

#include <iostream>


namespace biology
{
void Mammal::move() const
{
  std::cout << "I walk or run on land." << std::endl;
}
}  // namespace biology
