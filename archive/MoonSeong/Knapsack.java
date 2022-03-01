
public class Knapsack {
	final int capacity;
	final Item[] item;
	
	//result
	private int maxprofit;
	private boolean[] resultState;
	//temp
	private boolean[] state;
	private int profit, totalweight, bound;
	
	
	Knapsack(int cp, Item[] it) {
		this.capacity = cp;
		this.item = it;
		
		this.maxprofit = 0;
		this.state = new boolean[it.length];
		this.resultState = new boolean[it.length];
		for (int i = 0; i < it.length; i++) state[i] = false;
		
		//temp
		profit = 0;
		totalweight = 0;
		bound = 0;
	}
	
	void run() {
		System.out.println("run");
		checknode(0);
	}
	
	void checknode(int index) {
		if 
		
		//case: true
		state[index] = true;
		
		
		//case: false
		state[index] = false;
		
		
		if (promising(index)) checknode(index + 1);
	}
	
	boolean promising(int index) {
		if (item[index].bound <= maxprofit) return false;
		if (item[index].totalweight >= capacity) return false;
		
		return true;
	}
	
	public static void main(String[] args) {
		final Item item[] = { 
				new Item(40, 2), 
				new Item(30, 5), 
				new Item(50, 10), 
				new Item(10, 5) 
				};
		final int capacity = 16;
		
		Knapsack testcase = new Knapsack(capacity, item);
		testcase.run();
	}	
}

class Item {
	final int value;
	final int weight;
	
	public int profit, totalweight, bound;
	
	Item(int v, int w) {
		this.value = v;
		this.weight = w;
		
	}
}
