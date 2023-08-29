/* Citation and Sources...
Final Project Milestone 1
Module: Date
Filename: Date.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include"Date.h"
#include<string>
#include <iomanip>

using namespace std;

namespace sdds
{
   bool Date::validData()
   {
      if (this->m_year < MIN_YEAR || this->m_year > MAX_YEAR)
      {
         this->m_err = "Invalid Year";
         return false;
      }
      if (this->m_month < MIN_MONTH || this->m_month > MAX_MONTH)
      {
         this->m_err = "Invalid Month";
         return false;
      }
      if (this->m_day < 1 || this->m_day > daysOfMonth(m_year, m_month))
      {
         this->m_err = "Invalid Day";
         return false;
      }
      if (this->m_hour < MIN_TIME_HOUR || this->m_hour > MAX_TIME_HOUR)
      {
         this->m_err = "Invalid Hour";
         return false;
      }
      if (this->m_minute < MIN_TIME_MIN || this->m_minute > MAX_TIME_MIN)
      {
         this->m_err = "Invlid Minute";
         return false;
      }

      return true;
   }

   void Date::setEmpty()
   {
      this->m_day = 0;
      this->m_hour = 0;
      this->m_year = 0;
      this->m_minute = 0;
      this->m_month = 0;
   }

   bool Date::isEmpty() const
   {
      return this->m_year == 0;
   }

   void Date::SetMode(bool date)
   {
      this->m_dateOnly = date;
   }

   Date::Date()
   {
      this->getSystemDate(this->m_year, this->m_month, this->m_day, this->m_hour, this->m_minute, this->m_dateOnly);
      this->m_dateOnly = false;
   }
   Date::Date(int year, int month, int day, int hour, int min)
   {
      this->m_year = year;
      this->m_month = month;
      this->m_day = day;
      this->m_hour = hour;
      this->m_minute = min;
      this->m_dateOnly = false;
      this->validData();
   }

   Date::Date(int year, int month, int day)
   {
      this->m_year = year;
      this->m_month = month;
      this->m_day = day;
      this->m_dateOnly = true;
      this->validData();
   }

   Date::Date(const Date& dt)
   {
      *this = dt;
   }

   Date& Date::operator=(const Date& dt)
   {
      if (this != &dt)
      {
         this->m_dateOnly = dt.m_dateOnly;
         this->m_err = dt.m_err;

         if (dt.m_dateOnly)
         {
            this->m_year = dt.m_year;
            this->m_month = dt.m_month;
            this->m_day = dt.m_day;
            this->m_hour = 0;
            this->m_minute = 0;
         }
         else
         {
            this->m_year = dt.m_year;
            this->m_month = dt.m_month;
            this->m_minute = dt.m_minute;
            this->m_hour = dt.m_hour;
            this->m_day = dt.m_day;
         }
      }
      return *this;
   }

   int Date::daysOfMonth(int year, int month)const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = month >= 1 && month <= 12 ? month : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
   }

   void Date::getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly)
   {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      day = lt.tm_mday;
      mon = lt.tm_mon + 1;
      year = lt.tm_year + 1900;
      if (dateOnly) {
         hour = min = 0;
      }
      else {
         hour = lt.tm_hour;
         min = lt.tm_min;
      }
   }

   int Date::uniqueDateValue(int year, int mon, int day, int hour, int min)const
   {
      return year * 535680 + mon * 44640 + day * 1440 + hour * 60 + min;
   }

   bool Date::operator==(const Date& rhs)
   {
      return this->uniqueDateValue(this->m_year, this->m_month, this->m_day, this->m_hour, this->m_minute) == rhs.uniqueDateValue(rhs.m_year, rhs.m_month, rhs.m_day, rhs.m_hour, rhs.m_minute);
   }
   bool Date::operator!=(const Date& rhs)
   {
      return this->uniqueDateValue(this->m_year, this->m_month, this->m_day, this->m_hour, this->m_minute) != rhs.uniqueDateValue(rhs.m_year, rhs.m_month, rhs.m_day, rhs.m_hour, rhs.m_minute);
   }

   bool Date::operator<(const Date& rhs)
   {
      return this->uniqueDateValue(this->m_year, this->m_month, this->m_day, this->m_hour, this->m_minute) < rhs.uniqueDateValue(rhs.m_year, rhs.m_month, rhs.m_day, rhs.m_hour, rhs.m_minute);
   }

   bool Date::operator>(const Date& rhs)
   {
      return this->uniqueDateValue(this->m_year, this->m_month, this->m_day, this->m_hour, this->m_minute) > rhs.uniqueDateValue(rhs.m_year, rhs.m_month, rhs.m_day, rhs.m_hour, rhs.m_minute);
   }

   bool Date::operator<=(const Date& rhs)
   {
      return this->uniqueDateValue(this->m_year, this->m_month, this->m_day, this->m_hour, this->m_minute) <= rhs.uniqueDateValue(rhs.m_year, rhs.m_month, rhs.m_day, rhs.m_hour, rhs.m_minute);
   }

   bool Date::operator>=(const Date& rhs)
   {
      return this->uniqueDateValue(this->m_year, this->m_month, this->m_day, this->m_hour, this->m_minute) >= rhs.uniqueDateValue(rhs.m_year, rhs.m_month, rhs.m_day, rhs.m_hour, rhs.m_minute);
   }

   Date& Date::dateOnly(bool flag)
   {
      this->m_dateOnly = flag;
      if (flag == true)
      {
         this->m_hour = 0;
         this->m_minute = 0;
      }

      return *this;
   }

   Date::operator bool()const
   {
      return !m_err;
   }

   void Date::write(std::ostream& ostr) const
   {
      if (!this->isEmpty())
      {
         if (this->m_err)
            ostr << this->m_err << "(";

         ostr << this->m_year << "/";
         if (this->m_month < 10) ostr << "0";
         ostr << this->m_month << "/";
         if (this->m_day < 10) ostr << "0";
         ostr << this->m_day;
         if (!this->m_dateOnly) {
            ostr << ", ";
            if (this->m_hour < 10) ostr << "0";
            ostr << this->m_hour << ":";
            if (this->m_minute < 10) ostr << "0";
            ostr << this->m_minute;
         }

         if (this->m_err)
            ostr << ")";
      }
      else
      {
         ostr << endl;
      }
   }

   istream& Date::read(std::istream& istr)
   {
      this->m_err.clear();
      this->setEmpty();
      istr >> m_year;
      if (istr.fail()) {
         this->m_day = 0;
         this->m_hour = 0;
         this->m_year = 0;
         this->m_minute = 0;
         this->m_month = 0;
         m_err = "Cannot read year entry";
         return istr;
      }
      istr.ignore();
      istr >> m_month;
      if (istr.fail()) {
         this->m_minute = 0;
         this->m_month = 0;
         this->m_day = 0;
         this->m_hour = 0;
         m_err = "Cannot read month entry";
         return istr;
      }
      istr.ignore();
      istr >> this->m_day;
      if (istr.fail()) {
         this->m_minute = 0;
         this->m_day = 0;
         this->m_hour = 0;
         m_err = "Cannot read day entry";
         return istr;
      }
      if (!this->m_dateOnly) {
         istr.ignore();
         istr >> m_hour;
         if (istr.fail()) {
            this->m_minute = 0;
            this->m_hour = 0;
            m_err = "Cannot read hour entry";
            return istr;
         }
         istr.ignore();
         istr >> m_minute;
         if (istr.fail()) {
            this->m_minute = 0;
            m_err = "Cannot read minute entry";
            return istr;
         }
      }
      else
      {
         this->m_hour = 0;
         this->m_minute = 0;
      }

      this->validData();
      return istr;
   }

   ostream& operator<<(ostream& ostr, const Date& date)
   {
      date.write(ostr);

      return ostr;
   }
   istream& operator>>(istream& istr, Date& date)
   {
      return date.read(istr);
   }
}