set(tgt_name biology)

file(GLOB_RECURSE headers CONFIGURE_DEPENDS include/*.h include/*.hpp)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.c src/*.cpp src/*.cc src/*.cxx)

add_library(${tgt_name})

target_sources(${tgt_name} PUBLIC ${headers})
target_sources(${tgt_name} PRIVATE ${sources})

target_include_directories(${tgt_name} PUBLIC include)
