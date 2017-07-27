#include "Person.h"

Person::Person()
{
  //printf("Constructing...\n");
  this->name = new char[128];
  this->age  = 0;
}

Person::Person(const Person& other)
{
  //printf("Copying...\n");
  this->name = other.name;
  this->age = other.age;
}

Person& Person::operator = (const Person & other)
{
  //printf("Assigning...\n");
  this->name = other.name;
  this->age = other.age;

  return *this;
}

Person::~Person()
{
  //printf("Destorying...\n");
  delete this->name;
  this->name = NULL;
}

void Person::setAge(int newAge)
{
  this->age = newAge;
} 

void Person::setName(char * newName)
{
  for(int c = 0; c < strlen(newName); c++)
    this->name[c] = newName[c];
}

char * Person::getName()
{
  return this->name;
}