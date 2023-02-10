bool isValid(char * s){

    int strLength = strlen(s);
    if(strLength%2 != 0) {
        return false;
    }
    char *pile;
    pile = (char *) malloc((strLength/2)*sizeof(char));
    int topPile = -1;
    for(int i=0;i<strLength;i++) {

       if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
           topPile++;
           if(topPile == strLength/2){
               return false;
           } else {
                pile[topPile] = s[i];
           } 
        }
        else if(topPile == -1) {
            return false;
        }
        else if(s[i] == ')') {
            if(pile[topPile] != '(') {
                return false;
            }
            topPile--;
        }
        else if(s[i] == ']') {
            if(pile[topPile] != '[') {
                return false;
            }
            topPile--;
        }
        else if(s[i] == '}') {
            if(pile[topPile] != '{') {
                return false;
            }
            topPile--;
        }
    }
    if(topPile != -1) {
        return false;
    } else {
        return true;
    }

}

