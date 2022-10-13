#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node* next;
};

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void printList(Node *node)
{
	while (node!=NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
}

Node* mergeSLL(struct Node* a, struct Node* b)
{
    Node* result = NULL;
 
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    if (a->data <= b->data) {
        result = a;
        result->next = mergeSLL(a->next, b);
    }
    else {
        result = b;
        result->next = mergeSLL(a, b->next);
    }
    return (result);
}
 
void removeDuplicates(Node* head)
{
    Node* current = head;

    Node* next_next;
 
    if (current == NULL)
        return;
 
    while (current->next != NULL) {
 
        if (current->data == current->next->data) {
 
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else 
        {
            current = current->next;
        }
    }
}
 
Node* mergeWithoutDuplicates(Node* head1, Node* head2)
{
    Node* head = mergeSLL(head1, head2);
 
    removeDuplicates(head);
 
    return head;
}

int main()
{
	Node* res = NULL;
	Node* a = NULL;
	Node* b = NULL;

	push(&a, 15);
	push(&a, 10);
	push(&a, 10);
	push(&a, 6);
	push(&a, 5);

	push(&b, 20);
	push(&b, 6);
    push(&b, 6);
	push(&b, 4);	
    push(&b, 2);

	res = mergeWithoutDuplicates(a, b);

	cout << "Merged Linked List is: \n";
	printList(res);

	return 0;
}
