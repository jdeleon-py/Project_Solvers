# Project_Sudoku
# GUI App - Board

from tkinter import Frame, Button, Entry, IntVar
import numpy as np
import solver
# import exception_handling as e

class App:

	def __init__(self, master):

		self.frame = Frame(master)
		self.frame.pack()

		self.board_arr = []

		for i in range(0, 81):
			board_index = Entry(self.frame, textvariable = IntVar(), bd = 5, width = 2)
			board_index.grid(row = (i // 9), column = i % 9)
			self.board_arr.append(board_index)

		verify = Button(self.frame, text = 'Save', command = self.save).grid(row = 10, columnspan = 9)
		solve = Button(self.frame, text = 'Solve', command = self.solve).grid(row = 11, columnspan = 9) 
		reset = Button(self.frame, text = 'Reset', command = self.reset).grid(row = 12, columnspan = 9)
		

	def save(self):
		array = []
		for i in range(0, 81):
			array.append(int(self.board_arr[i].get()))

		array = np.array(array).reshape(9,9)
		print('\n')
		print(array)

		return array

	
	def solve(self):
		board = self.save()
		do = solver.SolverAlgorithm(board)
		do.solve()
		
		return ''


	def reset(self):
		self.board_arr = []

		for i in range(0, 81):
			board_index = Entry(self.frame, textvariable = IntVar(), bd = 5, width = 2)
			board_index.grid(row = (i // 9), column = i % 9)
			self.board_arr.append(board_index)
		
		return ''
