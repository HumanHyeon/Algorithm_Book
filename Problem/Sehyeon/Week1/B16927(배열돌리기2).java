https://www.acmicpc.net/problem/16927

import java.util.Scanner;

public class B16927 {
	static int N, M;
	static int R;
	static int[][] board;
	
	static void solution() {
		int group;
		
		group = Math.min(N, M) / 2;
		for (int gap = 0; gap < group; gap++) {
			int modR = ((N - (gap * 2)) * 2) + ((M - (gap * 2)) * 2) - 4;
			
			modR = R % modR;
			for (int cycle = 0; cycle < modR; cycle++) {
				int tmp = board[gap][gap];
				
				for (int i = 0; i < M - 1 - (gap * 2); i++) 	
					board[gap][gap + i] = board[gap][gap + i + 1];
				for (int i = 0; i < N - 1 - (gap * 2); i++)
					board[gap + i][M - 1 - gap] = board[gap + i + 1][M - 1 - gap];				
				for (int i = 0; i < M - 1 - (gap * 2); i++)
					board[N - 1 - gap][M - 1 - gap - i] = board[N - 1 - gap][M - 1 - gap - i - 1];					
				for (int i = 0; i < N - 1 - (gap * 2) - 1; i++) 
					board[N - 1 - gap - i][gap] = board[N - 1 - gap - i - 1][gap];
				
				board[gap + 1][gap] = tmp;
			}	
		}
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
	
		N = scan.nextInt();
		M = scan.nextInt();
		R = scan.nextInt();
		scan.nextLine();
		
		board = new int[N][M];
		for (int i = 0; i < N; i++) {
			String[] input = scan.nextLine().split(" ");
			
			for (int j = 0; j < M; j++)
				board[i][j] = Integer.parseInt(input[j]);
		}
		
		solution();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				System.out.print(board[i][j] + " ");
			System.out.println();
		}	
	}
}
