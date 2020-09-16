import random
import time

STUDY = {'study': ['AI', 'maths', 'linux', 'dealers choice']}
PROGRAM = {'program': ['c', 'c++', 'go', 'python', 'rust', 'dealers choice']}
RELAX = {'relax': ['play games', 'watch something', 'dealers choice']}
BLOG = {'blog': STUDY['study'] + PROGRAM['program']}
TODOS = [STUDY, PROGRAM, RELAX, BLOG]

def get_choice(l):
    return random.choice(l)

def main():
    random.seed(time.time())
    topic = get_choice(TODOS)
    target_key = next(iter(topic))
    target = get_choice(topic[target_key])
    print(f'Todo today: {target_key} {target}')

if __name__ == '__main__':
    main()