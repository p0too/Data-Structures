import random

# python has a garbage collector. yay.
class Queue:
  def __init__(self):
    self.ll = list()

  def push_back(self,  x):
    self.ll.append(x)

  def pop_front(self):
    if not self.empty():
      self.ll.pop(0)
    else:
      print("Queue is empty")

  def empty(self):
    if len(self.ll) == 0:
      return True
    else: 
      return False

  def full(self):
    pass

  def show(self):
    for x in self.ll:
      print(f'{x} ', end=" ")
    print()

q = Queue()
print("q created")
for _ in range(8):
  q.push_back(random.randint(1, 64))
q.show()

q.pop_front()
q.show()

for _ in range(8):
  q.pop_front()
q.show()


