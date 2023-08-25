#include <vector>

class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        int secs = 0;
        int i = 0;
        while (tickets[k] != 0) {
            if (tickets[i] != 0) {
                tickets[i]--;
                secs++;
            }
            i = (i + 1) % tickets.size();
        }
        return secs;
    }
};
