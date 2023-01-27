"""
Time complexity of O(n)
Space complexity of O(n)
as we are using an extra Hashmap to store the characters
"""
def firstRecurringCharacter(input):
    map = {}
    for i in input:
        if i in map:
            return i
        else:
            map[i] = True
    return None

input = [2,5,1,2,3,5,1,2,4]
result = firstRecurringCharacter(input)
if result == None:
    print("undefined")
else:
    print(result)

input = [2,1,1,2,3,4,1,2,4]
result = firstRecurringCharacter(input)
if result == None:
    print("undefined")
else:
    print(result)

input = [2, 3, 4, 5]
result = firstRecurringCharacter(input)
if result == None:
    print("undefined")
else:
    print(result)
