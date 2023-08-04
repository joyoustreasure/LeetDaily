class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        def getDate(date):
            monthlist = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
            month = int(date[:2])
            days = int(date[3:])
            return sum(monthlist[:month])+days
        s = max(getDate(arriveAlice), getDate(arriveBob))
        e = min(getDate(leaveAlice), getDate(leaveBob))
        return max(0, e-s+1)