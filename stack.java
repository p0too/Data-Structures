import java.lang.Math;

class Stack {

  int top, capacity;
  int array[];

  Stack(int capacity) {
    this.capacity = capacity;
    this.top = -1;
    this.array = new int[capacity];
  }

  private boolean empty() {
    return (top == -1) ? true : false;
  }

  private boolean full() {
    return (top == capacity-1) ? true : false;
  }

  public void push(int val) {
    if(!full()) {
      System.out.println("pushed " + val);
      this.array[++this.top] = val;
    } else {
      System.out.println("error: push: stack full");
    }

  }

  public int pop() {
    if(!empty()) {
      int val = this.array[this.top--];
      System.out.println("popped " + val);
      return val;
    } else {
      System.out.println("error: pop: stack empty");
      return -1;
    }
  }

  public int gettop() {
    return !empty() ? this.array[top] : -1;
  }

  public void show() {
    System.out.print("STACK: ");
    if(!empty()) {
      for(int i=0; i<=top; i++)
        System.out.print(this.array[i] + " ");
      System.out.println();
    }
  }

  public static void main(String[] args) {
    int capacity = 8;
    Stack stack = new Stack(capacity);

    for(int i=0; i<capacity; i++) {
      stack.push((int)(Math.random() * (64 - 0) + 0));
    }

    stack.push((int)(Math.random() * (64 - 0) + 0));
    stack.show();
    stack.pop();
    stack.show();
  }
}
