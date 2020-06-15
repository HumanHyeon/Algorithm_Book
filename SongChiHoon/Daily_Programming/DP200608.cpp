// 정수 배열이 주어지면 , 배열 안의 모든 정수의 최대 공약수(GCD)를 구하시오.

// 시간 복잡도 제한 O(n)

// Given an integer array, find the greatest common denominator of all elements.

// input: [3, 2, 1]

// output: 1

// input: [2, 4, 6, 8]

// output: 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Euclidean(int a, int b) // 호제법, 인류 최초의 알고리즘, 인터넷 공식 참고, 구하려는 수가 2개일 때만 가능.
{
	return a%b ? Euclidean(b, a%b) : b;
} // O(log n)

// int Euclidean(int a, int b, int c)
// {
//     return Euclidean(Euclidean(a, b), c);
// }

int main()
{
    vector<int> container;
    int a;    int count = 0;

    do
    {
        cin >> a;
        container.push_back(a);
        count++;
    } while (a >= 20000); // a가 2만을 넘어가면 시간 복잡도가 O(n)으로 상승
    
    sort(container.begin(), container.end());
    
    for (int i = 0; i < count; i++)
    {
        if(container[i] < container[i+1])
        {
            iter_swap(container[i], container[i+1]);
        }
        container[i+1] = Euclidean(container[i], container[i+1]);
    }

    cout << "output : " << *container.end();
}