
#include <stddef.h>

int timeRequiredToBuy(int* tickets, int ticketSize, int k) {
    int secs = 0;
    int i = 0;
    while (tickets[k] != 0) {
        if (tickets[i] != 0) {
            tickets[i]--;
            secs++;
        }
        i = (i + 1) % ticketSize;
    }
    return secs;
}
