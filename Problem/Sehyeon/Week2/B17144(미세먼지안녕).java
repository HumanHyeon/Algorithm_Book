https://www.acmicpc.net/problem/17144

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Position {
	public int y;
	public int x;
	public int amount;
	
	Position (int y, int x, int amount){
		this.y = y;
		this.x = x;
		this.amount = amount;
	}
}

public class B17144 {	
	static int R;
	static int C;
	static int T;
	static int[][] MAP;
	static int answer;
	
	static int airCleanerY[];
	static final int dy[] = { -1, 0, 1, 0 };
	static final int dx[] = { 0, 1, 0, -1 };
	
	static void calcAllDust() {
		int sum = 0;
		
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (MAP[i][j] > 0)
					sum += MAP[i][j];
		answer = sum;
	}
	
	static void airCleanerWorking() {
		int firstY = airCleanerY[0], secondY = airCleanerY[1];
		
		for (int i = firstY; i > 0; i--)
			MAP[i][0] = MAP[i - 1][0];
		for (int i = 0; i < C - 1; i++)
			MAP[0][i] = MAP[0][i + 1];
		for (int i = 0; i < firstY; i++)
			MAP[i][C - 1] = MAP[i + 1][C - 1];
		for (int i = C - 1; i > 1; i--)
			MAP[firstY][i] = MAP[firstY][i - 1];
		MAP[firstY][0] = -1;
		MAP[firstY][1] = 0;
		
		for (int i = secondY; i < R - 1; i++)
			MAP[i][0] = MAP[i + 1][0];
		for (int i = 0; i < C - 1; i++)
			MAP[R - 1][i] = MAP[R - 1][i + 1];
		for (int i = R - 1; i > secondY; i--)
			MAP[i][C - 1] = MAP[i - 1][C - 1];
		for (int i = C - 1; i > 1; i--)
			MAP[secondY][i] = MAP[secondY][i - 1];
		MAP[secondY][0] = -1;
		MAP[secondY][1] = 0;
	}
	
	static boolean is_valid(int y, int x) {
		if (y < 0 || x < 0 || y >= R || x >= C)
			return (false);
		if (MAP[y][x] == -1)
			return (false);
		return (true);
	}
	
	static void dustDiffusion() {
		int cache[][] = new int[R][C];
		
		for (int i = 0; i < R; i++) 
			for (int j = 0; j < C; j++)
				if (MAP[i][j] > 0) {
					int amount = MAP[i][j];
					int diffusion = amount / 5;
					int area = 0;
					
					for (int flag = 0; flag < 4; flag++) {
						int ny = i + dy[flag];
						int nx = j + dx[flag];
						
						if (diffusion == 0)	break;
						if (is_valid(ny, nx)) {
							cache[ny][nx] += diffusion;
							area++;
						}
					}
					
					cache[i][j] += (amount - (diffusion * area));
				}
		MAP = cache;
	}
	
	static void solution() {
		for (int t = 0; t < T; t++) {
			dustDiffusion();
			airCleanerWorking();
		}
		calcAllDust();
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int index;
		
		st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());
		
		MAP = new int[R][C];
		airCleanerY = new int[2];
		index = 0;
		for (int i = 0; i < R; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < C; j++) {
				MAP[i][j] = Integer.parseInt(st.nextToken());			
				
				if (MAP[i][j] == -1) 		airCleanerY[index++] = i;
			}
		}
		
		answer = -1;
		solution();
		System.out.println(answer);
	}

}
