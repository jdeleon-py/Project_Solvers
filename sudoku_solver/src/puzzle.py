# PUZZLE CLASS

from board import Board
from exception import RedundantDigitError
from exception import NotADigitError
from exception import OutOfRangeError

class Puzzle(Board):
	'''
	METHODS:
		- ability to create a Board object provided by user input or file input
		- ability to verify that the Board object has no redundant digits
		- ability to verify that the Board object contains integers within range
		- ability to verify that the Board object contains no missing indices

	ATTRIBUTES:
		- Board object
		- io_type defined
		- [False, True] -> file i/o
		- [True, False] -> user i/o
	'''
	def __init__(self, data, io_type = [False, False]):
		Board.__init__(self)
		self.data = data
		self.io_type = io_type

		if self.io_type == [False, True]:
			self.board = self.generate_board(self.data)

		elif self.io_type == [True, False]:
			self.board = self.data

		else:
			self.board = None

	def generate_board(self, filepath):
		try:
			with open(filepath, 'r') as file:
				data = file.read()
			file.close()
			data = [[int(digit) for digit in row] for row in data.split('\n')[:-1]]

		except:
			data = None

		finally:
			return self.verify_board(data)

	def verify_board(self, data):
		try:
			for row in data:
				for digit in row:
					if not isinstance(digit, int):
						raise NotADigitError
			return data
		
		except NotADigitError:
			print("One of these digits is not valid!")
			return None

		except RedundantDigitError:
			print("One of these digits is redundant!")
			return None
		
		except:
			return None


if __name__ == "__main__":
	puzzle1 = Puzzle('../lib/test_files/input1.txt', io_type = [False, True])
	puzzle2 = Puzzle('../lib/test_files/input2.txt', io_type = [False, True])
	puzzle3 = Puzzle('../lib/test_files/input3.txt', io_type = [False, True])
	puzzle4 = Puzzle('../lib/test_files/input4.txt', io_type = [False, True])

	print('{}'.format(puzzle1))
	print('{}'.format(puzzle2))
	print('{}'.format(puzzle3))
	print('{}'.format(puzzle4))

	board_input = [[1, 2, 3, 4, 5, 6, 7, 8, 9],
					[9, 6, 7, 0, 0, 0, 0, 0, 0],
					[8, 4, 5, 0, 0, 0, 0, 0, 0],
					[7, 0, 0, 0, 0, 0, 0, 0, 0],
					[6, 0, 0, 0, 0, 0, 0, 0, 0],
					[5, 0, 0, 0, 0, 0, 0, 0, 0],
					[4, 0, 0, 0, 0, 0, 0, 0, 0],
					[3, 0, 0, 0, 0, 0, 0, 0, 0],
					[2, 0, 0, 0, 0, 0, 0, 0, 0]]

	puzzle5 = Puzzle(board_input, io_type = [True, False])

	print('{}'.format(puzzle5))
