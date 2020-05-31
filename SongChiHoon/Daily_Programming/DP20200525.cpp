// 단방향 연결 리스트(Singly linked list)가 주어지면 O(n log n) 시간복잡도로 정렬하시오.



// Given a singly linked list, sort the list in O(n log n) time complexity.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> mergesort(vector<int>& vec, int size = 10){
    for (int i = 0; i < size; i++)
    {
        size/2;
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