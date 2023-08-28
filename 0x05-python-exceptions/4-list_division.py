#!/usr/bin/python3
def list_division(my_list_1, my_list_2, list_length):
    n_list = []
    for u in range(list_length):
        try:
            div = my_list_1[u] / my_list_2[u]
        except TypeError:
            print("wrong type")
            div = 0
        except ZeroDivisionError:
            print("division by 0")
            div = 0
        except IndexError:
            print("out of range")
            div = 0
        finally:
            n_list.append(div)
    return n_list
