from urllib.request import urlopen as uReq
from bs4 import BeautifulSoup as bs

def main():

    # BeautifulSoup implementation
    url = input('Please enter a url: ')
    sauce = uReq(url)
    page_html = sauce.read()
    sauce.close()
    soup = bs(page_html, "html.parser")

    # HTML parsing
    containers = soup.find('body')
    print(containers)

    # Writing to file - payload.txt
    with open('payload.txt', 'ab+') as f:
        f.write(bytes('\n{0}\n\n'.format(containers), 'UTF-8'))

if __name__ == '__main__':
    main()