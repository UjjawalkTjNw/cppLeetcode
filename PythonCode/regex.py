#code 1:
import re

text = "The phone number is 415-555-1212."

# Find the phone number
phone_number_regex = r"\d{3}-\d{3}-\d{4}"
match = re.search(phone_number_regex, text)

if match:
    print("Phone number found:", match.group())
else:
    print("Phone number not found.")
    
    

#code 2 finding pattern pejasnetworks.com in email
import re

text = "The phone number is 415-555-1212."

# Find the phone number
phone_number_regex = r"\d{3}-\d{3}-\d{4}"
match = re.search(phone_number_regex, text)

if match:
    print("Phone number found:", match.group())
else:
    print("Phone number not found.")
    
    
#info:
#\d: Matches a digit character.
#\w: Matches a word character (alphanumeric or underscore).
#\s: Matches a whitespace character.
#. : Matches any single character except a newline.
#*: Matches zero or more repetitions of the preceding element.
#+: Matches one or more repetitions of the preceding element.
#?: Matches zero or one repetition of the preceding element.   
#[]: Matches a character within the specified set.
#^: Matches the beginning of a string.
#$: Matches the end of a string.