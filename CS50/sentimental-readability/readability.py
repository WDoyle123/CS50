from cs50 import get_int, get_string
import string


def main():

    # Get text from user
    text = get_string("Text: ")

    # Creates translate table to remove spaces
    remove_space = text.maketrans("", "", " ")

    # Creates translate table to remove punctuation
    remove_punc = text.maketrans("", "", string.punctuation)

    # Removes punctuation and spaces and counts the amount of letters
    text_no_punc = text.translate(remove_punc)
    letter_count = len(text_no_punc.translate(remove_space))

    # Prints the grade of text
    index = coleman_liau(letter_count, word_count(text), sentence_count(text))
    if index > 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    elif (index > 1) and (index < 16):
        print("Grade " + str(index))


# Counts the words in text by counting spaces
def word_count(text):
    words = 1
    remove_punc = text.maketrans("", "", string.punctuation)
    text = text.translate(remove_punc)
    for i in text:
        if i == (" "):
            words += 1
    return words


# Counts the senteences in text by counting punctuation
def sentence_count(text):
    sentence_count = 0
    double_dot = 0
    for i in text:
        if i == ("!") and (double_dot == 0):
            sentence_count += 1
            double_dot = 1
        elif i == (".") and (double_dot == 0):
            sentence_count += 1
            double_dot = 1
        elif i == ("?") and (double_dot == 0):
            sentence_count += 1
            double_dot = 1
        else:
            double_dot = 0
    return sentence_count


# Applies the coleman-liau algo
def coleman_liau(num_l, num_w, num_s):
    L = num_l / num_w * 100
    S = num_s / num_w * 100
    return round(0.0588 * L - 0.296 * S - 15.8)


main()