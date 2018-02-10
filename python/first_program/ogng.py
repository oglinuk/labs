'''
NumberGuessing.py - 5/19/2017 - version 0.1

5/31/2017 update - v0.2
added logging to track:
    the random number generated,
    the guess input,
    the numOfGuesses,
    and the invalid inputs
'''
import random as rng
import logging

def main():
    # logger config
    logger = logging.getLogger(__name__)
    logger.setLevel(logging.DEBUG)
    formatter = logging.Formatter('%(asctime)s:%(name)s:%(levelname)s:%(message)s')
    file_handler = logging.FileHandler('numberguessing.txt')
    file_handler.setFormatter(formatter)
    logger.addHandler(file_handler)

    randomNum = rng.randint(1, 100)
    logger.debug("Random Number: %s" % (randomNum))
    randomNumGuessed = False
    numOfGuesses = 0

    print("Guess a number between 1 and 100")
    while not randomNumGuessed:
        try:
            userGuess = input("Guess: ")
            if (int(userGuess) > 0 and int(userGuess) < 101 and userGuess != None):
                logger.debug("Guess input: %s" %(userGuess))
                if (int(userGuess) == randomNum):
                    numOfGuesses += 1
                    print("Correct!")
                    print("It took you %s guesses!" % (numOfGuesses))
                    logger.debug("Number of guesses: %s" % (numOfGuesses))
                    randomNumGuessed = True
                elif (int(userGuess) > randomNum):
                    print("Too High!")
                    numOfGuesses += 1
                else:
                    print("Too Low!")
                    numOfGuesses += 1
            else:
                print("Invalid Input")
                logger.debug("Invalid Input: %s" % (userGuess))
        except ValueError:
            print("Invalid Input")
            logger.info("Invalid Input: %s" % (userGuess))

if __name__ == "__main__":
    main()
