/* Citation and Sources...
Final Project Milestone 1
Module: Date
Filename: Date.h
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

#ifndef SDDS_Date
#define SDDS_Date
#include <iostream>
#include "Error.h"
#include "POS.h"

using namespace std;

namespace sdds
{
   const int MIN_MONTH = 1;
   const int MAX_MONTH = 12;
   const int MIN_TIME_HOUR = 0;
   const int MAX_TIME_HOUR = 23;
   const int MIN_TIME_MIN = 0;
   const int MAX_TIME_MIN = 59;

   class Date
   {
      int m_year{};
      int m_month{};
      int m_day{};
      int m_hour{};
      int m_minute{};
      bool m_dateOnly{};
      Error m_err{};

      //validating
      bool validData();

   public:
      //set the data to empty state
      void setEmpty();

      //bool is empty
      bool isEmpty()const;

      void SetMode(bool date);

      //default constructor
      Date();
      //constructor
      Date(int year, int month, int day, int hour, int min = 0);

      //3 argument constructor
      Date(int year, int month, int day);

      //copy constructor
      Date(const Date& dt);

      //copy assignment constructor
      Date& operator=(const Date& dt);

      //return number of days
      int daysOfMonth(int year, int month)const;

      //to get the system date
      void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);

      //compare both the date with a special function
      int uniqueDateValue(int year, int mon, int day, int hour, int min)const;

      //comparison operator 
      bool operator==(const Date& rhs);
      bool operator!=(const Date& rhs);
      bool operator<(const Date& rhs);
      bool operator>(const Date& rhs);
      bool operator<=(const Date& rhs);
      bool operator>=(const Date& rhs);

      //dateonly Method
      Date& dateOnly(bool flag);

      //bool type conversion
      operator bool()const;

      //the error query
      const Error& error() const { return m_err; }

      //write function
      void write(std::ostream& ostr)const;

      //read functiom
      std::istream& read(std::istream& istr);

   };
   //ostream insertion operator
   ostream& operator<<(ostream& ostr, const Date& date);

   //extraction operator
   istream& operator>>(istream& istr, Date& date);
}
#endif // !SDDS_Date
