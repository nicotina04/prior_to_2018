import java.util.*;

/** An Main class for payroll system. */
public class Answer
{
    public static void main(String[] args)
    {
        LinkedBag<Employee> bagpeople = new LinkedBag<>();

        String firstname;
        String lastname;
        String nickname;
        String SSN;
        int month, day ,year;
        int jmonth, jday, jyear;
        int level;

        Scanner inputer = new Scanner(System.in);

        for(int i = 0; i < 10; ++i)
        {
            int mode;
            System.out.println("Select mode (1 - assault 2 - homework)");
            mode = inputer.nextInt();

            if(mode == 1)
            {
                System.out.println("Detect assault progress. Initiate assault.");
                CommissionEmployee zero = new CommissionEmployee("one", "il", "CAMARO", "111-11-111", 12, 20, 1989, 6000, 0.08);
                zero.setJoinDate(10, 30, 2000);
                BasePlusCommissionEmployee one = new BasePlusCommissionEmployee("two", "yee", "DINO","222-22-222", 2, 22, 1972, 5000, 0.05, 290);
                one.setJoinDate(3, 20, 2008);
                SalariedEmployee two = new SalariedEmployee("Ssumy", "kos", "JIM", "329-23-901", 10, 22, 1969, 3890);
                two.setJoinDate(3, 20, 2008);
                SalariedEmployee three = new SalariedEmployee("Herdson", "Koshtoka", "NUEA","708-47-171", 12, 4, 1998, 9000);
                three.setJoinDate(9, 3, 2018);
                SalariedEmployee four = new SalariedEmployee("Whitcher","James", "GOSU","123-12-123", 2, 24, 1970, 4550);
                four.setJoinDate(11,11,2007);
                HourlyEmployee five = new HourlyEmployee("Six", "Rainbow", "GOM","666-66-666", 3, 3, 1988, 15.9, 45);
                five.setJoinDate(11, 11, 2007);
                BasePlusCommissionEmployee six = new BasePlusCommissionEmployee("Rison", "Kops", "JOFIA", "531-29-182", 5, 27, 1990, 4800, 0.07, 300);
                six.setJoinDate(3, 7, 2010);
                BasePlusCommissionEmployee seven = new BasePlusCommissionEmployee("gatka", "elen", "ELA","437-22-009", 8, 29, 1973, 5000, 0.06, 500);
                seven.setJoinDate(3, 3, 2003);
                SalariedEmployee eight = new SalariedEmployee("Nine", "UMP", "BIGGUN","999-99-999", 9, 9, 1979, 9999);
                eight.setJoinDate(9, 9, 2000);
                SalariedEmployee nine = new SalariedEmployee("Master", "Joe", "THE KING","101-01-111", 10, 10, 1981, 10000);
                nine.setJoinDate(4, 22, 2008);
                bagpeople.add(zero);
                bagpeople.add(one);
                bagpeople.add(two);
                bagpeople.add(three);
                bagpeople.add(four);
                bagpeople.add(five);
                bagpeople.add(six);
                bagpeople.add(seven);
                bagpeople.add(eight);
                bagpeople.add(nine);
                break;
            }
            if(i == 0) System.out.println("Press enter button to start.");
            inputer.skip("[\\r\\n]");
            System.out.println(i + 1);
            System.out.print("Write first name : ");
            firstname = inputer.nextLine();
            System.out.print("Write last name : ");
            lastname = inputer.nextLine();
            System.out.print("Write nick name : ");
            nickname = inputer.nextLine();
            System.out.print("Input SSN code : ");
            SSN = inputer.nextLine();
            System.out.print("Input Birth month, day, year : ");
            month = inputer.nextInt();
            day = inputer.nextInt();
            year = inputer.nextInt();
            System.out.println();
            System.out.print("Input join month, day, year : ");
            jmonth = inputer.nextInt();
            jday = inputer.nextInt();
            jyear = inputer.nextInt();
            System.out.println();
            System.out.println("Select - 1 : CommissionEmployee 2 : HourlyEmployee 3 : SalariedEmployee\n" +
                    "4 : BasePlusCommissionEmployee");
            level = inputer.nextInt();
            switch (level)
            {
                case 1:
                    double sales, rate;
                    System.out.print("Put in sales and rate : ");
                    sales = inputer.nextDouble();
                    rate = inputer.nextDouble();
                    CommissionEmployee ctemp = new CommissionEmployee(firstname, lastname, nickname, SSN, month, day, year, sales, rate);
                    ctemp.setJoinDate(jmonth, jday, jyear);
                    bagpeople.add(ctemp);
                    System.out.println();
                    break;
                case 2:
                    double wage, hours;
                    System.out.print("Put in wage and hours : ");
                    wage = inputer.nextDouble();
                    hours = inputer.nextDouble();
                    HourlyEmployee htemp = new HourlyEmployee(firstname, lastname, nickname, SSN, month, day, year, wage, hours);
                    htemp.setJoinDate(jmonth, jday, jyear);
                    bagpeople.add(htemp);
                    System.out.println();
                    break;
                case 3:
                    double salary;
                    System.out.print("Input salary : ");
                    salary = inputer.nextDouble();
                    SalariedEmployee stemp = new SalariedEmployee(firstname, lastname, nickname, SSN, month, day, year, salary);
                    stemp.setJoinDate(jmonth, jday, jyear);
                    bagpeople.add(stemp);
                    System.out.println();
                    break;
                case 4:
                    double sales4, rate4, salary4;
                    System.out.print("Input sales, rage and salary : ");
                    sales4 = inputer.nextDouble();
                    rate4 = inputer.nextDouble();
                    salary4 = inputer.nextDouble();
                    BasePlusCommissionEmployee bctemp = new BasePlusCommissionEmployee(firstname, lastname, nickname, SSN, month, day, year, sales4, rate4, salary4);
                    bctemp.setJoinDate(jmonth, jday, jyear);
                    bagpeople.add(bctemp);
                    System.out.println();
                    break;
                default:
                    System.out.println("Making CommissionEmployee.");
                    double salesd, rated;
                    System.out.print("Put in sales and rate : ");
                    salesd = inputer.nextDouble();
                    rated = inputer.nextDouble();
                    CommissionEmployee defaultemp = new CommissionEmployee(firstname, lastname, nickname, SSN, month, day, year, salesd, rated);
                    defaultemp.setJoinDate(jmonth, jday, jyear);
                    bagpeople.add(defaultemp);
                    System.out.println();
                    break;
            }
        }
        inputer.close();

        LinkedBag<Employee> peoplecollection = new LinkedBag<>();

        while(!bagpeople.isEmpty())
        {
            Employee tmp = bagpeople.remove();
            double basicincome = tmp.earnings();
            if(tmp instanceof BasePlusCommissionEmployee)
            {
                BasePlusCommissionEmployee employee = (BasePlusCommissionEmployee)tmp;
                double old = employee.getBaseSalary();
                employee.setBaseSalary(old * 1.10);
                System.out.printf("new base salary with 10%% increase is: $%,.2f\n", employee.getBaseSalary() );
                tmp = employee;
            }
            peoplecollection.add(tmp);

            System.out.printf("Employee %d is a %s\n", peoplecollection.getCurrentSize(), tmp.getClass().getName());
            System.out.println("Basic income of " + tmp.myName().toString());
            System.out.println(basicincome + "$");
            Calendar c1 = Calendar.getInstance();

            System.out.println("Now calculate bonus income");
            double bonus = tmp.birthbonus(c1);
            double service = tmp.servicebonus(basicincome, c1);
            basicincome += bonus + service;
            if(bonus > 0)  System.out.println("Happy birth day!! You gain " + bonus + "$");
            System.out.println("Your service bonus : " + service + "$");
            System.out.println("total income of " + tmp.myName().getFirstName() + " " + tmp.myName().getLastName() + " a.k.a " + tmp.myName().getNickName());
            System.out.println(basicincome + "$");
        }
        while(!peoplecollection.isEmpty())
        {
            bagpeople.add(peoplecollection.remove());
        }

        System.out.println("\nFirst calculating complete. Now check order of bag is correct.\n");

        while(!bagpeople.isEmpty())
        {
            Employee tmp = bagpeople.remove();
            double basicincome = tmp.earnings();
            if(tmp instanceof BasePlusCommissionEmployee)
            {
                BasePlusCommissionEmployee employee = (BasePlusCommissionEmployee)tmp;
                double old = employee.getBaseSalary();
                employee.setBaseSalary(old * 1.10);
                System.out.printf("new base salary with 10%% increase is: $%,.2f\n", employee.getBaseSalary() );
                tmp = employee;
            }
            peoplecollection.add(tmp);

            System.out.printf("Employee %d is a %s\n", peoplecollection.getCurrentSize(), tmp.getClass().getName());
            System.out.println("Basic income of " + tmp.myName().toString());
            System.out.println(basicincome + "$");
            Calendar c1 = Calendar.getInstance();

            System.out.println("Now calculate bonus income");
            double bonus = tmp.birthbonus(c1);
            double service = tmp.servicebonus(basicincome, c1);
            basicincome += bonus + service;
            if(bonus > 0)  System.out.println("Happy birth day!! You gain " + bonus + "$");
            System.out.println("Your service bonus : " + service + "$");
            System.out.println("total income of " + tmp.myName().getFirstName() + " " + tmp.myName().getLastName() + " a.k.a " + tmp.myName().getNickName());
            System.out.println(basicincome + "$");
        }
        while(!peoplecollection.isEmpty())
        {
            bagpeople.add(peoplecollection.remove());
        }
    }
}
