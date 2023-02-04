def selection_sort(input):
    """
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    """
    for i in range(len(input)):
        min = i
        temp = input[i]

        for j in range(i+1, len(input)):
            if input[j] < input[min]:
                min = j

        input[i] = input[min]
        input[min] = temp

    return input


if __name__ == '__main__':
    input = [12, 4, 5, 3, 2, 7]
    selection_sort(input)
    print(input)