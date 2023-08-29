/* Citation and Sources...
Final Project Milestone ?
Module: PosIO
Filename: PosIO.cpp
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
#include"PosIO.h"
#include<iostream>

using namespace std;

namespace sdds
{
   std::ostream& operator<<(std::ostream& ostr, const PosIO& pos)
   {
      return pos.write(ostr);
   }
   std::ofstream& operator<<(std::ofstream& file, const PosIO& pos)
   {
      return pos.save(file);
   }
   std::ifstream& operator>>(std::ifstream& file, PosIO& pos)
   {
      return pos.load(file);
   }
   std::istream& operator>>(std::istream& istr, PosIO& pos)
   {
      return pos.read(istr);
   }
}