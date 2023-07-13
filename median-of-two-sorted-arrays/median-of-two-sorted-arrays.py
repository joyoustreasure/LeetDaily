class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        length= len(nums1) + len(nums2)


        m, n = len(nums1), len(nums2)
        mid = (m + n) // 2 + 1
        mid1 = mid2 = None
        i = j = 0

        for _ in range(mid):
            mid1 = mid2
            if j == n or (i != m and nums1[i] <= nums2[j]):
                mid2 = nums1[i]
                i += 1
            else:
                mid2 = nums2[j]
                j += 1
        
        return mid2 if (m + n) % 2 else (mid1 + mid2) / 2