# THREAD CLASS

import threading
from solver import Solver

class MyThread(threading.Thread):
	'''
	This class will include features that will allow
	this solver to be multi-threaded if necessary
	'''
	def __init__(self, threadID, name, arr):
		threading.Thread.__init__(self)
		self.threadID = str(threadID)
		self.name = name
		self.arr = arr

	def run(self):
		print("Starting {}".format(self.name))
		#threadLock.acquire()
		#threadLock.release()
		for index in self.arr:
			solver = Solver(index, '../lib/output_files/out' + self.define_id(index) + '.txt', io_type = [False, True])
			solver.solve()
		print("Exiting {}".format(self.name))

	def define_id(self, filename):
		return filename.split('input')[1].split('.txt')[0]


if __name__ == "__main__":
	# test the multi-threading feature by employing four threads
	# use input files input5.txt input6.txt input7.txt input8.txt

	threadLock = threading.Lock()
	threads = []

	FILE_ARR1 = ['../lib/test_files/input5.txt']
	FILE_ARR2 = ['../lib/test_files/input6.txt']
	FILE_ARR3 = ['../lib/test_files/input7.txt']
	FILE_ARR4 = ['../lib/test_files/input8.txt']

	threads.append(MyThread(1, "Thread 1", FILE_ARR1))
	threads.append(MyThread(2, "Thread 2", FILE_ARR2))
	threads.append(MyThread(3, "Thread 3", FILE_ARR3))
	threads.append(MyThread(4, "Thread 4", FILE_ARR4))

	for thread in threads: thread.start()
	for thread in threads: thread.join()

	print("--- ROUTINE COMPLETE!")
