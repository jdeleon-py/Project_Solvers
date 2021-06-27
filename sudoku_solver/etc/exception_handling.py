class Error(Exception):
	'''
	Base class for other exceptions
	'''
	pass


class RedundantDigit(Error):
	'''
	Raised when an input contradicts another input
	'''
	pass


class NotADigitError(Error):
	'''
	Raised when an input is not an integer
	'''
	pass


class MissingIndex(Error):
	'''
	Raised when the board has missing indices
	'''
	pass


class OutOfRangeError(Error):
	'''
	Raised when an input is outside the range of [0-9]
	'''
	pass


'''
# Pulled from board_app.save()
# Needs to be modified!

while True:
			try:
				for i in range(0, 81):
					if not isinstance(self.board_arr[i], str):
						raise e.NotADigitError

			except e.NotADigitError:
				print('Error! Enter integers only!')
				time.sleep(5)

			else:
				break
'''