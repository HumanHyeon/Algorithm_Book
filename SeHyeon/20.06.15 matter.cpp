#include <iostream>
#define UNDO "../"
#define CUR	"./"

using namespace std;

string pwd(string input) {
	string output, tmp = "", beforeSave = "";
	output = '/';
	bool calc = false;

	for (int i = 1; input[i] != NULL; i++) {
			tmp += input[i];
			
			if (input[i] == '/')	calc = true;
			else if (input[i + 1] == NULL) {
				tmp += '/';	calc = true;
			}
	
			if (calc) {
				if (tmp == UNDO)	beforeSave = "";
				else if (tmp == CUR);
				else {
					output += beforeSave;
					beforeSave = tmp;
				}
				tmp = "";	calc = false;
			}
	}
	
	output += beforeSave;
	return output;
}

int main() {
	string input;	cin >> input;
	string output = pwd(input);
	cout << output << endl;
}
