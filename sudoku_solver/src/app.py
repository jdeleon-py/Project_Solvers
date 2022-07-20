# TKINTER APP CLASS

import numpy as np
from tkinter import Tk, Frame, Button, Entry, IntVar
from tkinter.filedialog import asksaveasfile, askopenfile
from window import Window

class App:
	'''
	METHODS:
	- ability to open a file and fill the board with the contents of the file
	- ability to save the contents of the board out to a file
	- ability to solve a puzzle interactively by opening a pygame window
	- ability to reset the board by setting the board's contents to 0
	- ability to translate the contents of a file onto a sudoku board - vice versa
	- ability to reshape an array of board data into something readable by the solver

	ATTRIBUTES:
	- 1-D board array that is updated via file i/o or user i/o; converted to 2-D array to solve
	- 9x9 grid of Entry boxes for gui input
	- Button to open an existing puzzle file
	- Button to save a board's content to a file
	- Button to solve a board's contents
	- Button to reset a board's contents to 0
	'''
	def __init__(self, master):
		self.frame = Frame(master)
		self.frame.pack()
		self.populate_board(entry = True)

		self.open_button = Button(self.frame, text = 'Open', command = self.open).grid(row = 10, columnspan = 9)
		self.save_button = Button(self.frame, text = 'Save', command = self.save).grid(row = 11, columnspan = 9)
		self.solve_button = Button(self.frame, text = 'Solve', command = self.solve).grid(row = 12, columnspan = 9) 
		self.reset_button = Button(self.frame, text = 'Reset', command = self.reset).grid(row = 13, columnspan = 9)

	def open(self):
		self.board_arr = []
		file = askopenfile()
		data = file.read()
		data = [[int(digit) for digit in row] for row in data.split('\n')[:-1]]
		for row in data:
			for digit in row:
				self.board_arr.append(digit)
		self.populate_board(entry = False)
		
	def save(self):
		file = asksaveasfile(initialfile = 'Untitled.txt', defaultextension = ".txt")
		for row in self.clean_data(self.board_arr):
			for digit in row:
				file.write(str(digit))
			file.write('\n')
		file.close()
	
	def solve(self):
		interface = Window(self.clean_data(self.board_arr))
		interface.run()
		interface.exit_window()

	def reset(self):
		return self.populate_board()

	def populate_board(self, entry = True):
		if entry:
			self.board_arr = []
			for i in range(0, 81):
				board_index = Entry(self.frame, textvariable = IntVar(), bd = 5, width = 2)
				board_index.grid(row = (i // 9), column = i % 9)
				self.board_arr.append(board_index)
		else:
			for i in range(0, 81):
				text = IntVar()
				text.set(self.board_arr[i])
				board_index = Entry(self.frame, textvariable = text, bd = 5, width = 2)
				board_index.grid(row = (i // 9), column = i % 9)

	def clean_data(self, init_data):
		try:
			init_data = [int(digit.get()) for digit in init_data]
			return np.array(init_data).reshape(9, 9)
		except:
			return np.array(init_data).reshape(9, 9)


if __name__ == "__main__":
	root = Tk()
	root.geometry("400x450")
	root.wm_title("Sudoku Solver GUI")
	app = App(root)

	root.mainloop()
