#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;

    string stringfromfiles;
    int numstartindex, numindexcounter, seq;
    int *numsizecounter = new int[files.size()];
    seq = 0;
    for (auto x : files) {
    	stringfromfiles = x;
    	for (int i = 0; i < stringfromfiles.size(); i++) {
    		if ('0' <= stringfromfiles[i] && stringfromfiles[i] <= '9') {
    			numstartindex = i;
    			numsizecounter[seq]++;
    		}
    	}
    	seq++;
    }
    vector




    sort(files.begin(), files.end());
    string pivot, comparison;
    do {
    	pivot = files[startpoint];
    	comparison = files[movepoint];

    	if()

    }while(comparison != files.size())












    return answer;
}

// vector<string> solution(vector<string> files) {
//     sort(files.begin(), files.end());
//     vector<string> answer;

// 	bool intsensor = true;
//     vector<string> numlist, headlist, beforeanswer;
//     string *stringarray = new string[files.size()];
//     string vectorinput, temphead, tempnum;
//     int *numpartarray = new int[files.size()];
//     int size = 0;
//     char temp;
//     for (int i = 0; i < files.size(); i++) {
//     	vectorinput = files[i];
//     	for (int j = 0; j < vectorinput.size(); j++) {
//     		temp = vectorinput[j];
//     		if('0' <= temp && temp <= '9') {
//                 tempnum.push_back(temp);
//                 numpartarray[i]++;
//     		}
//     		else {
//                 temphead.push_back(temp);
//     		}
//     	}
//     	stringarray[i] = tempnum;
//     	tempnum.clear();
//     }

//     int startpoint, comppoint;
//     for (int i = 0; i < files.size(); i++) {
//     	for (int j = i+1; j < files.size(); j++) {
//     		startpoint = stoi(stringarray[i]);
//     		comppoint = stoi(stringarray[j]);
//     		if (startpoint > comppoint) {
//     			string tmp = files[i];
//     			stringarray[i] = files[j];
//     			stringarray[j] = tmp;
//     		}
//     	}
//     }
//     int filessize = files.size();
//     answer.assign(stringarray,stringarray + filessize);
//     return answer;
// }