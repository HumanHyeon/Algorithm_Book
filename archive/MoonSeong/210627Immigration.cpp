/*
table[] : 각 심사대의 남은시간

time = [7, 10]

[time]: [    ]
0: 7 10
7: 7 3
10: 4 10
14: 7 6
20: 1 10	or 20: 1 0
21: 0 9	or 21: 7 -1
28: -7 2	or 28: 0 -8
30: -9 0


최적이 아닌경우: 
모든 심사가 끝났을 때 (모든 심사대(table)가 0이하),

각각 심사시간(time[i]) < 심사대가 빈시간(abs(table[i])) 인 경우
*/
