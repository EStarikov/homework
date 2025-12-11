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
    length = len(arr)
    for i in range(length//2, -1, -1):
        tree(arr, length, i)
    while length - 1 > 0:
        arr[0], arr[length-1] = arr[length-1], arr[0]
        length -= 1
        tree(arr, length, 0)
    return arr
