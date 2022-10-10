#include <iostream>
using namespace std;

struct Node {
    int num;
    int power;
    struct Node* next;
};
 
void createNode(int x, int y, struct Node** temp)
{
    struct Node *a, *b;
    b = *temp;
    if (b != NULL) {
        a->num = x;
        a->power = y;
        a->next = (struct Node*)malloc(sizeof(struct Node));
        a = a->next;
        a->next = NULL;
    }
    else {
        a = (struct Node*)malloc(sizeof(struct Node));
        a->num = x;
        a->power = y;
        *temp = a;
        a->next = (struct Node*)malloc(sizeof(struct Node));
        a = a->next;
        a->next = NULL;
    }
}
 
void additionPoly(struct Node* P1, struct Node* P2,
             struct Node* ans)
{
    while (P1->next && P2->next) {
        if (P1->power > P2->power) {
            ans->power = P1->power;
            ans->num = P1->num;
            P1 = P1->next;
        }
 
        else if (P1->power < P2->power) {
            ans->power = P2->power;
            ans->num = P2->num;
            P2 = P2->next;
        }
 
        else {
            ans->power = P1->power;
            ans->num = P1->num + P2->num;
            P1 = P1->next;
            P2 = P2->next;
        }
 
        ans->next
            = (struct Node*)malloc(sizeof(struct Node));
        ans = ans->next;
        ans->next = NULL;
    }
    while (P1->next || P2->next) {
        if (P1->next) {
            ans->power = P1->power;
            ans->num = P1->num;
            P1 = P1->next;
        }
        if (P2->next) {
            ans->power = P2->power;
            ans->num = P2->num;
            P2 = P2->next;
        }
        ans->next
            = (struct Node*)malloc(sizeof(struct Node));
        ans = ans->next;
        ans->next = NULL;
    }
}
 
void displayPoly(struct Node* node)
{
    while (node->next != NULL) {
        printf("%dx^%d", node->num, node->power);
        node = node->next;
        if (node->num >= 0) {
            if (node->next != NULL)
                printf("+");
        }
    }
}
 
int main()
{
    struct Node *P1 = NULL, *P2 = NULL, *ans = NULL;
 
    printf("1st Polynomial: ");
    createNode(6, 2, &P1);
    createNode(5, 1, &P1);
    createNode(3, 0, &P1);
    displayPoly(P1);
 
    printf("\n2nd Polynomial: ");
    createNode(-3, 1, &P2);
    createNode(-2, 0, &P2);
    displayPoly(P2);
 
    ans = (struct Node*)malloc(sizeof(struct Node));
 
    additionPoly(P1, P2, ans);
 
    printf("\nAdded Polynomial: ");
    displayPoly(ans);
 
    return 0;
}