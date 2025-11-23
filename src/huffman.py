class Leaf:
    def __init__(self, ch=None, freq=None, left=None, right=None):
        self.ch = ch
        self.freq = freq
        self.left = left
        self.right = right

    def walk(self, code, acc):
        if self.ch is not None:
            code[self.ch] = acc
        else:
            if self.left is not None:
                self.left.walk(code, acc + '0')
            if self.right is not None:
                self.right.walk(code, acc + '1')


def encode(s):
    d = {}
    for char in s:
        if char in d:
            d[char] += 1
        else:
            d[char] = 1
    leaves = [Leaf(char, freq) for char, freq in d.items()]
    leaves.sort(key=lambda x: (x.freq, -ord(x.ch)))
    while len(leaves) > 1:
        left = leaves.pop(0)
        right = leaves.pop(0)
        parent = Leaf(None, left.freq + right.freq, left, right)
        i = 0
        while i < len(leaves):
            if leaves[i].freq < parent.freq:
                i += 1
            else:
                break
        leaves.insert(i, parent)
    code = {}
    leaves[0].walk(code, "")
    t = ""
    for x in s:
        t += code[x]
    return (t, code)


def decode(t, code):
    tt = ""
    s = ""
    reversed_code = {value: key for key, value in code.items()}
    for x in t:
        tt += x
        if tt in reversed_code:
            s += reversed_code[tt]
            tt = ""
    return s


def file_encode(filename1, filename2):
    try:
        with open(filename1, 'r') as f:
            s = f.read()
        t, code = encode(s)
    except UnicodeDecodeError:
        with open(filename1, 'rb') as f:
            binary_data = f.read()
            s = binary_data.decode('utf-8')
        t, code = encode(s)
    with open(filename2, 'w') as f:
        f.write(t)
    return filename2, code


def file_decode(filename1, filename2, code):
    with open(filename1, 'r') as f:
        s = f.read()
    t = decode(s, code)
    with open(filename2, 'w') as f:
        f.write(t)
    return filename2


