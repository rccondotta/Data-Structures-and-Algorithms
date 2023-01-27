"""
Time complexity: O(m log m) because the sort() method has a time complexity of O(n log n)
and we are calling it once with an array of size m+n

Space complexity: O(1) because we are merging the arrays in place, no additional memory is needed.
"""
def mergeSortedArrays(a, b):
    a.extend(b)
    a.sort()

a = [0, 3, 4, 31]
b = [4, 5, 30]

mergeSortedArrays(a, b)

print(a)