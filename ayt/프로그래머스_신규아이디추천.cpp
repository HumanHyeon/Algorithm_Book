#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    for (int i = 0; i < new_id.size(); ++i) {
        if (65 <= new_id[i] && 90 >= new_id[i])
            new_id[i] += 32;
        if ((97 <= new_id[i] && 122 >= new_id[i]) || (48 <= new_id[i] && 57 >= new_id[i]) || new_id[i] == 45 || new_id[i] == 95 || new_id[i] == 46)
            continue;
        new_id.erase(i, 1);
        --i;
    }

    for (int i = 1; i < new_id.size(); ++i) {
        if (new_id[i - 1] == 46 && new_id[i] == new_id[i - 1]) {
            new_id.erase(i, 1);
            --i;
        }
    }

    if (new_id[0] == 46) new_id.erase(0, 1);
    if (new_id == "") new_id = "a";
    if (new_id[new_id.size() - 1] == 46) new_id.erase(new_id.size() - 1, 1);
    if (new_id.size() >= 16) {
        new_id.erase(15);
        if (new_id[0] == 46) new_id.erase(0, 1);
        if (new_id[new_id.size() - 1] == 46) new_id.erase(new_id.size() - 1, 1);
    }
    if (new_id.size() <= 2)
        for (int i = new_id.size(); i < 3; ++i) new_id += new_id[new_id.size() - 1];

    return new_id;
}
