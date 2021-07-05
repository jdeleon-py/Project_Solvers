# SOLUTION CLASS

from board import Board

class Solution(Board):
	'''
	METHODS:
		- ability to output to file

	ATTRIBUTES:
		- output file
		- data to be written to file
	'''
	def __init__(self, file, data):
		Board.__init__(self)
		self.file = file
		self.data = data

	def generate_output(self):
		with open(self.file, 'w') as write_file:
			for row in self.data:
				for digit in row:
					write_file.write(str(digit))
				write_file.write('\n')
		write_file.close()


if __name__ == "__main__":
	pass