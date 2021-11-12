class Queue {

  int front, back, size, capacity;
  int[] array;

  Queue(int capacity) {
    this.capacity = capacity;
    this.front = 0;
    this.back = this.capacity - 1;
    this.size = 0;
    this.array = new int[this.capacity];
  }

  private boolean empty() {
    return (this.size == 0) ? true : false;
  }

  private boolean full() {
    return (this.size == this.capacity) ? true : false;
  }

  public void push_back(int val) {
    if(!this.full()) {
      this.back = (this.back + 1) % this.capacity;
      this.array[this.back] = val;
      this.size++;
    } else {
      System.out.println("error: push_back: queue capacity full");
    }
  }

  public int pop_front() {
    int val = -1;
    if(!this.empty()) {
      val = this.array[this.front];
      this.front = (this.front + 1) % this.capacity;
      this.size--;
    } else {
      System.out.println("error: pop_front: queue is empty");
    }
    return val;
  }

  public int getsize() {
    return this.size;
  }

  public void show() {
    System.out.print("Queue: ");
    if(!empty()) {
      int i = this.front;
      int j = this.back;
      while(i!=j) {
        System.out.print(this.array[i] + " ");
        i = (i+1) % this.capacity;
      }
    }
    System.out.println();
  }   

  /* entry point */
  public static void main(String[] args) {
    int capacity = 8;
    Queue queue = new Queue(capacity);

    for(int i=0; i<capacity; i++) {
      queue.push_back((int)(Math.random() * (64 - 0) + 0));
    }
    System.out.println("size: " + queue.getsize());
    queue.show();

    for(int i=0; i<capacity; i++) {
      queue.pop_front();
    }
    System.out.println("size: " + queue.getsize());
    queue.show();
  }
}
