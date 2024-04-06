#ifndef MAZE_CORE_COMMANDS_SETCOLOR_H_
#define MAZE_CORE_COMMANDS_SETCOLOR_H_

#include <iostream>
#include <memory>

#include "command.h"
#include "tinyfiledialogs.h"

namespace s21 {

class OpenFileCommand : public Command {
 public:
  void execute() override {
    const char* filterPatterns[2] = {"*.png", "*.jpg"};
    const char* filePath =
        tinyfd_openFileDialog("Open Image",    // Title
                              "",              // Default path
                              2,               // Number of filter patterns
                              filterPatterns,  // Filter patterns
                              "Image files",   // Single filter description
                              0                // Allow multiple file selection
        );

    if (filePath) {
      std::cout << "Selected file: " << filePath << std::endl;
      // Здесь вы можете сохранить путь к файлу или выполнить действия с
      // файлом
    } else {
      std::cout << "No file was selected or dialog was canceled." << std::endl;
    }
  }
};
}  // namespace s21

#endif  // MAZE_CORE_COMMANDS_SETCOLOR_H_