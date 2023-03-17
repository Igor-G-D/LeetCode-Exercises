int timeRequiredToBuy(int* tickets, int ticketsSize, int k){// bruteforce solution
    int seconds = 0; 
    while(true) {
        for(int i=0;i<ticketsSize;i++) {
            if(tickets[i] == 0) { // if it's 0, skip over since it left the line
                continue;
            } else {
                tickets[i]--;
                seconds++; // if it buys a ticket, add 1 second to the counter

            }
            if(tickets[k] == 0) {
                return seconds; // if the position k is 0, already bought all the required tickers
            }
        }
    }
}