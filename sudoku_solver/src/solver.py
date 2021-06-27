# import exception_handling as e
import solver_util as util
import numpy as np
import time

class SolverAlgorithm(util.SolverFunctions):

	def __init__(self, two_d_board_array):
		util.SolverFunctions.__init__(self, two_d_board_array)

		self.origin = 0
		self.row_len = 9
		self.col_len = 9

	
	def solve(self):
		find = util.SolverFunctions.find_next(self)
		if not find:
			print(self.board)
			return True
		else:
			row, col = find

		for i in range(self.origin + 1, self.row_len + 1):
			if util.SolverFunctions.valid(self, row, col, i):
				self.board[row][col] = i
				print(self.board)
				print('\n')

				if self.solve():
					return True

				self.board[row][col] = 0

		return False

