//checking binary as BST
public boolean isBinaryBST(Node root){
	
	Node result = getSubTree(root);

	if(result == null)
		return true;
	else if(result.val == Integer.MIN_VALUE)
		return false;
	else
		return true;
}

public Node getSubTree(Node root){
	if(root == null)
		return null;

	Node lCHild = getSubTree(root.left);
	Node rChild = getSubTree(root.right);

	if(lChild != null && rChild != null){
		//checking error condition
		if(lChild.val == Integer.MIN_VALUE || rChild.val = Integer.MIN_VALUE || !(lChild.val <= root.val && root.val < rChild.val)){
			root.val = Integer.MIN_VALUE;
		}
	}

	return root;

}

//====================================================

public boolean isBinaryBST(Node root){

	ArrayList<Integer> list = new ArrayList<Integer>(null);
	createList(root, list);

	return list.isSorted();
}

public void createList(Node root, LinkedList<Node> list){

	if(root == null)
		return;

	//in-order traversal
	Node head = createList(root.left);
	list.add(root.val);
	head = createList(root.right);

	return;

}
