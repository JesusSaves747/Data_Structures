package practice;

public class SortedStack<T> extends MyStack<T> {
	MyStack<T> s1;
	MyStack<T> temp;
	
	public SortedStack() {
		super(null);
		s1 = new MyStack<T>(null);
		temp = new MyStack<T>(null);	
	}
	
	@Override
	public void push(T item) {
		while(s1.top != null) {
			
			if((int)s1.top.data < (int)item) {
				T val = s1.pop();
				temp.push(val);
			}else {
				break;
				
			}
		}
		
		s1.push(item);
		
		while(temp.top != null) {
			T val = temp.pop();
			s1.push(val);
		}
	}
	
	@Override
	public T pop() {
		return s1.pop();
	}
	
	@Override
	public T peek() {
		return s1.peek();
	}
	
	@Override
	public boolean isEmpty() {
		return s1.isEmpty();
	}
}
