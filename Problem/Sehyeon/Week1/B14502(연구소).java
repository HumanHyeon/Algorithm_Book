https://www.acmicpc.net/problem/14502

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class B14502 {
	static int N;
	static int M;
	static int MAP[][];
	static int answer;
	
	static final int dy[] = { -1, 0, 1, 0 };	//Up Right Down Left
	static final int dx[] = { 0, 1, 0, -1 };
	static int virusCnt;
	static int[][] virusPos;
	
	static boolean is_valid(int y, int x) {
		if (y < 0 || y >= N || x < 0 || x>= M)
			return (false);
		return (true);
	}
	
	static int[][] infection(int[][] map) {
		Queue<int[]> virus = new LinkedList<>();
		int[][] infectionMap = new int[N][M];
		int y, x;
		
		for (int i = 0; i < N; i++)
			infectionMap[i] = MAP[i].clone();
		
		for (int i = 0; i < virusCnt; i++) {
			virus.add(virusPos[i]);
			
			while (!virus.isEmpty()) {
				y = virus.peek()[0];
				x = virus.peek()[1];
				virus.poll();
			
				for (int flag = 0; flag < 4; flag++) {
					int ny = y + dy[flag], nx = x + dx[flag];
					if (is_valid(ny, nx)) {
						if (infectionMap[ny][nx] == 0) {
							infectionMap[ny][nx] = 2;
							virus.add(new int[]{ny, nx});
						}
					}
				}
			}
		}
		
		
		return (infectionMap);
	}

	static void map_combination(int cnt) {
		if (cnt == 0) {
			int[][] infectionMap = infection(MAP);
			int safe = 0;
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (infectionMap[i][j] == 0) {
						safe++;
					}
				}
			}
			answer = Math.max(answer, safe);
			
			return;
		}
		
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < M; j++) {
				if (MAP[i][j] == 1 || MAP[i][j] == 2)
					continue;
				
				MAP[i][j] = 1;
				map_combination(cnt - 1);
				MAP[i][j] = 0;
			}
	}
	

	static void solution() {
		map_combination(3);
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		N = scan.nextInt();
		M = scan.nextInt();
		
		virusCnt = 0;
		virusPos = new int[10][2];
		
		MAP = new int[N][M];
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < M; j++) {
				MAP[i][j] = scan.nextInt();
				
				if (MAP[i][j] == 2) {
					virusPos[virusCnt][0] = i;
					virusPos[virusCnt][1] = j;
					virusCnt++;
				}
			}
				
		answer = 0;
		solution();
		System.out.println(answer);
	}
}
