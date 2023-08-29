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

#define _CRT_SECURE_NO_WARNINGS
#include "Error.h"
#include <cstring>
#include <string>
#include"POS.h"

using namespace std;

namespace sdds
{
   Error::Error(const char* str)
   {
      if (str != nullptr && str[0] != '\0')
      {
         this->errMsg = nullptr;
         this->errMsg = new char[strlen(str) + 1];

         strcpy(this->errMsg, str);

      }
      else
      {
         str = nullptr;
      }
   }
   Error::Error(const Error& err)
   {
      this->errMsg = nullptr;
      *this = err;
   }

   Error& Error::operator=(const Error& err)
   {
      if (this != &err)
      {
         if (this->errMsg != nullptr)
         {
            delete[] this->errMsg;
         }

         this->errMsg = nullptr;

         if (err.errMsg != nullptr)
         {
            this->errMsg = new char[strlen(err.errMsg) + 1];
            strcpy(this->errMsg, err.errMsg);
         }
         else
            this->errMsg = nullptr;
      }
      else
         this->errMsg = nullptr;

      return *this;
   }

   Error& Error::operator=(const char* str)
   {
      if (str != nullptr && str[0] != '\0')
      {
         if (this->errMsg != nullptr)
            delete[] this->errMsg;

         this->errMsg = nullptr;

         this->errMsg = new char[strlen(str) + 1];
         strcpy(this->errMsg, str);
      }

      return *this;
   }

   Error::operator bool()const
   {
      return this->errMsg != nullptr;
   }

   Error& Error::clear()
   {
      if (this->errMsg != nullptr)
         delete[] this->errMsg;
      this->errMsg = nullptr;

      return *this;
   }

   void Error::read(ostream& os) const
   {
      os << this->getMsg();
   }

   Error::~Error()
   {
      delete[] this->errMsg;
      this->errMsg = nullptr;
   }
   const char* Error::getMsg() const
   {
      return this->errMsg;
   }
   ostream& operator<<(ostream& os, const Error& error)
   {
      if (error)
      {
         error.read(os);
      }

      return os;
   }
}