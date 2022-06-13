import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class algorithm {
    static int N;
    static int M;
    static int[][] A;
    static int result = 987654321;
    static final int dy[] = {-1,1,0,0};
    static final int dx[] = {0,0,-1,1};

    static void bfs() {
        Queue<int[]> q = new LinkedList<>();
        boolean visit[][] = new boolean[N][M];

        q.add(new int[]{0,0,1});
        visit[0][0] = true;

        while(!q.isEmpty()){
            int y = q.peek()[0];
            int x = q.peek()[1];
            int count = q.peek()[2];
            q.poll();

            if(y==N-1 && x==M-1){
                result = Math.min(result, count);
                break;
            }

            for(int i=0;i<4;i++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                if(A[ny][nx]==0) continue;
                if(visit[ny][nx]) continue;

                visit[ny][nx] = true;
                q.add(new int[]{ny,nx,count+1});
            }
        }
    }

    static void solution() {
        bfs();
        System.out.println(result);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        N = scan.nextInt();
        M = scan.nextInt();
        scan.nextLine();
        A = new int[N][M];

        for(int i=0;i<N;i++){
            String str = scan.nextLine();
            for(int j=0;j<M;j++){
                A[i][j] = str.charAt(j)-'0';
            }
        }

        solution();
    }
}
