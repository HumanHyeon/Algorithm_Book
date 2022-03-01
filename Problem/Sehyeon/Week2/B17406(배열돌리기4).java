https://www.acmicpc.net/problem/17406

import java.util.Arrays;
import java.util.Scanner;

public class Main {
   static int N, M;
   static int K;
   static int[][] board;
   static int[][] cached;
   static String[] commands;
   static int[] permutation;
   static boolean[] visited;
   static int answer;
   
//   static void solution2(int n, int startY, int startX, int endY, int endX) {
//      int group;
//      
//      group = n / 2;
//      for (int gap = 0; gap < group; gap++) {
//         int tmp = board[startY + gap][startX + gap];
//
//         for (int i = 0; i < n - 1 - (gap * 2); i++)    
//            board[startY + gap][startX + gap + i] = board[startY + gap][startX + gap + i + 1];
//         for (int i = 0; i < n - 1 - (gap * 2); i++)
//            board[startY + gap + i][endX - gap] = board[startY + gap + i + 1][endX - gap];            
//         for (int i = 0; i < n - 1 - (gap * 2); i++)
//            board[endY - gap][endX - gap - i] = board[endY - gap][endX - gap - i - 1];               
//         for (int i = 0; i < n - 1 - (gap * 2) - 1; i++) 
//            board[endY - gap - i][startX + gap] = board[endY - gap - i - 1][startX + gap];
//
//         board[startY + gap + 1][startX + gap] = tmp;   
//      }
//   }
   
   static void cycle(int n, int startY, int startX, int endY, int endX) {
	   int group;

	   group = n / 2;
	   for (int gap = 0; gap < group; gap++) {
		   int tmp = cached[startY + gap][startX + gap];

		   for (int i = 0; i < n - 1 - (gap * 2); i++)    
			   cached[startY + gap + i][startX + gap] = cached[startY + gap + i + 1][startX + gap];
		   for (int i = 0; i < n - 1 - (gap * 2); i++)
			   cached[endY - gap][startX + gap + i] = cached[endY - gap][startX + gap + i + 1];            
		   for (int i = 0; i < n - 1 - (gap * 2); i++)
			   cached[endY - gap - i][endX - gap] = cached[endY - gap - i - 1][endX - gap];               
		   for (int i = 0; i < n - 1 - (gap * 2) - 1; i++) 
			   cached[startY + gap][endX - gap - i] = cached[startY + gap][endX - gap - i - 1];

		   cached[startY + gap][startX + gap + 1] = tmp;   
	   }
   }
   
   static void make_permutation(int depth) {
	   if (depth == K) {
		   cached = new int[N][M];
		   for (int i = 0; i < N; i++)
			   cached[i] = board[i].clone();
		   
		   for (int i = 0; i < K; i++) {
			   String[] command = commands[permutation[i]].split(" ");
			   int r, c, s;
			   
			   r = Integer.parseInt(command[0]);
			   c = Integer.parseInt(command[1]);
			   s = Integer.parseInt(command[2]);
			   cycle(s * 2 + 1, r - s - 1, c - s - 1, r + s - 1, c + s - 1);
		   }
		   
	      for (int i = 0; i < N; i++)
	    	  answer = Math.min(answer, Arrays.stream(cached[i]).sum());
	      return;
	   }

	   for (int i = 0; i < K; i++)
		   if (!visited[i]) {
			   visited[i] = true;
			   permutation[depth] = i;
			   make_permutation(depth + 1);
			   visited[i] = false;
		   }
   }
   
   static void solution() {
	   make_permutation(0);
   }
   
   
   
   public static void main(String[] args) {
      Scanner scan = new Scanner(System.in);
   
      N = scan.nextInt();
      M = scan.nextInt();
      K = scan.nextInt();
      scan.nextLine();
      
      board = new int[N][M];
      for (int i = 0; i < N; i++) {
         String[] input = scan.nextLine().split(" ");
         
         for (int j = 0; j < M; j++)
            board[i][j] = Integer.parseInt(input[j]);
      }
      
      permutation = new int[K];
      visited = new boolean[K];
      commands = new String[K];
      for (int i = 0; i < K; i++)
    	  commands[i] = scan.nextLine();
    	  //solution(s * 2 + 1, r - s - 1, c - s - 1, r + s - 1, c + s - 1);   
      
      answer = Integer.MAX_VALUE;
      solution();
      System.out.println(answer);
      
//      for (int i = 0; i < N; i++) {
//         for (int j = 0; j < M; j++)
//            System.out.print(board[i][j] + " ");
//         System.out.println();
//      }   	
      
//      answer = Integer.MAX_VALUE;
//      for (int i = 0; i < N; i++)
//    	  answer = Math.min(answer, Arrays.stream(board[i]).sum());
//      System.out.println(answer);
   }  
}
