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
	'''
	def __init__(self, input_file, output_file):
		self.input_file = input_file
		self.output_file = output_file
		self.puzzle = Puzzle(self.input_file)

	def find_next(self):
		for i in range(0, 9):
			for j in range(0, 9):
				if self.puzzle.board[i][j] == 0:
					return (i, j)
		return False

	def solve(self):
		find = self.find_next()
		if not find:
			print('{}'.format(self.puzzle))
			self.solution = Solution(self.output_file, self.puzzle.board)
			self.solution.generate_output()
			print('Completed!')
			return True
		else:
			row, col = find

		for i in range(1, 10):
			if self.puzzle.check_row(row, i) and self.puzzle.check_col(col, i) and self.puzzle.check_box(row, col, i):
				self.puzzle.board[row][col] = i
				print('{}'.format(self.puzzle))
				print('\n')
				if self.solve(): return True
				self.puzzle.board[row][col] = 0
		return False


if __name__ == "__main__":
	file_input = str(input("Enter an input file name: "))
	file_output = str(input("Enter an output filename: "))
	solver = Solver(file_input, file_output)
	solver.solve()
