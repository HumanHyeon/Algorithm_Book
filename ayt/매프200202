#include <iostream>
using namespace std;

void Second(int* in) {
	int fir, sec;
	fir = in[0];
	if (in[0] < in[1])
		sec = in[0];                       //fir이 sec보다 작을 경우 반복문이 끝난후 fir == sec이 되버림
	else
		sec = in[1];
	for (int i = 1; i < 5; i++) {
		if (fir < in[i]){
			if(sec < fir)
				sec = fir;
			fir = in[i];
		}
		else {
			if (sec < in[i])
				sec = in[i];
		}
	}
	if (fir == sec)
		cout << "Dose not exist";
	else
		cout << sec;
}

int main()
{
	int input[] = { 10,5,4,3,-1 };
	cout << "Input:";
	for(int i = 0; i < 5; i++)
		cout << ' ' << input[i];
	cout << "\nOutput: ";
	Second(input);

	return 0;
}
