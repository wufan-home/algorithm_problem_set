#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool FindItinAux(unordered_map<string, vector<string> >& t_map,
		 int n, vector<string>& rv,
		 unordered_set<string>& visited)
{
	if(n == 0)
		return true;

	for(int i = 0; i < t_map[*(rv.end() - 1)].size(); ++i)
	{
		string next = t_map[*(rv.end() - 1)][i];
		if(visited.find(next) == visited.end())
		{
			rv.push_back(next);
			visited.insert(next);
			if(FindItinAux(t_map, n - 1, rv, visited))
				return true;
			rv.pop_back();
			visited.erase(next);
		}
	}

	return false;
}

vector<string> findItinerary(vector<pair<string, string> > tickets) {
	vector<string> rv;

	if(tickets.empty())
		return rv;

	unordered_map<string, vector<string> > t_map;
	for(int i = 0; i < tickets.size(); ++i)
	{
		if(t_map.find(tickets[i].first) == t_map.end())
			t_map[tickets[i].first] = vector<string>();

		t_map[tickets[i].first].push_back(tickets[i].second);
	}

	unordered_map<string, vector<string> >::iterator it = t_map.begin();
	for(; it != t_map.end(); ++it)
		sort(it->second.begin(), it->second.end());

	unordered_set<string> visited;
	rv.push_back("JFK");
	visited.insert("JFK");
	FindItinAux(t_map, tickets.size(), rv, visited);
	return rv;
}

int main()
{
	/*
	  [["TIA","AUA"],["BNE","CNS"],["CBR","ADL"],["ADL","TIA"],["JFK","CNS"],["TIA","AUA"],["AXA","ADL"],["AUA","ADL"],["EZE","TIA"],["ANU","CNS"],["AUA","BNE"],["AXA","CNS"],["ADL","CBR"],["BNE","JFK"],["AUA","CNS"],["AUA","AXA"],["CNS","AUA"],["BNE","ANU"],["ADL","AXA"],["AUA","JFK"],["TIA","CBR"],["CBR","AXA"],["AXA","CNS"],["ADL","BNE"],["BNE","AXA"],["CNS","TIA"],["JFK","CBR"],["CNS","EZE"],["JFK","AUA"],["CBR","ADL"],["ADL","AUA"],["AUA","AXA"],["BNE","CBR"],["AXA","CBR"],["CBR","BNE"],["TIA","CNS"],["AXA","ANU"],["CBR","SYD"],["TIA","BNE"],["ADL","CNS"],["CNS","TIA"],["AUA","CBR"],["ANU","BNE"],["AUA","AXA"],["CBR","BNE"],["CNS","ADL"],["AXA","TIA"],["AXA","JFK"],["AXA","CNS"],["JFK","BNE"],["EZE","JFK"],["BNE","EZE"],["CBR","AXA"],["TIA","ADL"],["CBR","JFK"],["AUA","CBR"],["CBR","EZE"],["BNE","AXA"],["AXA","CBR"],["AUA","AXA"],["CBR","TIA"],["CBR","BNE"],["CNS","ANU"],["BNE","AXA"],["BNE","AXA"],["TIA","BNE"],["JFK","CBR"],["CNS","CBR"],["CNS","AUA"],["CNS","TIA"],["AXA","CNS"],["CNS","JFK"],["EZE","AUA"],["CNS","ADL"],["AXA","CBR"],["JFK","BNE"],["AXA","BNE"],["JFK","TIA"],["AUA","AXA"],["CBR","AUA"],["BNE","CNS"],["BNE","CNS"],["ANU","AXA"],["AUA","CBR"],["CBR","AUA"],["AXA","CBR"],["TIA","AUA"],["TIA","JFK"],["EZE","AXA"],["JFK","AUA"],["ADL","TIA"],["CNS","AUA"],["CBR","JFK"],["JFK","EZE"],["AXA","CBR"]]
*/
	return 1;
}
