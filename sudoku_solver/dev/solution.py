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
	def __init__(self, data, file):
		Board.__init__(self)
		self.data = data
		self.file = file

	def generate_output(self):
		try:
			with open(self.file, 'w') as write_file:
				for row in self.data:
					for digit in row:
						write_file.write(str(digit))
					write_file.write('\n')
			write_file.close()
		except:
			print('{}'.format(self.data))

if __name__ == "__main__":
	pass