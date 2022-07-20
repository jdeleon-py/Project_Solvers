# BOARD CLASS

class Board:
	'''
	METHODS:
		- <base class>
		- display 2D array (__str__)
		- ability to check each row for unique (non-zero) numbers
		- ability to check each column for unique (non-zero) numbers
		- ability to check each 3x3 box for unique (non-zero) numbers

	ATTRIBUTES:
		- 2D array provided by user input or file input
		- Ex. board structure (__str__)
		 -----------------------
		| # # # | # # # | # # # |
		| # # # | # # # | # # # |
		| # # # | # # # | # # # |
		 -----------------------
		| # # # | # # # | # # # |
		| # # # | # # # | # # # |
		| # # # | # # # | # # # |
		 -----------------------
		| # # # | # # # | # # # |
		| # # # | # # # | # # # |
		| # # # | # # # | # # # |
		 -----------------------

		- Ex. board structure (2D arr)
		self.board = 
		[[#, #, #, #, #, #, #, #, #],
		 [#, #, #, #, #, #, #, #, #],
		 [#, #, #, #, #, #, #, #, #],
		 [#, #, #, #, #, #, #, #, #],
		 [#, #, #, #, #, #, #, #, #],
		 [#, #, #, #, #, #, #, #, #],
		 [#, #, #, #, #, #, #, #, #],
		 [#, #, #, #, #, #, #, #, #],
		 [#, #, #, #, #, #, #, #, #]]
	'''
	def __init__(self):
		self.board = [[]]

	def __str__(self):
		try:
			print(" ----------------------- ")
			print("| {0} {1} {2} | {3} {4} {5} | {6} {7} {8} |".format(
				self.board[0][0], self.board[0][1], self.board[0][2],
				self.board[0][3], self.board[0][4], self.board[0][5],
				self.board[0][6], self.board[0][7], self.board[0][8]))
			print("| {0} {1} {2} | {3} {4} {5} | {6} {7} {8} |".format(
				self.board[1][0], self.board[1][1], self.board[1][2],
				self.board[1][3], self.board[1][4], self.board[1][5],
				self.board[1][6], self.board[1][7], self.board[1][8]))
			print("| {0} {1} {2} | {3} {4} {5} | {6} {7} {8} |".format(
				self.board[2][0], self.board[2][1], self.board[2][2],
				self.board[2][3], self.board[2][4], self.board[2][5],
				self.board[2][6], self.board[2][7], self.board[2][8]))
			print(" ----------------------- ")
			print("| {0} {1} {2} | {3} {4} {5} | {6} {7} {8} |".format(
				self.board[3][0], self.board[3][1], self.board[3][2],
				self.board[3][3], self.board[3][4], self.board[3][5],
				self.board[3][6], self.board[3][7], self.board[3][8]))
			print("| {0} {1} {2} | {3} {4} {5} | {6} {7} {8} |".format(
				self.board[4][0], self.board[4][1], self.board[4][2],
				self.board[4][3], self.board[4][4], self.board[4][5],
				self.board[4][6], self.board[4][7], self.board[4][8]))
			print("| {0} {1} {2} | {3} {4} {5} | {6} {7} {8} |".format(
				self.board[5][0], self.board[5][1], self.board[5][2],
				self.board[5][3], self.board[5][4], self.board[5][5],
				self.board[5][6], self.board[5][7], self.board[5][8]))
			print(" ----------------------- ")
			print("| {0} {1} {2} | {3} {4} {5} | {6} {7} {8} |".format(
				self.board[6][0], self.board[6][1], self.board[6][2],
				self.board[6][3], self.board[6][4], self.board[6][5],
				self.board[6][6], self.board[6][7], self.board[6][8]))
			print("| {0} {1} {2} | {3} {4} {5} | {6} {7} {8} |".format(
				self.board[7][0], self.board[7][1], self.board[7][2],
				self.board[7][3], self.board[7][4], self.board[7][5],
				self.board[7][6], self.board[7][7], self.board[7][8]))
			print("| {0} {1} {2} | {3} {4} {5} | {6} {7} {8} |".format(
				self.board[8][0], self.board[8][1], self.board[8][2],
				self.board[8][3], self.board[8][4], self.board[8][5],
				self.board[8][6], self.board[8][7], self.board[8][8]))
			print(" ----------------------- ")

		except: print("There was an error displaying the board!")
		finally: return '' 

	def check_row(self, x_coordinate, num):
		try:
			for i in range(0, 9):
				if self.board[x_coordinate][i] == num: return False
			return True
		except IndexError:
			print("Cannot check this board's rows!")
			return ''

	def check_col(self, y_coordinate, num):
		try:
			for i in range(0, 9):
				if self.board[i][y_coordinate] == num: return False
			return True
		except IndexError: 
			print("Cannot check this board's columns!")
			return ''

	def check_box(self, x_coordinate, y_coordinate, num):
		box_row = (x_coordinate // 3) * 3
		box_col = (y_coordinate // 3) * 3
		try:
			for i in range(0, 3):
				for j in range(0, 3):
					if self.board[box_row + i][box_col + j] == num: return False
			return True
		except IndexError:
			print("Cannot check this board's 3x3 grids!")
			return ''


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

	board_input2 = [[1, 2, 3, 4, 5, 6, 7, 8, 9],
					[9, 6, 7, 0, 0, 0, 0, 0, 0],
					[8, 4, 7, 0, 0, 0, 0, 0, 0],
					[7, 0, 0, 0, 0, 0, 0, 0, 0],
					[6, 0, 0, 0, 0, 0, 0, 0, 0],
					[5, 0, 0, 0, 0, 0, 0, 0, 0],
					[4, 0, 0, 0, 0, 0, 0, 0, 0],
					[3, 0, 0, 0, 0, 0, 0, 0, 0],
					[2, 0, 0, 0, 0, 0, 0, 0, 0]]

	board_true = Board()
	board_false = Board()
	board_none = Board()

	board_true.board = board_input1
	board_false.board = board_input2

	print("Board 1:")
	print('{}'.format(board_true))

	print("Board 2:")
	print('{}'.format(board_false))

	print("Board 3:")
	print('{}'.format(board_none))

	print("Column 2 does not contain the number 5: {}".format(board_true.check_col(2, 5)))
	print("Column 2 does not contain the number 5: {}".format(board_false.check_col(2, 5)))
	print("Column 2 does not contain the number 5: {}".format(board_none.check_col(2, 5)))
