# COLLECTION OF CUSTOM EXCEPTIONS

class Error(Exception):
	'''
	Base class for other exceptions
	'''
	pass


class RedundantDigitError(Error):
	'''
	- Raised when an input contradicts another input
	- Only applies to the initial input (irrelevant when solving)
	- Apply to Puzzle object
	- example in input2.txt
	'''
	pass


class NotADigitError(Error):
	'''
	- Raised when an input is not an integer
	- Only integers are allowed when providing input
	- Apply to Puzzle object
	- example in input3.txt

	- Raised when the board has missing indices
	- If a space is meant to be "empty", a placeholder '0' should occupy it
	- Apply to Puzzle object
	- example in imput4.txt
	'''
	pass


class OutOfRangeError(Error):
	'''
	- Raised when an input is outside the range of [0,9]
	- Apply to Puzzle object
	- example in <a future development>
	'''
	pass
