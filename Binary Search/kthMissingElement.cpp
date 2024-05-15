// Problem Link : https://www.geeksforgeeks.org/problems/k-th-missing-element3635/1

int KthMissingElement(int a[], int n, int k)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if ((a[mid] - (mid + a[0])) < k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    // int numberOfMissing = arr[end] +  k - (arr[end] - (end + a[0]))  ;
    int numberOfMissing = k + end + a[0];
    if (numberOfMissing > a[n - 1] || numberOfMissing < a[0])
        return -1;
    return numberOfMissing;
}