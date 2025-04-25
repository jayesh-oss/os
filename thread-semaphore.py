from threading import *
import time
BUFFER_SIZE = 5
BUFFER = [0]*BUFFER_SIZE
Mutex = Semaphore(1)
Empty = Semaphore(BUFFER_SIZE)
Full = Semaphore(0)
class Producer(Thread):
    def run(self):
        global BUFFER
        for i in range(5):
         Empty.acquire()
         Mutex.acquire()
         BUFFER[i % BUFFER_SIZE] = i
         print(f"Produced item {i}")
         Mutex.release()
         Full.release()
         time.sleep(1)
class Consumer(Thread):
    def run(self):
        global BUFFER
        for i in range(5):
         Full.acquire()
         Mutex.acquire()
         item = BUFFER[i % BUFFER_SIZE]
         BUFFER[i % BUFFER_SIZE] = 0
         print(f"Consumed Item {item}")
         Mutex.release()
         Empty.release()
         time.sleep(1)
P = Producer()
C = Consumer()
P.start()
P.join()
C.start()
C.join()