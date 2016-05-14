#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Point
{
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

static bool Compare(Point l, Point r)
{
	return (l.x < r.x || (l.x == r.x && l.y <= r.y));
}

bool Equal(Point l, Point r)
{
	return (l.x == r.x && l.y == r.y);
}

int maxPoints(vector<Point>& points)
{
	if(points.size() <= 2)
		return points.size();

	sort(points.begin(), points.end(), Compare);

	int size = points.size();
	int max_num = 0;
	for(int i = 0; i < size; ++i)
	{
		map<double, int> k_map_num;
		int same_start_num = 1;
		if(i < size - 1 && Equal(points[i], points[i + 1]))
		{
			for(++i; i < size && Equal(points[i - 1], points[i]); ++i)
				++same_start_num;
			--i;
		}
		max_num = max(max_num, same_start_num);
		k_map_num[INT_MAX] = same_start_num;

		for(int j = i + 1; j < size; ++j)
		{
			int same_end_num = 1;
			if(j < size - 1 && Equal(points[j], points[j + 1]))
			{
				for(++j; j < size && Equal(points[j - 1], points[j]); ++j)
					++same_end_num;
				--j;
			}

			if(points[j].x == points[i].x)
			{
				k_map_num[INT_MAX] += same_end_num;
				max_num = max(max_num, k_map_num[INT_MAX]);
			}
			else
			{
				double k = double(points[j].y - points[i].y) /
					double(points[j].x - points[i].x);
				if(k_map_num.find(k) == k_map_num.end())
					k_map_num[k] = same_start_num;
				
				k_map_num[k] += same_end_num;
				max_num = max(max_num, k_map_num[k]);
			}
		}
	}
	
	return max_num;
}

int main()
{
	Point a(0, 0);
	Point b(-1, -1);
	Point c(0, 0);
	vector<Point> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	cout << maxPoints(v) << endl;
	return 1;
}
