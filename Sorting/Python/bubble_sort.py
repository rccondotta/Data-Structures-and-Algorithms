def bubble_sort(input):
    """
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    """
    for i in range(len(input)):
        for j in range(len(input)-1):
            if (input[j] > input[j+1]):
                temp = input[j]
                input[j] = input[j+1]
                input[j+1] = temp

    return input

if __name__ == '__main__':
    input = [12, 4, 5, 3, 2, 7]
    print(bubble_sort(input))