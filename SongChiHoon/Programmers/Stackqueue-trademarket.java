class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        boolean smallchecker = false;

        for (int i = 0; i < prices.length; i++) {
            if (searchsmall(prices, i) >= 0) {
                smallchecker = true;
            } else {
                smallchecker = false;
            }
            if (smallchecker) {
                answer[i] = searchsmall(prices, i);
            } else {
                answer[i] = prices.length - (i + 1);
            }
        }
        return answer;
    }
    public int searchsmall(int[] prices, int i) {
        int temp;
        if (i == prices.length) {
            return 0;
        }
        for (int j = i + 1; j < prices.length; j++) {
            temp = prices[j];
            if (prices[i] > temp) {
                return j - i;
            }
        }
        return -1;
    }
}