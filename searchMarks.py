import json
import tkinter as tk
import webbrowser

# This program chrome only
# second search must destroy array if sign
path = r"C:\Users\reuser\AppData\Local\Google\Chrome\User Data\Default\Bookmarks"
bro = webbrowser.get('"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe" %s')
labelArray = []
root = tk.Tk()

def browser(url):
	bro.open(url)

def labelView(text, sign):
	if sign == 1:
		destroy()
	
	labelArray.append( tk.Label(root, text=text) )
	labelArray[-1].grid()

def destroy():
	for label in labelArray:
		#label.grid_forget()
		label.destroy()
	
	labelArray.clear()

def gui():
	root.configure(background="#DCECEC")
	root.title("BookmarksView")
	root.geometry("450x450")
	form = tk.Entry(root)#border
	form.bind('<Return>', lambda e: input(form) )
	form.focus_set()
	# lambda ev: la.configure(text='Clicked left mouse button'
	form.grid()
	root.mainloop() # main
	


def input(self):
	print (self.get())
	#browser(self.get())
	f = open(path, encoding="utf-8") # close siro
	text = json.load(f)
	global sign = fun( text["roots"]["bookmark_bar"]["children"], 0, self.get(), sign )
	f.close()


def fun( jsonArray, stage,  search, sign ):
	for array in jsonArray:
		
		#for k in range(stage):
			#if k != stage:
				#print(" -", end="")
			#else :
				#print(" -> ", end="")
				
		
		if array["name"].find(search) != -1 :
			print(array["name"])
			labelView(array["name"], sign)
		
		
		if "children" in array:
			fun( array["children"], stage+1, search )
	
	#return 1


# main path="bookmarkfile"
# chrome example path(Windows10) 
# C:\Users\[user_name]\AppData\Local\Google\Chrome\User Data\Default\Bookmarks
#text = json.load(f)
#fun( text["roots"]["bookmark_bar"]["children"], 0 )

gui()

#f.close()


