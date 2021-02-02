#include <string>
#include <algorithm>
using namespace std;

string solution(string new_id) {
    //step 1
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    //step 2
    string tmp = "";
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] >= 'a' && new_id[i] <= 'z')    tmp += new_id[i];
        else if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')   tmp += new_id[i];
        else if (new_id[i] >= '0' && new_id[i] <= '9')    tmp += new_id[i];
    }
    new_id = tmp;

    //step 3
    while (true) {
        tmp = "";
        bool check = true;
        for (int i = 0; i < new_id.size(); i++) {
            if (new_id[i] == '.' && new_id[i + 1] == '.') i++, check = false;
            tmp += new_id[i];
        }
        new_id = tmp;
        if (check)   break;
    }

    //step 4
    if (new_id[0] == '.')    new_id = new_id.substr(1, new_id.size());
    if (new_id[new_id.size() - 1] == '.')    new_id = new_id.substr(0, new_id.size() - 1);

    //step 5
    if (new_id == "")    new_id = "a";

    //step 6
    if (new_id.size() >= 16) new_id = new_id.substr(0, 15);
    if (new_id[new_id.size() - 1] == '.')    new_id = new_id.substr(0, new_id.size() - 1);

    //step 7
    if (new_id.size() <= 2) {
        char last = new_id[new_id.size() - 1];
        if (new_id.size() == 1)  new_id += last, new_id += last;
        else if (new_id.size() == 2)  new_id += last;
    }

    return new_id;
}
