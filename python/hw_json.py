import json

def main(): 
    with open('test.json', 'r+') as f:
        test = json.load(f)
        print(test['hello'])

if __name__ == '__main__':
    main()