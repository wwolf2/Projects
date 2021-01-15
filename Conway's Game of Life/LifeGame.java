
/*
 * Billy Wolf
 * Project 3
 * COSC 117-503
 * November 27, 2017
 * Runs Conway's Game Of Life
 */

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.LineBorder;
import java.util.Scanner;

public class LifeGame extends JPanel implements ActionListener {

	private int row = 16; // row size of board
	private int col = 16; // column size of board

	boolean Life[][] = new boolean[row][col]; // true = alive

	JLabel[][] grid = new JLabel[row][col]; // array that makes the cells JLabels

	/*
	 * Sets the Starting grid up randomly with on or off cells
	 */
	public void SetGrid() {

		setLayout(new GridLayout(row, col)); // creates grid

		// loop to set cells and make JLabels for each cell and randomly on or off
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				grid[i][j] = new JLabel();
				grid[i][j].setBorder(new LineBorder(Color.BLACK));
				grid[i][j].setOpaque(true);
				Life[i][j] = Math.random() > 0.5;

				if (Life[i][j]) {
					grid[i][j].setBackground(Color.black);
				} else {
					grid[i][j].setBackground(Color.white);
				}
				add(grid[i][j]);
			}

		}
	}

	/*
	 * Makes a new copy of the board for the new round then copies it over the
	 * starting board
	 */
	public void updateCells() {
		boolean Future[][] = new boolean[row][col]; // true = alive

		int NeededToBeBorn = 3; // Number of alive cells needed to create an alive cell
		int MinToLive = 2; // Minimum number of alive cells needed to keep a cell alive
		int MaxToLive = 3; // Maximum number of alive cells needed to keep a cell alive
		// loops through whole array
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < row; j++) {

				int count = 0; // counter variable
				// checks every cell around the middle one
				if (i != 0 && j != 0 && Life[i - 1][j - 1])
					count++; // top left
				if (i != 0 && Life[i - 1][j])
					count++; // top mid
				if (i != 0 && j != col - 1 && Life[i - 1][j + 1])
					count++; // top right
				if (j != 0 && Life[i][j - 1])
					count++; // mid left
				if (j != col - 1 && Life[i][j + 1])
					count++; // mid right
				if (i != row - 1 && j != 0 && Life[i + 1][j - 1])
					count++; // bot left
				if (i != row - 1 && Life[i + 1][j])
					count++; // bot mid
				if (i != row - 1 && j != col - 1 && Life[i + 1][j + 1])
					count++; // bot right

				// checks if the array is true and the count is equal to the min or max numbers
				// if yes then keep the cell alive
				if (Life[i][j] && (count == MinToLive || count == MaxToLive)) {
					Future[i][j] = true;
				}
				// checks if life is false and count is equal to the number NeededToBeBorn
				// if yes then create a new cell
				if (!Life[i][j] && (count == NeededToBeBorn)) {
					Future[i][j] = true;
				}
			}
		}
		// copies the future round array over the original array
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < row; j++) {
				Life[i][j] = Future[i][j];
				if (Life[i][j]) {
					grid[i][j].setBackground(Color.black);
				} else {
					grid[i][j].setBackground(Color.white);
				}
			}
		}

	}

	/*
	 * Sets the Dimensions of the board for whatever the user enters
	 */
	public void setDimension(int r, int c) {
		row = r; // sets row to whatever the user entered
		col = c; // sets column to whatever the user entered
		Life = new boolean[row][col]; // changes the cells to however many the user entered, true = alive
		grid = new JLabel[row][col]; // changes the JLabel to the user entered number
	}

	/*
	 * Creates the GUI and prompts the user for the board size Creates a timer that
	 * continues forever to keep updating the board
	 */
	public static void main(String[] args) {

		JFrame window = new JFrame("Simple Animation"); // Title
		LifeGame drawingArea = new LifeGame(); // creates the GUI window
		Scanner input = new Scanner(System.in); // Scanner
		int r = 0;

		System.out.println("Enter the desired size (8 or bigger and no more than 100):"); // prompt user for a number
		String temp_input = input.nextLine();

		try {
			r = Integer.parseInt(temp_input);
		}catch (Exception error){
			System.out.println("Incorrect input, Try again.");
		}

		// Restricts the user to enter specific numbers
		while (r < 8 || r > 100) {
			System.out.println("Enter the desired size (8 or bigger and no more than 100):"); // prompt user for a
			// number
			temp_input = input.nextLine();
			try {
				r = Integer.parseInt(temp_input);
			}catch (Exception error){
				System.out.println("Incorrect input, Try again.");
			}

		}

		drawingArea.setDimension(r, r); // changes the board to the user input number
		drawingArea.setBackground(Color.WHITE); // sets background to white
		window.setContentPane(drawingArea);

		drawingArea.setPreferredSize(new Dimension(600, 450)); // sets Dimensions of the window

		window.pack();
		window.setLocation(100, 50);
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		drawingArea.SetGrid();
		window.setResizable(true); // allows resize of window
		Timer frameTimer = new Timer(200, drawingArea); // Timer to update the board
		window.setVisible(true);
		frameTimer.start();

	} // end main

	// Takes an ActionEvent type and calls updateCells and repaint methods
	public void actionPerformed(ActionEvent evt) {
		updateCells(); //calls updateCells Method
	}

}