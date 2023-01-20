class Employee:
  def __init__(self, name, rate):
    self.name = name
    self.rate = rate
    self.hours = 0

  def calculate_pay(self):
    return self.rate * self.hours

class DoublyLinkedList:
  def __init__(self):
    self.head = None
    self.tail = None

  def append(self, data):
    new_node = Employee(data, 0)
    if self.head is None:
      self.head = new_node
      self.tail = new_node
    else:
      new_node.prev = self.tail
      self.tail.next = new_node
      self.tail = new_node

  def remove(self, node):
    if node == self.head:
      self.head = node.next
    if node == self.tail:
      self.tail = node.prev
    if node.prev is not None:
      node.prev.next = node.next
    if node.next is not None:
      node.next.prev = node.prev

employees = DoublyLinkedList()

# Add employees
employees.append("John")
employees.append("Jane")

# Set hourly rates for each employee
node = employees.head
while node:
  node.rate = float(input("Enter hourly rate for {}: ".format(node.name)))
  node = node.next

# Calculate pay for each employee
node = employees.head
while node:
  hours = int(input("Enter hours worked for {}: ".format(node.name)))
  node.hours = hours
  pay = node.calculate_pay()
  print("{}'s pay: ${:.2f}".format(node.name, pay))
  node = node.next
