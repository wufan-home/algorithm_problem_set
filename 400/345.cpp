#include <iostream>
#include <string>
#include <bitset>

using namespace std; 

string reverseVowels(string s) {
    if(s.empty())
	return s;
    
    bitset<128> vw;
    vw['a'].flip(); vw['A'].flip();
    vw['e'].flip(); vw['E'].flip();
    vw['i'].flip(); vw['I'].flip();
    vw['o'].flip(); vw['O'].flip();
    vw['u'].flip(); vw['U'].flip();
    for(int l = 0, r = s.size() - 1; l < r;)
    {
	bool l_vw = (vw[s[l]] || vw[s[l]]);
	bool r_vw = (vw[s[r]] || vw[s[r]]);
	if(l_vw && r_vw)
	    swap(s[l++], s[r--]);
	
	if(!l_vw)
	    ++l;
	
	if(!r_vw)
	    --r;
    }
    
    return s;
}

int main()
{
    cout << reverseVowels("hello") << endl;
    return 1;
}
