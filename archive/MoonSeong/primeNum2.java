class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        // 모든 서로다른 3개의 수의 합을 구함: O(n^3)
        for (int i = 0; i < nums.length - 2; i++) 
            for (int j = i + 1; j < nums.length - 1; j++) {
                for (int k = j + 1; k < nums.length; k++) {
                    if (Solution.isPrimeNum(nums[i] + nums[j] + nums[k])) answer++;
                }
            }
        return answer;
    }
    
    static boolean isPrimeNum(int num) {
        if (num == 2) return true;
        if (num % 2 == 0) return false;
    
        for (int i = 3; i <= Math.sqrt(num); i++)
            if (num % i == 0) return false;
        //END OF LOOP
        return true;
    }
}
