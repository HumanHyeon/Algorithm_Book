#include <vector>
std::vector<int> solution(int brown, int yellow) { 
  for (int i = 1; i * i <= yellow; i++) if (!(yellow % i) && !(brown - (yellow / i + 2) * 2 - i * 2)) return { yellow / i + 2, i + 2 }; 
}
