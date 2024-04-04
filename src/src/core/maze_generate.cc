#include "maze_generate.h"
#include <iostream>
#include <fstream>

using namespace s21;

bool Maze::parseFile(const char* file_name) {
  int error = true;


  std::ifstream file(file_name);
  if (!(file.is_open())) {
    std::cerr << "Error opening file: " << file_name << '\n';
    return false;
  }

  // сам парсинг

  // std::string line;
  // std::getline(file, line);
  // scanf("%s %d", maze_.rows, maze_.columns);

  // while (std::getline(file, line)) {
  //   if (line.rfind("v ", 0) == 0) {
  //     parseVertex(line, min_max);
  //   } else if (line.rfind("f ", 0) == 0) {
  //     parseFacet(line);
  //   }
  // }



  file.close(); 
  return error;
}
