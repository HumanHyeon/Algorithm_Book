#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char input1[] = "ABBCD";
	char input2[] = "APPLE";
	char temp1, temp2;
	bool tf = false;

	cout << "Input: " << input1 << ", " << input2 << endl;
	cout << "Output: ";
	if (strlen(input1) != strlen(input2)) {
		cout << "False" << endl;
		return 0;
	}
	
	for (int i = 0; i < strlen(input1); i++) {
		temp1 = input1[i];
		temp2 = input2[i];
		for (int j = i+1; j < strlen(input2); j++) {
			if ((temp1 == input1[j] && temp2 == input2[j]) || (temp1 != input1[j] && temp2 != input2[j]))
				tf = true;
			else if ((temp1 == input1[j] && temp2 != input2[j]) || (temp1 != input1[j] && temp2 == input2[j]))
				tf = false;
		}
	}
	
	if (tf == true)
		cout << "True" << endl;
	else
		cout << "False" << endl;

	return 0;
}
