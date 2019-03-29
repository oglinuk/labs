# https://stackoverflow.com/q/6760685
class Singleton(type):
    _instances = {}
    def __call__(cls, *args, **kwargs):
        if cls not in cls._instances:
            cls._instances[cls] = super(Singleton, cls).__call__(*args, **kwargs)
        return cls._instances[cls]

class Logger(metaclass=Singleton):
    pass

if __name__ == '__main__':
    log1 = Logger()
    log2 = Logger()
    print('%s\n%s' % (log1, log2))
    
