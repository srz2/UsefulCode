Big Three
=========

[Back to Root](../../../../README.md#covered-topics)

The Big Three is the concept within C++ which allows for dynamic memory allocation. The "Big Three" refer to functions which the programmer must manually write in order to make their functions work dynamically. The functions that need to be included are the ***Copy Constructor***, the ***Assignement Method*** and the ***Destructor***.

## Sample Project
This project includes a represetation of how to implement a dynamic class using the *Big Three* concept. [[sample-big-three]](sample-big-three.zip)


### Copy Constructor

  The copy constructor is called whenever an object is initialized from another object of the same type (unless overload resolution selects the move constructor as a better match), which includes. <p><a href="http://en.cppreference.com/w/cpp/language/copy_constructor" target="_blank">[Source.]</a></p>

### Assignment Method

  The copy assignment operator is called whenever selected by overload resolution, e.g. when an object appears on the left side of an assignment expression. <p><a href="http://en.cppreference.com/w/cpp/language/as_operator" target="_blank">[Source.]</a></p>

### Destructor

The destructor is called whenever an object's lifetime ends. <p><a style="" href="http://en.cppreference.com/w/cpp/language/destructor" target="_blank">[Source.]</a></p> This is called in order to clean up the class instance in order to free any other memory used by the class.

## Sample Code

**Person.h**

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

**Person.cpp**
    
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

## Implementation

  **main.cpp**

    #include "Person.h"
    #include <iostream>         //

    int main()
    {
      Person *newPerson = new Person();

      newPerson->setAge(18);
      newPerson->setName("Joe Somebody");

      std::cout << "Person is: " << newPerson->getName() << std::endl;

      delete newPerson;
    }