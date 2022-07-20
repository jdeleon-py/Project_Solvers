*** THIS FILE WILL OUTLINE IDEAS AND DEVELOPMENT FOR A SUDOKU SOLVER APPLICATION ***

- src/
	- This is rough, yet completed application for a sudoku solver.	
	- This implementation includes a gui interface responsible for user input.
	- This implementation includes a cli interface responsible for an updating output.
	- The solver algorithm uses a brute-force backtracking approach 
	  with a time complexity of approximately O(n^3).
	- This implementation does not account for a variety of potential errors
	  associated with user-input.
	- This implementation is a messy, yet object-oriented approach to a sudoku solver.
	- A future implementation (see dev/) will include a cleaner object-oriented
	  structure.

- dev/
	- Include a cleaner object-oriented structure.
	- Include a cli interface that will implement file I/O as input.
	- Include a gui interface that will implement file I/O and user I/O.
	- Include exceptions that examines valid input (see etc/).
	- Include the expected brute-force solver algorithm, with some room for
	  an improved solver algorithm.
	  (genetic algorithm, reinforced learning, hash comparisons, etc...).
	- Include a multi-threaded approach to handle hundreds of puzzles simultaneously.

- etc/
	- storage container for ideas to enhance the application.


*** THREAD TEST ***
In this investigation, a series of 10,000 puzzles will be solved three times with three variations of threads. Three trials of one thread, two threads, and four threads will measure the average computation time for each variation.

- ONE THREAD
	- Trial #1:		249.604 sec
	- Trial #2:		236.407 sec
	- Trial #3:		243.334 sec
	- Avg. Computation Time: 243.115 sec

- TWO THREADS
	- Trial #1:		386.183 sec
	- Trial #2:		334.005 sec
	- Trial #3:		331.524 sec
	- Avg. Computation Time: 350.571 sec

- FOUR THREADS
	- Trial #1:		368.730 sec
	- Trial #2:		329.609 sec
	- Trial #3:		290.868 sec
	- Avg. Computation Time: 329.736 sec
