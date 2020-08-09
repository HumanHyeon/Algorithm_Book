#include <string>
using namespace std;

int n, capacity;
int volume[100], need[100];
int cache [1001][100];
string name[100];

int pack(int capacity, int item) {
    if(item == n) return 0;
    int &ret = cache[capacity][item];
    if(ret != -1) return ret;

    ret = pack(capacity, item + 1);

    if(capacity >= volume[item]) {
        ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);

    return ret;
    }
}