#include <string>
#include <algorithm>
using namespace std;

string solution(string new_id) {   
    //step 1
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    
    //step 2
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')    continue;
        else if (new_id[i] >= 'a' && new_id[i] <= 'z')    continue;
        else if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')   continue;
        else new_id.erase(i, 1), i--;
    }

    //step 3
    string tmp = "";
    int dot = -2;
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] == '.' && new_id[i + 1] == '.')  i++;
        tmp += new_id[i];
    }
    new_id = tmp;
    
    //step 4
    if (new_id[0] == '.')    new_id = new_id.substr(1, new_id.size());
    if (new_id[new_id.size() - 1] == '.')    new_id = new_id.substr(0, new_id.size() - 1);

    //step 5
    if (new_id == "")    return "a";

    //step 6
    if (new_id.size() >= 16) new_id = new_id.substr(0, 16);

    //step 7
    if (new_id.size() <= 2) {
        char last = new_id[new_id.size() - 1];
        for( ; new_id.size() == 3; )
            new_id += last;
    }

    return new_id;
}
