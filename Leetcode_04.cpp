/*Method 1 : Binary Search
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median = 0;

        int n = nums1.size();
        int m = nums2.size();

        int con = (m + n) % 2;

        if(con != 0)
        {
            int t = (m + n + 1)/2;
            median =  kthElement(nums1, nums2, n, m, t);
        }

        else
        {
             int x = (m + n)/2;
             int y = x + 1;

             double a = kthElement(nums1, nums2, n, m, x);
             double b = kthElement(nums1, nums2, n, m, y);

             median = (a + b)/2;
        }

        return median;
        
    }

    int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
    {
         if(n>m){
           return kthElement(arr2, arr1, m, n, k);
       }
       
       int low = max(0, k-m); 
       int high = min(k,n);
       
       while(low <= high)
       {
           int mid1 = low + (high - low)/2;
           int mid2 = k - mid1;
           
           int l1 = mid1 == 0 ? INT_MIN : arr1[mid1 - 1];
           int l2 = mid2 == 0 ? INT_MIN : arr2[mid2 - 1];
           int r1 = mid1 == n ? INT_MAX : arr1[mid1];
           int r2 = mid2 == m ? INT_MAX : arr2[mid2];
           
           if(l1 <= r2 && l2 <= r1)
           return max(l1, l2);
           
           else if(l1 > r2)
           {
               high = mid1 - 1;
           }
           
           else
           low = mid1 + 1;
       }
        
        return 1;
    }
};
*/

/*Method 2: Priority Queue
class Solution {
    //T.C = O(m + n) log(m + n)
    //S.C = O(m + n)
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    void push_number(int num)
    {
        if((maxHeap.empty() && minHeap.empty()) || num <= maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        //rebalance the heap sizes if at any points the difference between there sizes is greater than 1
        if(minHeap.size() + 1 < maxHeap.size())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(maxHeap.size() + 1 < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if(m == 0)
        {
            int mid = (n-1)/2;
            if(n % 2 == 0)
            {
                return (nums2[mid] + nums2[mid+1]) / 2.0;
            }
            else
            {
                return nums2[mid];
            }
        }

        if(n == 0)
        {
            int mid = (m-1)/2;
            if(m % 2 == 0)
            {
                return (nums1[mid] + nums1[mid+1]) / 2.0;
            }
            else
            {
                return nums1[mid];
            }
        }

        int i = 0;
        int j = 0;
        while(i < m || j < n)
        {
            if(i < m)
            {
                push_number(nums1[i++]);
            }
            if(j < n)
            {
                push_number(nums2[j++]);
            }
        }

        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        else if(maxHeap.size() > minHeap.size())
        {
            return maxHeap.top();
        }
        else
        {
            return minHeap.top();
        }
    }
};
*/