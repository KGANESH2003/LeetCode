class Solution {
public:
    int mergeSort(vector<int>& arr, int l, int r) {
        int cnt = 0;
        if (l >= r) return cnt;

        int mid = (l + r) / 2;
        cnt += mergeSort(arr, l, mid);
        cnt += mergeSort(arr, mid + 1, r);
        cnt += count(arr, l, mid, r);
        merge(arr, l, mid, r);
        return cnt;
    }

    int count(vector<int>& arr, int l, int mid, int r) {
        int cnt = 0;
        int right = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (right <= r && (long long)arr[i] > 2LL * arr[right]) {
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> res;
        int left = l, right = mid + 1;
        while (left <= mid && right <= r) {
            if (arr[left] <= arr[right]) {
                res.push_back(arr[left++]);
            } else {
                res.push_back(arr[right++]);
            }
        }
        while (left <= mid) res.push_back(arr[left++]);
        while (right <= r) res.push_back(arr[right++]);

        for (int i = l; i <= r; i++) {
            arr[i] = res[i - l];
        }

        return 0; // 'cnt' was unused
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
