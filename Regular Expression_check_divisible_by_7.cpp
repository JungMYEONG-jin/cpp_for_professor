#include <regex>
// Write a regular expression to detect whether a binary number is divisible by 7
std::regex solution = std::regex("^(0|(10((0|11)(1|00))*(10|(0|11)01)|11)(01*0(0|101|1(1|00)((0|11)(1|00))*(10|(0|11)01)))*1)+$");
