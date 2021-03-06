#ifndef TROPHY_H
#define TROPHY_H

#include <iostream>
#include <string>
using namespace std;

enum Color { BRONZE, SILVER, GOLD };

class Trophy
{
public:
	Trophy();
	Trophy(string name, int level, Color color);
	Trophy(const Trophy& trophy);
	Trophy& operator = (const Trophy& trophy);
	~Trophy();
	string getName() const;
	int getLevel() const;
	Color getColor() const;
	void setName(string name);
	void setLevel(int level);
	void setColor(Color color);
	void print() const;
private:
	string* name;
	int* level;
	Color* color;
};

#endif