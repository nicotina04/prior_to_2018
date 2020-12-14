// Exercise 10.8 Solution: CommissionEmployee.java
// CommissionEmployee class derived from Employee.
/** The class inherited from Employee.*/
public class CommissionEmployee extends Employee 
{
   private double grossSales; // gross weekly sales
   private double commissionRate; // commission percentage

   // eight-argument constructor

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
    */
   public CommissionEmployee( String first, String last, String nick, String ssn,
      int month, int day, int year, double sales, double rate )
   {
      super( first, last, nick, ssn, month, day, year );
      setGrossSales( sales );
      setCommissionRate( rate );
   } // end eight-argument CommissionEmployee constructor

   // set commission rate

   /**
    * Sets the CommissionEmployee's commission rate.
    * @param rate A double that rate of commission
    */
   public void setCommissionRate( double rate )
   {
      commissionRate = ( rate > 0.0 && rate < 1.0 ) ? rate : 0.0;
   } // end method setCommissionRate

   // return commission rate

   /**
    * Get commission rate of CommissionEmployee.
    * @return A double that the commission rate of CommissionEmployee
    */
   public double getCommissionRate()
   {
      return commissionRate;
   } // end method getCommissionRate

   // set gross sales amount

   /**
    * Set the CommissionEmployee's gross sales.
    * @param sales A double that the sales of CommissionEmployee
    */
   public void setGrossSales( double sales )
   {
      grossSales = sales < 0.0 ? 0.0 : sales;
   } // end method setGrossSales

   // return gross sales amount

   /**
    * Get the CommissionEmployee's gross sales.
    * @return A double that the gross sales of CommissionEmployee
    */
   public double getGrossSales()
   {
      return grossSales;
   } // end method getGrossSales

   // calculate earnings; override abstract method earnings in Employee
   @Override
   /*
    * Caculate CommissionEmployee's income.
    * @return A double that the income of CommissionEmployee
    */
   public double earnings()
   {
      return getCommissionRate() * getGrossSales();
   } // end method earnings

   // return String representation of CommissionEmployee object
   @Override

   public String toString()
   {
      return String.format( "%s: %s\n%s: $%,.2f; %s: %.2f", 
         "commission employee", super.toString(), 
         "gross sales", getGrossSales(), 
         "commission rate", getCommissionRate() );
   } // end method toString   
} // end class CommissionEmployee

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
