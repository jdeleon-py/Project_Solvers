# THREAD TEST

# In this test, 10000 puzzles will be solved with the
# employment of one thread

import threading
import time
import glob
from thread import MyThread

if __name__ == "__main__":
	threadLock = threading.Lock()
	threads = []

	files = glob.glob('../lib/in_files/*.txt')

	threads.append(MyThread(1, "Thread 1", files))

	for thread in threads: thread.start()
	for thread in threads: thread.join()

	print("--- ROUTINE COMPLETE!")
