/*
  There are two sorted arrays nums1 and nums2 of size m and n respectively. 
  Find the median of the two sorted arrays. 
  The overall run time complexity should be O(log (m+n)).
*/

#include <iostream>
#include <vector>

using namespace std;

double f(const vector<int>& v1, int s1, int e1,
	 const vector<int>& v2, int s2, int e2, int k)
{
	int l1 = (e1 + 1 - s1) / 2;
	int mid1 = s1 + l1;
	int l2 = (e2 + 1 - s2) / 2;
	int mid2 = s2 + l2;

	cout << "s1 = " << s1 << ", e1 = " << e1 << ", s2 = " << s2 << ", e2 = " << e2 << endl;
	if(k <= 0)
		return 0.0;
	if(l1 <= 0)
		return v2[s2 + k - 1];
	else if(l2 <= 0)
		return v1[s1 + k - 1];
	else if(v1[mid1] < v2[mid2])
		return f(v2, s2, e2, v1, s1, e1, k);
	else
	{
		cout << mid1 << " - " << mid2 << endl;
		cout << l1 << ", " << l2 << ", " << k << endl;
		if(k == l1 + l2)
			return v1[mid1];
		else if(k > l1 + l2)
			return f(v1, mid1, e1, v2, mid2, e2, k - l1 - l2);
		else
			return f(v1, s1, mid1 - 1, v2, s2, e2, k);
	}
}

double FindMedianNumber(vector<int>& nums1, vector<int>& nums2)
{
	int l1 = nums1.size();
	int l2 = nums2.size();
	int total = l1 + l2;

	if(total % 2 == 0)
		return (f(nums1, 0, l1 - 1, nums2, 0, l2 - 1, total / 2)
			+ f(nums1, 0, l1 - 1, nums2, 0, l2 - 1, total / 2 + 1)) / 2;
	else
		return f(nums1, 0, l1 - 1, nums2, 0, l2 - 1, (l1 + l2) / 2 + 1);
}

int main()
{
	//-----Test cases-----
	/*
  vector<int> nums11;
  vector<int> nums12(1, 1);
  cout << "1: " << FindMedianNumber(nums11, nums12) << endl;  //Expected: 1
	*/

  vector<int> nums21(1, 1);
  vector<int> nums22(1, 2);
  cout << "2: " << FindMedianNumber(nums21, nums22) << endl; //Expected: 1.5.

  /*
  vector<int> nums31(4, 3);
  vector<int> nums32(4, 3);
  cout << "3: " << FindMedianNumber(nums31, nums32) << endl;  //Expected: 3.
  
  
  vector<int> nums41(2, 1);
  nums41.push_back(3);
  nums41.push_back(3);
  vector<int> nums42 = nums41;
  cout << "4: " << FindMedianNumber(nums41, nums42) << endl; //Expected: 2.
  
  vector<int> nums51(1, 1);
  nums51.push_back(3);
  vector<int> nums52(1, 2);
  nums52.push_back(4);
  cout << "5: " << FindMedianNumber(nums51, nums52) << endl; //Expected: 2.5.

  vector<int> nums61(1, 2);
  vector<int> nums62(1, 1);
  nums62.push_back(3);
  cout << "6: " << FindMedianNumber(nums61, nums62) << endl; //Expected: 2.
  
  vector<int> nums72(1, 2);
  vector<int> nums71(1, 1);
  nums71.push_back(1);
  cout << "7: " << FindMedianNumber(nums71, nums72) << endl; //Expected: 1.

  vector<int> nums81(1, 2);
  vector<int> nums82(1, 1);
  nums82.push_back(3);
  cout << "8: " << FindMedianNumber(nums81, nums82) << endl; //Expected: 2.
  
  vector<int> nums91;				
  for(int i = 1; i <= 10; ++i)
    nums91.push_back(i);

  vector<int> nums92(1, 1);
  nums92.push_back(2);
  nums92.push_back(3);
  for(int i = 11; i <= 15; ++i)
    nums92.push_back(i);

  cout << "9: " << FindMedianNumber(nums91, nums92) << endl; //Expected: 6.5

  vector<int> nums101(1, 3);
  vector<int> nums102(1, 1);
  nums102.push_back(2);
  nums102.push_back(4);
  cout << "10: " << FindMedianNumber(nums101, nums102) << endl; //Expected: 2.5

  vector<int> nums111(1, 1);
  nums111.push_back(3);
  
  vector<int> nums112(1, 2);
  nums112.push_back(4);
  for(int i = 5; i <= 7; ++i) 
    nums112.push_back(i);
  cout << "11: " << FindMedianNumber(nums111, nums112) << endl; //Expected: 4
  */
  return 1;
}
