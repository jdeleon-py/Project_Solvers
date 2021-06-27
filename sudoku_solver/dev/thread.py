# THREAD CLASS

import threading

class MyThread(threading.Thread):
	'''
	This class will include features that will allow
	this solver to be multi-threaded if necessary
	'''
	def __init__(self, threadID, name):
		threading.Thread.__init__(self)
		self.threadID = threadID
		self.name = name

	def run(self):
		print("Starting {}".format(self.name))
		threadLock.acquire()
		threadLock.release()
		# <function>
		print("Exiting {}".format(self.name))


if __name__ == "__main__":
	pass