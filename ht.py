import time 
import threading 

def myfunction(): 
    time.sleep(10000) 
    print("waited 30 seconds.") 
    # do whatever else 

num = 0 
mythreads = [] 
while(True): # Just loop forever for demo purposes 
    num += 1 
    if num % 5 == 0: # Execute the function once every 5 times 
     print("//////////")
     newthread = threading.Thread(target=myfunction) 
     mythreads.append(newthread) 
     newthread.start() 
    print("The loop is resumed.") 