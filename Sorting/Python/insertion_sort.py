def insertion_sort(input):
    """
    Useful when list is almost sorted and small dataset

    Time Complexity: O(n^2)
    Space Complexity: O(1)
    """
    for i in range(1, len(input)):
        key = input[i]
        j = i - 1

        while j >= 0 and key < input[j]:
            input[j + 1] = input[j]
            j -= 1

        input[j + 1] = key

    return input


if __name__ == '__main__':
    input = [64, 34, 25, 12, 22, 11, 90]

    print(insertion_sort(input))