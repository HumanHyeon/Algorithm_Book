
class Solution {	
    public int solution(String numbers) {
    	int answer = 0;    	
    	
    	//(string)numbers -> (int[])paper
    	int[] paper = new int[numbers.length()];
    	for (int i = 0; i < paper.length; i++) paper[i] = (int)numbers.charAt(i) - '0';

    	//Log1:
    	System.out.println("Log1: paper.length=" + paper.length);
    	
    	int[][] result = combination(paper);
    	
    	printArray(result);
    	//�� ���� �Ի�: (int)Math.pow((double)10 , (double)paper[0]);
    	
    	return answer;
    }
    
    public void printArray(int[] arr) {						//1���� �迭 ���
    	for (int i = 0; i < arr.length; i++) {
    		System.out.print("(" + arr[i] + ") ");
    	}
    }
    
    public void printArray(int[][] arr) {					//printArray() overload 1 : 2���� �迭 ���
    	//Log2:
    	System.out.println("Log2: printArray(int[][])");
    	for (int i = 0; i < arr.length; i++) {
    		printArray(arr[i]);
    		System.out.println("");
    	}
    }
    
    public int[] removeElement(int[] arr, int index) {		//index�� element�� ����
    	int[] newArr = new int[arr.length - 1]; 
    	for (int i = 0; i < arr.length; i++) {
    		if (i < index) newArr[i] = arr[i];
    		else if ( i == index) continue;
    		else newArr[i - 1] = arr[i];
    	}
    	return newArr;
    }
    
    public int[] addElement(int[] arr, int value) {			//value�� element�� �߰�
    	int[] newArr = new int[arr.length + 1];
    	for (int i = 0; i < arr.length; i++) newArr[i] = arr[i];
    	newArr[arr.length] = value;
    	
    	return newArr;
    }
    
    public int[][] addElement(int[][] arr, int[] value) {	//addElement() overload 1
    	int[][] newArr = new int[arr.length + 1][];
    	for (int i = 0; i < arr.length; i++) newArr[i] = arr[i];
    	newArr[arr.length] = value;
    	
    	return newArr;
    }
    
    public int[][] addElement(int[][] arr, int[][] value) {	//addElement() overload 2
    	int[][] newArr = new int[arr.length + value.length][];
    	for (int i = 0; i < arr.length; i++) newArr[i] = arr[i];
    	for (int i = arr.length; i < value.length; i++) newArr[i] = value[i - arr.length];
    	
    	return newArr;
    }
    
    
    
    public int[][] combination(int[] before) {		//before[3] = int paper[3]{ 0, 1, 2 }; 	
    	//���� �ݳ��� �迭
    	int[][] result = {};
    	////�ϴ� before�� ì���
    	//result = addElement(result, before);
    	
    	
    	
    	//�迭�� element�� 1���� ������� �ѹ��� Ž��
    	if (before.length > 1) {
    		for (int i = 0; i < before.length; i++) {
    			result = addElement(result, combination(removeElement(before, i)));
    			//combination(removeElement(before, i));
    			//Log3:
    	    	//System.out.print("Log3: result�� before{");
    	    	//printArray(before);
    	    	//System.out.println("}�� ì���.");
    		}
    	}
    	
    		
    	//Log4:
    	System.out.print("Log4: result�� before{");
    	printArray(before);
    	System.out.println("}�� return�ߴ�.");
    	
    	return result;	
    	
    }
}



//-----------------------------------------------------------------------------------
public class FindPrimeNumber {
	public static void main(String[] args) {
		Solution s = new Solution();
		String[] testCase = {"012"};

		for (int i = 0; i < testCase.length; i++) {
			System.out.println( "TestCase #" + (i + 1) + ": " + s.solution(testCase[i]) );
		}
	}
}
