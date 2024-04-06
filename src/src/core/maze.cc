#include "maze.h"
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>

using namespace s21;

void Maze::generateMaze(int rows, int cols) {
  srand(time(NULL)); // Генерирует случайное число, используя текущую дату как параметр
  std::vector<int> numbers(cols);

  int iter_nums = 0;
  // std::cout << "numbers:\n"; // --
  // std::cout << ' '; // --
  for (; iter_nums <= cols; iter_nums++) {
    numbers[iter_nums] = iter_nums;
    // printf("%d ", numbers[iter_nums]); // --
  }

  // std::cout << '\n'; // --



  vertical_.resize(rows, std::vector<bool>(cols));
  horizontal_.resize(rows, std::vector<bool>(cols));

  // Генерация вертикалей
  for (int i = 0; i < rows; i++) {
    // std::cout << " vertical_:\n"; // --
    // std::cout << ' '; // --
    for (int j = 0; j < cols; j++) {
      // 1.1 Стенку справа ставим  
      if (rand() % 2 == 1) {
        // printf("1 "); // --
        vertical_[i][j] = true;

      // Стенку справа не ставим  
      } else {
        // printf("0 "); // --
        // поверяем не крайняя ли ячейка
        if (j < cols-1) {
          // 1.2 если текущая ячейка и ячейка справа принадлежат одному множеству
          if (numbers[j] == numbers[j+1])
            vertical_[i][j] = true;
          else {
            // 1.3 объединияем множества - вынести общий код
            int num_right = numbers[j+1];
            for (int index = 0; index < cols; index++) {
              if (numbers[index] == num_right) 
                numbers[index] = numbers[j];
            }
          }
        } else vertical_[i][j] = true; // устанавливаем крайнюю правую стену
      }
    }


    // std::cout << '\n'; // --

    // --------------------------
    // std::cout << " numbers after vertical_:\n"; // --
    // std::cout << ' '; // --
    // for (int j = 0; j < cols; j++) {
    //   printf("%d ", numbers[j]);
    // }
    // std::cout << '\n'; // --
    // --------------------------

    // Генерация горизонталей
    // std::cout << " horizintal_:\n"; // --
    // std::cout << ' '; // --
    for (int j = 0; j < cols; j++) {
      if (rand() % 2 == 1) {
        // printf("1 "); // --
        if (checkSecondEmptyBorder(numbers, i, j)) {
          horizontal_[i][j] = true;
        }
      }
    }
    // std::cout << '\n'; // --


    // Пункт 5 - обработка перед генерацией следующей строки
    if (i < rows-1) {
      for (int j = 0; j < cols; j++) {
        if (horizontal_[i][j])
          numbers[j] = iter_nums++;
      }
    } else {
    // Пункт 5 - обработка последней строки
      for (int j = 0; j < cols; j++) {
        horizontal_[i][j] = true;

        if (j < cols-1) {
          // 5.1
          if (numbers[j] != numbers[j+1])
            vertical_[i][j] = false;

          // 5.2 объединияем множества - вынести общий код
          int num_right = numbers[j+1];
          for (int index = 0; index < cols; index++) {
            if (numbers[index] == num_right) 
              numbers[index] = numbers[j];
          }
        }
      }
    }

    // --------------------------
    // std::cout << " numbers after horizontal_:\n"; // --
    // std::cout << ' '; // --
    // for (int j = 0; j < cols; j++) {
    //   printf("%d ", numbers[j]);
    // }
    // std::cout << '\n'; // --
    // --------------------------
    // std::cout << '\n'; // --

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