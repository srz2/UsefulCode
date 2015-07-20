#include "Log.h"

int main()
{
    Log * log = Log::Instance();
    
    log->write("Hello");
}