# PYGAME WINDOW CLASS

import pygame
from pygame.locals import QUIT
from solver import Solver

class Window:
	'''
	METHODS:
	-

	ATTRIBUTES:
	-
	'''
	def __init__(self, data):
		pygame.init()
		pygame.display.set_caption('Sudoku Solver')
		self.screen = pygame.display.set_mode([500, 500])
		self.font = pygame.font.Font('freesansbold.ttf', 32)
		self.clock = pygame.time.Clock()

		self.data = data
		self.count = 0
		
		self.solver = Solver(self.data, io_type = [True, False], verbose = False)
		self.draw_text(self.data)

		self.solver.solve()
		self.running = True

	def solver_algorithm(self):
		pass

	def draw_board(self):
		for i in range(50, 450, 40):
			if (i - 50) % 120 == 0: pygame.draw.line(self.screen, (0, 0, 0), (i, 50), (i, 410), width = 4)
			else: pygame.draw.line(self.screen, (0, 0, 0), (i, 50), (i, 410), width = 2)

		for i in range(50, 450, 40):
			if (i - 50) % 120 == 0: pygame.draw.line(self.screen, (0, 0, 0), (50, i), (410, i), width = 4)
			else: pygame.draw.line(self.screen, (0, 0, 0), (50, i), (410, i), width = 2)

	def draw_text(self, data):
		self.text_arr = []

		for i in range(0, 9):
			for j in range(0, 9):
				digit_text = str(data[j][i])
				if digit_text == '0':
					self.text = self.font.render(' ', True, (0,0,0))	# create a text surface object, on which text is drawn on it.
				else:
					self.text = self.font.render(digit_text, True, (0,0,0))
				self.textRect = self.text.get_rect()					# create a rectangular object for the text surface object
				self.textRect.center = ((40 * i) + 70, (40 * j) + 70)	# set the center of the rectangular object.
				self.text_arr.append([self.text, self.textRect])
				self.count += 1

	def exit_window(self):
		return pygame.quit()

	def run(self):
		while self.running:
			# fill the background with white
			self.screen.fill((255, 255, 255))
			self.count = 0

			for text in self.text_arr: self.screen.blit(text[0], text[1])

			self.draw_board()
			self.draw_text(self.solver.puzzle.board)

			# Did the user click the window close button?
			for event in pygame.event.get():
				if event.type == pygame.QUIT: self.running = False

			# updates contents to the screen
			pygame.display.flip()
			self.clock.tick(30) # Ensure the program maintains a rate of 30 frames per second!

if __name__ == '__main__':
	data = [[1, 2, 3, 4, 5, 6, 7, 8, 9],
			[9, 6, 7, 0, 0, 0, 0, 0, 0],
			[8, 4, 5, 0, 0, 0, 0, 0, 0],
			[7, 0, 0, 0, 0, 0, 0, 0, 0],
			[6, 0, 0, 0, 0, 0, 0, 0, 0],
			[5, 0, 0, 0, 0, 0, 0, 0, 0],
			[4, 0, 0, 0, 0, 0, 0, 0, 0],
			[3, 0, 0, 0, 0, 0, 0, 0, 0],
			[2, 0, 0, 0, 0, 0, 0, 0, 0]]

	window = Window(data)
	window.run()
	pygame.quit()
