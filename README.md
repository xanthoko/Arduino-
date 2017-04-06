# Arduino-thermometer
A setup that reads the temperature and the humidity and prints it in a 3 digit 7 segment

HARDWARE:
DHT11 sensor,
Arduino board,
1 Pushbutton,
1 3 digit 7 segment, 
1 10k Ohm resistor,
3 Male-to-famale wires,
14 Male-to-male wires,

SOFTWARE:
Segment_Display library 

Circuit:
We connect the digits of the segment to the 10,11,12 arduino pins and the part of the digits
to the 2-8 pins.
For the pushbutton we connect the lower left pin to the +5V, the lower right pin through a 10k
resistance to the ground and the upper left to the buttonPin.
The sensor is connect to +5V, the ground and the declared pin.
