import java.util.ArrayList;

class Solution {
    public Integer[] solution(int[] answers) {
        Integer[] answer;
        int[][] answerPool = {
            {1, 2, 3, 4, 5},
            {2, 1, 2, 3, 2, 4, 2, 5},
            {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
        };
        int[] score = {0, 0, 0};
        int maxIndex;
        
        ArrayList<Integer> answerList = new ArrayList<>();
		
        
        // score 계산
        for (int i = 0; i < answers.length; i++) {
            for (int person = 0; person < 3; person++) {
                if (answerPool[person][i % (answerPool[person].length)] == answers[i]) score[person]++;
                System.out.println("TEST: i=" + i + " person=" + person);
            }
        }
        
        maxIndex = 0;
        for (int person = 1; person < 3; person++)
            if (score[maxIndex] < score[person]) maxIndex = person;
        
        for (int i = 0; i < 3; i ++) 
            if (score[i] == score[maxIndex]) answerList.add(i + 1);
        
        answer = answerList.toArray(new Integer[answerList.size()]);
        
        return answer;
    }
}