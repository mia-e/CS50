from cs50 import get_string

s = get_string("text: ")
num_words = num_sentences = num_letters = 0
#iterates through each character
for i in range(len(s)):
    # if its an alphabetic char
    if s[i].isalpha():
        # add a letter to the count
        num_letters += 1
    # if it has punctuation
    if s[i] == '?' or s[i] == '.' or s[i] == '!':
        #counts sentences
        num_sentences += 1
     # counts words
    if i == 0 and s[i] != ' ' or s[i] != len(s) - 1 and s[i] == ' ' and s[i + 1] != ' ':
        num_words += 1
S = num_sentences / num_words * 100
L = num_letters /  num_words * 100
grade = round(0.0588 * L - 0.296 * S - 15.8)

# conditions to print 
if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")