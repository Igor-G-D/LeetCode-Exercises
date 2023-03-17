int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize){
    int top = 0; //top of the stack
    int eaten = 0; //number of students who managed to eat sucessfully
    int preference[2] = {0,0}; //number of students with preference 0 and 1 that haven't eaten
    int iterations = 0;
    while(true){ //iterate until one of the cases is met and exits;
           for(int i=0;i<studentsSize;i++) {
            if(students[i] == 9) {
                continue; // -1 = student has already eaten, skip over
            }
            if(students[i] == sandwiches[top]) {
                sandwiches[top] = 9;
                top++;
                if(top == sandwichesSize) {
                    return 0; //if all the sandwiches have been eaten, means all students ate already;
                }
                if(iterations > 0) { // this is useful for multiple iterations over the queue of students
                    preference[students[i]]--;
                }
                students[i] = 9;
                eaten++;
            } else if (iterations == 0) { // prevents from counting each student that didn't eat more than once
                preference[students[i]]++;
            }
        }
        if(preference[0] == 0 && sandwiches[top] == 0) { // if all of this preference have eaten, and the top is of this preference, the other students won't get to their sandwich
            return preference[1];
        } else if (preference[1] == 0  && sandwiches[top] == 1) {
            return preference[0];
        }
        iterations++;
    }
    return 0;
}