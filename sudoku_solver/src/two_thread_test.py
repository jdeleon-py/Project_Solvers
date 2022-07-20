# THREAD TEST

# In this test, 10000 puzzles will be solved with the
# employment of two simultaneous threads

import threading
import time
import glob
from thread import MyThread

if __name__ == "__main__":
	threadLock = threading.Lock()
	threads = []

	files = glob.glob('../lib/in_files/*.txt')

	FILE_ARR1 = files[:5000]
	FILE_ARR2 = files[5000:]

	threads.append(MyThread(1, "Thread 1", FILE_ARR1))
	threads.append(MyThread(2, "Thread 2", FILE_ARR2))

	for thread in threads: thread.start()
	for thread in threads: thread.join()

	print("--- ROUTINE COMPLETE!")
