from cs50 import get_int, get_string


def main():

    # Gets the users cc number

    cc = get_string("Card Number: ")
    compute_card(cc)

# Find the brand of the cc


def cc_brand(cc):
    cc_length = len(cc)
    if (cc_length == 15):
        return ("AMEX")
    elif (cc_length == 16):
        return ("MASTERCARD or VISA")
    elif (cc_length == (13)):
        return ("VISA")
    else:
        return ("INVALID")

# Determines if the cc is M or V


def m_or_v(cc):
    digit_one = cc[0]
    if digit_one == "4":
        return ("VISA")
    else:
        return ("MASTERCARD")

# Calcs every other number and times by 2


def nums1(cc):
    # Starts at num 1 and jumps 2 spots
    num = cc[1::2]
    n = len(str(num))
    total = 0
    for i in (num):
        total += (int(i)) * 2
        return total

# Cals the remaining nums


def nums2(cc):
    # Starts at num 0 and jumps 2 spots
    num = cc[0::2]
    n = len(str(num))
    sum = 0
    for i in num:
        sum += int(i)
        return sum

# applies luhns algo to the two functions


def luhns_algo(num1, num2):
    if (num1 + num2) % 10 == 0:
        return ("VALID")
    else:
        return ("INVALID")


# Uses all the functions


def compute_card(cc):
    if luhns_algo(nums1(cc), (nums2(cc)) == ("VALID")):
        if cc_brand(cc) == ("AMEX"):
            print(cc_brand(cc))
        elif cc_brand(cc) == ("MASTERCARD or VISA"):
            if m_or_v(cc) == ("VISA"):
                print(m_or_v(cc))
            else:
                print(m_or_v(cc))
        else:
            print("INVALID")


main()