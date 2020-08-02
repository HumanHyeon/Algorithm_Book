//When Push Stack, Put in FIFO(Queue) order

#include <iostream>
#include <stack>
using namespace std;

template<class T>
class StackToQue {
private:
	stack<T> insteadQue;
public:
	void push(T input) {
		stack<T> tmp;

		while (!insteadQue.empty()) {
			tmp.push(insteadQue.top());
			insteadQue.pop();
		}
		tmp.push(input);
		while (!tmp.empty()) {
			insteadQue.push(tmp.top());
			tmp.pop();
		}
	}
	T pop(void) {
		T output = insteadQue.top();
		insteadQue.pop();
		return output;
	}
};

int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);

	StackToQue<int> stq;
	for (int i = 0; i < size; i++)	stq.push(arr[i]);
	for (int i = 0; i < size; i++)	cout << stq.pop() << " ";
	putchar('\n'); 
}
