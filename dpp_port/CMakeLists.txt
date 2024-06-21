cmake_minimum_required(VERSION 3.13)
project(__dpp_port VERSION 1.0 LANGUAGES CXX)

option(ISX64 ON)
option(DEBUG OFF)
option(TRACK ON)

if (ISX64)
	set(ARM "64")
else()
	set(ARM "32")
endif()

if (DEBUG)
	set(DR "debug")
else()
	set(DR "release")
endif()

add_library(
    ${PROJECT_NAME} 
    "a.cpp" 
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    "${PROJECT_SOURCE_DIR}/lib/${ARM}/${DR}/lib/dpp-10.0/dpp.lib"
)

# include 디렉토리 설정
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# install set
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

target_compile_definitions(${PROJECT_NAME} PUBLIC -DDPP_WIN_TEMPLATE = 1)
target_compile_definitions(${PROJECT_NAME} PUBLIC -DDPP_CORO = 1)
target_compile_options(${PROJECT_NAME} PUBLIC /std:c++20 /W4)


message("TRACK is ${TRACK}")
if (TRACK)
    target_compile_definitions(${PROJECT_NAME} PUBLIC -DTRACK=1)
else()
    target_compile_definitions(${PROJECT_NAME} PUBLIC -DTRACK=0)
endif()

# DLL set
set(__DLL_ROOT "${PROJECT_SOURCE_DIR}/lib/${ARM}/${DR}")

set_target_properties(${PROJECT_NAME} PROPERTIES
    DLL_ROOT "${__DLL_ROOT}"
)

target_link_libraries(__dpp_port PUBLIC "${__DLL_ROOT}/lib/dpp-10.0/dpp.lib")
