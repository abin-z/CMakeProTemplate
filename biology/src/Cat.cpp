#include <biology/Cat.h>
#include <iostream>

namespace biology
{
  void Cat::makeSound() const
  {
    std::cout << "Meow! Meow!" << std::endl;
  }

  const char *Cat::getType() const
  {
    return "Cat";
  }
}