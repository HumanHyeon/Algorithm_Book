https://www.acmicpc.net/problem/1074

import java.util.Scanner;

public class B1074 {
	static int N;
	static int R;
	static int C;
	static int answer;
	
	static int findSection(int halfSideSize, int y, int x) {
		int section = 0;
		
		if (R >= halfSideSize + y)
			section += 2;
		if (C >= halfSideSize + x)
			section += 1;
		return (section);
	}
	
	static void divideConquer(int sideSize, int y, int x) {
		int section;
		int oneSectionSize;
		int halfSideSize;
		
		if (sideSize == 1)		
			return ;
		
		halfSideSize = sideSize / 2;
		section = findSection(halfSideSize, y, x);
		oneSectionSize = (int)Math.pow(halfSideSize, 2);
		
		answer += (oneSectionSize * section);
		if (section == 1)
			x += halfSideSize;
		else if (section == 2)
			y += halfSideSize;
		else if (section == 3) {
			y += halfSideSize;
			x += halfSideSize;	
		}
		divideConquer(halfSideSize, y, x);
	}
	
	static void solution() {
		divideConquer((int)Math.pow(2, N), 0, 0);
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		N = scan.nextInt();
		R = scan.nextInt();
		C = scan.nextInt();
		
		answer = 0;
		solution();
		System.out.println(answer);
	}
}
