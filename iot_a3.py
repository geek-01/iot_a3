import time
import serial
ser = serial.Serial('/dev/ttyACM0', 9600)
while True:
    ch=raw_input("1.blink \n2.buzz \n3.temeprature and humidity \n4.switch on\n5.switch off\nenter your choice")
    print("\n")
    ser.flushInput() #flush previous output
    if(ch=='1'):
        ser.write("blink")
        print("Led on ...")
        print("Led off ...")
    elif(ch=='2'):
        ser.write("buzz")
        print (" Buzzer on ...")
        print (" Buzzer off ...")
    elif(ch=='3'):
        ser.write("temphumid")
        print(ser.readline())
    elif(ch=='4'):
        ser.write("switch_on")
        print("switch on")
    elif(ch=='5'):
        ser.write("switch_off")
        print("switch off")
    else:
        print("invalid choice")
    print("\n")
