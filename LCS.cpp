#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Spell
{
private:
	string scrollName;
public:
	Spell()
		:scrollName("")
	{}
	Spell(string name)
		:scrollName(name)
	{}
	virtual ~Spell() {}
	string revealScrollName()
	{
		return scrollName;
	}
};


class Fireball : public Spell
{
public:
	Fireball(int pow)
		:power(pow)
	{}
	void revealFirepower()
	{
		cout << "Fireball: " << power << endl;
	}



private:
	int power;
};

class Waterbolt : public Spell
{
public:
	Waterbolt(int pow)
		:power(pow)
	{}
	void revealWaterpower()
	{
		cout << "Waterbolt: " << power << endl;
	}



private:
	int power;
};


class Frostbite : public Spell
{
public:
	Frostbite(int pow)
		:power(pow)
	{}
	void revealFrostpower()
	{
		cout << "Frostbite: " << power << endl;
	}



private:
	int power;
};


class Thunderstorm : public Spell
{
public:
	Thunderstorm(int pow)
		:power(pow)
	{}
	void revealThunderpower()
	{
		cout << "Thunderstorm: " << power << endl;
	}



private:
	int power;
};

class SpellJournal {
public:
	static string journal;
	static string read()
	{
		return journal;
	}
};


string SpellJournal::journal = "";


void counterspell(Spell* spell)
{
	if (Fireball* f = dynamic_cast<Fireball*>(spell))
		f->revealFirepower();
	else if (Waterbolt* w = dynamic_cast<Waterbolt*>(spell))
		w->revealWaterpower();
	else if (Thunderstorm* t = dynamic_cast<Thunderstorm*>(spell))
		t->revealThunderpower();
	else if (Frostbite* f = dynamic_cast<Frostbite*>(spell))
		f->revealFrostpower();
	else
	{
		string str1 = spell->revealScrollName();
		string str2 = SpellJournal::read();

		int lcs[1001][1001] = { 0, };

		int l1 = str1.length();
		int l2 = str2.length();

		for (int i = 1; i <= l2; i++)
		{
			for (int j = 1; j <= l1; j++)
			{
				if (str2[i - 1] == str1[j - 1])
				{
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				}
				else
				{
					lcs[i][j] = (lcs[i - 1][j] > lcs[i][j - 1] ? lcs[i - 1][j]: lcs[i][j - 1]);
				}
			}
		}

		cout << lcs[l2][l1] << endl;


	}
}

class Wizard {
public:
	Spell* cast() {
		Spell* spell;
		string s; cin >> s;
		int power; cin >> power;
		if (s == "fire") {
			spell = new Fireball(power);
		}
		else if (s == "frost") {
			spell = new Frostbite(power);
		}
		else if (s == "water") {
			spell = new Waterbolt(power);
		}
		else if (s == "thunder") {
			spell = new Thunderstorm(power);
		}
		else {
			spell = new Spell(s);
			cin >> SpellJournal::journal;
		}
		return spell;
	}
};


int main() {
	int T;
	cin >> T;
	Wizard Arawn;
	while (T--) {
		Spell* spell = Arawn.cast();
		counterspell(spell);
	}
	return 0;
}
