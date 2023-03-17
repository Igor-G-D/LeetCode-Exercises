#include <stdio.h>
#include <stdlib.h>

typedef struct _NodeStack{
    int value;
    struct _NodeStack *next;
} NodeStack;

typedef struct {
    int quantity;
    NodeStack *next;
} NodeStackHead;

bool isPalindrome(struct ListNode* head);
NodeStackHead *createHead(void);
NodeStack *createNode(int value);
void push(NodeStackHead **head, NodeStack *newNode);
NodeStack *pop(NodeStackHead **head);
void reset(NodeStackHead **head);
void listStack(NodeStackHead **head);

bool isPalindrome (struct ListNode *head) { 
    struct ListNode *fast = head->next; // pointer that goes through linked list 2 positions at a time
    struct ListNode *middle = head; // pointer that geos through linked lise 1 position at a time
    NodeStackHead *stack = createHead();
    int isOdd = 0;
    if(fast == NULL) {
        reset(&(stack));
        return true; // if there is only one element, means that it's a palindrome
    }
    while(fast->next != NULL) { 
        if(fast->next->next == NULL) {
            isOdd = 1;
            break;
        }
        fast = fast->next->next;
        push(&(stack), createNode(middle->val));
        middle = middle->next;

    }
    push(&(stack), createNode(middle->val));
    middle = middle->next;
    if(isOdd) {
        middle = middle->next; // if its odd, the middle needs to advance one more to skip over the middle character
    }
    
    // now with the stack containing all the elements that are in the first half, needs to test to see if it's a palindrome

    for(; middle != NULL; middle = middle->next) {
        NodeStack *temp = pop(&(stack));
        if(temp->value != middle->val) {
            reset(&(stack));
            free(temp);
            return false;
        }
        free(temp);
    }
    reset(&(stack));
    return true;




}

NodeStackHead *createHead(void) { // return the address of a new Head that points to NULL
    
    NodeStackHead* newHead = (NodeStackHead*)malloc(sizeof(NodeStackHead));
    newHead->next = NULL;
    newHead->quantity = 0;
    return newHead;
}

NodeStack *createNode(int value) {
    NodeStack* newNode = (NodeStack*)malloc(sizeof(NodeStack));
    newNode->next = NULL;
    newNode->value = value;
    return newNode;
}

void push(NodeStackHead **head, NodeStack *newNode) {
    
    if((*head)->next == NULL) {
        (*head)->next = newNode;
        (*head)->quantity++;
    } else {
        newNode->next = (*head)-> next; // makes the newNode point to the top element of the stack
        (*head)->next = newNode; // makes the head point to the newNode, making it the first element
        (*head)->quantity++;
    }
}

NodeStack *pop(NodeStackHead **head) { //pops the top element from the stack, NOTE: Does not free the removed element
    NodeStack *poppedNode;
    if((*head)->next == NULL) {
        return NULL; // the stack is empty
    } else {
        poppedNode = ((*head)->next);
        (*head)->next = ((*head)->next)->next; // makes the head skip the element that was removed from the top, can also be NULL
        poppedNode->next = NULL;
        (*head)->quantity--;
        return poppedNode;
    }
}

void reset(NodeStackHead **head) { // clears stack
    for(NodeStack *p = pop(head); p != NULL; p = pop(head)) { //iterates over the stack, popping each element until the head points to NULL
        free(p);  // frees the current element
    }
}

void listStack(NodeStackHead **head) {
    NodeStackHead *newHead = createHead(); // new head to insert the read elements
    int totalQuantity = (*head)->quantity;
    printf("There are %d elements in the stack \n", (*head)->quantity);
    for(int i=0;i<totalQuantity;i++) {
        NodeStack *poppedElement = pop(head);
        printf("- Value: %d\n", poppedElement->value);
        push(&(newHead), poppedElement); //insert the popped elements into the new head
    }
    for(int i=0;i<totalQuantity;i++) {
        NodeStack *poppedElement = pop(&newHead);
        push(head, poppedElement); //insert the popped elements back into head in the right order
    }
    free(newHead);
}
