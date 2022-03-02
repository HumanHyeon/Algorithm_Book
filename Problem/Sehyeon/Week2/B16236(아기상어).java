https://www.acmicpc.net/problem/16236

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int MAP[][];
	static int N;
	static int answer;
	
	static ArrayList<ArrayList<int[]>> position;
	static int sharkX, sharkY;
	static int sharkSize;
	static int eatenFish;
	
	static boolean is_valid(int y, int x) {
		if (y < 0 || x < 0 || y >= N || x >= N)
			return (false);
		if (MAP[y][x] > sharkSize)
			return (false);
		return (true);
	}
	
	static int[] nextFish() {
		Queue<int[]> fishList = new LinkedList<>();
		int stdDistance = Integer.MAX_VALUE;
		int y, x;
		int pos[];
		
		for (int i = 1; i < sharkSize; i++) {
			if (i >= 7)	continue;
			if (position.get(i).size() != 0) {
				for (int j = 0; j < position.get(i).size(); j++) {
					int tmpDistance = distance(sharkY, sharkX, position.get(i).get(j)[0], position.get(i).get(j)[1]);
					
					if (tmpDistance == Integer.MIN_VALUE)
						continue;
					
					if (stdDistance > tmpDistance) {
						while (!fishList.isEmpty())	fishList.poll();
						stdDistance = tmpDistance;
						fishList.add(new int[] { position.get(i).get(j)[0], position.get(i).get(j)[1], i, j });	
					}
					else if (stdDistance == tmpDistance) {
						fishList.add(new int[] { position.get(i).get(j)[0], position.get(i).get(j)[1], i, j });
					}
				}
			}
		}
		//먹을 수 있는 최단 거리 생선이 구해져있음
		
		if (fishList.isEmpty())
			return (null);
		y = fishList.peek()[0];
		x = fishList.peek()[1];
		pos = new int[] { fishList.peek()[2], fishList.peek()[3] }; 
		fishList.poll();
		while (!fishList.isEmpty()) {
			int tmpY = fishList.peek()[0];
			int tmpX = fishList.peek()[1];
			int tmpPos[] = new int[] { fishList.peek()[2], fishList.peek()[3] }; 
			fishList.poll();
			
			if (y < tmpY)	continue;
			else if (y == tmpY && x < tmpX) continue;
			y = tmpY;
			x = tmpX;
			pos = tmpPos;
		}
		
		MAP[y][x] = 0;
		position.get(pos[0]).remove(pos[1]);
		return (new int[] { y, x });
	}
	
	static int distance(int y1, int x1, int y2, int x2) {
		Queue<int[]> bfs = new LinkedList<>();
		boolean visited[][] = new boolean[N][N];
		int calcDistance = Integer.MIN_VALUE;
		
		final int dy[] = { -1, 0, 0, 1 };	//UP LEFT RIGHT DOWN
		final int dx[] = { 0, -1, 1, 0 };
		
		visited[y1][x1] = true;
		bfs.add(new int[] { y1, x1, 0 });
		while (!bfs.isEmpty()) {
			int nowY = bfs.peek()[0];
			int nowX = bfs.peek()[1];
			int nowDistance = bfs.peek()[2];
			bfs.poll();
			
			if (nowY == y2 && nowX == x2) {
				calcDistance = nowDistance;
				break;
			}
			
			for (int flag = 0; flag < 4; flag++) {
				int ny = nowY + dy[flag];
				int nx = nowX + dx[flag];

				if (is_valid(ny, nx) && !visited[ny][nx]) {
					visited[ny][nx] = true;
					bfs.add(new int[] { ny, nx, nowDistance + 1 });
				}
			}
		}
		return (calcDistance);
	}
	
	static void solution() {
		int fish[];
	
		sharkSize = 2;
		eatenFish = 0;
	
		MAP[sharkY][sharkX] = 0;
		while ((fish = nextFish()) != null) {
			answer += distance(sharkY, sharkX, fish[0], fish[1]);
			sharkY = fish[0];
			sharkX = fish[1];
			eatenFish++;
			
			if (eatenFish == sharkSize) {
				sharkSize++;
				eatenFish = 0;
			}
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		
		position = new ArrayList<>();
		for (int i = 0; i <= 6; i++)
			position.add(new ArrayList<>());
		MAP = new int[N][N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {				
				MAP[i][j] = Integer.parseInt(st.nextToken());
				if (MAP[i][j] == 1) 
					position.get(1).add(new int[] { i, j });
				else if (MAP[i][j] == 2) 
					position.get(2).add(new int[] { i, j });
				else if (MAP[i][j] == 3) 
					position.get(3).add(new int[] { i, j });
				else if (MAP[i][j] == 4) 
					position.get(4).add(new int[] { i, j });
				else if (MAP[i][j] == 5) 
					position.get(5).add(new int[] { i, j });
				else if (MAP[i][j] == 6) 
					position.get(6).add(new int[] { i, j });
				else if (MAP[i][j] == 9) {
					sharkY = i;
					sharkX = j;
				}
			}
		}
		
		answer = 0;
		solution();
		System.out.println(answer);
		br.close();
	}

}
