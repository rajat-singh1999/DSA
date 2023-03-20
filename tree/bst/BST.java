package tree.bst;

class Node{
    int data;
    Node left;
    Node right;
    
    public Node(int d){
        data = d;
        left = right = null;
    }
}


class BinaryTree{
    
    Node root;
    
    BinaryTree(){
        root = null;
    }
    
    public void insert(int d){
        root = insertRec(root, d);
    }
    
    Node insertRec(Node root, int d){
        if(root == null){
            root = new Node(d);
            return root;
        }
        if(d<root.data){
            root.left = insertRec(root.left, d);
        }
        else if(d>=root.data)
            root.right = insertRec(root.right, d);
        
        return root;
    }
    
    void preOrder(){
        preOrderRec(root);
        System.out.println();
    }
    
    void preOrderRec(Node root){
        if(root == null)
            return;
        
        System.out.print(root.data + " ");
        preOrderRec(root.left);
        preOrderRec(root.right);
    }
    
    void inOrder(){
        inOrderRec(root);
        System.out.println();
    }
    
    void inOrderRec(Node root){
        if(root == null)
            return;
        
        inOrderRec(root.left);
        System.out.print(root.data + " ");
        inOrderRec(root.right);
    }
    
    void postOrder(){
        postOrderRec(root);
        System.out.println();
    }
    
    void postOrderRec(Node root){
        if(root == null)
            return;
        
        postOrderRec(root.left);
        postOrderRec(root.right);
        System.out.print(root.data + " ");
    }
    
    int search(int d){
        return searchRec(root, d);
    }
    
    int searchRec(Node root, int d){
        if(root == null)
            return 0;
        if(root.data == d)
            return 1;
        
        if(d < root.data)
            return searchRec(root.left, d);
        else
            return searchRec(root.right, d);
    }
    
    int minValue(Node root)
    {
        int minv = root.data;
        while (root.left != null) {
            minv = root.left.data;
            root = root.left;
        }
        return minv;
    }
  void delete(int d) { root = deleteRec(root, d); }
 
    Node deleteRec(Node root, int d)
    {
        if (root == null)
            return root;
 
        if (d < root.data)
            root.left = deleteRec(root.left, d);
        else if (d > root.data)
            root.right = deleteRec(root.right, d);
 
        else {
            if (root.left == null)
                return root.right;
            else if (root.right == null)
                return root.left;
 
       
            root.data = minValue(root.right);
 
            root.right = deleteRec(root.right, root.data);
        }
 
        return root;
    }
}

class Main{
    public static void main(String args[]){
        BinaryTree T = new BinaryTree();
        T.insert(17);
        T.insert(4);
        T.insert(2);
        T.insert(10);
        T.insert(20);
        T.insert(18);
        T.insert(22);
        T.insert(21);
        
        T.preOrder();
        T.inOrder();
        T.postOrder();
        System.out.println(T.search(221));
        
        T.preOrder();

    }
}
