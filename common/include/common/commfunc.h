#pragma once
#include <common/dll_export.h>

#ifdef __cplusplus
extern "C"
{
#endif

  /// 可选：如果需要显式的内存对齐控制，可以使用 #pragma pack 或 __attribute__((packed))
  struct point_t
  {
    double x;
    double y;
    double z;
  };

  struct parameter_t
  {
    int num;
    point_t point;
  };

  DLL_PUBLIC_API void say_hello();
  DLL_PUBLIC_API int add(int a, int b);

  DLL_PUBLIC_API point_t getPoint();
  DLL_PUBLIC_API void printPoint(point_t arg);

  DLL_PUBLIC_API parameter_t getParam();
  DLL_PUBLIC_API void printParam(parameter_t arg);

#ifdef __cplusplus
}
#endif