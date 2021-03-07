#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> operand;
vector<string> num;
long long cal(string order)
{
  vector<string> temp_num = num;
  vector<char> temp_operand = operand;
  for(int i = 0 ; i<order.size() ; i++)
  {
      for(int j = 0 ; j<temp_operand.size() ; j++)
      {
          if(temp_operand[j] == order[i])
          {
              long long temp1 = stol(temp_num[j]), temp2 = stoll(temp_num[j+1]);
              temp_num.erase(temp_num.begin() + j);
              temp_num.erase(temp_num.begin() + j); 
              string temp_input;
         
              if(order[i] == '*') temp_input = to_string(temp1 * temp2);
              else if(order[i] == '-') temp_input = to_string(temp1 - temp2);
              else temp_input = to_string(temp1 + temp2);
              .
              temp_num.insert(temp_num.begin() + j, temp_input);
             
              temp_operand.erase(temp_operand.begin() + j);
              
              j--;
          }
      }
  }
  return stoll(temp_num[0]);
}
long long solution(string expression) {
  long long answer = 0;
  string temp = "";
  
  for(int i = 0 ; i<expression.size() ; i++)
  {
      if(expression[i] != '*' && expression[i] != '+' && expression[i] != '-')
      {
          temp += expression[i];
      }
      else
      {
          operand.push_back(expression[i]);
          num.push_back(temp);
          temp = "";
      }
  }
  num.push_back(temp); 
  //6가지의 경우의수 중 가장 큰 값 찾기
  long long r = abs(cal("*+-"));
  r = max(r, abs(cal("*-+")));
  r = max(r, abs(cal("+*-")));
  r = max(r, abs(cal("+-*")));
  r = max(r, abs(cal("-+*")));
  r = max(r, abs(cal("-*+")));
  answer = r;
  return answer;
}
