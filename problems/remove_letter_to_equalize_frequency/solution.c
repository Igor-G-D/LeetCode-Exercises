struct cell{
    char character;
    int occurrences;
    struct cell *next; 
};

typedef struct cell cell;

cell *create(void);

bool contains(cell *head, char characterChecked);
void insert(char newCharacter, cell *head);
bool checkOccurrences(int num, cell *head);
bool equalFrequency(char * word){ // this method is very brute force, I'm tackling this as a challenge to myself, probably going to try to optimize it later

    cell *head = create();
    
    int length = strlen(word);
    for(int i=0;i<length;i++) { // runs through the word and counts up the number of occurrences of each character
        if(!(contains(head, word[i]))) {
            insert(word[i], head);
        }
    }

    int numOccurrences[2]; // you can only have 2 different letters with a distinct number of occurrences for it to fall into other cases that need testing, if there is, for example, abbccc, from there being 1 a, 2 b, 3 c, you can't make their frequency equal by removing one of them.
    numOccurrences[0] = head->next->occurrences; //gets the first n of occurrences for the first character
    numOccurrences[1] = 0;

    for(cell *i=head->next;i != NULL; i = i->next) {
        if(i->occurrences != numOccurrences[0] && numOccurrences[1] == 0) { // if the second number is undefined (0), equal to the next number read
           numOccurrences[1] = i->occurrences; 
        } else if(i->occurrences != numOccurrences[0] && i->occurrences != numOccurrences[1]) {
            printf("0\n");
            return false; // if it finds a 3rd number that's different, already you know the word cannot meet the requirements
        }
    }

    if(numOccurrences[1] == 0) { // if numOccurrences[1] = 0, means all the elements have the same size
        if(numOccurrences[0] == 1) {// and if that size is 1, one can be removed and keep them all the same number of occurrences
            printf("1.1\n");
            return true;
        } else if (checkOccurrences(numOccurrences[0], head)){ // if there is only one character with that many occurences, it means that there is only one type of letter in the word. and one can be removed without making the frequency uneven
            return true;
        }
    }

    if(numOccurrences[0] == 1 || numOccurrences[1] == 1) { //if one of the elements has only one occurence, it can be removed to have the other be equal in occurrences
        printf("occurence %c %d\n", head->next->character, head->next->occurrences);
        printf("occurence %c %d\n", head->next->next->character, head->next->next->occurrences);
        printf("numOC[0] %d \n", numOccurrences[0]);
        printf("numOC[1] %d \n", numOccurrences[1]);
        if(checkOccurrences(1, head)) { // checks to see if there is only one element with 1 occurence
            printf("2\n");
            return true;
        }
    }
    if(numOccurrences[0] - numOccurrences[1] == 1 || numOccurrences[0] - numOccurrences[1] == -1) { //if there is a difference of 1 occurence, one element can be removed from the higher of the two to equalize the number of occurrences

        if(numOccurrences[0] > numOccurrences[1]) {
            if(checkOccurrences(numOccurrences[0], head)) {
                printf("3.1\n");
                return true;
            }
        } else {
            if(checkOccurrences(numOccurrences[1], head)) {
                printf("3.2\n");
                return true;
            }
        }
    }
        printf("numOC[0] %d \n", numOccurrences[0]);
        printf("numOC[1] %d \n", numOccurrences[1]);
    printf("4\n");
    return false;
}

cell *create(void) // creates the head of the linked list
{
	cell *start;

	start = (cell *) malloc(sizeof(cell));
	start->next = NULL;
	return start;
}

void insert(char newCharacter, cell *head) // inserts new characters in the start of the linked list
{
	cell *new;

	new = (cell *) malloc(sizeof(cell));
    new->character = newCharacter;
    new->next = NULL;
    new->occurrences = 1;
    if(head->next == NULL) {
        head->next = new;
    } else {
        new->next = head->next;
        head->next = new;
    }

}

bool contains(cell *head, char characterChecked)  // checks if a character is already accounted for in the linked list, and if it is, adds to the occurrences and returns true, otherwise, returns false
{
    printf("%c \n", characterChecked);
    if(head->next == NULL) {
        return false;
    } 
    for(cell *i = head->next; i != NULL; i=i->next) {
        if(i->character == characterChecked) {
            i->occurrences++;
            //printf("occurrences %c %d\n", i->character, i->occurrences);
            return true;
        }
    }
    return false;
} 

bool checkOccurrences(int num, cell *head) { // checks if there are more than one character with that number of occurrences
    int numCharacters = 0;
    for(cell *i = head->next; i != NULL; i=i->next) {
        if(i->occurrences == num) {
            numCharacters++;
        }
    }
    if(numCharacters > 1) {
        return false;
    }
    return true;
}
