class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int x, y;
        
        for (y = 1; y < ((brown + 4) / 2); y++) {
            x = (brown + 4) / 2 - y;
            if ( (x * y) == yellow + brown ) {
                answer[0] = x;
                answer[1] = y;
                break;
            }
        }
        
        
        return answer;
    }
}
