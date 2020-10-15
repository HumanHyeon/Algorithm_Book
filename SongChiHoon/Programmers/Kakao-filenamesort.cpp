#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> files) {
    sort(files.begin(), files.end());
    vector<string> answer;

	bool intsensor = true;
    vector<string> numlist, headlist, beforeanswer;
    string vectorinput, temphead, tempnum;
    int *numpartarray = new int[files.size()];
    int size = 0;
    char temp;
    for (int i = 0; i < files.size(); i++) {
    	vectorinput = files[i];
    	for (int j = 0; j < vectorinput.size(); j++) {
    		temp = vectorinput[j];
    		if('0' <= temp && temp <= '9') {
                tempnum.push_back(temp);
                numpartarray[i]++;
    		}
    		else {
                temphead.push_back(temp);
    		}
    	}
    	numlist.push_back(tempnum);
        headlist.push_back(temphead);
    }

    int startpoint, comppoint;
    for (int i = 0; i < files.size(); i++) {
    	for (int j = i+1; j < files.size(); j++) {
    		startpoint = stoi(numlist[i]);
    		comppoint = stoi(numlist[j]);
    		if (startpoint > comppoint) {
    			string tmp = files[i];
    			numlist[i] = files[j];
    			numlist[j] = tmp;
    		}
    	}
    }
    answer = numlist;
    return answer;
}