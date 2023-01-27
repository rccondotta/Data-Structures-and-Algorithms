"""
Time Complexity: O(n) where n is the length of the input string.
This is because the slicing operator [::-1] iterates through the entire string once to create a new reversed string.

Space Complexity: O(n) where n is the length of the input string.
This is because a new string is created to store the reversed string.
"""
# Function to reverse a string
def reverse(string):
    return string[::-1]

print(reverse("Hey how you doing?"))
