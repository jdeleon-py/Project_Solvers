# THREAD TEST

# In this test, 10000 puzzles will be solved with the
# employment of four simultaneous threads

import threading
import time
import glob
from thread import MyThread

if __name__ == "__main__":
	threadLock = threading.Lock()
	threads = []

	files = glob.glob('../lib/in_files/*.txt')

	FILE_ARR1 = files[:2500]
	FILE_ARR2 = files[2500 : 5000]
	FILE_ARR3 = files[5000 : 7500]
	FILE_ARR4 = files[7500:]

	threads.append(MyThread(1, "Thread 1", FILE_ARR1))
	threads.append(MyThread(2, "Thread 2", FILE_ARR2))
	threads.append(MyThread(3, "Thread 3", FILE_ARR3))
	threads.append(MyThread(4, "Thread 4", FILE_ARR4))

	for thread in threads: thread.start()
	for thread in threads: thread.join()

	print("--- ROUTINE COMPLETE!")
