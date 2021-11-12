import random

class Stack:
  def __init__(self):
    self.stack = list()

  def push(self, x):
    self.stack.append(x)

  def pop(self):
    self.stack.pop(-1)

  def empty(self):
    if len(self.stack) == 0:
      return True
    else:
      return False

  def show(self):
    for x in self.stack:
      print(f'{x}', end=" ")
    print()

if __name__ == "__main__":

  stack = Stack()

  print("stack created")

  for _ in range(8):
    stack.push(random.randint(1, 64))
    print("pushed")

  stack.show()

