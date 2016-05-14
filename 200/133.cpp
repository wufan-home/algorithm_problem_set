#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	typedef UndirectedGraphNode udg;
        if(node == NULL)
		return NULL;

	udg *rnode = new udg(node->label);
	udg *r_cur = rnode;
	queue<udg *> udg_queue;
	set<udg *> finished;
	finished.insert(finished.begin(), node);
	map<udg *, udg *> old_to_new;
	old_to_new[node] = rnode;
	if(node->neighbors.empty())
		return rnode;
	else
	{
		for(int i = 0; i < node->neighbors.size(); ++i)
		{
			if(node->neighbors[i] == node)
				rnode->neighbors.push_back(rnode);
			else
			{
				rnode->neighbors.push_back(new udg(node->neighbors[i]->label));
				udg_queue.push(node->neighbors[i]);
				old_to_new[node->neighbors[i]] = *(rnode->neighbors.end() - 1);
			}
		}
			
	}

	int cur_size = udg_queue.size();
	while(cur_size)
	{
		udg *p_cur = udg_queue.front();
		udg_queue.pop();
		--cur_size;

		for(int i = 0; i < p_cur->neighbors.size(); ++i)
		{
			if(finished.find(p_cur->neighbors[i]) != finished.end())
				continue;

			if(old_to_new.find(p_cur->neighbors[i]) != old_to_new.end())
				old_to_new[p_cur].push_back(old_to_new[p_cur->neighbors[i]]);
			else
			{
				old_to_new[p_cur].push_back(new udg(p_cur->neighbors[i]->label));
				old_to_new[p_cur->neighbors[i]] = *(old_to_new[p_cur].end() - 1);
			}
		}

		finished.insert(finished.begin(), p_cur);
		if(cur_size == 0)
			cur_size = udg_queue.size();
	}
}

int main()
{
	return 1;
}
