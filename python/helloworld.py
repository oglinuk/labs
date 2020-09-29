# Credit to - https://www.youtube.com/watch?v=N4mEzFDjqtA

import random # import a library
import sys
import os

print("Hello World")
print('Hello World') # single quote is the same as double in Python

#  ----- Comments  -----

# <- Single line
'''
Multiline
'''

#  ----- Variables  -----

name = "OGLinuk"
print(name)

#  ----- Main data types -----

'''
Numbers
Strings
Lists
Tuples
Dictionaries

+
-
*
/
% - mod
** - power
// - floor div
'''
#ORDER OF OPERATION MATTERS (multiplication and div is
                            #performed before addition or subtraction)

# Strings
#--------------------------------------------------------------

quote = "\"Always remember you are unique" #how to do a quote in python

multi_line_quote = ''' just like everyone else '''

#  ----- String concatination in Python -----
new_string = quote + multi_line_quote
print("%s %s %s" % ('I like this quote', quote, multi_line_quote))
print('{0} {1} {2}!'.format('This is', 'another form', 'of string concatination!'))
print(f'{quote} {multi_line_quote}') # Only available in version of Python >= 3.6 ~ Best option


print("\n * 5") # output is 5 newlines
print("\n") # newline
print("I don't like this", end="") # end="" gets rid of newline
print("newlines")


# Lists
#--------------------------------------------------------------

grocery_list = ['Juice', 'Tomatoes', 'Potatoes', 'Bananas']
print('First Item', grocery_list[0]) # prints the first item in the list

grocery_list[0] = "Green Juice" # how to replace a value in a list
print('First Item', grocery_list[0])

print(grocery_list[1:3]) # prints a sub-set of a list
# REMEMBER this will not print 3's value, it will print values UP TO 3

other_events = ['Wash Car', 'Pick up Kids', 'Cash Check']

to_do_list = [other_events, grocery_list] # how to store multiple lists into one list
print(to_do_list)

print((to_do_list[1][1])) # how to print specific values from a list w/ multiple Lists

grocery_list.append('Onions')
print(to_do_list) # Onions will appear last, appends to the end of existing data

grocery_list.insert(1, "Pickle") # How to add a value in a list at a specified index
grocery_list.remove("Pickle") # How to remove a value in a list
grocery_list.sort()
grocery_list.reverse()
del grocery_list[3] # deletes the value at the specified index

to_do_list2 = other_events + grocery_list
print(len(to_do_list2) # prints the length of the list
print(max(to_do_list2)) # prints the highest alphabetical value in the list
print(min(to_do_list2)) # prints whatever comes first alphabetically

print(grocery_list[-1]) # prints the last item in the list - negative numbers start from the end and work backwards

# Tuples - unlike a list you cannot change the tuple once its created
#-------------------------------------------------------------------

pi_tuple = (3,1,4,1,5,9) # a tuple is surrounded by the ()

new_tuple = list(pi_tuple) # how to convert a tuple into a list
new_list = tuple(new_tuple) # how to convert a list into a tuple

len(pi_tuple) # how to get the length of a tuple
min(pi_tuple) # how to get the highest alphabetical value in a tuple
max(pi_tuple) # how to get the first alphabetical value in a tuple


# Dictionaries (maps) - similar to lists, but you can't join 2 dictionaries together
#---------------------------------------------------------------------------------

super_villians = {'Fiddler' : 'Issac Bowin', # Key : Value
                  'Captain Cold' : 'Leonard Snart',
                  'Weather Wizard' : 'Mark Mardon',
                  'Mirror Master' : 'Sam Scudder',
                  'Pied Piper' : 'Thomas Peterson'}

print(super_villians['Captain Cold'])

del super_villians['Fiddler']

super_villians['Pied Piper'] = 'Harley Rathaway'

print(len(super_villians))

print(super_villians get("Pied Piper")))

print(super_villians.keys())

print(super_villians.values())

super_villians.update({'Harley Quinn': 'Margot Robbie'}) # how to add key/value to a dictionary


# Conditionals --- if else elif == != > >= <=
#-------------------------------------------

# age = 21
age = 30

if age > 16:
    print('You are old enough to drive')
else :
    print('You are not old enough to drive')

if age >= 21:
    print('You are old enough to drive a tractor trailer')
elif age >= 16:
    print('You are old enough to drive a car')
else : print("You are not old enough to drive") # '' and "" are the same it does not matter

# logical operators --- and or not

if ((age >= 1) and (age <= 18)):
    print('You get a birthday')
elif (age == 21) or (age >= 65):
    print('You get a birthday')
elif not(age == 30):
    print('You dont get a birthday')
else:
    print('You get a birthday party yeah!')


# ----- Looping -----

for x in range(0, 10):
    print(x, ' ', end="")

print('\n') # newline

grocery_list = ['Juice', 'Tomatoes', 'Potatoes', 'Bananas']

