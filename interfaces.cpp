#include "Mylibraty.h"
#include <iostream>
using namespace std;

class Ship : public ISwim 
{
public:
	void Swim() override
	{
		cout << "Ships swim great\n";
	}
};

void Func(ISwim* ptr)
{
	ptr->Swim();
}

void FuncFly(IFly* ptr)
{
	ptr->Fly();
}

int main()
{
    system("chcp 1251");
    system("cls");
    Pingwin pg("Linuxoid", 10, "North America");
    pg.Print();
    pg.Eat();
    pg.Sound();
    pg.Swim();
    pg.Continent();

	Ship sh;
	sh.Swim();

	Parrot pr("Kesha", 1, "South America");
	pr.Print();
	pr.Eat();
	pr.Sound();
	pr.Continent();

	Airplane ap;

	Func(&pg);
	Func(&sh);
	
	FuncFly(&pr);
	FuncFly(&ap);

	return 0;
}
