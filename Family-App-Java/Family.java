/*	Doğa Mine Kaba 121044004 HW8
 * 	
 * 	Family class
 */

package javaapplication1;

public class Family
{
	private Person mother;
	Person father;
	private Person [] children;
	private int numOfChildren;
	private static int numOfFamilies=0;
	
	public Family(Person newMother, Person newFather)
	{	
		try
		{
			if((newMother.getGender() == "female") && (newFather.getGender() == "male"))
			{
				mother = newMother;
				father = newFather;
			}
			else if((newMother.getGender() == "male") && (newFather.getGender() == "female"))
			{
				mother = newFather;
				father = newMother;
			}
			else
			{
				throw new Exception("Parents must consist of a male and a female person.");
			}
		}
		catch(Exception e)
		{
			String message = e.getMessage();
			System.out.println(message);
			System.exit(0);
		}
		children = new Person[1];
		++ numOfFamilies;
		numOfChildren=0;
	}

        Family()
        {}
	public Person getMother()
	{
		return mother;
	}
	public Person getFather()
	{
		return father;
	}
	public Person[] getChildren()
	{
		return children;
	}
	public final int getNumOfChildren()
	{
		return numOfChildren;
	}
	public final int getNumOfFamilies()
	{
		return numOfFamilies;
	}
	public void add(Person newChild)
	{
		if(numOfChildren == 0)
		{
			children[0] = newChild;
		}
		else
		{
			Person [] tempChildArr = new Person[(numOfChildren + 1)];
			for(int i=0; i<numOfChildren; ++i)
			{
				tempChildArr[i] = children[i];
			}
			children = new Person[(numOfChildren + 1)];
			for(int i=0; i<(numOfChildren); ++i)
			{
				children[i] = tempChildArr[i];
			}
			children[numOfChildren] = newChild;
		}
		++numOfChildren;
	}
	public boolean isFamilyEqualTo(Family family2)
	{
		boolean isEqual = false;
		
		if	((family2.mother.getName() == mother.getName()) &&
			(family2.mother.getLastName() == mother.getLastName()) &&
			(family2.mother.getBirthYear() == mother.getBirthYear()) &&
			(family2.father.getName() == father.getName()) &&
			(family2.father.getLastName() == father.getLastName()) &&
			(family2.father.getBirthYear() == father.getBirthYear()))
		{
			if(family2.numOfChildren == numOfChildren)
			{
				isEqual = true;
				for(int i=0; i<numOfChildren; ++i)
				{
					if	((family2.children[i].getName() == children[i].getName()) &&
						(family2.children[i].getLastName() == children[i].getLastName()) &&
						(family2.children[i].getBirthYear() == children[i].getBirthYear()) &&
						(family2.children[i].getGender() == children[i].getGender()))
						isEqual = true;
					else
					{
						isEqual = false;
						break;
					}
				}
			}
			else
				isEqual = false;
		}
		else
			isEqual = false;
		
		return isEqual;
	}
	public Person at(int index)
	{
		if(index == (numOfChildren - 1))
			return (children[index]);
		else
		{
			System.out.println("There are no child at given index.");
			return null;
		}
	}
        public int decNumOfFamilies()
        {
            --numOfFamilies;
            return numOfFamilies;
        }
}








