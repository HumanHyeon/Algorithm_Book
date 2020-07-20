class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        // Vector<Integer> tempanswer = new Vector<Integer>(0, 1);
        int[] answer = {};
        // Vector<Integer> temp = new Vector<Integer>(100);
        int[] temp = new int[progresses.length];
        int day = 1;
        int num = 0;  int status = 0;
        int order = num % progresses.length;

        //  각 progresses들의 작업완료 일 구해서 temp에 대입
        do
        {
            progresses[order] += speeds[order];
            if(progresses[order] >= 100)
            {
                temp[order] = day;
                num++;
                status++;
            } else {
                day++;
                num++;
            }
        }while(status == progresses.length);

        // temp값들 중 첫째 값 부터 뒤에 값 비교, 삭제
        int count = 1;
        int answerpoint = 0;
        int[] tempanswer = new int[temp.length];

        for (int i = 0 ; i < progresses.length - 1; i++)
        {
            if(temp[i] >= temp[i+1])
            {
                count++;
                temp[i+1] = temp[i];
            } else {
                tempanswer[answerpoint] = count;
                answerpoint++;
            }
        }

        return answer;
    }
}