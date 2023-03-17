/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct _NodeStack{
    int value;
    struct _NodeStack *next;
} NodeStack;
typedef struct {
    int quantity;
    NodeStack *next;
} NodeStackHead;

NodeStackHead *createStackHead(void);
NodeStack *createStackNode(int value);
void pushStack(NodeStackHead **head, NodeStack *newNode);
NodeStack *popStack(NodeStackHead **head);

bool isPalindrome(struct ListNode* head){
    NodeStackHead *stackHead = createStackHead();
    struct ListNode* middleNode = head;
    int isOdd = 0; //variable to store if the linked list has an off number of variables
    if(head->next == NULL) { //if there is only one element, it already is a palindrome, here to prevent errors when trying to access memory
        printf("a\n");
        free(stackHead);
        return true;
    }
    for(struct ListNode* fastNode = middleNode->next;fastNode->next != NULL; middleNode = middleNode->next, fastNode = fastNode->next->next) { //fast pointer iterates 2 by 2 and starts at second node, middle follows 1 by 1, and when the fast pointer reaches the end, the middle pointer should be 1 position before the middle of the linked list.
        pushStack(&(stackHead),createStackNode(middleNode->val)); // pushes elements from the start to the middle into a stack
        if(fastNode->next->next == NULL) { //means that there is an odd number of elements
            isOdd = 1;
            break;
        }
    }
    if(isOdd == 1) {
        middleNode = middleNode->next; //if the number of elements is odd, advances 1 more position to skip the element right in the middle
    } else {
        pushStack(&(stackHead), createStackNode(middleNode->val)); // pushes last element before the middle into stack, must not be done when odd becuase it'll push the element before the middle one twice
    }
    middleNode = middleNode->next; // advances middle pointer by 1 position, since it was 1 position before the middle of the list
    for(; middleNode != NULL; middleNode = middleNode->next) { // this could have been done in one for loop, but that's an optimization I'll work on later, am doing this late at night :) This iterates over the rest of the linked list, testing each element of the stack to test if it's a palindrome
        NodeStack *temp = popStack(&(stackHead)); 
        if(middleNode->val != temp->value) {
            free(temp);
            resetStack(&(stackHead));
            free(stackHead);
            return false;
        }
        free(temp);
    }
    free(stackHead); // stack should already be empty if it gets to this point
    return true;
}
void pushStack(NodeStackHead **head, NodeStack *newNode) {
    
    if((*head)->next == NULL) {
        (*head)->next = newNode;
        (*head)->quantity++;
    } else {
        newNode->next = (*head)-> next; // makes the newNode point to the top element of the stack
        (*head)->next = newNode; // makes the head point to the newNode, making it the first element
        (*head)->quantity++;
    }
}

NodeStack *popStack(NodeStackHead **head) { //pops the top element from the stack, NOTE: Does not free the removed element
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

NodeStackHead *createStackHead(void) { // return the address of a new Head that points to NULL
    
    NodeStackHead* newHead = (NodeStackHead*)malloc(sizeof(NodeStackHead));
    newHead->next = NULL;
    newHead->quantity = 0;
    return newHead;
}

NodeStack *createStackNode(int value) {
    NodeStack* newNode = (NodeStack*)malloc(sizeof(NodeStack));
    newNode->next = NULL;
    newNode->value = value;
    return newNode;
}
void resetStack(NodeStackHead **head) { // clears stack
    for(NodeStack *p = popStack(head); p != NULL; p = popStack(head)) { //iterates over the stack, popping each element until the head points to NULL
        free(p);  // frees the current element
    }
}