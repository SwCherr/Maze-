#ifndef MAZE_CORE_COMMANDS_GENERATE_MAZE_COMMAND_H_
#define MAZE_CORE_COMMANDS_GENERATE_MAZE_COMMAND_H_

#include "../maze.h"
#include "command.h"

namespace s21 {
class GenerateMazeCommand : public Command {
 public:
  GenerateMazeCommand(Maze* maze) : maze_(maze) {}
  void execute() override {
    maze_->clear();
    maze_->generateMaze(10, 10);
  }

 private:
  Maze* maze_;
};
}  // namespace s21

#endif  // MAZE_CORE_COMMANDS_GENERATE_MAZE_COMMAND_H_