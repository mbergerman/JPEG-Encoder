import numpy as np

class Coordinates():
    def __init__(self, i=0, j=0, imax=8, jmax=8):
        self.i = i
        self.j = j
        self.set_max_coordinates(imax,jmax)
    def __add__(self, other):
        i = self.i + other.i
        j = self.j + other.j
        self.is_valid(i,j)
        return Coordinates(i,j,self.imax,self.jmax)
    def __sub__(self,other):
        i = self.i - other.i
        j = self.j - other.j
        self.is_valid(i,j)
        return Coordinates(i,j,self.imax,self.jmax)
    def __repr__(self):
        return "("+str(self.i)+","+str(self.j)+")"
    def __eq__(self, other):
        return self.i==other.i and self.j==other.j
    def set_max_coordinates(self,i,j):
        self.imax = i
        self.jmax = j
    def is_valid(self,i,j):
        if i<0 or i>self.imax:
            raise ValueError(f'i coordinate out of boundaries: {Coordinates(i,j)}')
        if j<0 or j>self.jmax:
            raise ValueError(f'j coordinate out of boundaries: {Coordinates(i,j)}')
        
class Vectorize():
    def zigzag(self, array: np.ndarray):
        self.arr = array
        self.c = Coordinates()
        rows, cols = np.shape(array)
        self.c.set_max_coordinates(rows-1,cols-1)
        self.end = Coordinates(rows-1,cols-1)

        switcher = {
            'right': self.__right,
            'downleft': self.__downleft,
            'upright': self.__upright,
            'down': self.__down
        }
        self.state = 'right'
        self.vector = np.array([])
        while True:
            self.vector = np.append(self.vector,self.arr[self.c.i,self.c.j])
            if self.state == 'end':
                break
            switcher[self.state]()
        return self.vector
    
    def unzigzag(self, vector: np.ndarray, rows, cols):
        self.arr = np.zeros([rows,cols])
        self.c = Coordinates()
        self.c.set_max_coordinates(rows-1,cols-1)
        self.end = Coordinates(rows-1,cols-1)

        switcher = {
            'right': self.__right,
            'downleft': self.__downleft,
            'upright': self.__upright,
            'down': self.__down
        }
        self.state = 'right'

        for k in range(np.size(vector)):
            self.arr[self.c.i,self.c.j] = vector[k]
            if self.state == 'end':
                break
            switcher[self.state]()
        return self.arr

    def __right(self):
        self.c += Coordinates(0,1)
        if self.c == self.end:
            self.state = 'end'
        elif self.c.i == self.c.imax:
            self.state = 'upright'
        elif self.c.i == 0:
            self.state = 'downleft'

    def __downleft(self):
        self.c += Coordinates(1,-1)
        if self.c.j == 0 and self.c.i<self.c.imax:
            self.state = 'down'
        elif self.c.i==self.c.imax:
            self.state = 'right'

    def __upright(self):
        self.c += Coordinates(-1,1)
        if self.c.i == 0 and self.c.j<self.c.jmax:
            self.state = 'right'
        elif self.c.j==self.c.jmax:
            self.state = 'down'

    def __down(self):
        self.c += Coordinates(1,0)
        if self.c == self.end:
            self.state = 'end'
        elif self.c.j == 0:
            self.state = 'upright'
        elif self.c.j == self.c.jmax:
            self.state = 'downleft'

def test_vectorize_class():
    arr1 = np.array([[1,2,3],[4,5,6],[7,8,9]])
    arr2 = np.array([[1, 2, 3, 4],[5, 6, 7, 8],[9, 10, 11, 12],[13, 14, 15, 16]])
    arr3 = np.array([[1,2,3],[4,5,6],[7,8,9],[10,11,12]])
    arr4 = np.array([[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15]])
    for arr in arr1,arr2,arr3,arr4:
        v = Vectorize()
        print(f"Array:\n{arr}")
        vect = v.zigzag(arr)
        print(f"Vector:\n{vect}")
        print(f"Array:\n{v.unzigzag(vect,*np.shape(arr))}")

