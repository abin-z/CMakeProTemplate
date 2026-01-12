// #define DLL_PUBLIC_EXPORTS  // 在CMakeLists中已经定义了导出宏, 不需要在定义了

#include <common/utils.h>

#include <cmath>

DLL_PUBLIC_API double mysqrt(double val)
{
  return std::sqrt(val);
}

DLL_PUBLIC_API double mypow(double base, double exponent)
{
  return std::pow(base, exponent);
}