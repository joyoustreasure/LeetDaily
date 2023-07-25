import numpy as np
class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        peak = np.argmax(arr)
        if len(arr)>2 and 0<peak<len(arr)-1:
            return peak
        return 0