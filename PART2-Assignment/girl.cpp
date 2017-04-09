#include "girl.h"

string Girl::getname()
{
        return this->name;
}

int Girl::getIntelligence()
{
        return this->intelligence;
}
int Girl::getAttractiveness()
{
        return this->attractiveness;
}

int Girl::getMaintenance()
{
        return this->maintenance;
}

int Girl::getStatus()
{
        return this->status;
}

char Girl::getType()
{
        return this->type;
}

char Girl::getCriterion()
{
	return this->criterion;
}

void Girl::setDetails(string name,int attractiveness,int intelligence,int maintenance ,char type,int status,char criterion)
{
        this->name = name;
        this->attractiveness = attractiveness;
        this->intelligence = intelligence;
        this->maintenance = maintenance;
        this->type = type;
        this->status = status;
	this->criterion = criterion;
}
void Girl::setStatus(int i) {
	this->status = i;
}
