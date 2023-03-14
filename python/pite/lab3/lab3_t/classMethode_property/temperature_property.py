class Celsius:
    def __init__(self,temperature = 0):
        self._temperature = temperature
    
    @property 
    def temperature(self):
        print("Getting value...")
        return self._temperatur
    
    @temperature.setter
    def temperature(self,value):
        print("Setting value...")
        if value < -273:
            raise ValueError("Temp lower than 0K")
        self._temperatur = value
    
    #def temperature_get(self):
    #   print("Getting value...")
    #   return self._temperature
    
    #def temperature_set(self,value):
    #   print("Setting value...")
    #   if value < -273:
    #       raise ValueError("Temp lower than 0K")
    #   self._temperature = value
    #temperature = property(temperature_get, temperature_set)
    
    #  make empty property
    # temperature = property()
    # assign fget
    # temperature = temperature.getter(get_temperature)
    # assign fset
    # temperature = temperature.setter(set_temperature)

human = Celsius()
human._temperatur = 23
print(human._temperature)