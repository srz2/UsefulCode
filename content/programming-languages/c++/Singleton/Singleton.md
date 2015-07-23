Singleton Class
===============

[Back to Root](../../../../README.md#covered-topics)

A Singleton Class is a class which can only be instantiated once but can be called everywhere in a program instead of carrying around it's instance variable or pointer to the class.

##Sample Project
This project includes a represetation of how to implement a log file. [[sample-singleton]](sample-singleton.zip)

##Sample Code

**MySingleClass.h**

    class MySingleClass
    {
      private:
        static MySingleClass * instance;                           //Keeps track of instance of class

        MySingleClass();                                           //Private Constructor
        MySingleClass(const MySingleClass & other);                //Private Copy Constructor
        MySingleClass & operator = (const MySingleClass & other);  //Private  Assignment Constructor
      public:
        static MySingleClass * Instance();                         //Accessor to instance
        virtual ~MySingleClass();                                  //Destructor
    };

**MySingleClass.cpp**

    #include "MySingleClass.h"

    MySingleClass * MySingleClass::instance = NULL;    //Initiates instance to NULL

    MySingleClass * MySingleClass::Instance()          //Accessor to instance definition
    {
      if(!instance)                                    //If instance is NULL
        instance = new MySingleClass();                     //create a new class (this should only happen once)
      return instance;                                 //return instance of class
    }

    MySingleClass::MySingleClass()                     //Constructor
    {

    }

    MySingleClass::~MySingleClass()                    //Deconstructor
    {

    }

    MySingleClass::MySingleClass(const MySingleClass & other)               //Copy Constructor
    {
        return *this;
    }

    MySingleClass& MySingleClass::operator = (const MySingleClass & other)  //Assignement 
    {

    }

##Implemenation

  **main.ccp**
    
    #include "MySingleClass.h"

    int main()
    {
        MySingleClass class = MySingleClass::Instance();

        delete class;
    }
