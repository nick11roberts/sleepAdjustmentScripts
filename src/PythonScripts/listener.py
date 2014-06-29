# This program anticipates values every 15000ms ranging from 0-100 from the serial port. 
import serial
import os
import datetime



# CONSTANTS
PORT = "/dev/ttyACM0"
SER = serial.Serial(PORT, 9600)
# This is the length of the range used for averaging the data
ARDUINO_DELAY = 15000
AVERAGING_ITER_FACTOR = 40
TIME_LENGTH_OF_AVERAGES = ARDUINO_DELAY * AVERAGING_ITER_FACTOR
RANGE_ITERATIONS = (TIME_LENGTH_OF_AVERAGES/ARDUINO_DELAY)
CUTOFF_VAL = 85
NAME = "Nick"

running = True
dat_mean = 0;
dat_index = [0,0,0,0,
			 0,0,0,0,
			 0,0,0,0,
			 0,0,0,0,
			 0,0,0,0]


def average_of_list(num_list, list_length):
	sum_of_list_items = 0
	average = 0
	for i in range (0, list_length):
		sum_of_list_items += num_list[i]
	average = sum_of_list_items/list_length
	return average


def low():
	for i in range (0, RANGE_ITERATIONS):
		dat_index[i] = int(SER.readline())
		dat_mean = average_of_list(dat_index, i+1)
	if dat_mean <= CUTOFF_VAL-1: 
		is_low = True
	else:
		is_low = False 	
	return is_low


def text_to_speech(text):
      return os.system("espeak  -s 155 -a 200 "+text+" " )
      

# The first reading is most likely for calibration, so skip it.         
SER.readline()
while running:
	m = datetime.datetime.now().strftime("%I %M %S")
	
	if not low():
		# TODO
		# do something
		# like make the user enter the numbers from LOST
		# Perhaps later it can grab text from an online service or an AI? Maybe Reddit? 
		text_to_speech("'Master "
						+NAME+
						", the time is "
						+str(int(m[0:2]))
						+" "+str(int(m[3:5]))
						+" : go forth and "
						+"prepare yourself some coffee : "
						+"The day awaits : ' ")
		running = False
		
		
		
		

