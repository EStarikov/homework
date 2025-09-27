mas = [0, 6, 4, 8, 45 ,9 ,15, 11,890, 76]

def bubble_sort(m):
    for i in range(len(m)-1):
        for j in range(len(m)-1-i):
            if m[j] > m[j+1]:
                m[j], m[j+1] = m[j+1], m[j]
    return m 
    
print(bubble_sort(mas))
