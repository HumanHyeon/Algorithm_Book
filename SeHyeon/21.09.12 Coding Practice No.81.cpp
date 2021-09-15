https://programmers.co.kr/learn/courses/30/lessons/84512

const char charset[] = { 'A', 'E', 'I', 'O', 'U' };
const int expr[] = { 781, 156, 31, 6, 1 };

int solution(string word) {
    int answer = 0;

    for (int i = 0; i < word.size(); i++) {
        int index;
        
        for (index = 0; index < 5; index++)
            if (charset[index] == word[i])
                break;
        answer += (expr[i] * (index) + 1);
    }

    return answer;
}

//#include <string>
//using namespace std;

//int solution(string word) {
//    int answer = 0;
//
//    for (int i = 0; i < word.size(); i++)
//        answer += string("AEIOU").find(word[i]) * expr[i] + 1;
//    return answer;
//}
