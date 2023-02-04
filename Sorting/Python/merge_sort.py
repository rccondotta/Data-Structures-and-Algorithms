def merge_sort(input):
    """
    Time Complexity: O(nlogn)
    Space Complexity: O(n)
    """
    if len(input) > 1:
        mid = len(input) // 2
        L = input[:mid]
        R = input[mid:]

        merge_sort(L)
        merge_sort(R)

        i = j = k = 0

        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                input[k] = L[i]
                i += 1
            else:
                input[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            input[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            input[k] = R[j]
            j += 1
            k += 1

    return input


if __name__ == '__main__':
    input = [12, 4, 5, 3, 2, 7]

    print(merge_sort(input))