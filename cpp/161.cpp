/*

*/

bool IsEqual(const string& ls, int l, const string& ss, int s)
{
	for(; l < ls.size() && s < ss.size(); ++l, ++s)
	{
		if(ls[l] != ss[s])
			return false;
	}
	return true;
}

bool isOneEditDistance(string s, string t)
{
	string& ss = s.size() > t.size() ? t : s;
	string& ls = s.size() > t.size() ? s : t;
	if(ls.size() > ss.size() + 1)
		return false;

	for(int li = 0, si = 0; li < ls.size() && si < ss.size(); ++li, ++si)
	{
		if(ls[li] != ss[si])
			return IsEqual(ls, li + 1, ss, si + (1 - ls.size() + ss.size()));
	}
	
	return ls.size() != ss.size();
}
