public class ShortestPathProgram {
	public static void main(String[] args) {
		final int INF = 99999;
		//testCase Info
		int n = 6;
		int[][] W = {
				{0, 2, 5, 1, INF, INF}, 
				{2, 0, 3, 2, INF, INF}, 
				{5, 3, 0, 3, 1, 5}, 
				{1, 2, 3, 0, 1, INF}, 
				{INF, INF, 1, 1, 0, 2}, 
				{INF, INF, 5, INF, 2, 0}
				};
		Edge[] setOfEdges = new Edge[n];
		//testCase Info end
		
		ShortestPathProgram s = new ShortestPathProgram();
		s.dijkstra(n, W, setOfEdges);
		
		//check
		for (int i = 0; i < setOfEdges.length - 1; i++) setOfEdges[i].show();
	}
	
	void dijkstra(int n, int[][] W, Edge[] F) {
		final int INF = 99999;
		int i; 
		int vnear = INF;
		int min;
		Edge e;
		int[] touch = new int[n];
		int[] length = new int[n];
		
		//F = empty_set;
		touch[0] = INF;
		length[0] = -1;
		for (i = 1; i < n; i++) {
			touch[i] = 0;
			length[i] = W[0][i];
		}
		
		for(int count = 0; count < n - 1; count++) {
			min = INF;
			for(i = 1; i < n; i++) {
				if ((0 <= length[i]) && (length[i] < min)) {
					min = length[i];
					vnear = i;
				}
			}
			e = new Edge(touch[vnear], vnear);
			F[count] = e;	//e를 F에 추가
			
			for(i = 1; i < n; i++)
				if (length[vnear] + W[vnear][i] < length[i]) {
					length[i] = length[vnear] + W[vnear][i];
					touch[i] = vnear;
				}
			length[vnear] = -1;
		}
	}
}

class Edge {
	private int start, end;
	
	Edge(int start, int end) { this.start = start; this.end = end; }
	void show() {
		System.out.println("Edge: Vertex(" + (start + 1) + ") - (" + (end + 1) + ")" );
	}
	
}