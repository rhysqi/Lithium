#include "../../include/Lithium.hh"

void check_ASLR();
void check_AntiDebugger();

void Bootstrap()
{
    #ifndef _DEBUG
    #define _DEBUG
    
    check_ASLR();
    check_AntiDebugger();
    
    #endif /* _DEBUG */
}

void check_ASLR()
{
    
}

void check_AntiDebugger()
{
    
}