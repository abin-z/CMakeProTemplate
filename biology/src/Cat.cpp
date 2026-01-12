#include <biology/Cat.h>

#include <iostream>

namespace biology
{
void Cat::makeSound() const
{
  std::cout << "Meow! Meow!" << '\n';
}

const char *Cat::getType() const
{
  return "Cat";
}
}  // namespace biology