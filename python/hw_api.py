'''Riot API'''
import requests
import json

def getSummonerData(region, summonerName, APIKey):
    # Can you spot the problem in the line of code below?
    URL = "https://{0}.api.riotgames.com/api/lol/OCE/v1.4/summoner/by-name/{1}?api_key={2}".format(region, summonerName, APIKey)
    print(URL)
    response = requests.get(URL)
    parsedResponse = json.loads(str(response))
    for jsonItem in response:
        parsedJSON = jsonItem.decode('UTF-8')
    return parsedResponse

def main():
    print('\nType a region to start \n\nNA EUW EUNE LAN BR KR LAS OCE TR RU PBE')
    region = input('Region: ')
    summonerName = input('Summoner Name: ')
    APIKey = input('API Key: ')

    JSONfile = getSummonerData(region, summonerName, APIKey)
    print(JSONfile)
    summonerID = JSONfile[summonerName]['id']
    print(str(summonerID))

if __name__ == '__main__':
    main()
