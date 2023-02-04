def heapify(arr, n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2

    if l < n and arr[i] < arr[l]:
        largest = l

    if r < n and arr[largest] < arr[r]:
        largest = r

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(input):
    """
    Time Complexity: O(nlogn)
    Space Complexity: O(1)
    """
    n = len(input)

    for i in range(n, -1, -1):
        heapify(input, n, i)

    for i in range(n-1, 0, -1):
        input[i], input[0] = input[0], input[i]
        heapify(input, i, 0)

    return input

if __name__ == '__main__':
    input = [12, 4, 5, 3, 2, 7]

    print(heap_sort(input))