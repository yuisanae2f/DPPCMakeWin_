cmake_minimum_required(VERSION 3.10)

project(Bin VERSION 1.0 LANGUAGES CXX)

# 프로젝트 전체에 C++20 적용
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} 

"src/main.cpp" 
"src/MyBot.cpp"
"src/onEnable.cpp"
"src/slashCommand.cpp"
)

# include 디렉토리 설정
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)


target_link_libraries(${PROJECT_NAME} PUBLIC __dpp_port)

get_target_property(dll_path __dpp_port DLL_ROOT)

file(GLOB DLLS "${dll_path}/bin/*.dll")

foreach(d ${DLLS})
file(COPY ${d} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
message("copying ${d}")
endforeach()

# install(FILES ${DLLS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
message("Out: ${CMAKE_CURRENT_BINARY_DIR}")