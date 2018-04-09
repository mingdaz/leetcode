struct Node
{
	string  name;
	unordered_map<string, double> next;
	Node(string name_) :name(name_){}
};
class Solution {
public:
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {

		unordered_map<string, Node*> Nodes = createNodes(equations, values);

		int id = 0;

		unordered_map<string, pair<int, double> > datas;
		queue<string> q;
		while (!Nodes.empty())
		{
			q.push(Nodes.begin()->first);
			datas[Nodes.begin()->first] = pair<int, double>(id, 1);
			while (!q.empty())
			{
				Node* p = Nodes[q.front()];
				for (auto it = p->next.begin(); it != p->next.end(); it++)
				{
					datas[it->first] = pair<int, double>(id, datas[p->name].second / it->second);
					q.push(it->first);
					Nodes[it->first]->next.erase(p->name);
				}
				Nodes.erase(p->name);
				q.pop();
			}
			id++;
		}


		vector<double> ret;
		for (size_t i = 0; i < queries.size(); i++)
		{
			if (datas.find(queries[i].first)==datas.end()||datas.find(queries[i].second)==datas.end()||datas[queries[i].first].first != datas[queries[i].second].first || datas[queries[i].second].second == 0)
				ret.push_back(-1.0);
			else
				ret.push_back(datas[queries[i].first].second / datas[queries[i].second].second);
		}
		return ret;

	}
	unordered_map<string, Node*> createNodes(vector<pair<string, string> >& eqs, vector<double>& vals)
	{
		unordered_map<string, Node*> accessed;

		for (size_t i = 0; i < eqs.size(); i++)
		{
			if (accessed.find(eqs[i].first) == accessed.end())
			{
				Node* p = new Node(eqs[i].first);
				accessed[p->name] = p;
			}
			if (accessed.find(eqs[i].second) == accessed.end())
			{
				Node* p = new Node(eqs[i].second);
				accessed[p->name] = p;
			}
			if (vals[i] != 0)
			{
				accessed[eqs[i].first]->next[eqs[i].second] = vals[i];
				accessed[eqs[i].second]->next[eqs[i].first] = 1 / vals[i];
			}

		}
		return accessed;

	}
};
