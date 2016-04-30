/**
 *		Cell.java
 * 
 * @author Doğa Mine Kaba
 */
public class Cell 
{
    private int x;
    private int y;
    
	public Cell(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
	public void setX(int x)
	{
		this.x = x;
	}
	public void setY(int y)
	{
		this.y = y;
	}
	public int getX()
	{
		return x;
	}
	public int getY()
	{
		return y;
	}
	public boolean isEqual(Cell other)
	{
		if((this.x == other.x) && (this.y == other.y))
			return true;
		else
			return false;
	}
}
