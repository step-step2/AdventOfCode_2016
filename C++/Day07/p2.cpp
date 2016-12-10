#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string line;
  int c = 0;

  std::map<std::string, bool> inBrackets{};
  std::map<std::string, bool> outBrackets{};

  while (std::getline(std::cin, line)) {
    char ch;
    bool inBrackets = false;
    bool valid = false;

    for (int i = 0; i < line.length() - 2; ++i) {
      ch = line[i];
      if (ch == '[') inBrackets = true;
      if (ch == ']') inBrackets = false;

      if (line[i] == line[i + 2] && line[i] != line[i + 1]) {
        if (inBrackets) {
          valid = false;
          break;
        }
        valid = true;
      }
    }

    if (valid) {
      std::cout << "Valid: " << line << std::endl;
      ++c;
      std::cout << std::endl;
    }
  }

  std::cout << c << std::endl;
  return 0;
}
