#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int nums[N];

void merge(int left, int right, int mid)
{
    int left_size = mid - left + 1;
    int l[left_size + 1];
    int right_size = right - (mid + 1) + 1;
    int r[right_size + 1];

    for (int i = left, j = 0; i <= mid; i++, j++)
    {
        l[j] = nums[i];
    }

    for (int i = mid + 1, j = 0; i <= right; i++, j++)
    {
        r[j] = nums[i];
    }
    l[left_size] = INT_MAX;
    r[right_size] = INT_MAX;

    int lp = 0, rp = 0;
    for (int i = left; i <= right; i++)
    {
        if (l[lp] <= r[rp])
        {
            nums[i] = l[lp];
            lp++;
        }
        else
        {
            nums[i] = r[rp];
            rp++;
        }
    }
}

void mergeSort(int left, int right)
{
    if (left == right)
        return;

    int mid = (left + right) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    merge(left, right, mid);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    // sort(nums, nums + n);

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}