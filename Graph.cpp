#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>

template<typename Vertex = int, typename Weight = double>
class graph
{
	typedef Vertex vertex_type;
	typedef Weight weight_type;
	typedef std::pair<Vertex, Weight> neighbor;
	typedef std::vector<neighbor> neighbor_list_type;

public:
	size_t vertex_count() const
	{
		return ad_list.size();
	}

	void add_edge(Vertex const source, Vertex const target, Weight const val, bool const bidirectional = true)
	{
		ad_list[source].push_back(std::make_pair(target, val));
		ad_list[target].push_back(std::make_pair(source, val));
	}


	std::vector<Vertex> vertices() const
	{
		std::vector<Vertex> keys;
		for (auto const& it : ad_list)
			keys.push_back(it.first);
		return keys;
	}


	neighbor_list_type const& neighbors(Vertex const v) const
	{
		auto pos = ad_list.find(v);
		if (pos == ad_list.end())
			throw std::runtime_error("Not Found");
		return pos->second;
	}

	constexpr static Weight Infinity = std::numeric_limits<Weight>::infinity();


private:
	std::map<vertex_type, neighbor_list_type> ad_list;


};


template<typename Vertex, typename Weight>
void shortest_path(graph<Vertex, Weight> const& g, Vertex const source, std::map<Vertex, Weight>& mindist, std::map<Vertex, Vertex>& prev)
{
	auto const n = g.vertex_count();  //number of vertex
	auto const vertexes = g.vertices(); //set of vertex


	mindist.clear();
	for (auto const& it : vertexes)
		mindist[it] = graph<Vertex, Weight>::Infinity;
	mindist[source] = 0; // source init with min value to start here
	prev.clear(); // clear the set of vertex move log

	std::set<std::pair<Weight, Vertex>> vertex_queue;


	vertex_queue.insert(std::make_pair(mindist[source], source));

	while (!vertex_queue.empty())
	{
		auto dist = vertex_queue.begin()->first;
		auto u = vertex_queue.begin()->second;

		vertex_queue.erase(vertex_queue.begin());

		auto const neighbors = g.neighbors(u);

		for (auto const& it : neighbors)
		{
			auto v = it.first;
			auto w = it.second;
			auto dist_via = dist + w;

			if (mindist[v] > dist_via)
			{
				vertex_queue.erase(std::make_pair(mindist[v], v)); // erase prev value
				mindist[v] = dist_via;
				prev[v] = u;
				vertex_queue.insert(std::make_pair(mindist[v], v)); //update with min value
			}
		}

	}

}

template<typename Vertex>
void print_path(std::vector<Vertex> const& path)
{
	for (int i = 0; i < path.size(); i++)
	{
		std::cout << path[i];
		if (i < path.size() - 1)
			std::cout << " --> ";
	}
}

template<typename Vertex>
void build_path(std::map<Vertex, Vertex>const & prev, Vertex const v, std::vector<Vertex>& result)
{
	result.push_back(v);
	auto pos = prev.find(v);
	if (pos == prev.end())
		return;
	build_path(prev, pos->second, result);
}

template<typename Vertex>
std::vector<Vertex> build_path(std::map<Vertex, Vertex> const& prev, Vertex const v)
{
	std::vector<Vertex> res;
	build_path(prev, v, res);
	std::reverse(res.begin(), res.end());
	return res;
}



graph<char, double> make_graph()
{
	graph<char, double> g;
	g.add_edge('A', 'B', 4);
	g.add_edge('A', 'H', 8);
	g.add_edge('B', 'C', 8);
	g.add_edge('B', 'H', 11);
	g.add_edge('C', 'D', 7);
	g.add_edge('C', 'F', 4);
	g.add_edge('C', 'J', 2);
	g.add_edge('D', 'E', 9);
	g.add_edge('D', 'F', 14);
	g.add_edge('E', 'F', 10);
	g.add_edge('F', 'G', 2);
	g.add_edge('G', 'J', 6);
	g.add_edge('G', 'H', 1);
	g.add_edge('H', 'J', 7);

	return g;
}



graph<std::string, double> graph_map()
{
	graph<std::string, double> g;
	g.add_edge("London", "Reading", 41);
	g.add_edge("London", "Oxford", 57);
	g.add_edge("Reading", "Swindon", 40);
	g.add_edge("Swindon", "Bristol", 40);
	g.add_edge("Oxford", "Swindon", 30);
	g.add_edge("London", "Southampton", 80);
	g.add_edge("Southampton", "Bournemouth", 33);
	g.add_edge("Bournemouth", "Exeter", 89);
	g.add_edge("Bristol", "Exeter", 83);
	g.add_edge("Bristol", "Bath", 12);
	g.add_edge("Swindon", "Bath", 35);
	g.add_edge("Reading", "Southampton", 50);

	return g;
}


graph<std::string, double> station_graph_map()
{
	graph<std::string, double> g;
	g.add_edge("노량진", "흑석", 41);
	g.add_edge("노량진", "용산", 17);
	g.add_edge("흑석", "동작", 40);
	g.add_edge("동작", "구반포", 40);
	g.add_edge("Oxford", "Swindon", 30);
	g.add_edge("London", "Southampton", 80);
	g.add_edge("Southampton", "Bournemouth", 33);
	g.add_edge("Bournemouth", "Exeter", 89);
	g.add_edge("Bristol", "Exeter", 83);
	g.add_edge("Bristol", "Bath", 12);
	g.add_edge("Swindon", "Bath", 35);
	g.add_edge("Reading", "Southampton", 50);

	return g;
}


int main()
{

	{
		using namespace std;
		auto g = make_graph();
		std::map<char, double> mindist;
		std::map<char, char> prev;
		char source = 'A';

		shortest_path(g, source, mindist, prev);

		for (auto const& it : mindist)
		{
			cout << source << " -> " << it.first << " : " << it.second << '\t';
			print_path(build_path(prev, it.first));
			cout << std::endl;
		}

	}

	{
		using namespace std;
		auto g = station_graph_map();
		std::map<string, double> mindist;
		std::map<string, string> prev;
		string source = "노량진";

		shortest_path(g, source, mindist, prev);

		for (auto const& it : mindist)
		{
			cout << source << " -> " << it.first << " : " << it.second << '\t';
			print_path(build_path(prev, it.first));
			cout << std::endl;
		}

	}



}