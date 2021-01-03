class Solution {
    int ret = 0;
    int temp[50001];
public:
    int reversePairs(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>sorted = nums;
        helper(nums, sorted, 0, n-1);
        return ret;
    }

    void helper(vector<int>& nums, vector<int>& sorted, int a, int b)
    {
        if (a>=b) return;
        int mid = a+(b-a)/2;
        helper(nums, sorted, a, mid);
        helper(nums, sorted, mid+1, b);

        for (int j=mid+1; j<=b; j++)
        {
            auto iter = upper_bound(sorted.begin()+a, sorted.begin()+mid+1, 2*(long)nums[j]);
            ret += sorted.begin()+mid+1 - iter;
        }
        // sort(sorted.begin()+a, sorted.begin()+b+1);
        int i=a, j=mid+1, p = 0;        
        while (i<=mid && j<=b)
        {
            if (sorted[i]<=sorted[j])
            {
                temp[p] = sorted[i];
                i++;
            }                
            else
            {
                temp[p] = sorted[j];
                j++;
            } 
            p++;
        }
        while (i<=mid)
        {
            temp[p] = sorted[i];
            i++;
            p++;
        }
        while (j<=b)
        {
            temp[p] = sorted[j];
            j++;
            p++;
        }
        for (int i=0; i<b-a+1; i++)
            sorted[a+i] = temp[i];
    }
};
