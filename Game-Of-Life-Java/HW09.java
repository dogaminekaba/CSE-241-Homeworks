/**
 *		HW09.java
 *
 * @author Doğa Mine Kaba
 */

import java.util.Scanner;

public class HW09 
{

    public static void main(String[] args) 
    {
		Scanner keyboard = new Scanner(System.in);
		System.out.print("Please enter move number N: ");
		int moveNum = keyboard.nextInt();
		
		GameOfLife game1 = new GameOfLife("test1.txt");
		GameOfLife game2 = new GameOfLife("test2.txt");
		GameOfLife game3 = new GameOfLife("test3.txt");
		GameOfLife game4 = new GameOfLife("test4.txt");
		GameOfLife game5 = new GameOfLife("test5.txt");
		
		//				1
		for (int i = 0; i < game1.getWidth()/3; i++)
			System.out.print(" ");
		System.out.println("GAME 1");
		game1.displayGame();
		
		//				2
		for (int i = 0; i < game2.getWidth()/3; i++)
			System.out.print(" ");
		System.out.println("GAME 2");
		game2.displayGame();
		
		//				3
		for (int i = 0; i < game3.getWidth()/3; i++)
			System.out.print(" ");
		System.out.println("GAME 3");
		game3.displayGame();
		
		//				4
		for (int i = 0; i < game4.getWidth()/3; i++)
			System.out.print(" ");
		System.out.println("GAME 4");
		game4.displayGame();
		
		//				5
		for (int i = 0; i < game5.getWidth()/3; i++)
			System.out.print(" ");
		System.out.println("GAME 5");
		game5.displayGame();
		
		game2.join(game5);
		for (int i = 0; i < game2.getWidth()/3; i++)
			System.out.print(" ");
		System.out.println("GAME 2 + GAME 5");
		game2.displayGame();
		
		System.out.println("Number of living cells: " + 
							GameOfLife.numOfLivingCells() + "\n");
		
		String button;
		button = keyboard.nextLine();
		int count = 0;
		
		while (count != moveNum)
		{
			System.out.print("Press Enter button to see next state of cells: ");
				button = keyboard.nextLine();
			if (button.equals(""))
			{
				//				1
				for (int i = 0; i < game1.getWidth()/3; i++)
					System.out.print(" ");
				System.out.println("GAME 1");
				game1.play();
				game1.displayGame();

				//				2
				for (int i = 0; i < game2.getWidth()/3; i++)
					System.out.print(" ");
				System.out.println("GAME 2");
				game2.play();
				game2.displayGame();

				//				3
				for (int i = 0; i < game3.getWidth()/3; i++)
					System.out.print(" ");
				System.out.println("GAME 3");
				game3.play();
				game3.displayGame();

				//				4
				for (int i = 0; i < game4.getWidth()/3; i++)
					System.out.print(" ");
				System.out.println("GAME 4");
				game4.play();
				game4.displayGame();

				//				5
				for (int i = 0; i < game5.getWidth()/3; i++)
					System.out.print(" ");
				System.out.println("GAME 5");
				game5.play();
				game5.displayGame();
				
				System.out.println("Number of living cells: " + 
									GameOfLife.numOfLivingCells() + "\n");
				++count;
			}
		}
    }
}
