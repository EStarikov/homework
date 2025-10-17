def tree(arr, n, i):
    large = i
    l = 2 * i + 1
    r = 2 * i + 2
    if l < n and arr[l] > arr[large]:
        large = l
    if r < n and arr[r] > arr[large]:
        large = r
    if large != i:
        arr[large], arr[i] = arr[i], arr[large]
        tree(arr, n, large)


def h_sort(arr):
    l = len(arr)
    while l - 1 > 0:
        for i in range(l//2, -1, -1):
            tree(arr, l, i)
        arr[0], arr[l-1] = arr[l-1], arr[0]
        l -= 1
    return arr


a = []

print(h_sort(a))
