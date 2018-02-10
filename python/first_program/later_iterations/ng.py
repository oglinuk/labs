'''
np.py - 6/2/2017
'''
import csv
import logging
import random as rng
from ngLogParser import parse

def main():
    userResponse = input("\n1. Number Guessing Game\n\n2. Number Guessing Bot\n\n3. NG Log Parser\n\n")
    if (userResponse == '1'):
        ng()
    elif (userResponse == '2'):
        ngBot()
    elif (userResponse == '3'):
        parse()
    else:
        print("Invalid Input")

    logging.info('User Initial Input:%s' % (userResponse))

def ng():
    # logger config
    logger = logging.getLogger('ng')
    logger.setLevel(logging.DEBUG)
    formatter = logging.Formatter('%(asctime)s:%(name)s:%(levelname)s:%(message)s')
    file_handler = logging.FileHandler('c:\\logs\\RAWnglogs.txt')
    file_handler.setFormatter(formatter)
    logger.addHandler(file_handler)

    randomNum = rng.randint(1, 100)
    logger.info("Random Number:%s" % (randomNum))
    randomNumGuessed = False
    numOfGuesses = 0

    print("Guess a number between 1 and 100")
    while not randomNumGuessed:
        try:
            userGuess = input("Guess: ")
            if (int(userGuess) > 0 and int(userGuess) < 101 and userGuess != None):
                logger.info("Guess input:%s" %(userGuess))
                if (int(userGuess) == randomNum):
                    numOfGuesses += 1
                    print("Correct!")
                    print("It took you %s guesses!" % (numOfGuesses))
                    logger.info("Number of guesses:%s" % (numOfGuesses))
                    randomNumGuessed = True
                elif (int(userGuess) > randomNum):
                    print("Too High!")
                    numOfGuesses += 1
                else:
                    print("Too Low!")
                    numOfGuesses += 1
            else:
                print("Invalid Input")
                logger.info("Invalid Input:%s" % (userGuess))
        except ValueError:
            print("Invalid Input")
            logger.info("Invalid Input:%s" % (userGuess))

def ngBot():
    # logger config
    logger = logging.getLogger('ngbot')
    logger.setLevel(logging.DEBUG)
    formatter = logging.Formatter('%(asctime)s:%(name)s:%(levelname)s:%(message)s')
    file_handler = logging.FileHandler('RAWngBotLogs.txt')
    file_handler.setFormatter(formatter)
    logger.addHandler(file_handler)

    i = 0
    generationNo = int(input("Enter a generation number: "))
    while (i < generationNo):
        i += 1
        randomNum = rng.randint(1, 100)
        logger.info("Random Number:%s" % (randomNum))
        randomNumGuessed = False
        numOfGenerations = 0
        numOfGuesses = 0

        while not randomNumGuessed:
            guesserGuess = rng.randint(1, 100)
            logger.info("Guess input:%s" %(guesserGuess))
            print(guesserGuess)
            if(guesserGuess == randomNum):
                numOfGuesses += 1
                print("It took the mini bot %s guesses!" % (numOfGuesses))
                logger.info("Number of guesses:%s" % (numOfGuesses))
                randomNumGuessed = True
            elif(guesserGuess > randomNum):
                guesserGuess = rng.randint(1, guesserGuess)
                numOfGuesses += 1
            else:
                guesserGuess = rng.randint(guesserGuess, 100)
                numOfGuesses += 1




if __name__ == "__main__":
    main()
