class Solution {
    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        
        numberOfArea = AreaCounter(m, n, picture);
        maxSizeOfOneArea = biggestSize(picture);

        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }

    public int AreaCounter(int m, int n, int[][] picture) {
        int[] temp = new int[100];
        int tempcount = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(picture[i][j] != 0 && 
                picture[i+1][j] != picture[i][j] &&
                picture[i-1][j] != picture[i][j] &&
                picture[i][j+1] != picture[i][j] &&
                picture[i][j-1] != picture[i][j]) {
                    temp[tempcount]++;
                    tempcount++;
                } else if(picture[i][j] != 0) {
                    temp[tempcount]++;
                }
            }
        }
        return tempcount;
    }

    public int biggestSize(int[][] picture) {
        return 0;
    }
}