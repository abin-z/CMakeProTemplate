set(tgt_name common)

file(GLOB_RECURSE headers CONFIGURE_DEPENDS include/*.h include/*.hpp)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.c src/*.cpp src/*.cc src/*.cxx)

add_library(${tgt_name} SHARED)


# 设置跨平台定义
if(WIN32)
  # Windows 需要指定 DLL_PUBLIC_EXPORTS 宏，表示这是一个导出库, 在dll_export.h中有判断
  target_compile_definitions(${tgt_name} PRIVATE DLL_PUBLIC_EXPORTS)
elseif(UNIX)
  # Unix 不需要额外定义，默认支持 SO 文件
endif()

target_sources(${tgt_name} PUBLIC ${headers})
target_sources(${tgt_name} PRIVATE ${sources})

target_include_directories(${tgt_name} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
)
