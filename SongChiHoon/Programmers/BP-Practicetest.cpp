#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    int MAX_NUM = 10000;
    vector<int> returns;
    int student[3] = { 0, 0, 0 };

    // 1번 수포자 정답 비교
    for (int i = 0; i < MAX_NUM; i++) {
    	if (answers[i] == (i % 5) + 1) {
    		student[0]++;
    	}
    }

    // 2번 수포자 정답 비교
    for (int i = 0; i < MAX_NUM; i++) {
    	if (i % 2 == 0) {
    		if (answers[i] == 2) {
    			student[1]++;
    		}
    	}
    	else {
	    	switch (i % 8) {
	    		case 1 :
	    			if(answers[i] == 1) {
	    				student[1]++;
                        break;
	    			}
	    		case 3 :
	    			if(answers[i] == 3) {
	    				student[1]++;
                        break;
	    			}
	    		case 5 :
	    			if(answers[i] == 4) {
	    				student[1]++;
                        break;
	    			}
	    		case 7 :
	    			if(answers[i] == 5) {
	    				student[1]++;
                        break;
	    			}
	    	}
	    }
    }

    // 3번 수포자 정답 비교
    int temparray[5] = {3, 1, 2, 4, 5};
    for (int i = 0; i < MAX_NUM; i++) {
    	int index = i % 10;
    	if(answers[i] == temparray[index/2]) {
    		student[2]++;
    	}
    }

    // 정답 횟수 비교
    int biggest = student[0];
    returns.push_back(1);
    if (biggest == student[1]) {
    	returns.push_back(2);
    }
    if (biggest == student[2]) {
    	returns.push_back(3);
    }
    if (biggest < student[1]) {
    	biggest = student[1];
    	returns.pop_back();
    	returns.push_back(2);
    }
    if (biggest < student[2]) {
    	biggest = student[2];
    	returns.pop_back();
    	returns.push_back(3);
    }

    return returns;
}