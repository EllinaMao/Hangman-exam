#pragma once  
#include <iostream>  
#include <string>  
#include <conio.h>

struct InputIO {  
public:
   static char GetCh() {  
       char ch;  
       ch = _getch(); 
       return ch; 
   }  
};
