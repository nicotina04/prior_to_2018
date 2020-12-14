public class Name
{
    private String firstname;
    private String lastname;
    private String nickname;

    /**
     * Initialize the Name class.
     * @param fname A string that first name.
     * @param lname A string that last name.
     * @param nname A string that nickname.
     */
    public Name(String fname, String lname, String nname)
    {
        this.firstname = fname;
        this.lastname = lname;
        this.nickname = nname;
    }

    /**
     * Initialize the Name class if no given arguments.
     */
    public Name()
    {
        this("Unknown", "Unknown", "Unknown");
    }

    /**
     * Set the first name of the Name class.
     * @param fname A string that first name.
     */
    public void setFirstName(String fname)
    {
        this.firstname = fname;
    }

    /**
     * Set the first name of the Name class.
     * @param lname A string that last name.
     */
    public void setLastName(String lname)
    {
        this.lastname = lname;
    }

    /**
     * Set the nick name of the Name class.
     * @param nname A string that nick name.
     */
    public void setNickName(String nname)
    {
        this.nickname = nname;
    }

    /**
     * Get the first name of the Name class.
     * @return A string that first name.
     */
    public String getFirstName()
    {
        return this.firstname;
    }

    /**
     * Get the last name of the Name class.
     * @return A string that last name.
     */
    public String getLastName()
    {
        return this.lastname;
    }

    /**
     * Get the nick name of the Name class.
     * @return A string that nick name.
     */
    public String getNickName()
    {
        return this.nickname;
    }

    public String toString()
    {
        return String.format( "Name is %s %s\n and his nick name is %s:", this.getFirstName(), this.getLastName(), this.getNickName());
    }
}
