import math

class vect:
    def __init__(self, id=None):
        self.data = []
        self.n = 0
        self.id = id
    def __str__(self):
        return "[vector: id = %s]"%self.id
    def set(self, id, data):
        self.data=[float(x) for x in data]
        self.n=len(data)
        self.id=id
    def norm(self):
        return math.sqrt(sum([self.data[i]**2 for i in range(self.n)]))
    def __add__(self, v):
        if self.n==v.n:
            av = vect()
            av.set("av", [self.data[i] + v.data[i] for i in range(v.n)])
        return av

class sub_vect(vect):
    def norm(self):
        return vect.norm(self)+0.5 

if __name__=="__main__":
    v = vect()
    v.set("myvect", [3,4,5])
    print(str(v))

    sv =sub_vect()
    sv.set("sv", [4,0,3])
    v2 = v+sv
    print(v2)


