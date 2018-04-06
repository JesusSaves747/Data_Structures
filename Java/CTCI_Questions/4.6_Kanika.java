
//finding the next successor

public Node nextNode(Node x){
	//corner case
	if(x == null)
		return x;
	
	if(x.rchild != null){
		//go right
		x = x.rchild;
		while(x.lchild != null){
			//keep going left until null
			x = x.lchild;
		}
		return x;
	}else{
		//go up until greater root

		Node parent = x.root
		while(parent != null && parent.val < x.val){
			parent = parent.root;
		}
		if(parent == null)
			return x
		else
			return parent;
	}
}