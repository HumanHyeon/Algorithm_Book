
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
    	//총 값을 게산: (int)Math.pow((double)10 , (double)paper[0]);
    	
    	return answer;
    }
    
    public void printArray(int[] arr) {						//1차원 배열 출력
    	for (int i = 0; i < arr.length; i++) {
    		System.out.print("(" + arr[i] + ") ");
    	}
    }
    
    public void printArray(int[][] arr) {					//printArray() overload 1 : 2차원 배열 출력
    	//Log2:
    	System.out.println("Log2: printArray(int[][])");
    	for (int i = 0; i < arr.length; i++) {
    		printArray(arr[i]);
    		System.out.println("");
    	}
    }
    
    public int[] removeElement(int[] arr, int index) {		//index로 element를 제거
    	int[] newArr = new int[arr.length - 1]; 
    	for (int i = 0; i < arr.length; i++) {
    		if (i < index) newArr[i] = arr[i];
    		else if ( i == index) continue;
    		else newArr[i - 1] = arr[i];
    	}
    	return newArr;
    }
    
    public int[] addElement(int[] arr, int value) {			//value로 element를 추가
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
    	//최종 반납할 배열
    	int[][] result = {};
    	////일단 before를 챙긴다
    	//result = addElement(result, before);
    	
    	
    	
    	//배열의 element가 1개가 넘을경우 한번더 탐색
    	if (before.length > 1) {
    		for (int i = 0; i < before.length; i++) {
    			result = addElement(result, combination(removeElement(before, i)));
    			//combination(removeElement(before, i));
    			//Log3:
    	    	//System.out.print("Log3: result에 before{");
    	    	//printArray(before);
    	    	//System.out.println("}를 챙겼다.");
    		}
    	}
    	
    		
    	//Log4:
    	System.out.print("Log4: result에 before{");
    	printArray(before);
    	System.out.println("}를 return했다.");
    	
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
