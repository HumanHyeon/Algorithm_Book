//When Pop Stack, pop in FIFO(Queue) order(put LIFO(Stack))

#include <iostream>
#include <stack>
using namespace std;

template<class T>
class StackToQue {
private:
	stack<T> insteadQue;
public:
	void push(T input) {
		insteadQue.push(input);
	}
	T pop(void) {
		stack<T> tmp;
		T output;

		while (!insteadQue.empty()) {
			tmp.push(insteadQue.top());
			insteadQue.pop();
		}
		output = tmp.top();
		tmp.pop();
		while (!tmp.empty()) {
			insteadQue.push(tmp.top());
			tmp.pop();
		}
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
