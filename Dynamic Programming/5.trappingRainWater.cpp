class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        // code here
        // using dynamic programming (prefix, suffix array)
        // vector<int>pre(n+1,0);
        // vector<int>post(n+1,0);
        // for(int i =1 ; i <= n;i++){
        //     pre[i] = max(pre[i-1],arr[i-1]);
        // }
        // for(int i = n-1 ; i>= 0 ; i--){
        //     post[i] = max(post[i+1],arr[i]);
        // }
        // // for(auto x : pre)cout << x << " "; cout << endl;
        // // for(auto x : post)cout << x << " ";cout << endl;
        // long long ans =0 ;
        // for(int i =1 ; i < n-1 ; i++){
        //   int minElementOfBothSides = min(pre[i],post[i+1]);
        //   if(arr[i]<=minElementOfBothSides) ans += minElementOfBothSides - arr[i];
        // }
        // return ans;

        // optimized code with two pointers
        int leftMax = arr[0], rightMax = arr[n - 1];
        int start = 0, end = n - 1;
        long long ans = 0;
        while (start < end)
        {
            if (arr[start] <= arr[end])
            {
                if (leftMax <= arr[start])
                    leftMax = arr[start];
                else
                    ans += leftMax - arr[start];
                start++;
            }
            else
            {
                if (rightMax <= arr[end])
                    rightMax = arr[end];
                else
                    ans += rightMax - arr[end];
                end--;
            }
        }
        return ans;
    }
};