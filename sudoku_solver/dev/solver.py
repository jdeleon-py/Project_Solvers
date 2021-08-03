# SOLVER CLASS

from puzzle import Puzzle
from solution import Solution

class Solver:
	'''
	METHODS:
		- validate number -> bool
		- find next number -> returns next coordinates to calculate number
		- solve -> uses new number to calculate current square
		- ability to differentiate between file_io and input_io

	ATTRIBUTES:
		- Puzzle object for solving
		- Solution object
		- io_type defined
		- [False, True] -> file i/o
		- [True, False] -> user i/o
	'''
	def __init__(self, data, outfile = None, io_type = [False, False], verbose = True):
		self.data = data
		self.outfile = outfile
		self.io_type = io_type
		self.verbose = verbose

		self.puzzle = Puzzle(self.data, self.io_type)
		self.solution = Solution(self.puzzle.board, self.outfile)

	def find_next(self):
		for i in range(0, 9):
			for j in range(0, 9):
				if self.puzzle.board[i][j] == 0:
					return (i, j)
		return False

	def solve(self):
		find = self.find_next()
		if not find:
			if self.verbose: print('{}'.format(self.puzzle))
			self.solution.board = self.puzzle.board
			self.solution.generate_output()
			if self.verbose: print('Completed!')
			return True
		else:
			row, col = find

		for i in range(1, 10):
			if self.puzzle.check_row(row, i) and self.puzzle.check_col(col, i) and self.puzzle.check_box(row, col, i):
				self.puzzle.board[row][col] = i
				if self.verbose: print('{}'.format(self.puzzle))
				if self.verbose: print('\n')
				if self.solve(): return True
				self.puzzle.board[row][col] = 0
		return False


if __name__ == "__main__":
	board_input1 = [[1, 2, 3, 4, 5, 6, 7, 8, 9],
					[9, 6, 7, 0, 0, 0, 0, 0, 0],
					[8, 4, 5, 0, 0, 0, 0, 0, 0],
					[7, 0, 0, 0, 0, 0, 0, 0, 0],
					[6, 0, 0, 0, 0, 0, 0, 0, 0],
					[5, 0, 0, 0, 0, 0, 0, 0, 0],
					[4, 0, 0, 0, 0, 0, 0, 0, 0],
					[3, 0, 0, 0, 0, 0, 0, 0, 0],
					[2, 0, 0, 0, 0, 0, 0, 0, 0]]

	#file_input = str(input("Enter an input file name: "))
	#file_output = str(input("Enter an output filename: "))
	solver = Solver(board_input1, io_type = [True, False], verbose = True)
	solver.solve()
