/**
 *		GameOfLife.java
 * 
 * @author Doğa Mine Kaba
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author Doğa Mine Kaba
 */

public class GameOfLife 
{
	private Cell[] livingCells;
	private int width;
	private int height;
	private int startPointX;
	private int startPointY;
	private static int numOfLiving = 0;
	
	private boolean isAlive(Cell c)
	{
		boolean result = false;
		for (Cell livingCell : livingCells)
		{
			if (livingCell.getX() == c.getX() && livingCell.getY() == c.getY())
				result = true;
		}
		return result;
	}
	
	private int aliveNeighbours(Cell c)
	{
		int neighbourX = c.getX()-1, neighbourY = c.getY()-1;
		int neighbourCount = 0;

		for (int i = 0; i < 3; i += 1)
		{
			for (int j = 0; j < 3; j += 1)
			{
				if (!(c.getX() == neighbourX && c.getY() == neighbourY) &&
					isAlive(new Cell(neighbourX, neighbourY)))
						++ neighbourCount;
				++neighbourY;
			}
			neighbourY = c.getY()-1;
			++neighbourX;
		}
		return neighbourCount;
	}
	
	private void removeFromAlives(Cell c)
	{
		for (int i = 0; i < livingCells.length; i++)
		{
			if (livingCells[i].getX() == c.getX() && 
				livingCells[i].getY() == c.getY())
			{
				// removing the cell
				for (int j = i+1; j < livingCells.length; j++)
					livingCells[j-1] = livingCells[j];
				
				//updating livingCells
				Cell [] changed = new Cell[livingCells.length - 1];
				System.arraycopy(livingCells, 0, changed, 0, changed.length);
				livingCells = changed;
				
				--numOfLiving;
			}
		}
	}
	
	private void addToAlives(Cell c)
	{
		if (!isAlive(c))
		{
			Cell [] changed = new Cell [livingCells.length+1];
			System.arraycopy(livingCells, 0, changed, 0, livingCells.length);
			changed[livingCells.length] = c;
			
			livingCells = changed;
			++numOfLiving;
		}
	}
	
	private void updateBoardSize()
	{
		int	tempX, tempY;
	
		if (livingCells.length != 0) 
		{
			tempX = livingCells[0].getX();
			tempY = livingCells[0].getY();

			startPointX = tempX;
			startPointY = tempY;
			width = tempX;
			height = tempY;

			for (int i = 1; i < livingCells.length; i++)
			{
				tempX = livingCells[i].getX();
				tempY = livingCells[i].getY();
				
				if (tempX < startPointX)
					startPointX = tempX;
				if (tempY < startPointY)
					startPointY = tempY;
				if (tempX > width)
					width = tempX;
				if (tempY > height)
					height = tempY;
			}
		}
	}
	
	private void readFile(String fileName)
	{
		File inputFile = new File(fileName);
		
		try (Scanner inputStream = new Scanner(inputFile))
		{
			
			String line;
			
			int j=0;	//temporary height
			while (inputStream.hasNextLine())
			{				
				line = inputStream.nextLine().toLowerCase();
				for (int i = 0; i < line.length(); i++)
				{
					if (line.charAt(i) == 'x')
					{
						//Update living cells
						addToAlives(new Cell(i,j));

						//Update board size
						if (i > width)
							width = i;
						height = j;
					}
				}
				++j;
			}
			updateBoardSize();
			
			inputStream.close();
		} 
		catch (FileNotFoundException e) 
		{
			System.err.println("File doesn't exist in this directory.\n");
		}
		
	}
	
	public GameOfLife(String fileName)
	{
		startPointX = 0;
		startPointY = 0;
		width = 0;
		height = 0;
		livingCells = new Cell[0];
		showLineRows = false;
		
		readFile(fileName);
	}
	
	public void displayGame()
	{
		boolean contains = false;
		int count = 0;
		
		if (showLineRows)
		{
			System.out.print("  ");
			for (int j = 0; j < getWidth(); j++)
				System.out.print(j+1);
			System.out.println();
		}
		
		for (int i = startPointY; i <= height; i++)
		{
			if (showLineRows)
			{
				++count;
				System.out.print(count + " ");
			}
			for (int j = startPointX; j <= width; j++)
			{
				if (isAlive(new Cell(j, i)))
				{
					contains = false;
					System.out.print('x');
				}
				else
					System.out.print(' ');
			}
			System.out.println();
		}
		System.out.println();
	}
	
	public void play()
	{
		//Temporary arrays to hold next states without changing current states
		Cell[] tempLivingCells = new Cell[0];
		Cell[] tempDiedCells = new Cell[0];

		int neighbourCount;
		int tempX = 0, tempY = 0;

		for (int i = startPointY-1; i <= height+1; i++)
		{
			for (int j = startPointX-1; j <= width+1; j++)
			{
				neighbourCount = aliveNeighbours(new Cell(j, i));
				if (isAlive (new Cell(j, i)))
				{
					if (neighbourCount < 2 || neighbourCount > 3)
					{
						Cell[] newDiedCells = new Cell[tempDiedCells.length+1];
						System.arraycopy(tempDiedCells, 0, 
										newDiedCells, 0, tempDiedCells.length);
						newDiedCells[newDiedCells.length-1] = new Cell(j, i);
						tempDiedCells = newDiedCells;
					}
				}
				else
				{
					if (neighbourCount == 3)
					{
						Cell[] newLivingCells = new Cell[tempLivingCells.length+1];
						System.arraycopy(tempLivingCells, 0, newLivingCells, 
										0, tempLivingCells.length);
						newLivingCells[newLivingCells.length-1] = new Cell(j, i);
						tempLivingCells = newLivingCells;
					}
				}
			}
		}
		for (Cell tempDiedCell : tempDiedCells)
			removeFromAlives(tempDiedCell);

		for (Cell tempLivingCell : tempLivingCells)
			addToAlives(tempLivingCell);
		
		updateBoardSize();
	}
	
	public int getWidth()
	{
		return width - startPointX + 1;
	}
	
	public int getHeight()
	{
		return height - startPointY + 1;
	}
	
	public boolean showLineRows;
	
	public static int numOfLivingCells()
	{
		return numOfLiving;
	}
	
	public void join(GameOfLife other)
	{
		for (Cell cell : other.livingCells)
			addToAlives(cell);
	}
}