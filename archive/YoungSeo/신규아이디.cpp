#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string new_id) {
	string answer = "";
	string s2 = "";
    // 1단계
	for(char& c:new_id)
		c=tolower(c);
	
    // 2단계
	for(char c:new_id){
		if(c!='-'&&c!='_'&&c!='.'&&!('a'<=c&&c<='z')&&!('0'<=c&&c<='9'))
			continue;
		answer.push_back(c);
	}
  
    //3단계
    for(int i = 1; i < answer.size(); ){
        if (answer[i] == '.' && answer[i - 1] == '.'){
            answer.erase(answer.begin() + i);
            continue;
        }
        else i++;
    }
    // 4단계
	if(answer[0]=='.') 
        answer=answer.substr(1);
	if(answer[answer.size()-1]=='.') 
        answer=answer.substr(0,answer.size()-1);

    // 5단계
	if(answer.empty()) answer="a";

    // 6단계
	if(answer.size()>15) 
        answer=answer.substr(0,15);
	if(answer[answer.size()-1]=='.') 
        answer=answer.substr(0,answer.size()-1);

    // 7단계
	while(answer.size()<=2) 
      answer+=answer[answer.size()-1];
	
	return answer;
}
