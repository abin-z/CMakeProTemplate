#include <common/commfunc.h>
#include <iostream>

DLL_PUBLIC_API void say_hello()
{
  std::cout << "Hello from shared library!" << std::endl;
}

DLL_PUBLIC_API int add(int a, int b)
{
  return a + b;
}

DLL_PUBLIC_API void printPoint(point_t arg)
{
  std::cout << "Point: (" << arg.x << ", " << arg.y << ", " << arg.z << ")" << std::endl;
}

DLL_PUBLIC_API point_t getPoint()
{
  point_t pt = {1.0, 2.0, 3.0};
  return pt;
}

DLL_PUBLIC_API parameter_t getParam()
{
  parameter_t pt = {1, {10.0, 20.0, 30.0}};
  return pt;
}

DLL_PUBLIC_API void printParam(parameter_t arg)
{
  std::cout << "Parameter - Num: " << arg.num << ", Point: ("
            << arg.point.x << ", " << arg.point.y << ", " << arg.point.z << ")" << std::endl;
}
