class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def push(self,data):
        new_node = Node(data) #Allocating the node
        new_node.next = self.head
        self.head = new_node
    
    
    def insertAfter(self,prev_node,new_data):
        if prev_node is None:
            print("no prev_node initialized")
        new_node = Node(new_data)
        new_node.next = prev_node.next
        prev_node.next = new_node
    

    def append(self,new_data):
        new_node = Node(new_data)
        if self.head is None:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        
        last.next = new_node
    
    def printlist(self):
        temp = self.head
        while temp.next:
            print(temp.data)
            temp = temp.next
    
    def deleteNode(self,key):
        temp = self.head
        if temp is not None:
            if temp.data == key:
                self.head = temp.next
                temp = None
                return
        prev = None
        while temp:
            if temp.data == key:
                break
            prev = temp
            temp = temp.next
        if temp == None:
            return #Key not found

        prev.next = temp.next
        # temp = None
    def deletePos(self,pos):
        if self.head == None:
            print("ll empty")
            return
        temp = self.head
        if pos == 0:
            # temp = self.head
            self.head = temp.next
            return
        cnt = 0
        prev = None
        while cnt != pos and temp.next:
            prev = temp
            temp = temp.next
            cnt += 1
        prev.next = temp.next


if __name__ == '__main__':
    llist = LinkedList()
    llist.append(0)
    for i in range(10):
        # print(i)
        llist.push(i)
    # llist.printlist()
    # llist.deleteNode(4)
    llist.deletePos(0)
    llist.printlist()

# class Node: