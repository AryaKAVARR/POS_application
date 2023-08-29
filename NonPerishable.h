/* Citation and Sources...
Final Project Milestone 4
Module: NonPerishable
Filename: NonPerishable.h
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
#ifndef SDDS_NONPERISHABLE
#define SDDS_NONPERISHABLE
#include "Item.h"

namespace sdds
{
   class NonPerishable : public Item
   {

      //overriding ItemType to identify as a Non-Perishable 
      char ItemType() const;

   public:

      ~NonPerishable();
      std::ofstream& save(std::ofstream& file)const;
      //overriding write method of base class
      std::ostream& write(std::ostream& ostr)const;

   };
}
#endif // !SDDS_NONPERISHABLE
