public class Nqueens {
	int n;
	int[] col;
	
	Nqueens(int n) {
		this.n = n;
		this.col = new int[n+1];
		queens(0);
	}
	void queens(int i) {
		int j;
		if (promising(i))
			if (i == n) {
				for (int count = 1; count <= n; count++) System.out.print(col[count] + " ");
				System.out.println();
			}
			else
				for (j = 1; j <= n; j++) {
					col[i+1] = j;
					queens(i+1);
				}
	}
	boolean promising(int i) {
		int k = 1;
		boolean swtch = true;
		while (k < i && swtch) {
			if (col[i] == col[k] || Math.abs(col[i] - col[k]) == Math.abs(i - k))
				swtch = false;
			k++;
		}
		return swtch;
	}
	public static void main(String[] args) {
		Nqueens case_1 = new Nqueens(4);
		Nqueens case_2 = new Nqueens(5);
		Nqueens case_3 = new Nqueens(6);
	}
}
