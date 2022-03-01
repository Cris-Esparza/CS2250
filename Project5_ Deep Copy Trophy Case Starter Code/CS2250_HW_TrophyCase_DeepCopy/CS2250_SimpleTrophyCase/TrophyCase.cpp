#include "TrophyCase.h"

TrophyCase::TrophyCase()
{
	TrophyCase* trophies = new TrophyCase[10];
	nbrOfTrophies = new int(1);
	capacity = new int(10);
}

TrophyCase::TrophyCase(const TrophyCase& trophyCase)
{
	trophies = new TrophyCase(*trophyCase.trophies);
	nbrOfTrophies = new int(*trophyCase.nbrOfTrophies);
	capacity = new int(*trophyCase.capacity);
}

TrophyCase :: ~TrophyCase()
{
	delete trophies;
	delete nbrOfTrophies;
	delete capacity;
}

TrophyCase& TrophyCase :: operator = (const TrophyCase& trophyCase)
{
	*trophies = *trophyCase.trophies;
	*nbrOfTrophies = *trophyCase.nbrOfTrophies;
	*capacity = *trophyCase.capacity;
	return *this;
}

ostream& operator << (ostream& sout, const TrophyCase& trophies)
{
	for (int i = 0; i < *trophies.capacity; ++i)
	{
		sout << trophies.trophies[i] << endl;
	}
	return sout;
}

int TrophyCase :: getNbrOfTrophies()
{
	return *nbrOfTrophies;
}

int TrophyCase::getAllocatedSize()
{
	return *capacity;
}

bool TrophyCase::addTrophy(string name, int level, Color color)
{
	TrophyCase** trophies = new TrophyCase * [10];
	for (int i = 0; i < 10; ++i)
	{
		trophies[i] = new TrophyCase();
	}
	return true;
}

bool TrophyCase::copyTrophy(string name)
{
	return true;
}

bool TrophyCase::deleteTrophy(string name)
{
	return true;
}

bool TrophyCase::renameTrophy(string name, string newName)
{
	return true;
}

bool TrophyCase::relevelTrophy(string name, int newLevel)
{
	return true;
}

bool TrophyCase::recolorTrophy(string name, Color newColor)
{
	return true;
}

void TrophyCase::searchTrophies(string name)
{

}

void TrophyCase::sortTrophies()
{

}