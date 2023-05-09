import logging
if __name__ == '__main__':
    import zad1
    import zad2
    import zad3
    logging.basicConfig(filename="test.log",filemode='w',format = '%(asctime)s %(message)s')
    logger = logging.getLogger()
    logger.setLevel(logging.INFO)
    print(zad1.zad.__doc__)
    try:
        zad1.zad("1234567891234564")
    except zad1.DlugosNr:
        logging.info("wyjatek! zla dl numeru karty")
    except zad1.BlednyKod:
        logging.info("wyjatek! numer karty niepoprawny")
    except zad1.NieNumer:
        logging.info("wyjatek! numer karty nie jest liczba")
    
    
    print(zad2.zad.__doc__)
    import datetime
    data = datetime.datetime(*(1902,7,4))
    try:
        zad2.zad("02070803628",data,"mezczyzna")
    except zad2.RokError:
        logger.info("wyjatek! rok niepoprawny!")
    except zad2.MiesiacError:
        logger.info("wyjatek! miesiac niepoprawny!")
    except zad2.DzienError:
        logger.info("wyjatek! dzien niepoprawny!")
    except zad2.PlecError:
        logger.info("wyjatek! plec niepoprawny!")


    print(zad3.zad.__doc__)
    zad3.zad()