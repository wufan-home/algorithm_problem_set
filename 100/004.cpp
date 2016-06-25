/*
  There are two sorted arrays nums1 and nums2 of size m and n respectively. 
  Find the median of the two sorted arrays. 
  The overall run time complexity should be O(log (m+n)).
  
  Solution: The key idea of the solution of this problem is to find the k-th element of the combined arries.
  If the index k is bigger or equal than the left of the new array, the left part will be discarded 
  (move the start index to the next of the middle index of the array 1), and substract the size of the discarded part.
  Else, move the end index of the array2 to the previous index of the middle index of the array2.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findKth(const vector<int>& nums1, int s1, int e1,
	const vector<int>& nums2, int s2, int e2, int k)
{
	int l1 = e1 + 1 - s1;
	int l2 = e2 + 1 - s2;

	if (l1 == 0)
		return double(nums2[s2 + k]);
	else if (l2 == 0)
		return double(nums1[s1 + k]);
	else if (k == 0)
		return min(nums1[s1], nums2[s2]);
	else
	{
		int m1 = s1 + (e1 + 1 - s1) / 2;
		int m2 = s2 + (e2 + 1 - s2) / 2;
		if (nums1[m1] > nums2[m2])
			return findKth(nums2, s2, e2, nums1, s1, e1, k);
		else if (k >= m1 - s1 + 1 + m2 - s2)
		{
			// Magic number m1 - s1 + 1 + m2 - s2:
			// Notice that k is the index of the element we need.
			// If k is larger or equal than the index of the last element ((m1 + 1 - s1) + (m2 + 1 - s2) - 1) of
			// the combined array of nums1 and nums2,
			// the left part of nums1 do not need to be considered,
			// and the index k should substract the size of this part (m1 + 1 - s1).
			return findKth(nums1, m1 + 1, e1, nums2, s2, e2, k - (m1 + 1 - s1));
		}
		else
		{
			// Since k is smaller than the last index of two array,
			// we only need to consider the combined array from start to
			// the previous index of the last index.
			return findKth(nums1, s1, e1, nums2, s2, m2 - 1, k);
		}
	}
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int l1 = nums1.size();
	int l2 = nums2.size();
	int total = l1 + l2;
	if (total % 2 == 0)
		return (findKth(nums1, 0, l1 - 1, nums2, 0, l2 - 1, total / 2 - 1)
			+ findKth(nums1, 0, l1 - 1, nums2, 0, l2 - 1, total / 2)) / 2;
	else
		return findKth(nums1, 0, l1 - 1, nums2, 0, l2 - 1, total / 2);
}

int main()
{
	//-----Test cases-----
	vector<int> nums11;
	vector<int> nums12(1, 1);
	cout << "1: " << findMedianSortedArrays(nums11, nums12) << endl;  //Expected: 1
	

	vector<int> nums21(1, 1);
	vector<int> nums22(1, 2);
	cout << "2: " << findMedianSortedArrays(nums21, nums22) << endl; //Expected: 1.5.

	vector<int> nums31(4, 3);
	vector<int> nums32(4, 3);
	cout << "3: " << findMedianSortedArrays(nums31, nums32) << endl;  //Expected: 3.
	
	vector<int> nums41(2, 1);
	nums41.push_back(3);
	nums41.push_back(3);
	vector<int> nums42 = nums41;
	cout << "4: " << findMedianSortedArrays(nums41, nums42) << endl; //Expected: 2.

	vector<int> nums51(1, 1);
	nums51.push_back(3);
	vector<int> nums52(1, 2);
	nums52.push_back(4);
	cout << "5: " << findMedianSortedArrays(nums51, nums52) << endl; //Expected: 2.5.

	vector<int> nums61(1, 2);
	vector<int> nums62(1, 1);
	nums62.push_back(3);
	cout << "6: " << findMedianSortedArrays(nums61, nums62) << endl; //Expected: 2.

	vector<int> nums72(1, 2);
	vector<int> nums71(1, 1);
	nums71.push_back(1);
	cout << "7: " << findMedianSortedArrays(nums71, nums72) << endl; //Expected: 1.

	vector<int> nums81(1, 2);
	vector<int> nums82(1, 1);
	nums82.push_back(3);
	cout << "8: " << findMedianSortedArrays(nums81, nums82) << endl; //Expected: 2.

	vector<int> nums91;
	for(int i = 1; i <= 10; ++i)
		nums91.push_back(i);
	vector<int> nums92(1, 1);
	nums92.push_back(2);
	nums92.push_back(3);
	for(int i = 11; i <= 15; ++i)
		nums92.push_back(i);
	cout << "9: " << findMedianSortedArrays(nums91, nums92) << endl; //Expected: 6.5

	vector<int> nums101(1, 3);
	vector<int> nums102(1, 1);
	nums102.push_back(2);
	nums102.push_back(4);
	cout << "10: " << findMedianSortedArrays(nums101, nums102) << endl; //Expected: 2.5

	vector<int> nums111(1, 1);
	nums111.push_back(3);

	vector<int> nums112(1, 2);
	nums112.push_back(4);
	for(int i = 5; i <= 7; ++i)
		nums112.push_back(i);
	cout << "11: " << findMedianSortedArrays(nums111, nums112) << endl; //Expected: 4
	
	return 1;
}
