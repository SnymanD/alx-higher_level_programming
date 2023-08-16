#!/usr/bin/python3


def complex_delete(my_dict, value):
    tmp = my_dict.copy()
    for s, n in tmp.items():
        if value == n:
            my_dict.pop(s)
    return my_dict
