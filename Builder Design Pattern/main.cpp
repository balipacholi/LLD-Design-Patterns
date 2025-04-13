#include <iostream>
#include <string>

using namespace std;

class Desktop
{
public:
	string motherBoard;
	string processor;
	string memory;
	string storage;
	string graphicCard;

	void display()
	{
		cout << "Desktop Configurations :" << endl;
		cout << "MotherBoard :" << motherBoard << endl;
		cout << "Processor :" << processor << endl;
		cout << "Memory :" << memory << endl;
		cout << "Storage :" << storage << endl;
		cout << "Graphic Card :" << graphicCard << endl;
	}
};

// Abstract Builder
class DesktopBuilder
{
protected:
	Desktop desktop;

public:
	virtual void buildMotherBoard() = 0;
	virtual void buildProcessor() = 0;
	virtual void buildMemory() = 0;
	virtual void buildStorage() = 0;
	virtual void buildGraphicCard() = 0;

	Desktop getDesktop()
	{
		return desktop;
	}
};

class DellDesktopBuilder : public DesktopBuilder
{
public:
	void buildMotherBoard() override
	{
		desktop.motherBoard = " Dell Mother Board";
	}

	void buildProcessor() override
	{
		desktop.processor = "Dell Processor";
	}

	void buildMemory() override
	{
		desktop.memory = "32 gb DDR4 RAM";
	}

	void buildStorage() override
	{
		desktop.storage = "1TB SSD + 2TB HDD";
	}

	void buildGraphicCard() override
	{
		desktop.graphicCard = "NVIDIA RTX 3080";
	}
};

class HpDesktopBuilder : public DesktopBuilder
{
public:
	void buildMotherBoard() override
	{
		desktop.motherBoard = " Hp Mother Board";
	}

	void buildProcessor() override
	{
		desktop.processor = " Intel core i7";
	}

	void buildMemory() override
	{
		desktop.memory = "16GB DDR4 RAM";
	}

	void buildStorage() override
	{
		desktop.storage = "256GB SSD";
	}

	void buildGraphicCard() override
	{
		desktop.graphicCard = "Integrated graphics Card";
	}
};

class DesktopDirector
{
public:
	Desktop buildDesktop(DesktopBuilder &builder)
	{
		builder.buildMotherBoard();
		builder.buildProcessor();
		builder.buildMemory();
		builder.buildStorage();
		builder.buildGraphicCard();
		return builder.getDesktop();
	}
};

int main()
{

	DesktopDirector desktopDirector;
	DellDesktopBuilder dellDesktopBuilder;
	Desktop dellDesktop = desktopDirector.buildDesktop(dellDesktopBuilder);
	dellDesktop.display();

	cout << endl;
	HpDesktopBuilder hpDesktopBuilder;
	Desktop HpDesktop = desktopDirector.buildDesktop(hpDesktopBuilder);
	HpDesktop.display();

	return 0;
}