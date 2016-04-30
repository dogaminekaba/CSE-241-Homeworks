/*	Doğa Mine Kaba 121044004 HW8
 * 	
 * 	Person Class
 */

package javaapplication1;

public class Person
{
	private String name;
	private String lastName;
	private int birthYear;
	private String gender;
        private static int numOfPersons = 0;

	public Person()
	{
		name = "Blank";
		lastName = "Blank";
		birthYear = 0;
		gender = "Undefined";
                numOfPersons++;
	}
	public Person(String userName, String userLastName, 
					int userBirthYear, String newGender)
	{
		name = userName;
		lastName = userLastName;
		birthYear = userBirthYear;
                newGender.toLowerCase();
                if (newGender.contains("female")) {
                    gender = "female";
                }
                else if (newGender.contains("male")) {
                    gender = "male";
                }
                else
                    gender = "Undefined";
                numOfPersons++;
	}
        public int getNumOfPersons()
        {
            return numOfPersons;
        }
        public int decNumOfPersons()
        {
            --numOfPersons;
            return numOfPersons;
        }
	public void setName(final String userName)
	{
		name = userName;
	}
	public void setLastName(final String userLastName)
	{
		lastName = userLastName;
	}
	public void setBirthYear(final int userBirthYear)
	{
		birthYear = userBirthYear;
	}
	public void setGender(String newGender)
	{
                newGender.toLowerCase();
                if (newGender.contains("female")) {
                    gender = "female";
                }
                else if (newGender.contains("male")) {
                    gender = "male";
                }
                else
                    gender = "Undefined";
	}
	public final String getName()
	{
		return name;
	}
	public final String getLastName()
	{
		return lastName;
	}
	public final int getBirthYear()
	{
		return birthYear;
	}
	public final String getGender()
	{
		return gender;
	}
	public final String toString()
	{
		return (name + " " + lastName + " " + birthYear + " " + gender);
	}
}
