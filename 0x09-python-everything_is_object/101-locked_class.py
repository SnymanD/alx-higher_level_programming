#!/usr/bin/python3
"""Defines a locked class."""


class LockedClass:
    """
    Prevents the user from instantiating a new LockedClass attributes
    for anything but attributes called 'first name'.
    """

    __slots__ = ["first_name"]
