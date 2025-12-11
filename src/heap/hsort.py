def tree(arr, n, i):
    large = i
    left = 2 * i + 1
    right = 2 * i + 2
    if left < n and arr[left] > arr[large]:
        large = left
    if right < n and arr[right] > arr[large]:
        large = right
    if large != i:
        arr[large], arr[i] = arr[i], arr[large]
        tree(arr, n, large)


def h_sort(arr):
    l = len(arr)
    for i in range(l//2, -1, -1):
        tree(arr, l, i)
    while l - 1 > 0:
        arr[0], arr[l-1] = arr[l-1], arr[0]
        l -= 1
        tree(arr, l, 0) 
    return arr
