import pyttsx3
import speech_recognition as sr
import serial

engine = pyttsx3.init()

port = 'COM3'
baud = '9600'

ser = serial.Serial(port, baud)

def speak(audio):
    rate = engine.getProperty("rate")
    engine.setProperty("rate", 175)
    engine.say(audio)
    engine.runAndWait()

def takeCommand():
    r = sr.Recognizer()

    with sr.Microphone() as source:
        print("Listening...")
        r.adjust_for_ambient_noise(source, duration=1)
        audio = r.listen(source)

    try:
        print("Recognizing...")
        command = r.recognize_google(audio, language='en-in')
        print(command)
    except Exception as ex:
        print(ex)
        return "none"
    return command.lower()

def greeting():
    speak("Hello! I'm your Personal Assistant! Please tell me how can I help you?")


if _name__=="__main_":
    greeting()
    while True:
        command = takeCommand()
        if 'on' in command:
            speak("turning on the lamp")
            ser.write(b'H')
        elif 'off' in command:
            speak("turning off the lamp") 
            ser.write(b'L')
        elif 'red' in command:
            speak("turning on the red lamp")
            ser.write(b'R')
        elif 'green' in command:
            speak("turning on the green lamp")
            ser.write(b'G')
        elif 'blue' in command:
            speak("turning on the blue lamp")
            ser.write(b'B')
        elif 'open' in command:
            speak("Well, I'll open the garage door")
            ser.write(b'Q')
        elif 'close' in command:
            speak("Well, I'll close the garage door")
            ser.write(b'Z')
        elif 'yellow' in command:
            speak("turning on the yellow lamp")
            ser.write(b'Y')
        elif 'temperature' in command:
            speak("The temprature was displayed on the screen")
            ser.write(b'T')
        elif 'cyan' in command:
            speak("turning on the cyan lamp")
            ser.write(b'C') 
        elif 'purple' in command:
            speak("turning on the purple lamp")
            ser.write(b'P')      
        elif 'bye' in command:
            speak("Goodbye, have a nice day!")
            ser.write(b'L')  
            quit()