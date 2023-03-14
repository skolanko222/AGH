import math

class Vector(object):
    # instantiation
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # str(v)
    def __str__(self):
        return '<{0.x}, {0.y}>'.format(self)

    # repr(v)
    def __repr__(self):
        return 'Vector({0.x}, {0.y})'.format(self)

    # unary negation (-v)
    def __neg__(self):
        return Vector(-self.x, -self.y)

    # addition (v + u)
    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    # subtraction (v - u)
    def __sub__(self, other):
        return self + (-other)

    # equality (v == u)
    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    # abs(v)
    def __abs__(self):
        return math.hypot(self.x, self.y)



def main():

    v = Vector(1, 4)
    u = Vector(2, 0)

    u + v           # Vector(3, 4)
    print(u + v)    # "<3, 4>" (implicit string conversion)
    u - v           # Vector(1, -4)
    u == v          # False
    u + v == v + u  # True
    abs(u + v)      # 5.0


if __name__ == '__main__':
    main()