from Point import Point


def parse_point(stuff):
    stuff = stuff.split(",")
    return Point(int(stuff[0]), int(stuff[1]))

def get_op_and_split(mystr):
    if "+" in val:
        split_char = '+'
    elif "-" in val:
        split_char = '-'

    two_points = val.split(split_char)
    print(f"This is the input: {val}")
    print(f"this is two points: {two_points}")
    left_point  = two_points[0].strip().replace("(", "").replace(")", "")
    right_point = two_points[1].strip().replace("(", "").replace(")", "")

    return split_char, left_point, right_point

if __name__ == "__main__":
    print("hey welcome to my point calculator!")
    
    val = input("> ")
    while(val.strip() != "quit"): # remove whitespace and \n

        op, left_point, right_point = get_op_and_split(val)
        left_point = parse_point(left_point)
        right_point = parse_point(right_point)

        if op == "+":
            print(left_point + right_point)
        elif op == '-':
            print(left_point - right_point)

        val = input("> ")

    print("k bye")
