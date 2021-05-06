#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <random>
#include <map>
#include <ctime>


using namespace std;


typedef unsigned int ui;

class Cell
{
private:
	vector<int> state;
	ui rc;

public:
	explicit Cell(ui _rc)
		:rc(_rc)
	{
		state.resize(rc * rc);
		for (ui i = 0; i < state.size(); i++)
		{
			state[i] = i;
		}
	}

	Cell(ui _rc, const vector<int>& arr)
		:rc(_rc)
	{
		assert(arr.size() == rc * rc); // 크기 같나 확인 다르면 바로 error날리자
		state = arr;
	}
	// 복사 생성자
	Cell(const Cell& cell)
	{
		rc = cell.rc;
		state = cell.state;
	}

	// 할당 연산자
	Cell& operator=(const Cell& cell)
	{
		if (this != &cell)
		{
			rc = cell.rc;
			state = cell.state;
		}
		return *this;
	}

	// check same
	friend bool operator==(const Cell& left, const Cell& right)
	{
		return left.state == right.state;
	}

	friend bool operator!=(const Cell& left, const Cell& right)
	{
		return !(left == right);
	}

	// empty slot 찾기
	int FindEmpty() const
	{
		for (ui i = 0; i < state.size(); i++)
		{
			if (state[i] == 0)
				return i;
		}
		return static_cast<int>(state.size());
	}

	void Randomize()
	{
		random_device rd;
		mt19937 gen(rd());
		shuffle(state.begin(), state.end(), gen);
	}

	// Empty index와 swap하는 method

	void SwapEmpty(int idx0, int idx1)
	{
		swap(state[idx0], state[idx1]);
	}

	const vector<int>& getArray() const
	{
		return state;
	}

	void SetArray(const vector<int>& arr)
	{
		state = arr;
	}

	ui GetSize() const
	{
		return rc;
	}

	void print(ostream& os, bool flag = false) const
	{
		for (ui i = 0; i < rc; i++)
		{
			for (ui j = 0; j < rc; j++)
			{
				ui idx = i * rc + j;
				if (flag)
				{
					os << state[idx];
				}
				else
				{
					os << state[idx] << " ";
				}
			}
			if (!flag)
			{
				os << "\n";
			}
		}
		os << "\n";
	}

};

class Neighbor
{
public:
	map<int, vector<int>> edge;

	Neighbor()
	{
		Create8Puzzle();
	}

	const vector<int>& GetNeighbor(int id) const
	{
		auto it = edge.find(id);
		if (it != edge.end())
			return it->second; // 존재하면 return
		static vector<int> temp; // 없으면 empty vector
		return temp;
	}

private:
	void Create8Puzzle()
	{
		edge.insert(make_pair(0, vector<int>{1, 3}));
		edge.insert(make_pair(1, vector<int>{0, 2, 4}));
		edge.insert(make_pair(2, vector<int>{1, 5}));
		edge.insert(make_pair(3, vector<int>{4, 0, 6}));
		edge.insert(make_pair(4, vector<int>{3, 5, 1, 7}));
		edge.insert(make_pair(5, vector<int>{4, 2, 8}));
		edge.insert(make_pair(6, vector<int>{7, 3}));
		edge.insert(make_pair(7, vector<int>{6, 8, 4}));
		edge.insert(make_pair(8, vector<int>{7, 5}));

	}

};

class Node
{
private:
	Cell cell;
	shared_ptr<Node> parent;
	int depth;

public:
	Node(const Cell& _cell, shared_ptr<Node> _parent, int _depth = 0)
		:cell(_cell), depth(_depth)
	{
		parent = _parent;
	}

	void SetParent(Node* node)
	{
		parent.reset(node);
	}

	void SetParent(shared_ptr<Node> node)
	{
		parent = node;
	}

	shared_ptr<Node> GetParent()
	{
		return parent;
	}

	const shared_ptr<Node> GetParent() const
	{
		return parent;
	}

	const Cell& getCell() const
	{
		return cell;
	}

	int getDepth() const
	{
		return depth;
	}

	void print(ostream& os, int line)
	{
		os << line << " - Node { ";
		for (ui i = 0; i < cell.getArray().size(); i++)
		{
			os << cell.getArray()[i];
		}
		os << " | Depth: " << depth;
		os << " }" << "\n";
	}
};


int HammingCost(const Cell& cell)
{
	int cost = 0;
	const vector<int>& state = cell.getArray();
	for (ui i = 0; i < state.size(); i++)
	{
		if (state[i] == 0) continue;
		if (state[i] != i + 1) cost++; // 해당 index와 수가 같지않으면 cost 증가
	}
	return cost;
}

int ManhattanCost(const Cell& cell)
{
	int cost = 0;
	const vector<int>& state = cell.getArray();
	ui rc = cell.GetSize();

	for (ui i = 0; i < state.size(); i++)
	{
		int v = state[i];
		if (v == 0) continue;

		// 실제 인덱스는 -1해야됨
		v--;
		int x = v % rc;
		int y = v / rc;

		int x2 = i % rc;
		int y2 = i / rc;

		int man = abs(x - x2) + abs(y - y2);
		cost += man;

		int z = 0;
	}
	return cost;
}

