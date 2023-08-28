#!/usr/bin/python3


def magic_calculation(a, b):
    result = 0
    for u in range(1, 3):
        try:
            if u > a:
                raise Exception('Too far')
            else:
                result += a ** b / u
        except Exception:
            result = b + a
            break
    return (result)
