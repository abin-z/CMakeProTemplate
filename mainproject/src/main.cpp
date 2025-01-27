#include <iostream>
#include <vector>
#include <memory>

#include <biology/Cat.h>
#include <biology/Dog.h>
#include <network/socket.h>
#include <mainproject/utils.hpp>
#include <common/utils.h>
#include <common/commfunc.h>
#include <common/cppslefuse.h>

int main(int argc, char **argv)
{
  std::cout << "========================================================\n";
  std::vector<std::unique_ptr<biology::Animal>> animals;
  animals.emplace_back(std::make_unique<biology::Cat>());
  animals.emplace_back(std::make_unique<biology::Dog>());

  std::cout << "----------------------" << std::endl;
  for (const auto &animal : animals)
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

  std::cout << "----------------------" << std::endl;
  say_hello();
  auto addret = add(50, 50);
  point_t point = getPoint();
  printPoint(point);
  auto param = getParam();
  printParam(param);
  std::cout << "mysqrt(81) = " << mysqrt(81) << std::endl;
  std::cout << "mypow(10, 3) = " << mypow(10, 3) << std::endl;

  std::cout << "----------------------" << std::endl;
  Person person01("张三");
  person01.say();
  person01.say("欢迎来到c++的世界!");
  MyClass obj;
  obj.doSomething();
  std::cout << "========================================================\n";
}