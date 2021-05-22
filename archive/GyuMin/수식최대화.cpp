//https://programmers.co.kr/learn/courses/30/lessons/67257#qna
#include <string>
#include <vector>

using namespace std;

vector<char> symbol = { '+','-','*' };

long long cal(long long A, long long B, char sym)
{
    switch (sym)
    {
    case '+':
        return A + B;
    case '-':
        return A - B;
    case '*':
        return A * B;
  }
}

long long solution(string expression) 
{
    long long biggest = 0;

    vector<long long> num;
    vector<char> sym;

    for (int a = 0; a < 3; a++)
        for (int b = 0; b < 3; b++)
            for (int c = 0; c < 3; c++)
                if ((a == b) || (b == c) || (a == c))
                    continue;

                else
                {
                    num.clear();
                    sym.clear();

                    int head = 0;

                    for (int i = 0; i < expression.size(); i++)
                        if ((expression[i]=='+')|| (expression[i] == '-')|| (expression[i] == '*'))
                        {
                            num.push_back(stoi(expression.substr(head, i - head)));
                            sym.push_back(expression[i]);
                            head = i + 1;
                        }

                    num.push_back(stoi(expression.substr(head, expression.size() - head)));

                    for (int i = 0; i < sym.size(); i++)
                        if (sym[i] == symbol[a])
                        {
                            long long x = cal(num[i], num[i + 1], sym[i]);

                            num[i] = x;

                            num.erase(num.begin() + i + 1);
                            sym.erase(sym.begin() + i);
                            i--;
                        }
                
                    for (int i = 0; i < sym.size(); i++)
                        if (sym[i] == symbol[b])
                        {
                            long long x = cal(num[i], num[i + 1], sym[i]);

                            num[i] = x;

                            num.erase(num.begin() + i + 1);
                            sym.erase(sym.begin() + i);
                            i--;
                        }
                    
                    for (int i = 0; i < sym.size(); i++)
                        if (sym[i] == symbol[c])
                        {
                            long long x = cal(num[i], num[i + 1], sym[i]);

                            num[i] = x;

                            num.erase(num.begin() + i + 1);
                            sym.erase(sym.begin() + i);
                            i--;
                        }

                    if (abs(num[0]) > biggest)
                        biggest = abs(num[0]);
                }

    return biggest;
}
