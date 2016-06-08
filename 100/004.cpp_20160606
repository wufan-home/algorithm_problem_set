#include <vector>
#include <iostream>

using namespace std;

double FindMedianAux(vector<int>& nums1, int start1, int end1,
		     vector<int>& nums2, int start2, int end2,
		     int position)
{
  if(end1 < start1)
    return double(nums2[start2 + position]);
  
  if(end2 < start2)
    return double(nums1[start1 + position]);

  int mid1 = start1 + (end1 - start1) / 2;
  int mid2 = start2 + (end2 - start2) / 2;
  
  if(nums1[mid1] > nums2[mid2])
    return FindMedianAux(nums2, start2, end2, nums1, start1, end1, position);
  
  int lower_part = mid1 - start1 + mid2 - start2 + 1;
  if(nums1[end1] <= nums2[start2]) {
    if(position <= end1 - start1)
      return nums1[start1 + position];
    else
      return nums2[start2 + position - (end1 - start1 + 1)];
  } else if(position <= 0) {
    return double(nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2]);
  } else {
    if(position >= lower_part)
      return FindMedianAux(nums1, mid1 + 1, end1, nums2, start2, end2, position - (mid1 - start1 + 1));
    else
      return FindMedianAux(nums1, start1, end1, nums2, start2, mid2 - 1, position);
  }
}

double FindMedianNumber(vector<int>& nums1, vector<int>& nums2)
{
  int m = nums1.size();
  int n = nums2.size();

  if((m + n) % 2 == 0)
    return (FindMedianAux(nums1, 0, m - 1, nums2, 0, n - 1, (m + n) / 2 - 1)
	    + FindMedianAux(nums1, 0, m - 1, nums2, 0, n - 1, (m + n) / 2)) / 2;
  else
    return FindMedianAux(nums1, 0, m - 1, nums2, 0, n - 1, (m + n) / 2);;
}

int main()
{
  //-----Test cases-----
  vector<int> nums11;
  vector<int> nums12(1, 1);
  cout << "1: " << FindMedianNumber(nums11, nums12) << endl;  //Expected: 1
  
  vector<int> nums21(1, 1);
  vector<int> nums22(1, 2);
  cout << "2: " << FindMedianNumber(nums21, nums22) << endl; //Expected: 1.5.
  
  
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
  
  return 1;
}
