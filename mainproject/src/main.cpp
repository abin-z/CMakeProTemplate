#include <biology/Cat.h>
#include <biology/Dog.h>
#include <common/commfunc.h>
#include <common/cppslefuse.h>
#include <common/utils.h>
#include <network/socket.h>

#include <iostream>
#include <mainproject/utils.hpp>
#include <memory>
#include <vector>

int main(int argc, char **argv)
{
  std::cout << "========================================================\n";
  std::vector<std::unique_ptr<biology::Animal>> animals;
  animals.emplace_back(std::make_unique<biology::Cat>());
  animals.emplace_back(std::make_unique<biology::Dog>());

  std::cout << "----------------------" << '\n';
  for (const auto &animal : animals)
  {
    std::cout << "animal type: " << animal->getType() << '\n';
    animal->move();
    animal->makeSound();
    std::cout << "----------------------" << '\n';
  }

  network::Socket scoket;
  scoket.connect("127.0.0.1", 8848);

  double n = 100.0;
  std::cout << "mainproject::sin(n) = " << mainproject::sin(n) << '\n';
  std::cout << "mainproject::cos(n) = " << mainproject::cos(n) << '\n';
  std::cout << "mainproject::sqrt(n) = " << mainproject::sqrt(n) << '\n';

  std::cout << "----------------------" << '\n';
  say_hello();
  auto addret = add(50, 50);
  point_t point = getPoint();
  printPoint(point);
  auto param = getParam();
  printParam(param);
  std::cout << "mysqrt(81) = " << mysqrt(81) << '\n';
  std::cout << "mypow(10, 3) = " << mypow(10, 3) << '\n';

  std::cout << "----------------------" << '\n';
  Person person01("张三");
  person01.say();
  person01.say("欢迎来到c++的世界!");
  MyClass obj;
  obj.doSomething();
  std::cout << "========================================================\n";
}