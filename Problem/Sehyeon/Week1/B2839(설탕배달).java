https://www.acmicpc.net/problem/2839

import java.util.Scanner;

public class B2839 {
	static int N;
	static int answer;
	
	static void brute_force(int n, int cnt) {
		if (n == 0)
			answer = Math.min(answer, cnt);
		if (n < 3 || answer <= cnt)
			return ;
		
		brute_force(n - 5, cnt + 1);
		brute_force(n - 3, cnt + 1);
	}
	
	static void dp(int n) {
		int[] cache = new int[n + 1];
		
		cache[3] = cache[5] = 1;
		for (int i = 6; i <= n; i++) {
			if (cache[i - 3] != 0)
				cache[i] = cache[i - 3] + 1;
			if (cache[i - 5] != 0) {
				if (cache[i] == 0)
					cache[i] = cache[i - 5] + 1;
				else
					cache[i] = Math.min(cache[i], cache[i - 5] + 1);
				
			}
		}
		answer = (cache[n] != 0) ? cache[n] : -1;
	}
	
	static void solution() {
		//brute_force(N, 0);
		if (N <= 5) {
			if (N == 3 || N == 5)
				answer = 1;
			return;
		}
		dp(N);
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		N = scan.nextInt();
		
		answer = -1;
		solution();
		System.out.println(answer);
	}

}
