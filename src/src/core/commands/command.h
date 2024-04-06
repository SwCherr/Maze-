#ifndef MAZE_CORE_COMMANDS_COMMAND_H_
#define MAZE_CORE_COMMANDS_COMMAND_H_

namespace s21 {
class Command {
 public:
  virtual ~Command() = default;
  virtual void execute() = 0;
};
}  // namespace s21
#endif  // MAZE_CORE_COMMANDS_COMMAND_H_