#!/usr/bin/python3
from magic_calculation_102 import add, sub


def magic_calculation(a, b):
    if b > a:
        c = add(a, b)
        for x in range(4, 6):
            d = add(c, x)
        return (d)
    else:
        return sub(a, b)
