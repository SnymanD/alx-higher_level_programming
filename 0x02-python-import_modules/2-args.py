#!/usr/bin/python3
# Your code should not be executed when imported

if __name__ == "__main__":
    import sys

    size = len(arg) - 1
    arg = sys.argv

    if size == 0:
        print("{} arguments.".format(size))

    elif size > 1:
        print("{} arguments:".format(size))
        for i in range(1, size + 1):
            print("{}: {}".format(i, arg[i]))

    else:
        print("{} argument:".format(size))
        print("{}: {}".format(size, arg[1]))
