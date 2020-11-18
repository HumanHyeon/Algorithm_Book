#include <iostream>
using namespace std;

long long solution(int w, int h){
	int x;   //최대공약수
	long long total_square = (long long)w * (long long)h;
  
 //최대공약수 구하기
	for (int i = (w < h) ? w : h; i > 0; i--) {
		if ((w % i == 0) && (h % i == 0)) { 
			x = i;
			break;}
	}
	return total_square - x * ((w / x) + (h / x) - 1);  
}
