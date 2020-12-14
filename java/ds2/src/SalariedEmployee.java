// Exercise 10.8 Solution: SalariedEmployee.java
// SalariedEmployee class derived from Employee.

/** The class inherited from Employee */
public class SalariedEmployee extends Employee 
{
   private double weeklySalary;

   // seven-argument constructor

   /**
    * Initialize the class.
    * @param first A string that employee's first name
    * @param last A string that employee's last name
    * @param ssn A string that employee's SSN
    * @param month An integer that employee's birth month
    * @param day An integer that employee's birth day
    * @param year An integer that employee's birth year
    * @param salary A double that employee's salary
    */
   public SalariedEmployee( String first, String last, String nick, String ssn,
      int month, int day, int year, double salary )
   {
      super( first, last, nick, ssn, month, day, year );
      setWeeklySalary( salary );
   } // end seven-argument SalariedEmployee constructor

   // set salary

   /**
    * Set the SalariedEmployee's weekly salary.
    * @param salary A double that the weekly salary of SalariedEmployee
    */
   public void setWeeklySalary( double salary )
   {
      weeklySalary = salary < 0.0 ? 0.0 : salary;
   } // end method setWeeklySalary

   // return salary

   /**
    * Get the SalariedEmployee's weekly salary.
    * @return A double that the weekly salary of SalariedEmployee
    */
   public double getWeeklySalary()
   {
      return weeklySalary;
   } // end method getWeeklySalary

   // calculate earnings; override abstract method earnings in Employee
   @Override
   public double earnings()
   {
      return getWeeklySalary();
   } // end method earnings

   // return String representation of SalariedEmployee object
   @Override
   public String toString()
   {
      return String.format( "salaried employee: %s\n%s: $%,.2f", 
         super.toString(), "weekly salary", getWeeklySalary() );
   } // end method toString   
} // end class SalariedEmployee

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
