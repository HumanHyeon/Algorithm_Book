#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int change_min(string time) {
	int min = 0;
	min = ((time[0] - '0') * 10 + time[1] - '0') * 60;
	min += ((time[3] - '0') * 10 + time[4] - '0');
	return min;
}
string solution(int n, int t, int m, vector<string> timetable) {

	string answer = "";
	int start_time = 60 * 9;
	int answer_min;
	vector<int>timetable_min(timetable.size());
	for (int i = 0; i < timetable.size(); i++) {
		timetable_min[i] = change_min(timetable[i]);
    }
	sort(timetable_min.begin(), timetable_min.end());
	int check = 0;
	for (int z = 0; z < n; z++) {
		int max_crew = m;
		for (int i = check; i < timetable_min.size(); i++) {
			if (timetable_min[i] <= start_time) {
				max_crew--;
				check++;
				if (max_crew == 0) break;
			}
		}
		if (z == n - 1)	{
			if (max_crew == 0) { 
                answer_min = timetable_min[check - 1] - 1;
            }
			else {
                answer_min = start_time; 
            }
		}
		start_time += t;
		if (start_time >= 60 * 24) break;
	}
	answer += (answer_min / 60 / 10) + '0';
	answer += (answer_min / 60 % 10) + '0';
	answer += ':';
	answer += (answer_min % 60 / 10) + '0';
	answer += (answer_min % 60 % 10) + '0';
	return answer;
}