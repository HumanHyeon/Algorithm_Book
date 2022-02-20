https://www.acmicpc.net/problem/16935

import java.util.Scanner;

public class B16935 {
	static int N;
	static int M;
	static int R;
	static String[] commands;
	static int[][] board;
	
	static void oneOper() {
		for (int y = 0; y < N / 2; y++)
			for (int x = 0; x < M; x++) {
				int tmp = board[y][x];
				board[y][x] = board[N - 1 - y][x];
				board[N - 1 - y][x] = tmp;
			}
	}
	
	static void twoOper() {
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M / 2; x++) {
				int tmp = board[y][x];
				board[y][x] = board[y][M - 1 - x];
				board[y][M - 1 - x] = tmp;
			}
	}
	
	static void threeOper() {
		int[][] tmpBoard = new int[101][101];
		int tmp;
		
		for (int i = 0; i < N; i++)
			tmpBoard[i] = board[i].clone();
		
		for (int y = 0; y < M; y++) 
			for (int x = 0; x < N; x++) 
				board[y][x] = tmpBoard[N - x - 1][y];
		tmp = N;
		N = M;
		M = tmp;
	}
	
	static void fourOper() {
//		for (int y = 0; y < N; y++) {
//			for (int x = 0; x < y; x++) {
//				int tmp = board[y][x];
//				board[y][x] = board[x][y];
//				board[x][y] = tmp;
//			}
//		}
//		oneOper();
		
		int[][] tmpBoard = new int[101][101];
		int tmp;

		for (int i = 0; i < N; i++)
			tmpBoard[i] = board[i].clone();
		
		for (int y = 0; y < M; y++) 
			for (int x = 0; x < N; x++) 
				board[y][x] = tmpBoard[x][M - y - 1];
		tmp = N;
		N = M;
		M = tmp;
	}
	
	static void fiveOper() {
		int[][] tmpBoard = new int[101][101];

		for (int i = 0; i < N; i++)
			tmpBoard[i] = board[i].clone();
		
		final int xSize = M / 2;
		final int ySize = N / 2;
		final int x1 = 0, y1 = 0;
		final int x2 = xSize, y2 = 0;
		final int x3 = xSize, y3 = ySize;
		final int x4 = 0, y4 = ySize;
		
		for (int y = 0; y < ySize; y++)
			for (int x = 0; x < xSize; x++) 
				board[y1 + y][x1 + x] = tmpBoard[y4 + y][x4 + x];	
		for (int y = 0; y < ySize; y++)
			for (int x = 0; x < xSize; x++) 
				board[y2 + y][x2 + x] = tmpBoard[y1 + y][x1 + x];	
		for (int y = 0; y < ySize; y++)
			for (int x = 0; x < xSize; x++) 
				board[y3 + y][x3 + x] = tmpBoard[y2 + y][x2 + x];
		for (int y = 0; y < ySize; y++)
			for (int x = 0; x < xSize; x++) 
				board[y4 + y][x4 + x] = tmpBoard[y3 + y][x3 + x];
	}
	
	static void sixOper() {
		int[][] tmpBoard = new int[101][101];

		for (int i = 0; i < N; i++)
			tmpBoard[i] = board[i].clone();
		
		final int xSize = M / 2;
		final int ySize = N / 2;
		final int x1 = 0, y1 = 0;
		final int x2 = xSize, y2 = 0;
		final int x3 = xSize, y3 = ySize;
		final int x4 = 0, y4 = ySize;
		
		for (int y = 0; y < ySize; y++)
			for (int x = 0; x < xSize; x++) 
				board[y1 + y][x1 + x] = tmpBoard[y2 + y][x2 + x];
		for (int y = 0; y < ySize; y++)
			for (int x = 0; x < xSize; x++) 
				board[y2 + y][x2 + x] = tmpBoard[y3 + y][x3 + x];	
		for (int y = 0; y < ySize; y++)
			for (int x = 0; x < xSize; x++) 
				board[y3 + y][x3 + x] = tmpBoard[y4 + y][x4 + x];	
		for (int y = 0; y < ySize; y++)
			for (int x = 0; x < xSize; x++) 
				board[y4 + y][x4 + x] = tmpBoard[y1 + y][x1 + x];	
	}
	
	static void solution() {
		for (int i = 0; i < R; i++)
			switch(Integer.parseInt(commands[i])) {
			case 1:
				oneOper();
				break;
			case 2:
				twoOper();
				break;
			case 3:
				threeOper();
				break;
			case 4:
				fourOper();
				break;
			case 5:
				fiveOper();
				break;
			case 6:
				sixOper();
				break;
			}
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
	
		N = scan.nextInt();
		M = scan.nextInt();
		R = scan.nextInt();
		scan.nextLine();

		board = new int[101][101];
		for (int i = 0; i < N; i++) {
			String[] input = scan.nextLine().split(" ");
			
			for (int j = 0; j < M; j++)
				board[i][j] = Integer.parseInt(input[j]);
		}
		commands = scan.nextLine().split(" ");
		
		solution();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				System.out.print(board[i][j] + " ");
			System.out.println();
		}
	}
}
