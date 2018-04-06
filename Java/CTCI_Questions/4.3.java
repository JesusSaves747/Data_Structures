
//main function breadth first search implementation
public void treeToList(Node root){
	LinkedList[] lists = new LinkedList[];
	int count = 0;
	lists[count] = new LinkedList(root); 
	getList(root, count, lists[count]);
}

public void getList(Node root, int count, LinkedList[] lists){
	lists[count + 1] = new LinkedList(null);
	for Node node: lists[count]{
		for Node kid : node.adjacency{
			lists[count + 1].add(kid);
		}
	}

	getList(head, count+1, lists[count+1])

}

//defined inside linked list class
public void add(Node node){
	if(head == null){
		head = kid;
		tail = kid;
	}else{
		tail.next = kid;
		tail = tail.next;
	}
}

//-----------------------------------------------------
//depth first search implementation

public void treeToList(Node root){
	LinkedList[] lists = new LinkedList[];
	int count = 0;
	getList(lists, count, root);
}

public void getList(LinkedList[] lists, count, Node root){
	if(root == null)
		return;
	getList(lists, count+1,root.left);
	getList(lists, count+1, root.right);
	lists[count].add(root);
}

//add function - similar to above

