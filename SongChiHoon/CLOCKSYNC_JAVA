import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
public class CLOCKSYNC {
    private int[] input;
    private int minValue = Integer.MAX_VALUE;
    private int[] clickNum = new int[10];
    private int[][] switches = { { 0, 1, 2 }, { 3, 7, 9, 11 }, { 4, 10, 14, 15 }, { 0, 4, 5, 6, 7 }, { 6, 7, 8, 10, 12 }, { 0, 2, 14, 15 },
            { 3, 14, 15 }, { 4, 5, 7, 14, 15 }, { 1, 2, 3, 4, 5 }, { 3, 4, 5, 9, 13 } };
 
    public CLOCKSYNC(String[] inputData) {
        input = new int[16];
        for (int i = 0; i < inputData.length; i++) {
            input[i] = Integer.parseInt(inputData[i].trim());
        }
 
        sync(0, 0);
 
        //minValue가 Integer가 가지는 MAX_VALUE와 같다는건 가능한 경우가 없다는 것.
        if (minValue == Integer.MAX_VALUE) {
            System.out.println("-1");
        } else {
            System.out.println(minValue);
        }
    }
 
    public void sync(int button, int countOfPressBtn) {
        // Base-Case 버튼이 10이면 각버튼의 경우의 수를 다 계산 => 완전탐색의 마무리지점
        if (button == 10) {
            int[] temp = new int[16];
            for (int i = 0; i < clickNum.length; i++) {
                for (int j = 0; j < switches[i].length; j++) {
                    temp[switches[i][j]] += 3 * clickNum[i];
                }
            }
 
            boolean b = true;
            for (int i = 0; i < input.length; i++) {
                if (((temp[i] + input[i]) % 12) != 0) {
                    b = false;
                    break;
                }
            }
 
            if (b) {
                if (minValue > countOfPressBtn) {
                    minValue = countOfPressBtn;
                }
            }
 
            return;
        }
 
        for (int i = 0; i < 4; i++) {
            clickNum[button] = i;
            sync(button + 1, countOfPressBtn + i);
        }
    }
 
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 
        try {
            int numOfTestCase = Integer.parseInt(br.readLine());
 
            if (numOfTestCase > 30) {
                return;
            }
 
            while ((numOfTestCase--) > 0) {
                String[] inputDatas = br.readLine().trim().split(" ");
                CLOCKSYNC c = new CLOCKSYNC(inputDatas);
            }
        } catch (NumberFormatException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
