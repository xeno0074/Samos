import random
import time
import string


def random_str(length):
    return str.title(''.join(random.choices(string.ascii_lowercase, k=length)))


def get_txType(values_txType, values_tags, given_tag):
    for index in range(len(values_tags)):
        if values_tags[index] is given_tag:
            map_txType = ['debit', 'credit']
            return map_txType[int(values_txType[index])]


def str_time_prop(start, end, time_format, prop):
    """Get a time at a proportion of a range of two formatted times.

    start and end should be strings specifying times formatted in the
    given format (strftime-style), giving an interval [start, end].
    prop specifies how a proportion of the interval to be taken after
    start.  The returned time will be in the specified format.
    """

    stime = time.mktime(time.strptime(start, time_format))
    etime = time.mktime(time.strptime(end, time_format))

    ptime = stime + prop * (etime - stime)

    return time.strftime(time_format, time.localtime(ptime))


def random_date(start, end):
    return str_time_prop("1/1/{} 12:00 AM".format(start), "1/1/{} 12:00 AM".format(end), '%m/%d/%Y %I:%M %p',
                         random.random())