for y in grocery_list: # for loop that cycles through grocery_list
    print(y)

for x in [2,4,6,8,10]:
    print(x)

num_list = [[1,2,3], [10,20,30], [100,200,300]]

for x in range(0,3):
    for y in range(0,3):
        print(num_list[x][y])

#  ----- While loop -----

random_num = random.randrange(0,100)
while (random_num != 15):
    print(random_num)
    random_num = random.randrange(0,100)

i = 0
while (i <= 20):
    if (i%2 == 0):
        print(i)
    elif (i == 9):
        break
    else:
        i += 1
        continue
    i += 1


# ----- Functions -----

def addNumber(fNum, lNum):
    sumNum = fNum + lNum
    return sumNum

print(addNumber(1, 4))

string = addNumber(1,4)
print(string)

# ----- Getting user input -----

print('What is your name')
name = sys.stdin.readline()
print('Hello ', name)
# OR
name = input('What is your name')
print('Hello ', name)

# ----- String manipulation -----

long_string = "I'll catch you if you fall - The Floor"

print(long_string[0:4]) # prints out I'll
print(long_string[-5:]) # prints Floor
print(long_string[:4] + " be there") # prints I'll be there
print("%c is my %s letter and my number %d number is %.5f" % ('X', 'favorite', 1, .14)) # string concatination

print(long_string.capitalize()) # adds capitalization
print(long_string.find("Floor")) # finds the index of a specified value (case sensative)
print(len(long_string)) # prints length of long_string
print(long_string.replace("Floor", "Ground")) # replace specified value
print(long_string.strip()) # strips whitespace

quote_list = long_string.split(" ")
print(quote_list)

# ----- File IO -----

test_file = open("test.txt", "ab+") # "wb" (write bytes) -- use "ab+" (Read & Append)
print(test_file.mode) # prints mode of the file
print(test_file.name) # prints name
test_file.write(bytes("Write me to the file\n", 'UTF-8')) # write information to a file (must include the bytes() and 'UTF-8'
test_file.close() # closes the file
test_file = open("test.txt", "r+") # read write
text_in_file = test_file.read() # how to read a file
print(text_in_file)

# better way of opening files - similar to a using statment in C#
with open("test.txt", "ab+") as test_file:
    print(test_file)
    test_file.write(bytes("Write me to the file\n", "UTF-8"))
    # this way you dont need test_file.close()

os.remove("test.txt") # how to remove a file

# ----- Objects -----

class Animal:
    # State
    __name = None # signifies lack of a value
    __height = 0 # __ means private
    __weight = 0
    __sound = 0

    # Behavior

    # constructor
    def __init__(self, name, height, weight, sound):
        self.__name = name
        self.__height = height
        self.__weight = weight
        self.__sound = sound

    # getter/setter
    def set_name(self, name):
        self.__name = name

    def get_name(self):
        return self.__name

    def set_height(self, height):
        self.__height = height

    def get_height(self):
        return self.__height

    def set_weight(self, weight):
        self.__weight = weight

    def get_weight(self):
        return self.__weight

    def set_sound(self, sound):
        self.__sound = sound

    def get_sound(self):
        return self.__sound

    def get_type(self):
        print("Animal")

    def toString(self):
        return "{} is {} cm tall and {} kgs and says {}".format(self.__name,
                                                                self.__height,
                                                                self.__weight,
                                                                self.__sound)

cat = Animal('Whiskers', 33, 10, 'Meow')

print(cat.toString())

class Dog(Animal): # example of inheritance
    __owner = ""

    def __init__(self, name, height, weight, sound, owner):
        self.__owner = owner
        super(Dog, self).__init__(name, height, weight, sound) # calls the base constructor

    def set_owner(self, owner):
        self.__owner = owner

    def get_owner(self):
        return self.__owner

    def get_type(self):
        print("Dog")

    def toString(self): # creating a function with the same name is overriding in Python
        return "{} is {} cm tall and {} kgs and says {}. His owner is {}".format(self.__name,
                                                                self.__height,
                                                                self.__weight,
                                                                self.__sound,
                                                                self.__owner)

    # example of method overloading
    def multiple_sounds(self, how_many=None): # local var how_many has the ability to be None
        if how_many is None:
            print(self.get_sound())
        else:
            print(self.get_sound() * how_many)


spot = Dog("spot", 53, 27, "Ruff", "Daniel")
print(spot.toString())

# ----- polymorphism -----

class AnimalTesting:
    def get_type(self, animal):
        animal.get_type()

test_animals = AnimalTesting()

test_animals.get_type(cat) # prints animal
test_animals.get_type(spot) # prints dog

spot.multiple_sounds(4) # prints Ruff 4 times
spot.multiple_sounds()

# ----- Lambda expressions -----
def DoSomething(f, x): # simple function for the lamda expression
    return f(x)

print(DoSomething(lambda x: x * x * x, 3))

