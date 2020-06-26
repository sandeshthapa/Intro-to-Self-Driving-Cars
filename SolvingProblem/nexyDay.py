###
### Define a simple nextDay procedure, that assumes
### every month has 30 days.
###
### For example:
###    nextDay(1999, 12, 30) => (2000, 1, 1)
###    nextDay(2013, 1, 30) => (2013, 2, 1)
###    nextDay(2012, 12, 30) => (2013, 1, 1)  (even though December really has 31 days)
###

def nextDay(year, month, day):
    """
    Returns the year, month, day of the next day.
    Simple version: assume every month has 30 days.
    """
    # YOUR CODE HERE
    #nextyear = 0

    if (month == 12 and day ==30):
        nextyear = year+1
    else:
        nextyear = year

    if (day == 30 ):
        nextmonth = (month %12) +1
    else:
        nextmonth = month

    nextday = (day % 30) + 1


    return nextyear, nextmonth,  nextday
