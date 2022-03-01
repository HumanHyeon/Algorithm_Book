#include <iostream>
using namespace std;

int main()
{
	char input1[] = "apple";
	char input2[] = "apps";
	char input3[] = "ape";
	int Output1 = 0;
	char Output2[5] = { " ", };

	for (int i = 0; i < 5; i++) {
		if (input1[i] == input2[i] && input1[i] == input3[i] && input2[i] == input3[i]) {
			Output2[i] = input1[i];
			Output1++;
		}
	}

	cout << "Output: " << Output1 << " // "<< Output2 << endl;

	return 0;
}
