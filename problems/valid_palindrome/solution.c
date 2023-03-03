char toLowerCase(char a);
bool isPalindrome(char * s){
    int length = strlen(s);
    int offsetStart = 0; //offsets jump over non alphanumeric characters
    int offsetEnd = 0;
    for(int i=0;i<length; i++) { //iterates over each character in the string
        for(char*word = s+sizeof(char)*(i+offsetStart);!(((int)*word>=48 && (int)*word<=57)||((int)*word>=97 && (int)*word<=122)||((int)*word>=65 && (int)*word<=90)); word+=(sizeof(char))) { //enters this for if a non alphanumeric character is found while reading from left to right
            printf("teste\n");
            offsetStart++;
            if(offsetStart >= length) { //if the string has no alphanumeric characters, it means that it's not a palindrome
                return true;
            }
        }

        for(char*word = s+sizeof(char)*(length-1-offsetEnd-i);!(((int)*word>=48 && (int)*word<=57)||((int)*word>=97 && (int)*word<=122)||((int)*word>=65 && (int)*word<=90)); word-=(sizeof(char))) { //enters this for if a non alphanumeric character is found while reading from right to left
            offsetEnd++;
        }
        //printf("teste: %d\n", (int)s[length-i-1-offsetEnd]);
        //printf("string %s\n", s);
        //printf("offsetStart %d, %d, %c\n", i, offsetStart, tolower(s[i+offsetStart]));
        //printf("offsetEnd %d, %d, %c, %d\n", i, offsetEnd, tolower(s[(length-i-offsetEnd-1)]), ((length-i) - (offsetEnd-1)));
        if(i+offsetStart >= (length-i) - (offsetEnd)) { //if the string iterated through and the readers met in the middle, means no difference was found, and so the string is a palindrome
            printf("1\n");
            return true;
        }
        if(tolower(s[i+offsetStart]) != tolower(s[(length-i-1) - (offsetEnd)])) {
            printf("2\n");
            return false;
        }
    }
    printf("3\n");
    return true; // probably won't reach here, but if it does, means the string was iterated through
}