// Exercise 10.8 Solution: Employee.java
// Employee abstract superclass.
import java.util.Calendar;

/**An Abstract class for Class of Employees. */
public abstract class Employee 
{

   private String socialSecurityNumber;
   private Date birthDate;
   private Date joinDate;
   private Name empname;

   // six-argument constructor
   /**
    * Initialize the class.
    * @param ssn A string that employee's SSN
    * @param month An integer that employee's birth month
    * @param day An integer that employee's birth day
    * @param year An integer that employee's birth year
    */
   public Employee( String first, String last, String nick, String ssn,
      int month, int day, int year )
   {
      empname = new Name(first, last, nick);
      socialSecurityNumber = ssn;
      birthDate = new Date( month, day, year );
      //joinDate = new Date(1,1, 0);
   } // end six-argument Employee constructor


   // set first name

   /**
    * Sets the Employee's first name.
    * @param first A string that Employee's first name
    */
//   public void setFirstName( String first )
//   {
//      firstName = first;
//   } // end method setFirstName

   // return first name

   /**
    * Gets the Employee's first name.
    * @return A string that Employee's first name
    */
//   public String getFirstName()
//   {
//      return firstName;
//   } // end method getFirstName

   // set last name
   /**
    * Sets the Employee's last name.
    * @param last A string that Employee's last name
    */
//   public void setLastName( String last )
//   {
//      lastName = last;
//   } // end method setLastName

   // return last name
   /**
    * Gets the Employee's last name.
    * @return A string that Employee's last name
    */
//   public String getLastName()
//   {
//      return lastName;
//   } // end method getLastName

   public Name myName()
   {
      return empname;
   }

   // set social security number
   /**
    * Sets the Employee's SSN.
    * @param ssn A string that Employee's Social Security Number
    */
   public void setSocialSecurityNumber( String ssn )
   {
      socialSecurityNumber = ssn;  // should validate
   } // end method setSocialSecurityNumber

   // return social security number

   /**
    * Gets ther Employee's SSN.
    * @return A string that Employee's Social Security Number
    */
   public String getSocialSecurityNumber()
   {
      return socialSecurityNumber;
   } // end method getSocialSecurityNumber

   // set birth date

   /**
    * Set the Employee's birth day.
    * @param month A string that Employee's Birth month
    * @param day A string that Employee's Birth day
    * @param year A string that Employee's Birth year
    */
   public void setBirthDate( int month, int day, int year )
   {
      birthDate = new Date( month, day, year );
   } // end method setBirthDate

   // return birth date

   /**
    * Get the Employee's birth day.
    * @return A date that Employee's birth month, day and year
    */
   public Date getBirthDate()
   {
      return birthDate;
   } // end method getBirthDate

   /**
    * Set the join date of employee.
    * @param month A string that Employee's join month
    * @param day A string that Employee's join day
    * @param year A string that Employee's join year
    */
   public void setJoinDate(int month, int day, int year)
   {
      joinDate = new Date(month, day, year);
   }

   /**
    * Get the join date of employee.
    * @return A Date that Employee's join date
    */
   public Date getJoinDate() { return joinDate; }

   /**
    * Give birth day bonus.
    * @param now A Calender that date of today
    * @return A double that birth day bonus if Employee's join month equal to present month
    */
   public double birthbonus(Calendar now)
   {
      double bonus = 100.0;
      Date data = getBirthDate();
      int y = data.getMonth();
      if(y == (now.get(Calendar.MONTH) + 1))
      {
         return bonus;

      }
      else {return 0;}
   }

   /**
    * Give service bonus.
    * @param basicearning A double that the default income of employee
    * @param now A Calender that date of today
    * @return A double that service bonus if service duration over the 10 years
    */
   public double servicebonus(double basicearning, Calendar now)
   {
      Date data = getJoinDate();
      int joiny = data.getYear();
      int joinm = data.getMonth();
      int joind = data.getDay();
      int serviceyear = now.get(Calendar.YEAR) - joiny;
      int servicemonth = now.get(Calendar.MONTH) + 1 - joinm;
      int serviceday = now.get(Calendar.DAY_OF_MONTH) - joind;
      if(serviceyear > 10)
      {
         return basicearning * 0.1;
      }
      else if(serviceyear == 10 && servicemonth > 0)
      {
         return basicearning * 0.1;
      }
      else if(servicemonth == 0 && serviceday > 0)
      {
         return basicearning * 0.1;
      }
      else
      {
         return 0;
      }
   }
   // return String representation of Employee object
   @Override
   public String toString()
   {
      return String.format( "%s %s\n%s: %s\n %s", "social security number", getSocialSecurityNumber(), "birth date", getBirthDate(), empname.toString());
   } // end method toString

   // abstract method overridden by subclasses

   /**
    * Calculate employee's default income.
    * @return A double that default income of employee
    */
   public abstract double earnings();
} // end abstract class Employee

/**************************************************************************
 * (C) Copyright 1992-2010 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/ 