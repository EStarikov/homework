class Queue:
    def __init__(self):
        self.roots = []

    def merge(self):
        self.roots.sort(key=lambda x: x.degree)
        i = 0
        while i < len(self.roots) - 1:
            a, b = self.roots[i], self.roots[i+1]
            if a.degree == b.degree:
                if a.key < b.key:
                    b.sibling = a.child
                    a.child = b
                    b.parent = a
                    a.degree += 1
                    self.roots.pop(i + 1)
                else:
                    a.sibling = b.child
                    b.child = a
                    a.parent = b
                    b.degree += 1
                    self.roots.pop(i)
            else:
                i += 1

    def insert(self, key):
        self.roots.insert(0, Tree(key=key))
        self.merge()

    def extract_min(self):
        minimum = self.roots[0].key
        ind_min = 0
        for i in range(1, len(self.roots)):
            if minimum > self.roots[i].key:
                minimum = self.roots[i].key
                ind_min = i
        if self.roots[ind_min].child is not None:
            self.roots.append(self.roots[ind_min].child)
            self.roots[-1].parent = None
            tree = self.roots[-1]
            while tree.sibling is not None:
                self.roots.append(tree.sibling)
                tree1 = tree.sibling
                tree.sibling = None
                tree = tree1
                tree.parent = None
        k = minimum
        self.roots.pop(ind_min)
        self.merge()
        return k


class Tree:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.child = None
        self.sibling = None
        self.degree = 0
