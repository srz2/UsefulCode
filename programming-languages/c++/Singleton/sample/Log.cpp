#include "Log.h"

Log * Log::instance = NULL;    //Initiates instance to NULL

Log * Log::Instance()          //Accessor to instance definition
{
    if(!instance)              //If instance is NULL
        instance = new Log();      //create a new class (this should only happen once)
    return instance;           //return instance of class
}

Log::Log()                     //Constructor
{
    
}

Log::~Log()                     //Deconstructor
{
    
}

Log::Log(const Log & other)    //Copy Constructor
{
    
}

Log& Log::operator = (const Log & other)  //Assignement
{
    return *this;
}

void Log::write(char * msg)
{
    cout << msg << endl;
}