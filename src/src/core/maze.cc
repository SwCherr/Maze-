#include "maze.h"
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>

using namespace s21;

void Maze::generateMaze(int rows, int cols) {
  srand(time(NULL)); // Генерирует случ. число, используя текущую дату как параметр
  std::vector<int> numbers(cols);
  vertical_.resize(rows, std::vector<bool>(cols));
  horizontal_.resize(rows, std::vector<bool>(cols));

  int iter_nums = 0;
  for (; iter_nums < cols; iter_nums++)
    numbers[iter_nums] = iter_nums;

  for (int i = 0; i < rows; i++) {
    generateVertical(numbers, i, cols);
    generateHorizontal(numbers, i, cols);
    preprocessingBeforeGeneration(numbers, iter_nums, i);
  }
}

void Maze::generateVertical(std::vector<int> &numbers, int curr_rows, int cols) {
  for (int j = 0; j < cols; j++) {
    if (rand() % 2 == 1) { // 1.1 Стенку справа ставим  
      vertical_[curr_rows][j] = true;
    } else { // Стенку справа не ставим  
      if (j < cols-1) { // поверяем не крайняя ли ячейка
        if (numbers[j] == numbers[j+1])
          vertical_[curr_rows][j] = true;
        else {
          unionOfSets(numbers, j, cols);
        }
      } else vertical_[curr_rows][j] = true; // устанавливаем крайнюю правую стену
    }
  }
}

void Maze::generateHorizontal(std::vector<int> &numbers, int curr_rows, int cols) {
  for (int j = 0; j < cols; j++) {
    if (rand() % 2 == 1) {
      if (checkSecondEmptyBorder(numbers, curr_rows, j)) {
        horizontal_[curr_rows][j] = true;
      }
    }
  }
}

void Maze::preprocessingBeforeGeneration(std::vector<int> &numbers, int &iter_nums, int curr_rows) {
  if (curr_rows < (getRows()-1)) {
    for (int j = 0; j < getCols(); j++) {
      if (horizontal_[curr_rows][j])
        numbers[j] = iter_nums++;
    }
  } else {
    for (int j = 0; j < getCols(); j++) {
      horizontal_[curr_rows][j] = true;
      if (j < getCols()-1) {
        if (numbers[j] != numbers[j+1])
          vertical_[curr_rows][j] = false;
        unionOfSets(numbers, j, getCols());
      }
    }
  }
}

void Maze::unionOfSets(std::vector<int> &numbers, int index_cur, int cols) {
  if (index_cur < cols-1) {
    int num_right = numbers[index_cur+1];
    for (int index = 0; index < cols; index++) {
      if (numbers[index] == num_right) 
        numbers[index] = numbers[index_cur];
    }
  }
}

bool Maze::checkSecondEmptyBorder(std::vector<int> numbers, int rows, int cols_in) {
  bool result_check = false;
  // если есть справа текущее множество = есть пустые горизонтали
  if (cols_in < (int)(horizontal_[0].size()-1) && numbers[cols_in] == numbers[cols_in+1]) {
    result_check = true;
  } else {
    int i_back = cols_in - 1;
    while (i_back >= 0 && !result_check && numbers[cols_in] == numbers[i_back]) {
      if (horizontal_[rows][i_back] == false)
        result_check = true;
      i_back--;
    }
  }
  return result_check;
}

bool Maze::initFromFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Unable to open filen" << std::endl;
    return false;
  }
  int rows, cols;
  file >> rows >> cols;
  vertical_.resize(rows, std::vector<bool>(cols));
  horizontal_.resize(rows, std::vector<bool>(cols));

  if (!readMatrixFromFile(file, vertical_, rows, cols)) return false;
  return readMatrixFromFile(file, horizontal_, rows, cols);
}

int Maze::getRows() const noexcept { return vertical_.size(); }

int Maze::getCols() const noexcept {
  if (vertical_.size() == 0) {
    return 0;
  }
  return vertical_[0].size();
}

void Maze::printData() const {
  for (int rows = 0; rows < getRows(); rows++) {
    if (rows == 0) {
      for (int i = 0; i < getCols(); i++)
        std::cout << " _";
      std::cout << '\n';
    }

    for (int cols = 0; cols < getCols(); cols++) {
      if (cols == 0) std::cout << "|";
      if (horizontal_[rows][cols]) std::cout << "_";
      else std::cout << " ";
      if (vertical_[rows][cols]) std::cout << "|";
      else std::cout << " ";
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}