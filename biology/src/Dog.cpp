#include <biology/Dog.h>
#include <iostream>

namespace biology
{
  void Dog::makeSound() const
  {
    std::cout << "Wang! Wang!" << std::endl;
  }

  const char *Dog::getType() const
  {
    return "Dog";
  }
}