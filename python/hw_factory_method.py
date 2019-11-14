import abc
import urllib2
from BeautifulSoup import BeautifulStoneSoup

class FactoryMethodExample(object):
    @staticmethod
    def build_connection(protocol):
        if protocol == 'http':
            return HTTPConnection()
        elif protocol == 'ftp':
            return FTPConnection()
        else:
            raise RunttimeError('Unknown protocol')

class Connector(object):
    __metaclass__ = abc.ABCMeta

    def __init__(self, is_secure):
        self.is_secure = is_secure
        self.port = self.port_factory_method()
        self.protocol = self.protocol_factory_method()

    @abc.abstractmethod
    def parse(self):
        pass

    def read(self, host, path):
        url = self.protocol + '://' + host + ':' + str(self.port) + path
        print('Connecting to ', url)
        return urllib2.urlopen(url, timeout=2).read()

        @abc.abstractmethod
        def protocol_factory_method(self):
            pass

class HTTPConnector(Connector):
    def protocol_factory_method(self):
        if self.is_secure:
            return 'https'
        return 'http'

    def port_factory_method(self):
        if self.is_secure:
            return HTTPSecurePort()
        return HTTPPort()

    def parse(self, content):
        filenames = []
        soup - BeautifulStoneSoup(content)
        links = soup.table.findAll('a')
        for link in links:
            filenames.append(link['href'])
        return '\n'.join(filenames)

class FTPConnector(Connector):
    def protocol_factory_method(self):
        return 'ftp'

    def port_factory_method(self):
        return FTPPort()

    def parse(self, content):
        lines = content.split('\n')
        filenames = []
        for line in lines:
            split_line = line.split(None, 8)
            if len(split_line) == 9:
                filenames.append(split_line[-1])
        return '\n'.join(filenames)

class Port(object):
    @abc.abstractmethod
    def __str__(self):
        pass

class HTTPPort(Port):
    def __str__(self):
        return '80'

class HTTPSecurePort(Port):
    def __str__(self):
        return '443'

class FTPPort(Port):
    def __str__(self):
        return '21'



if __name__ == '__main__':
    protocol = input('Protocol (http or ftp): ')
    protocol = FactoryMethodExample.build_connection(protocol)
    protocol.connect()
    print(protocol.get_respoense())
    domain = 'ftp.freebsd.org'
    path = '/pub/FreeBSD/'
    protocol = input('Connecting to {0}. Which protocol to use?\n0) HTTP\n1)FTP').format(domain)
    if protocol == 0:
        is_secure = bool(input('Use secure connection?\n1) Yes\n2) No'))
        connector = HTTPConnector(is_secure)
    else:
        is_secure = False
        connector = FTPConnector(is_secure)

    try:
        content = connector.read(domain, path)
    except urllib2.URLError, e:
        print('Can not access resource with this method')
