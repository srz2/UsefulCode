#include "Person.h"
#include <iostream>

int main()
{
  Person *newPerson = new Person();

  newPerson->setAge(18);
  newPerson->setName("Joe Somebody");

  std::cout << "Person is: " << newPerson->getName() << std::endl;

  delete newPerson;
}