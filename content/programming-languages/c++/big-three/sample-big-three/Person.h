#include <string.h>
#include <stdio.h>

class Person
{ 
  private:
    char * name;
    int age;
  public:
    Person();

    Person(const Person& other);
    Person& operator = (const Person & other);
    virtual ~Person();

    void setAge(int newAge);
    void setName(char * newName);

    char * getName();
};