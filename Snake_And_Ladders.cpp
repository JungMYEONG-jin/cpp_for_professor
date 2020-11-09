#include <map>

using namespace std;
map<int, int> make_ladder()
{
  map<int, int> res;
  for (auto i = 1; i <= 100; i++)
    res[i] = i;


  
  res[2] = 38;
  res[7] = 14;
  res[8] = 31;
  res[15] = 26;
  res[16] = 6;
  res[21] = 42;
  res[28] = 84;
  res[36] = 44;
  res[46] = 25;
  res[49] = 11;
  res[51] = 67;
  res[62] = 19;
  res[64] = 60;
  res[71] = 91;
  res[74] = 53;
  res[78] = 98;
  res[87] = 94;
  res[89]=68;
  res[92] = 88;
  res[95] = 75;
  res[99] = 80;
  return res;
}

map<int, int> res = make_ladder();


class SnakesLadders
{
public:
  SnakesLadders() {};

  string real_play(int die1, int die2)
  {
    string k;
    if (player1 == true)
    {

      if (sum2 == 100)
        return "Game over!";

      if (sum1 + die1 + die2 < 100)
      {
        if (die1 != die2)
        {
          player1 = false;
          player2 = true;
        }
        else
        {
          player1 = true;
          player2 = false;
        }
        int k1 = sum1+die1+die2;
        sum1 = res[k1];
        if(sum1!=100)
          k= "Player 1 is on square " + to_string(sum1);
        else
          k="Player 1 Wins!";

      }
      else
      {

        if (die1 != die2)
        {
          player1 = false;
          player2 = true;
        }
        else
        {
          player1 = true;
          player2 = false;
        }

        int diff = sum1 + die1 + die2 - 100;
        int k1 = 100-diff;
        sum1 = res[k1];
        if(sum1!=100)
          k= "Player 1 is on square " + to_string(sum1);
        else
          k="Player 1 Wins!";
      }


    }
    else if (player2 == true)
    {
      if (sum1 == 100)
        return "Game over!";


      if (sum2 + die1 + die2 < 100)
      {
        if (die1 != die2)
        {
          player2 = false;
          player1 = true;
        }
        else
        {
          player2 = true;
          player1 = false;
        }
        int k1 = sum2+die1+die2;
        sum2 = res[k1];
        if(sum2!=100)
          k = "Player 2 is on square " + to_string(sum2);
        else
          k="Player 2 Wins!";

      }
      else if (sum2 == 100)
      {
        k = "Player 2 Winds!";
      }
      else
      {
        if (die1 != die2)
        {
          player2 = false;
          player1 = true;
        }
        else
        {
          player2 = true;
          player1 = false;
        }


        int diff = sum2 + die1 + die2 - 100;
        sum2 = res[100 - diff];
         if(sum2!=100)
          k = "Player 2 is on square " + to_string(sum2);
        else
          k="Player 2 Wins!";

      }


    }
    return k;
  }

  std::string play(int die1, int die2)
  {
    return real_play(die1, die2);

  };


private:
  bool player1 = true;
  bool player2 = false;
  int sum1 = 0;
  int sum2 = 0;
};
