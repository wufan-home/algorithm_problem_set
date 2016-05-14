#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;

static bool Compare(const pair<int, int> l, const pair<int, int> r)
{
	return l.first <= r.first;
}

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> r;
        if(nums.size() < 2)
		return r;

	if(nums.size() == 2)
	{
		r.push_back(0);
		r.push_back(1);
		return r;
	}

	vector<pair<int, int> > nums1;
	for(int i = 0; i < nums.size(); ++i)
		nums1.push_back(make_pair(nums[i], i));

	sort(nums1.begin(), nums1.end(), Compare);

	for(int start = 0, end = nums1.size() - 1; start < end;)
	{
		if(nums1[start].first + nums1[end].first == target)
		{
			r.push_back(nums1[start].second);
			r.push_back(nums1[end].second);
			sort(r.begin(), r.end());
			break;
		}
		else if(nums1[start].first + nums1[end].first > target)
			for(--end; end > start && nums1[end].first == nums1[end + 1].first; --end) {}
		else
			for(++start; start < end && nums1[start].first == nums1[start - 1].first; ++start) {}
	}

	return r;
}

vector<int> twoSum1(vector<int>& nums, int target)
{
	vector<int> rv;
	if(nums.size() < 2)
		return rv;

	if(nums.size() == 2)
	{
		rv.push_back(0);
		rv.push_back(1);
		return rv;
	}

	unordered_map<int, int> hash_map;
	for(int i = 0; i < nums.size(); ++i)
	{
		unordered_map<int, int>::iterator it = hash_map.find(target - nums[i]);
		if(it != hash_map.end())
		{
			rv.push_back(i);
			rv.push_back(it->second);
			sort(rv.begin(), rv.end());
			break;
		}

		hash_map[nums[i]] = i;
	}

	return rv;
}

int main()
{
	vector<int> nums({230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,
				337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,
				61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,
				173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,
				531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,
				652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789});
	vector<int> t = twoSum1(nums, 542);
	cout << t[0] << ", " << t[1] << endl;
	return 1;
}
