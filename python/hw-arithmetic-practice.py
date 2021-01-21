import random
import time

BEGINNER = ['+', '-']
INTERMEDIATE = BEGINNER + ['*', '/']
ADVANCED = INTERMEDIATE + ['**', '%']

def get_arithmetic(difficulty):
    switch = {
        'beginner': BEGINNER,
        'intermediate': INTERMEDIATE,
        'advanced': ADVANCED,
    }

    arithmetic = switch.get(difficulty, BEGINNER)

    return f'{random.randint(1, 10)} {random.choice(arithmetic)} {random.randint(1, 10)}'

def main():
    total = 0
    total_correct = 0

    while True:
        total += 1
        timer = time.time()
        question = get_arithmetic('intermediate')
        ans = float(input(f'{question}: '))
        finished = time.time() - timer
        if ans == eval(question):
            total_correct += 1
            print(f'Correct! It took {finished} seconds')

if __name__ == "__main__":
    main()