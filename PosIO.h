/* Citation and Sources...
Final Project Milestone 3
Module: PosIO
Filename: PosIO.h
Version 1.0
Author	Arya Kavar
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
#ifndef SDDS_PosIO
#define SDDS_PosIO
#include<fstream>
#include <iostream>

namespace sdds
{
   class PosIO
   {
   public:

      virtual std::ostream& write(std::ostream& ostr)const = 0;
      virtual std::istream& read(std::istream& istr) = 0;
      virtual std::ofstream& save(std::ofstream& file)const = 0;
      virtual std::ifstream& load(std::ifstream& file) = 0;
   };
   //insertion operator for write and save method
   std::ostream& operator<<(std::ostream& ostr, const PosIO& pos);
   std::ofstream& operator<<(std::ofstream& file, const PosIO& pos);

   //extraction operator for read and load method
   std::istream& operator>>(std::istream& istr, PosIO& pos);
   std::ifstream& operator>>(std::ifstream& file, PosIO& pos);
}
#endif // !SDDS_PosIO