class CompareBestFunction
{
public:
	bool operator()(const shared_ptr<Node>& left, const shared_ptr<Node>& right) const
	{
		const Cell& state1 = left->getCell();
		int cost1 = ManhattanCost(state1) + HammingCost(state1);
		const Cell& state2 = right->getCell();
		int cost2 = ManhattanCost(state2) + HammingCost(state2);

		return cost1 < cost2;
	}
};

class Compare_Astar
{
public:
	bool operator()(const shared_ptr<Node>& left, const shared_ptr<Node>& right) const
	{
		const Cell& state1 = left->getCell();
		int cost1 = ManhattanCost(state1) + HammingCost(state1) + left->getDepth();
		const Cell& state2 = right->getCell();
		int cost2 = ManhattanCost(state2) + HammingCost(state2) + right->getDepth();

		return cost1 < cost2;

	}
};

bool isIn(const Cell& cell, const vector<shared_ptr<Node>>& values)
{
	ui i = 0;
	for (; i < values.size(); i++)
	{
		if (cell == values[i]->getCell()) //존재하면
			return true;
	}
	return false;
}

class Solver
{
public:
	enum Type
	{
		DEPTH_FIRST = 0,
		BR_FIRST,
		GREEDY_BEST_FIRST,
		ASTAR,
	};

	Solver(const Cell& start, const Cell& _goal, Type _type = Type::ASTAR)
		:goal(_goal), solved(false), type(_type)
	{
		shared_ptr<Node> root(new Node(start, 0, 0));
		open.push_back(root);
	}

	virtual ~Solver()
	{

	}

	bool isSolved() const
	{
		return solved;
	}

	static bool Solvable(const Cell& cell)
	{
		int cnt = 0;
		const vector<int> arr = cell.getArray();
		for (ui i = 0; i < arr.size() - 1; i++)
		{
			for (ui j = i + 1; j < arr.size(); j++)
			{
				if (arr[j] && arr[i] && arr[i] > arr[j])
					cnt++;
			}
		}
		return (cnt % 2 == 0);
	}

	shared_ptr<Node> GetNextNode()
	{
		if (open.empty())
			return 0;
		shared_ptr<Node> cur;
		switch (type)
		{
		case ASTAR:
		{
			auto cur_iter = min_element(open.begin(), open.end(), Compare_Astar());

			if (cur_iter == open.end())
				return 0;

			cur = *cur_iter;
			open.erase(cur_iter);
			close.push_back(cur);

			break;
		}
		case GREEDY_BEST_FIRST:
		{
			auto cur_iter = min_element(open.begin(), open.end(), CompareBestFunction());
			if (cur_iter == open.end())
				return 0;

			cur = *cur_iter;
			open.erase(cur_iter);
			close.push_back(cur);

			break;

		}
		case BR_FIRST:
		{
			cur = open[0];
			open.erase(open.begin());
			close.push_back(cur);

			break;
		}
		case DEPTH_FIRST:
		{
			auto cur_iter = open.begin();
			if (cur_iter == open.end()) return 0;

			cur = *cur_iter;
			open.erase(cur_iter);
			close.push_back(cur);

			break;



		}
		}
		return cur;
	}

	void ExpandNode(shared_ptr<Node> cur, const Neighbor& graph)
	{
		if (cur->getCell() == goal)
		{
			solved = true;
			return;
		}
		int zero = cur->getCell().FindEmpty();
		const vector<int>& neighbor = graph.GetNeighbor(zero);


		for (int next : neighbor)
		{
			Cell cell = cur->getCell();
			cell.SwapEmpty(zero, next);

			if (!isIn(cell, close))
			{
				shared_ptr<Node> n(new Node(cell, cur, cur->getDepth() + 1));
				open.push_back(n);

			}
		}


	}



private:
	vector<shared_ptr<Node>> open;
	vector<shared_ptr<Node>> close;
	const Cell& goal;
	bool solved;
	Type type;
};

int main()
{
	srand(time(0));
	Neighbor g;

	Cell goal(3, vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 0});

	Cell start(3, vector<int>{1, 2, 3, 4, 5, 0, 7, 6, 8});

	while (!Solver::Solvable(start))
	{
		start.print(cout);
		cout << "Puzzle state is unsolvable..! Creating anoter configuration!\n";
		start.Randomize();
	}

	cout << "Start State:\n";
	start.print(cout);
	cout << "Solving Puzzle..\n";
	shared_ptr<Node> node;
	Solver solver(start, goal, Solver::ASTAR);
	int cnt = 0;

	while (!solver.isSolved())
	{
		node = solver.GetNextNode();
		solver.ExpandNode(node, g);
		cnt++;
	}

	vector<shared_ptr<Node>> res;
	shared_ptr<Node> temp = node;
	do
	{
		res.push_back(temp);
		temp = temp->GetParent();
	} while (temp != NULL);

	cout << "Puzzle can be solved in " << res.size() - 1 << " steps. Solution below\n";
	for (int i = (int)res.size() - 1; i >= 0; i--)
	{
		res[i]->getCell().print(cout, false);
	}
	cout << "\n";

}
