// 단방향 연결 리스트(Singly linked list)가 주어지면 O(n log n) 시간복잡도로 정렬하시오.



// Given a singly linked list, sort the list in O(n log n) time complexity.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void merge(vector<int>& vec, int start, int end, int middle) {
    vector<int> ret;
    int i = start, j = middle + 1, copy = 0;

    while (i <= middle && j <= end) {
        if (vec[i] < vec[j]) ret.push_back(vec[i++]);
        else if (vec[i] > vec[j]) ret.push_back(vec[j++]);
    }

    while (i <= middle) ret.push_back(vec[i++]);
    while (j <= end) ret.push_back(vec[j++]);

    for (int k = start; k < end; k++)
    {
        vec[k] = ret[copy++];
    }
}

vector<int> mergesort(vector<int>& vec, int start = 0, int end = 10){
    if(start < end) {
        int middle = (start + end) / 2;
        mergesort(vec, start, middle);
        mergesort(vec, middle+1, end);
        merge(vec, start, end, middle);
    }
    
    for (int i = 0; i < 10; i++)
    {
        cout << vec[i];
    }
    
}

int main(){
    int size = 10;

    time_t timeCur;
    srand(time(&timeCur));

    vector<int> vec, answer;

    for (int i = 0; i < size; i++)
    {
        vec.push_back(rand());
    }
    
    answer = mergesort(vec);

}