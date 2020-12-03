#include <string>
#include <vector>

bool solution(std::vector<std::string> phone_book) {
    for (auto fetch : phone_book) 
        for (auto cmpStr : phone_book) 
            if (fetch == cmpStr) continue;
            else if (fetch.find(cmpStr) == 0) return false;
    return true;
}
