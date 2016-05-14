#include <iostream>
#include <map>
#include <utility>

using namespace std;

class LRUCache{
public:
	LRUCache(int capacity) {
		m_capacity = capacity;
		m_head = NULL;
		m_tail = NULL;
	}
    
	int get(int key) {
		cout << "Get: " << key << endl;
		if(m_info_map.find(key) == m_info_map.end())
			return -1;

		UpdateFreq(m_info_map[key]);
		return m_info_map[key]->value;
	}
	
	void set(int key, int value) {
		cout << "Set: " << key << ", " << value << endl;
		if(m_info_map.find(key) != m_info_map.end())
		{
			m_info_map[key]->value = value;
			UpdateFreq(m_info_map[key]);
		}
		else
		{
			if(m_info_map.size() >= m_capacity)
			{
				cout << "Add: " << key << ", " << value << m_info_map.size() << ", " << m_capacity << endl;
				int delete_key = m_tail->key;
				RemoveNode(m_tail);
				delete m_info_map[delete_key];
				m_info_map.erase(delete_key);
			}

			m_info_map[key] = new node(key, value);
			if(m_tail)
			{
				m_tail->next = m_info_map[key];
				m_info_map[key]->prev = m_tail;
				m_tail = m_tail->next;
			}
			else
			{
				m_head = m_info_map[key];
				m_tail = m_head;
			}
			UpdateFreq(m_info_map[key]);
		}

		for(node *cur = m_head; cur != NULL; cur = cur->next)
		{
			cout << cur->key << " - " << cur->value << ", ";
			if(cur == m_tail)
			{
				if(cur->next)
					cout << "| " << cur->next->key << " - " << cur->next->value;
				break;
			}
		}
		cout << endl;
	}
private:
	struct node
	{
		int key;
		int value;

		node *prev;
		node *next;
		node(int key, int value) : key(key), value(value), prev(NULL), next(NULL) {}
	};
	void UpdateFreq(node *n)
	{
		cout << "update: " << n->key << endl;
		RemoveNode(n);
		if(n)
		{
			n->prev = NULL;
			n->next = m_head;
			if(m_head)
				m_head->prev = n;
			m_head = n;
		}
	}

	void RemoveNode(node *n)
	{
		
		if(!n)
			return;

		if(!n->prev)
		{
			m_head = m_head->next;
			if(m_head)
				m_head->prev = NULL;
			return;
		}

		cout << "Remove" << endl;
		n->prev->next = n->next;
		if(n->next)
			n->next->prev = n->prev;
		else
		{
			m_tail = n->prev;
			m_tail->next = NULL;
		}

		
	}
	node *m_head;
	node *m_tail;
	map<int, node *> m_info_map;
	int m_capacity;
};

int main()
{
	//2,[set(2,1),set(2,2),get(2),set(1,1),set(4,1),get(2)]
	LRUCache c(2);
	c.set(2, 1);
	c.set(2, 2);
	cout << c.get(2) << endl;
	c.set(1, 1);
	c.set(4, 1);
	cout << c.get(2) << endl;
	
	return 1;
}
