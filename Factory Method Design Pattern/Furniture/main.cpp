#include <iostream>

class FurnitureItem
{
public:
	virtual ~FurnitureItem() {}
	virtual void display() = 0;
};

class Chair : public FurnitureItem
{
public:
	void display() override
	{
		std::cout << "I'm Chair class" << std::endl;
	}
};

class Sofa : public FurnitureItem
{
public:
	void display() override
	{
		std::cout << "I'm Sofa class" << std::endl;
	}
};

class Table : public FurnitureItem
{
public:
	void display() override
	{
		std::cout << "I'm Table class" << std::endl;
	}
};

class FurnitureFactory
{
public:
	virtual ~FurnitureFactory() {}
	virtual FurnitureItem *createFurniture() = 0;
};

class ChairFactory : public FurnitureFactory
{
public:
	FurnitureItem *createFurniture() override
	{
		return new Chair();
	}
};

class SofaFactory : public FurnitureFactory
{
public:
	FurnitureItem *createFurniture() override
	{
		return new Sofa();
	}
};

class TableFactory : public FurnitureFactory
{
public:
	FurnitureItem *createFurniture() override
	{
		return new Table();
	}
};

int main()
{
	FurnitureFactory *sofaFactory = new SofaFactory();
	FurnitureItem *sofa = sofaFactory->createFurniture();
	sofa->display();
	delete sofaFactory;
	delete sofa;
	return 0;
}