class MyCircularQueue:

    def __init__(self, k: int):
        self.queue = []
        self.k = k
        """
        Initialize your data structure here. Set the size of the queue to be k.
        """
        

    def enQueue(self, value: int) -> bool:
        if self.isFull() == False:
            self.queue.append(value)
            # print("appended",value)
            return True
        return False
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        """
        

    def deQueue(self) -> bool:
        if self.isEmpty() == False:
            self.queue.pop(-1)
            return True
        return False
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        """
        

    def Front(self) -> int:
        if self.isEmpty() == False:
            return self.queue[0]
        return -1
        """
        Get the front item from the queue.
        """
        

    def Rear(self) -> int:
        if self.isEmpty() == False:
            return self.queue[-1]
        return -1
        """
        Get the last item from the queue.
        """
        

    def isEmpty(self) -> bool:
        if self.queue == []:
            return True
        return False
        
        """
        Checks whether the circular queue is empty or not.
        """
        

    def isFull(self) -> bool:
        if len(self.queue) == self.k:
            return True
        return False
        """
        Checks whether the circular queue is full or not.
        """
        


if __name__ == "__main__":
    obj = MyCircularQueue(8)
    print(obj.enQueue(3))
    print(obj.enQueue(9))
    print(obj.enQueue(5))
    print(obj.enQueue(0))
print(    obj.deQueue())
print(    obj.deQueue())
print(    obj.isEmpty())
print(    obj.isEmpty())
print(    obj.Rear())
print(    obj.Rear())
print(    obj.deQueue())
    