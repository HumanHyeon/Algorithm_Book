//https://programmers.co.kr/learn/courses/30/lessons/17686?language=cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool HEADcmp(string file_a,string file_b)
{
    string a_HEAD;
    string b_HEAD;

    int i, j;

    for (i = 0; !((file_a[i] >= 48) && (file_a[i] <= 57));)
        i++;

    for (j = 0; !((file_b[j] >= 48) && (file_b[j] <= 57));)
        j++;
    
    a_HEAD = file_a.substr(0, i);
    b_HEAD = file_b.substr(0, j);

    for (int a = 0; a <= i; a++)
        a_HEAD[a] = tolower(a_HEAD[a]);

    for (int b = 0; b <= j; b++)
        b_HEAD[b] = tolower(b_HEAD[b]);

    return (a_HEAD.compare(b_HEAD) < 0);
}

bool NUMBERcmp(string file_a,string file_b)
{
    int a_NUMBER;
    int b_NUMBER;

    int i, j;

    for (i = 0; !((file_a[i] >= 48) && (file_a[i] <= 57));)
        i++;

    for (j = 0; !((file_b[j] >= 48) && (file_b[j] <= 57));)
        j++;

    a_NUMBER = stoi(file_a.substr(i));
    b_NUMBER = stoi(file_b.substr(j));

    return (a_NUMBER < b_NUMBER);
}

vector<string> solution(vector<string> files) 
{
    stable_sort(files.begin(), files.end(), NUMBERcmp);

    stable_sort(files.begin(), files.end(), HEADcmp);

    return files;
}
