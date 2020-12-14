// Exercise 10.8 Solution: BasePlusCommissionEmployee.java
// BasePlusCommissionEmployee class derived from CommissionEmployee.
/** The class inherited from Employee.*/
public class BasePlusCommissionEmployee extends CommissionEmployee 
{
   private double baseSalary; // base salary per week

   // nine-argument constructor

   /**
    * Initialize the class.
    * @param first A string that employee's first name
    * @param last A string that employee's last name
    * @param ssn A string that employee's SSN
    * @param month An integer that employee's birth month
    * @param day An integer that employee's birth day
    * @param year An integer that employee's birth year
    * @param sales A double that employee's gross sales
    * @param rate A double that employee's commission rate
    * @param salary A double that employee's salary
    */
   public BasePlusCommissionEmployee( String first, String last, String nick,
      String ssn, int month, int day, int year, 
      double sales, double rate, double salary )
   {
      super( first, last, nick, ssn, month, day, year, sales, rate );
      setBaseSalary( salary );
   } // end nine-argument BasePlusCommissionEmployee constructor

   // set base salary

   /**
    * Set the base salary of BasePlusCommissionEmployee.
    * @param salary A double that the salary of BasePlusCommissionEmployee
    */
   public void setBaseSalary( double salary )
   {
      baseSalary = salary < 0.0 ? 0.0 : salary; // non-negative
   } // end method setBaseSalary

   // return base salary

   /**
    * Get the base salary of BasePlusCommissionEmployee.
    * @return A double that the BasePlusCommissionEmployee's base salary
    */
   public double getBaseSalary()
   {
      return baseSalary;
   } // end method getBaseSalary

   // calculate earnings; override method earnings in CommissionEmployee
   @Override
   public double earnings()
   {
      return getBaseSalary() + super.earnings();
   } // end method earnings

   // return String representation of BasePlusCommissionEmployee object
   @Override
   public String toString()
   {
      return String.format( "%s %s; %s: $%,.2f", 
         "base-salaried", super.toString(), 
         "base salary", getBaseSalary() );
      } // end method toString
} // end class BasePlusCommissionEmployee

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
