// https://www.geeksforgeeks.org/problems/find-the-highest-number2259/1

class Solution
{
public:
    int findPeakElement(vector<int> &a)
    {
        // Code here.
        int start = 0, end = a.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            // following two conditions can also be taken out from the loop and
            // can be checked explicitely
            if (mid == 0 && a[mid] > a[mid + 1])
                return a[mid];
            if (mid == a.size() - 1 && a[mid] > a[mid - 1])
                return a[mid];
            if (a[mid - 1] < a[mid] && a[mid] > a[mid + 1])
                return a[mid];
            if (a[mid - 1] > a[mid])
                end = mid - 1;
            else if (a[mid + 1] > a[mid])
                start = mid + 1;
            // this case handles multiple peaks
            else
                end = mid - 1;
        }
        return -1;
    }
};
