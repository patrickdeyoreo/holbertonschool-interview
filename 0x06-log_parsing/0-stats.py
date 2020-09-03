#!/usr/bin/python3
"""
Read log data line-by-line from stdin and print statistics to stdout after
every ten lines or upon receipt of a SIGINT
"""
# pylint: disable=invalid-name
import sys

STATUS_CODES = {200, 301, 400, 401, 403, 404, 405, 500}


class DefaultDict(dict):
    """Defines a dict subclass to set default values for missing keys"""

    def __init__(self, default, *args, **kwargs):
        """Initializes a dict using the provided constructor for defaults"""
        super().__init__(*args, **kwargs)
        self.default = default

    @property
    def default(self):
        """Gets the callable object used to construct default values"""
        return self.__default

    @default.setter
    def default(self, default):
        """Sets the callable object used to construct default values"""
        if not callable(default):
            raise TypeError("'default' must be a callable object")
        self.__default = default

    def __getitem__(self, key):
        """Gets the value of a mapping, setting a default if none exists"""
        if key not in self:
            self.__setitem__(key, self.default())
        return super().__getitem__(key)


def print_stats(file_size, status_codes):
    """Print log metrics to stdout"""
    print('File size: {}'.format(file_size))
    for code in filter(status_codes.get, sorted(STATUS_CODES)):
        print('{}: {}'.format(code, status_codes[code]))


if __name__ == '__main__':

    file_size = 0
    status_codes = DefaultDict(int)
    try:
        for lineno, line in enumerate(sys.stdin, 1):
            fields = line.strip().split()
            try:
                file_size += int(fields.pop())
                status_codes[int(fields.pop())] += 1
            except (IndexError, ValueError):
                pass
            if lineno % 10 == 0:
                print_stats(file_size, status_codes)
        print_stats(file_size, status_codes)
    except KeyboardInterrupt:
        print_stats(file_size, status_codes)
        raise
