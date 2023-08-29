/* Citation and Sources...
Final Project Milestone ?
Module: Error
Filename: Error.cpp
Version 1.0
Author	Asad Norouzi
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#ifndef SDDS_ERROR
#define SDDS_ERROR
#include <iostream>
#include"PosIO.h"
#include<fstream>


namespace sdds
{
   class Error
   {
      char* errMsg{};

   public:
      //default constructor
      Error() : errMsg{ nullptr } {};

      //constructor
      Error(const char* str);

      //copy constructor
      Error(const Error& err);

      //copy assignment operator
      Error& operator=(const Error& err);

      //assignment operator
      Error& operator=(const char* str);

      //bool operator overloading
      operator bool()const;

      //clear function
      Error& clear();

      //return the cstring
      void read(std::ostream& os)const;

      //destructor
      ~Error();

      //extra function
      const char* getMsg()const;
   };
   std::ostream& operator<<(std::ostream& os, const Error& error);
}
#endif // !SDDS_ERROR
