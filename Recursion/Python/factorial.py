def findfactorialRecursive(number):

    if number == 0:
        return 1

    return number * findfactorialRecursive(number - 1)

def findfactorialIterative(number):

    result = 1
    for i in range(1, number + 1):
        result *= i

    return result

if __name__ == '__main__':
    number = 4
    result = findfactorialRecursive(number)
    print(f"The factorial of {number} is {result}")

    result = findfactorialIterative(number)
    print(f"The factorial of {number} is {result}")
