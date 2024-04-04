#ifndef A1_MAZE_CPP_CORE_MAZE_GENERATE_H_
#define A1_MAZE_CPP_CORE_MAZE_GENERATE_H_

namespace s21 {

// struct MazeType {
//   Maze() : rows(0), columns(0) {}
//   Maze(unsigned int inRows, unsigned int inColumns) : rows(inRows), columns(inColumns) {}
//   unsigned int rows;
//   unsigned int columns;
//   bool maze_vertical[rows][columns];
//   bool maze_horizontal[rows][columns];
// };

class Maze {
private:
  // struct MazeType maze_;
  
public:
  bool parseFile(const char* file_name);
  // generateMaze();
  // solutionMaze();
  // mazeSolvingTraining();
};

} // namespace s21
#endif
