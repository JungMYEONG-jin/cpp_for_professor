// PNG-Writer 오픈소스 라이브러리 사용
// PDF-Writer 의 LinPng ZLib FreeType도 필요함
// CMake 빌드방법은 전체폴더에 위 3 폴더 및 pngwriter 라이브러리 폴더를 넣은후 전체 폴더에
/*
cmake_minimum_required (VERSION 3.7.0) 
project(problem_82)

include_directories(${LIBS_PATH}/PNGWriter/LibPng)
include_directories(${LIBS_PATH}/PNGWriter/ZLib)
include_directories(${LIBS_PATH}/PNGWriter/FreeType/include)
include_directories(${LIBS_PATH}/pngwriter)

add_executable(problem_82 main.cpp)


ADD_SUBDIRECTORY(ZLib)
ADD_SUBDIRECTORY(LibPng)
ADD_SUBDIRECTORY(FreeType)
ADD_SUBDIRECTORY(PngWriter)

target_link_libraries(problem_82 LibPng)
target_link_libraries(problem_82 Zlib)
target_link_libraries(problem_82 FreeType)
target_link_libraries(problem_82 PngWriter)

set_target_properties (problem_82 PROPERTIES FOLDER "10.ArchivesImagesDatabases")
add sub directory를 해줘야 sub direc에서도 cmake가 실행됨
direc명은 sub direc에 있는 cmake에서 설정한 project name
*/

#include <iostream>
#include <string_view>
#include <string>

#include "pngwriter.h"

void create_flag(int const width, int const height, string_view filepath)
{

  pngwriter flag{width, height, 0, filepath.data()};
  int const size = width/3;
  // red rectangle
  flag.filledsquare(0,0, size, 2*size, 65535, 0, 0);
  //yellow
  flag.filledsquare(size, 0, 2*size, 2*size, 65535, 65535, 0);
  // blue
  flag.filledsquare(2*size, 0, 3*size, 2*size, 0, 0, 65535);
  
  flag.close();
  
}

int main()
{
  int width =0, height=0;
  string filepath;
  cout<<"Width: ";
  cin>>width;
  
  cout<<"Height: "
  cin>>height;
  
  cout<<"Output: "
  cin>>filepath;
  
  create_flag(width, height, filepath);


}

