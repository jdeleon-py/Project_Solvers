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
	'''
	def __init__(self, file):
		Board.__init__(self)
		self.file = file
		self.board = self.generate_board()

	def generate_board(self):
		try:
			with open(self.file, 'r') as file:
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
	puzzle1 = Puzzle('../lib/test_files/input1.txt')
	puzzle2 = Puzzle('../lib/test_files/input2.txt')
	puzzle3 = Puzzle('../lib/test_files/input3.txt')
	puzzle4 = Puzzle('../lib/test_files/input4.txt')

	print('{}'.format(puzzle1))
	print('{}'.format(puzzle2))
	print('{}'.format(puzzle3))
	print('{}'.format(puzzle4))
