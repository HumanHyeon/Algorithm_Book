#include <iostream>
using namespace std;

int input[] = { 3, 1, 5, 6 };

void merge(int list[], int left2, int mid2, int right2) {
    int left = left2, mid = mid2 + 1, store = left2;   //mid + 1 because mid is left maximun
    int sorted[sizeof(input) / sizeof(int)];

    while (left <= mid2 && mid <= right2) {
        if (list[left] <= list[mid])   sorted[store++] = list[left++];
        else   sorted[store++] = list[mid++];
    }

    if (left > mid2) {     //remaining right handle
        for (int i = mid; i <= right2; i++)
            sorted[store++] = list[i];
    }
    else {  //remaining left handle
        for (int i = left; i <= mid2; i++)
            sorted[store++] = list[i];
    }

    for (int i = left2; i <= right2; i++)
        list[i] = sorted[i];
}

void mergeSort(int list[], int left, int right) {
    int mid;


    if (left < right) {   //1 size is not working
        mid = (left + right) / 2;
        mergeSort(list, left, mid);
        mergeSort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

int main() {
    const int size = sizeof(input) / sizeof(int);
    mergeSort(input, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << input[i] << " ";
}
