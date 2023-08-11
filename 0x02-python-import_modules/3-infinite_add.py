#!/usr/bin/python3
# The output should be the result of the addition of all arguments.


def add_arg(argv):
    x = len(argv) - 1
    if x == 0:
        print("{:d}".format(x))
        return
    else:
        u = 1
        add = 0
        while u <= x:
            add += int(argv[u])
            u += 1
        print("{:d}".format(add))


if __name__ == "__main__":
    import sys
    add_arg(sys.argv)
