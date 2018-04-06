package practice;

public class MyStack<T> {
	T data;
	MyStack next;
	
	public MyStack(T data) {
		this.data = data;
	}
	
	MyStack<T> top;
	
	public void push(T item) {
		MyStack<T> t = new MyStack<T>(item);
		
		if(top == null) {
			top = t;
		}else {
			t.next = top;
			top = t;
		}	
	}
	
	public T pop() throws NullPointerException {
		T value;
		if(top == null) {
			throw new NullPointerException();
		}else {
			value = top.data;
			top = top.next;
		}
		return value;
	}
	
	public T peek() {
		return top.data;
	}
	
	public boolean isEmpty() {
		return (top == null);
	}
}
