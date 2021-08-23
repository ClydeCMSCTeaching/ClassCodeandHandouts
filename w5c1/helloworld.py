import math


# example with an optional parameter with default value None
def example_func_using_funcs(a, b, power=None):
    if power is None:
        return a + b
    else:
        return math.pow(a + b, power)

a = 3
b = 5



print(example_func_using_funcs(a, b))
print(example_func_using_funcs(a, b, power=3))
print(example_func_using_funcs(a, b, 3))
print(example_func_using_funcs("hello ", "world "))
print("hello world")


### list example
a = [1, 2, 3, 'Hello']
print("the first thing", a[0])
# format string, so if you put f"", then whenever you use {} you can put code in there!
print(f"the length is {len(a)}")
print(f"the second thing is {a[1]} and the last is {a[-1]}")
print(f"This is a slice of the middle two things", a[1:3])

for i, thing in enumerate(a):
    print(f"{i}th thing is:", thing)

### iterable

myzipcodemap = {14580 : "New York", 60615: "Chicago"}

for key, value in myzipcodemap.items():
    print(f"The key {key} maps to the item {value}")

for key in myzipcodemap.keys():
    print(key)

# a range for loop
# range() /// if you passs it one thing it goes from 0...x

for i in range(10):
    print(i)

for i in range(5, 10):
    print(i)

for i in range(0, 10, 2):
    print(i)

    
print(list(range(10)))


# list comphrensions
b = "hello how are you doing today?"
a = [b[i] for i in range(0, len(b), 2)]
print(a)
print("but to make into a string again use join")
print("".join(a))
print(",".join(a))


def ispalindrome(word):
    front_counter = 0
    back_counter = len(word) - 1
    while front_counter < back_counter:
        if word[front_counter] != word[back_counter]:
            return False
        

        front_counter += 1
        back_counter -= 1

    return True

print(f"Is applesauce a palindrome? {ispalindrome('applesauce')}")
print(f"Is kayak ??? {ispalindrome('kayak')}")


c  = [1, 2, 3]
print(c[0:2])
print(c[:2])
print(c[1:3])
print(c[1:])
print("up to just the end", c[:-1])
