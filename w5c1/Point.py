import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def magnitude(self):
        return math.sqrt(self.x**2 + self.y**2)

    def __iter__(self):
        for i in [self.x, self.y]:
            yield i

    def __len__(self):
        return 2
    
    def __getitem__(self, i):
        if i == 0:
            return self.x
        if i == 1:
            return self.y
        raise IndexError("i is not a valid index from [0,1]")

    def __str__(self):
        return f"({self.x}, {self.y})"

    def __repr__(self):
        return self.__str__()

    def __add__(self, rhs):
        return Point(self.x + rhs.x, self.y + rhs.y)

    def __sub__(self, rhs):
        return Point(self.x - rhs.x, self.y - rhs.y)

    def __eq__(self, rhs):
        return self.x == rhs.x and self.y == rhs.y
