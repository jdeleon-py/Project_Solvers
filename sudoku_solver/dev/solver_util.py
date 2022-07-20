# import exception_handling as e
import numpy as np

class SolverFunctions:

	def __init__(self, two_d_board_array):
		self.board = two_d_board_array

		self.origin = 0
		self.row_len = 9
		self.col_len = 9

	
	def check_row(self, x_cor, num):
		for i in range(self.origin, self.col_len):
			if self.board[x_cor][i] == num:
				return False
		return True

	
	def check_col(self, y_cor, num):
		for i in range(self.origin, self.row_len):
			if self.board[i][y_cor] == num:
				return False
		return True

	
	def check_box(self, x_cor, y_cor, num):
		box_row = (x_cor // 3) * 3
		box_col = (y_cor // 3) * 3
		for i in range(self.origin, int(self.col_len / 3)):
			for j in range(self.origin, int(self.row_len / 3)):
				if self.board[box_row + i][box_col + j] == num:
					return False
		return True

	
	def valid(self, x_cor, y_cor, num):
		if self.check_row(x_cor, num) and self.check_col(y_cor, num) and self.check_box(x_cor, y_cor, num):
			return True
		return False

	
	def find_next(self):
		for i in range(self.origin, self.row_len):
			for j in range(self.origin, self.col_len):
				if self.board[i][j] == 0:
					return (i, j)
		return False