https://www.acmicpc.net/problem/15683

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class CCTV {
	public int y;
	public int x;
	public int flag;
	public int identify;
	
	CCTV(int y, int x, int identify){
		this.y = y;
		this.x = x;
		this.identify = identify;
	}
}

public class Main {
	static int N;
	static int M;
	static int[][] MAP;

	static CCTV[] cctv;
	static int cctvCnt;
	
	static int answer;
	
	static boolean is_valid_pos(int y, int x) {
		return (!(y < 0 || x < 0 || y >= N || x >= M));
	}
	
	static void fillCmd(int y, int x, int flag, int[][] map) {
		final int dy[] = { 0, 1, 0, -1 };	//Right Down Left Up
		final int dx[] = { 1, 0, -1, 0 };
		
		while (true) {
			if (!is_valid_pos(y, x))
				break;
			if (map[y][x] == 6)
				break;
			//System.out.println("i : " + y + " j : " + x);
			map[y][x] = -1;
			y += dy[flag];
			x += dx[flag];
		}
	}
	
	static int[][] fill_blindSpot(int[][] MAP){
		final int RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3;
		int[][] map = new int[N][M];
		
		for (int i = 0; i < N; i++)
			map[i] = MAP[i].clone();
		
		for (int i = 0; i < cctvCnt; i++) {	
			switch (cctv[i].identify){
			case 1:
				if (cctv[i].flag == 0) fillCmd(cctv[i].y, cctv[i].x, RIGHT, map);
				if (cctv[i].flag == 1) fillCmd(cctv[i].y, cctv[i].x, DOWN, map);
				if (cctv[i].flag == 2) fillCmd(cctv[i].y, cctv[i].x, LEFT, map);
				if (cctv[i].flag == 3) fillCmd(cctv[i].y, cctv[i].x, UP, map);
				break;
			case 2:
				if (cctv[i].flag == 0) {
					fillCmd(cctv[i].y, cctv[i].x, RIGHT, map);
					fillCmd(cctv[i].y, cctv[i].x, LEFT, map);
				}
				if (cctv[i].flag == 2) {
					fillCmd(cctv[i].y, cctv[i].x, UP, map);
					fillCmd(cctv[i].y, cctv[i].x, DOWN, map);
				}
				break;
			case 3:
				if (cctv[i].flag == 0) {
					fillCmd(cctv[i].y, cctv[i].x, UP, map);
					fillCmd(cctv[i].y, cctv[i].x, RIGHT, map);
				}
				if (cctv[i].flag == 1) {
					fillCmd(cctv[i].y, cctv[i].x, RIGHT, map);
					fillCmd(cctv[i].y, cctv[i].x, DOWN, map);
				}
				if (cctv[i].flag == 2) {
					fillCmd(cctv[i].y, cctv[i].x, DOWN, map);
					fillCmd(cctv[i].y, cctv[i].x, LEFT, map);
				}
				if (cctv[i].flag == 3) {
					fillCmd(cctv[i].y, cctv[i].x, LEFT, map);
					fillCmd(cctv[i].y, cctv[i].x, UP, map);
				}
				break;
			case 4:
				if (cctv[i].flag == 0) {
					fillCmd(cctv[i].y, cctv[i].x, UP, map);
					fillCmd(cctv[i].y, cctv[i].x, RIGHT, map);
					fillCmd(cctv[i].y, cctv[i].x, LEFT, map);	
				}
				if (cctv[i].flag == 1) {
					fillCmd(cctv[i].y, cctv[i].x, RIGHT, map);
					fillCmd(cctv[i].y, cctv[i].x, UP, map);
					fillCmd(cctv[i].y, cctv[i].x, DOWN, map);	
				}
				if (cctv[i].flag == 2) {
					fillCmd(cctv[i].y, cctv[i].x, DOWN, map);
					fillCmd(cctv[i].y, cctv[i].x, LEFT, map);
					fillCmd(cctv[i].y, cctv[i].x, RIGHT, map);	
				}
				if (cctv[i].flag == 3) {
					fillCmd(cctv[i].y, cctv[i].x, LEFT, map);
					fillCmd(cctv[i].y, cctv[i].x, UP, map);
					fillCmd(cctv[i].y, cctv[i].x, DOWN, map);	
				}
				break;
			case 5:
				fillCmd(cctv[i].y, cctv[i].x, RIGHT, map);
				fillCmd(cctv[i].y, cctv[i].x, UP, map);
				fillCmd(cctv[i].y, cctv[i].x, DOWN, map);	
				fillCmd(cctv[i].y, cctv[i].x, LEFT, map);	
				break;
			}
		}
		
		return (map);
	}
	
	static int count_blindSpot(int[][] map) {
		int cnt = 0;
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] == 0)
					cnt++;
		return (cnt);
	}
	
	static void solution(int depth) {
		if (depth == cctvCnt) {
			//System.out.println("test depth : " + depth);
			int[][] map = fill_blindSpot(MAP);
			answer = Math.min(answer, count_blindSpot(map));
			return;
		}
		
		switch (cctv[depth].identify) {
		case 1:
			for (int flag = 0; flag < 4; flag++) {
				cctv[depth].flag = flag;
				solution(depth + 1);
			}
			break;
		case 2:
			for (int flag = 0; flag < 4; flag += 2) {
				cctv[depth].flag = flag;
				solution(depth + 1);
			}
			break;
		case 3:
			for (int flag = 0; flag < 4; flag++) {
				cctv[depth].flag = flag;
				solution(depth + 1);	
			}
			break;
		case 4:
			for (int flag = 0; flag < 4; flag++) {
				cctv[depth].flag = flag;
				solution(depth + 1);	
			}
			break;
		case 5:
			cctv[depth].flag = 0;
			solution(depth + 1);	
			break;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		cctv = new CCTV[8];
		cctvCnt = 0;
		
		MAP = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				MAP[i][j] = Integer.parseInt(st.nextToken());
				if (MAP[i][j] >= 1 && MAP[i][j] <= 5) {
					cctv[cctvCnt++] = new CCTV(i, j, MAP[i][j]);
				}
			}
		}
		
		answer = Integer.MAX_VALUE;
		solution(0);
		System.out.println(answer);
	}
	
}
