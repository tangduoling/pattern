#include <stdio.h>
#include <iostream>

class Originator
{
public:
	Originator(int var=0);
	~Originator();

	void loadStage(const int& var);
	int  saveStage();
	void change();

	void show()
	{
		std::cout << "current value:" << stage_ << std::endl;
	}

private:
	int stage_;
};

Originator::Originator(int var)
{
	stage_ = var;
}

Originator::~Originator()
{
}

void Originator::loadStage(const int& var)
{
	stage_ = var;
}

int Originator::saveStage()
{
	return stage_;
}

void Originator::change()
{
	stage_ *= -1;
}

class saveIter
{
public:
	saveIter();
	~saveIter();

	int  getIter();
	void setIter(const int& var);

private:
	int iter_;
};

saveIter::saveIter()
{
}

saveIter::~saveIter()
{
}

int saveIter::getIter()
{
	return iter_;
}

void saveIter::setIter(const int& var)
{
	iter_ = var;
}

class saveOper
{
public:
	saveOper();
	~saveOper();

	void saveToFile(const int&);
	int  loadFromFile();

private:
	int saveIter;
};

saveOper::saveOper()
{
}

saveOper::~saveOper()
{
}

void saveOper::saveToFile(const int& var)
{
	saveIter = var;
}

int saveOper::loadFromFile()
{
	return saveIter;
}

int main()
{
	
	Originator or(88);
	saveOper oper;

	//±£´æ
	oper.saveToFile(or.saveStage());
	or.show();

	or.change();
	or.show();

	//¼ÓÔØ
	or.loadStage(oper.loadFromFile());
	or.show();

	return 0;
}
