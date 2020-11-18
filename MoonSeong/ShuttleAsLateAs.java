import java.util.Arrays;

class Solution {
    public String solution(int n, int t, int m, String[] timetable) {
        String answer = "";
        int intAnswer;
        
        Shuttle[] shuttle = new Shuttle[n];
        int lastPerson = -1;
        int shuttleCount = 0;
        int arrivalTime = 0;
        
        //int format으로 바꿈 (ex. 09:00 => 900)
        int[] intTimeTable = new int[timetable.length];
        for (int i = 0; i < timetable.length; i++)
            intTimeTable[i] = 
                1000 * (int)(timetable[i].charAt(0) - '0') + 100 * (int)(timetable[i].charAt(1) - '0') + 
                10 * (int)(timetable[i].charAt(3) - '0') + (int)(timetable[i].charAt(4) - '0');
        //오름차순 정렬
        Arrays.sort(intTimeTable);
        //Shuttle 객체 생성
        for(int i = 0; i < n; i++) { shuttle[i] = new Shuttle(m); }
        //Shuttle 순서대로 크루 태움
        for (shuttleCount = 0; shuttleCount < n; shuttleCount++) {
            //모든 크루 확인시 종료
            if (lastPerson == intTimeTable.length - 1) break;
            //버스도착시간 계산
            arrivalTime = 900; 
            arrivalTime += ((shuttleCount*t) / 60)*100; //시간
            arrivalTime += ((shuttleCount*t) % 60);     //분
            //셔틀이 꽉차지 않았고 타야할 크루가 시간내로 와있다면 태움
            while (lastPerson != intTimeTable.length - 1) {
            	if (shuttle[shuttleCount].isFull()) break;
            	if (intTimeTable[lastPerson+1] > arrivalTime) break;
                shuttle[shuttleCount].add(intTimeTable[(lastPerson+1)]);
                lastPerson++;
            }
        }
        
        //lastShuttle은 shuttleCount - 1이 됨
        if (!shuttle[shuttleCount - 1].isFull()) //arrivalTime에 타면 됨
            intAnswer = arrivalTime;
        else {                               //lastShuttle의 마지막사람보다 1분빨리 타면 됨
            intAnswer = shuttle[shuttleCount - 1].getLastPerson();
            //시간 format으로 1분뺌
            if (intAnswer % 100 == 0) intAnswer -= 41;
            else intAnswer -= 1;
        }
        
        //int to string
        answer += Integer.toString(intAnswer / 1000);
        intAnswer %= 1000;
        answer += Integer.toString(intAnswer / 100);
        intAnswer %= 100;
        answer += ":";
        answer += Integer.toString(intAnswer / 10);
        intAnswer %= 10;
        answer += Integer.toString(intAnswer);
        
        return answer;
    }
}

class Shuttle {
    int size;
    int lastIndex;
    int[] person;
    Shuttle(int size) {
        this.size = size;
        this.lastIndex = -1;
        this.person = new int[45]; // 0 < m <= 45
        for (int i = 0; i < person.length; i++) person[i] = -888;	//NULL = -888
    }
    void add(int time) { if (!isFull()) person[++lastIndex] = time; }
    int getLastPerson() { return person[lastIndex]; }
    boolean isFull() { return (lastIndex+1) == size; }
}
