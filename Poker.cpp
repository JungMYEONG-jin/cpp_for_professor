#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

struct PokerHand
{
	PokerHand(const char* poke) { pokerhand = poke; }
	const char* pokerhand;
};

enum class Result{Win, Loss, Tie};


vector<string> sort_(vector<string> vec, string order)
{
	size_t found;
	size_t next;

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i + 1; j < vec.size(); j++)
		{
			found = order.find(vec[i][0]);
			next = order.find(vec[j][0]);
			if (found != string::npos && next != string::npos)
			{
				if (next < found)
				{
					char temp = vec[j][0];
					vec[j][0] = vec[i][0];
					vec[i][0] = temp;
				}
			}
		}
	}
	return vec;

}

//cehck if exist pair

int pairSearch(vector<string> vec)
{
	int score = 0;
	int pairs = 0;
	int switches = -1;
	char prev = 'x';

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i + 1; j < vec.size(); j++)
		{
			if (vec[i][0] == vec[j][0])
			{
				pairs++;
				if (prev != vec[j][0])
				{
					prev = vec[j][0];
					switches++;
				}
				break;
			}
		}
	}

	if (pairs == 3 && switches == 0)
	{
		score = 8;
	}
	if (pairs == 3 && switches == 1)
	{
		score = 7;
		//full house
	}
	if (pairs == 2 && switches == 1)
	{
		score = 3;
		//two pair
	}
	if (pairs == 2 && switches == 0)
	{
		score = 4;
	}
	if (pairs == 1 && switches == 0)
	{
		score = 2;
		// one pair
	}

	return score;
}

int flushOrSt(vector<string> vec, string order)
{
	int flush = 0;
	set<char> k;
	for (auto i : vec)
		k.insert(i[1]);
	if (k.size() == 1)
		flush = 6;

	char test = 'A';
	if (vec[4][0] == test)
	{
		if (vec[0][0] == '2' && vec[1][0] == '3' && vec[2][0] == '4' && vec[3][0] == '5')
		{
			if (flush < 5)
				flush = 5;
			else if (flush == 6)
				flush = 9;
		}
	}


	size_t find1 = order.find(vec[0][0]);
	size_t find2 = order.find(vec[1][0]);
	size_t find3 = order.find(vec[2][0]);
	size_t find4 = order.find(vec[3][0]);
	size_t find5 = order.find(vec[4][0]);
	if (find1 == find2 - 1 && find2 == find3 - 1 && find3 == find4 - 1 && find4 == find5 - 1) {
		if (flush < 5) {
			flush = 5;
		}
		else if (flush == 6) {
			flush = 9;
		}
	}
	return flush;



}

char highCard(vector<string> player, vector<string> opp, string order)
{
	size_t play;
	size_t op;
	int p_score = flushOrSt(player, order);
	int o_score = flushOrSt(opp, order);

	if (p_score == 5 && player[4][0] == 'A' && player[3][0] == '5')
	{
		//lowest ace
		string temp = player[4];
		player[4] = player[3];
		player[3] = player[2];
		player[2] = player[1];
		player[1] = player[0];
		player[0] = temp;
	}

	if (o_score == 5 && opp[4][0] == 'A' && opp[3][0] == '5')
	{
		//lowest ace
		string temp = opp[4];
		opp[4] = opp[3];
		opp[3] = opp[2];
		opp[2] = opp[1];
		opp[1] = opp[0];
		opp[0] = temp;
	}

	// other case
	for (int i = 4; i >= 0; i--)
	{
		play = order.find(player[i][0]);
		op = order.find(opp[i][0]);
		if (play > op)
			return 'p';
		else if (play < op)
			return 'o';
	}
	return 't';
}

Result compare(const PokerHand& player, const PokerHand& opponent)
{
	stringstream ss;
	stringstream ss2;
	ss << player.pokerhand;
	ss2 << opponent.pokerhand;

	string temp1;
	string temp2;
	vector<string> play_vec;
	vector<string> opp_vec;
	while (getline(ss, temp1, ' '))
		play_vec.push_back(temp1);
	while (getline(ss2, temp2, ' '))
		opp_vec.push_back(temp2);

	string order = "23456789TJQKA";
	vector<string> sort_p = sort_(play_vec, order);
	vector<string> sort_o = sort_(opp_vec, order);


	int player_pts = pairSearch(sort_p);
	int opp_pts = pairSearch(sort_o);

	int flush_player = flushOrSt(sort_p, order);
	int flush_opp = flushOrSt(sort_o, order);

	if (flush_player > player_pts)
		player_pts = flush_player;
	else
		flush_player = player_pts;


	if (flush_opp > opp_pts)
		opp_pts = flush_opp;
	else
		flush_opp = opp_pts;


	if (player_pts > opp_pts)
	{
		return Result::Win;
	}
	else if (player_pts < opp_pts)
	{
		return Result::Loss;

	}
	else
	{
		char win = highCard(sort_p, sort_o, order);
		switch (win)
		{
		case 'p':
			return Result::Win;
		case 'o':
			return Result::Loss;
		default:
			return Result::Tie;
		}
	}


}
