class Bnode: 
    
    # Constructor: 
    def __init__(self, data = 0): 
        
        # Three parameters: 
        # 1. data - Value held by the node: 
        # 2. left - Left child of the node: 
        # 3. right - Right child of the node: 
        self.data = data
        self.left = None
        self.right = None
        

class BTree: 
    
    # Constructor: 
    def __init__(self, root= None): 
        
        # One parameters: 
        # 1. root - Root node of the tree 
        self.root = root