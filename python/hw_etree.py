import requests
import xml.etree.ElementTree as ET

def main():
    raw_rss_feed = requests.get('https://www.reddit.com/r/python.rss', headers={'User-Agent': 'rss-ingestor'})
    rss_content = raw_rss_feed.content
    parsed_rss = ET.fromstring(rss_content)
    for child in parsed_rss:
        for ele in child:
            if ele.text is not None:
                print(ele.text)

if __name__ == '__main__':
    main()