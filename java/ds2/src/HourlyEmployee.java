// Exercise 10.8 Solution: HourlyEmployee.java
// HourlyEmployee class derived from Employee.
/** The class inherited from Employee.*/
public class HourlyEmployee extends Employee 
{
   private double wage; // wage per hour
   private double hours; // hours worked for week

   // eight-argument constructor

   /**
    * Initialize the class.
    * @param first A string that employee's first name
    * @param last A string that employee's last name
    * @param ssn A string that employee's SSN
    * @param month An integer that employee's birth month
    * @param day An integer that employee's birth day
    * @param year An integer that employee's birth year
    * @param hourlyWage A double that employee's hourly wage
    * @param hoursWorked A double that employee's worked hours
    */
   public HourlyEmployee( String first, String last, String nick, String ssn,
      int month, int day, int year,
      double hourlyWage, double hoursWorked )
   {
      super( first, last, nick, ssn, month, day, year );
      setWage( hourlyWage );
      setHours( hoursWorked );
   } // end eight-argument HourlyEmployee constructor

   // set wage

   /**
    * Set the HourlyEmployee's wage.
    * @param hourlyWage A double that the wage of HourlyEmployee
    */
   public void setWage( double hourlyWage )
   {
      wage = hourlyWage < 0.0 ? 0.0 : hourlyWage;
   } // end method setWage

   // return wage

    /**
     * Get the wage of HourlyEmployee.
     * @return A double that the wage of HourlyEmployee
     */
   public double getWage()
   {
      return wage;
   } // end method getWage

   // set hours worked

    /**
     * Set the HourlyEmployee's worked hours.
     * @param hoursWorked A double that the HourlyEmployee's worked hours
     */
   public void setHours( double hoursWorked )
   {
      hours = ( ( hoursWorked >= 0.0 ) && ( hoursWorked <= 168.0 ) ) ?
         hoursWorked : 0.0;
   } // end method setHours

   // return hours worked

    /**
     * Get worked hours of HourlyEmployee.
     * @return A double that worked hours of HourlyEmployee
     */
   public double getHours()
   {
      return hours;
   } // end method getHours

   // calculate earnings; override abstract method earnings in Employee
   @Override
   /*
    * Caculate HourlyEmployee's income.
    * @return A double that the income of HourlyEmployee
    */
   public double earnings()
   {
      if ( getHours() <= 40 ) // no overtime
         return getWage() * getHours();
      else
         return 40 * getWage() + ( getHours() - 40 ) * getWage() * 1.5;
   } // end method earnings

   // return String representation of HourlyEmployee object
   @Override
   public String toString()
   {
      return String.format( "hourly employee: %s\n%s: $%,.2f; %s: %,.2f", 
         super.toString(), "hourly wage", getWage(), 
         "hours worked", getHours() );
   } // end method toString
} // end class HourlyEmployee

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
