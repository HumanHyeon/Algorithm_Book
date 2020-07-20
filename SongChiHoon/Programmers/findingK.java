class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = {};
        int[] temp = {};
        int startpoint, endpoint, target;
        for(int i = 0; i < commands.length; i++)
        {
            startpoint = commands[i][0];
            endpoint = commands[i][1];
            target = commands[i][2];

            for(int j = 0; j < endpoint - startpoint; j++)
            {
                temp[j] = array[j + startpoint];
            }
        }
        return answer;
    }
}