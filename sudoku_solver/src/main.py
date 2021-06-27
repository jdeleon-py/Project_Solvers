# Project_Sudoku
# Main Function

from tkinter import Tk
import board_app as app

if __name__ == "__main__":

	root = Tk()
	root.geometry("400x400")
	root.wm_title('Sudoku Solver GUI')
	app = app.App(root)

	root.mainloop()
