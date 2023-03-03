int strStr(char * haystack, char * needle){
    int position = 0;
    int tempPos = 0;
    int found = 0;
    for(char *word = haystack; *word != '\0'; word += sizeof(char), position++) { // iterates over each char of haystack with a new pointer
        if((strlen(haystack) - position) < strlen(needle)) { // if there isn't enough characters left in the haystack to fit the needle, the needle isn't present
            printf("1\n");
            return -1;
        }
        if(*word == *needle) {
            char * subNeedle = needle;
            char * subWord = word;
            while(*subNeedle != '\0') { // creates two new pointers and checks to see if all the chars in needle are present in subWord, a pointer to a part of haystack
                if(*subWord != *subNeedle) {
                    break;
                }
                subNeedle += sizeof(char);
                subWord += sizeof(char);
            }
            if(*subNeedle == '\0' ) {
                return position;
            }
        }
    }
    return -1;
}