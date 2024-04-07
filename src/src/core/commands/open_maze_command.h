#ifndef MAZE_CORE_COMMANDS_OPENMAZECOMMAND_H_
#define MAZE_CORE_COMMANDS_OPENMAZECOMMAND_H_

#include <iostream>
#include <memory>

#include "../maze.h"
#include "command.h"
#include "tinyfiledialogs.h"

namespace s21 {

class OpenMazeCommand : public Command {
 public:
  OpenMazeCommand(Maze* maze) : maze_(maze) {}

  void execute() override {
    if (maze_) {
      const char* filter_patterns[0];
      const char* file_path =
          tinyfd_openFileDialog("Open Image",     // Title
                                "resources",      // Default path
                                0,                // Number of filter patterns
                                filter_patterns,  // Filter patterns
                                "Text files",     // Single filter description
                                0  // Allow multiple file selection
          );

      if (file_path) {
        std::cout << "Selected file: " << file_path << std::endl;
        maze_->initFromFile(file_path);
      } else {
        std::cout << "No file was selected or dialog was canceled."
                  << std::endl;
      }
    }
  }

 private:
  Maze* maze_;
};
}  // namespace s21

#endif  // MAZE_CORE_COMMANDS_OPENMAZECOMMAND_H_