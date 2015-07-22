#include <iostream>
using namespace std;

class Log
{
private:
    static Log * instance;                 //Keeps track of instance of class
    
    Log();                                 //Private Constructor
    Log(const Log & other);                //Private Copy Constructor
    Log & operator = (const Log & other);  //Private  Assignment Constructor
public:
    static Log * Instance();               //Accessor to instance
    virtual ~Log();                        //Destructor
    
    void write(char * msg);                          //Write to log
};