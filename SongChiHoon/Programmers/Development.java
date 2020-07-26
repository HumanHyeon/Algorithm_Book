import java.util.Arrays;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] daycontainer = new int[progresses.length];
        
        for (int i = 0; i < progresses.length; i++)
        {
            if((100 - progresses[i]) % speeds[i] == 0)
            {
                daycontainer[i] = (100 - progresses[i]) / speeds[i];
            }
            else
            {
                daycontainer[i] = (100 - progresses[i]) / speeds[i] + 1;
            }
                
        }
        
        int distro = 1;
        int answerpoint = 0;
        int[] tempanswer = new int[100];
        for (int i = 0; i < daycontainer.length; i++)
        {
            if(i+1 == daycontainer.length)
            {
                tempanswer[answerpoint] = distro;
                answerpoint++;
                break;
            }
            if(daycontainer[i] < daycontainer[i+1])
            {
                tempanswer[answerpoint] = distro;
                distro = 1;
                answerpoint++;
            }
            else
            {
                daycontainer[i+1] = daycontainer[i];
                distro++;
            }
        }
        
        tempanswer[answerpoint] += 1;
        
        int[] answer = Arrays.copyOf(tempanswer, answerpoint);
        return answer;
    }
}
