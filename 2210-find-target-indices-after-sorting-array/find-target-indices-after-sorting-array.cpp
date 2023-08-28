class Solution {
public:
std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> merged;
    int leftIndex = 0, rightIndex = 0;

    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex] < right[rightIndex]) {
            merged.push_back(left[leftIndex]);
            leftIndex++;
        } else {
            merged.push_back(right[rightIndex]);
            rightIndex++;
        }
    }

    while (leftIndex < left.size()) {
        merged.push_back(left[leftIndex]);
        leftIndex++;
    }

    while (rightIndex < right.size()) {
        merged.push_back(right[rightIndex]);
        rightIndex++;
    }

    return merged;
}

// Merge Sort 함수
std::vector<int> mergeSort(const std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {
        return arr; // 기저 조건: 원소가 1개 이하면 이미 정렬된 것으로 간주
    }

    int middle = n / 2;
    std::vector<int> left(arr.begin(), arr.begin() + middle);
    std::vector<int> right(arr.begin() + middle, arr.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

  std::vector<int> targetIndices(std::vector<int>& nums, int target) {
        std::vector<int> ans;
        std::vector<int> sorted = mergeSort(nums);
        for (int i = 0; i < nums.size(); i++) {
            if (sorted[i] == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};