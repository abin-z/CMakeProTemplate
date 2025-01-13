#include <iostream>
#include <vector>
#include <memory>

#include <biology/Cat.h>
#include <biology/Dog.h>
#include <network/socket.h>
#include <mainproject/utils.hpp>

int main(int argc, char **argv)
{
  std::cout << "hello world\n";
  std::vector<std::unique_ptr<biology::Animal>> animals;
  animals.emplace_back(std::make_unique<biology::Cat>());
  animals.emplace_back(std::make_unique<biology::Dog>());
  
  std::cout << "----------------------" << std::endl;
  for(const auto &animal : animals)
  {
    std::cout << "animal type: " << animal->getType() << std::endl;
    animal->move();
    animal->makeSound();
    std::cout << "----------------------" << std::endl;
  }

  network::Socket scoket;
  scoket.connect("127.0.0.1", 8848);

  double n = 100.0;
  std::cout << "mainproject::sin(n) = " << mainproject::sin(n) << std::endl;
  std::cout << "mainproject::cos(n) = " << mainproject::cos(n) << std::endl;
  std::cout << "mainproject::sqrt(n) = " << mainproject::sqrt(n) << std::endl;

}