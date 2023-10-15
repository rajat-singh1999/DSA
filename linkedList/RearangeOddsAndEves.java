package linkedList;

class Node{
    int data;
    Node next;
    public Node(int data){
        this.data = data;
    }
}

public class RearangeOddsAndEves{

    public static Node buildLL(int arr[]){
        Node head = null;
        for(int i:arr){
            head = insert(head, i);
        }
        return head;
    }

    public static Node insert(Node head, int d){
        if(head == null){
            head = new Node(d);
            return head;
        }
        else{
            Node p = head;
            while(p.next!=null){
                p = p.next;
            }
            Node newnode = new Node(d);
            p.next = newnode;
            return head;
        }
    }
    
    public static void show(Node head){
        if(head == null)
            System.out.println("Nothing to print...");
        else{
            Node temp = head;
            System.out.print("Linked List: ");
            while(temp!=null){
                System.out.print(temp.data + "->");
                temp = temp.next;
            }
            System.out.println();
        }
    }
    
    public static Node rearrange(Node head){
        if(head==null)
            System.out.println("Nothing to print...");
        else{
            Node odd = null;
            Node even = null;
            Node p = head;
            
            for(int i=0;p!=null;i++){
                if(i == 0 || i%2 == 0){
                    even = insert(even, p.data);
                }
                else{
                    odd = insert(odd,p.data);
                }
                p = p.next;
            }

            p = even;
            while(p.next!=null){
                p = p.next;
            }
            p.next = odd;
            head = even;
        }
        return head;
    }
    public static void main(String args[]){
        int arr[] = {0,1,2,3,4,5,6,7,8};
        Node head = buildLL(arr);
        show(head);
        /*
         * required output:
         * 0->2->4->6->8->1->3->5->7->
         */
        head = rearrange(head);
        show(head);
    }
}