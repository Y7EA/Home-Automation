# Home Automation

## Overview
The Smart Home Project is a home automation system that allows you to control various aspects of your home using voice commands. With this project, you can control lights, monitor temperature, open/close the garage door, and more.

## Features
- Voice-controlled lights: Turn lights on/off and change colors using voice commands.
- Temperature monitoring: Display temperature readings on an LCD screen.
- Garage door control: Open and close the garage door using voice commands.
- Gas detection: Detect gas levels in your home and trigger an alarm if necessary.
- Motor controls: Control the movement of devices such as curtains or doors using motor controls.

## Hardware Requirements
- Arduino board
- Sensors (IR sensor, gas sensor)
- Actuators (LED lights, motor controls)
- LCD screen
- Buzzer
- RGB lights
- Microphone

## Installation and Setup
1. Connect the Arduino board to your computer.
2. Install the required libraries (LiquidCrystal, Wire, LiquidCrystal_I2C, pyttsx3, speech_recognition) on your Arduino IDE and Python environment.
3. Upload the Arduino code (`smart_home_arduino.ino`) to your Arduino board.
4. Connect the sensors, actuators, and lights to the appropriate pins on the Arduino board according to the circuit diagram provided.
5. Connect the microphone to your computer for voice commands.

## Usage
1. Run the Python script (`smart_home_python.py`) on your computer.
2. Ensure that the Arduino board is connected and the correct COM port is selected.
3. Speak voice commands to control the smart home system. For example:
   - "Turn on the lights"
   - "Open the garage door"
   - "Display temperature"


## Video Demo
<!-- [![Watch the video](https://img.youtube.com/vi/YOUR_VIDEO_ID_HERE/0.jpg)](https://www.youtube.com/watch?v=YOUR_VIDEO_ID_HERE)
 -->
## Additional Resources
- [Article: Building a Voice-Controlled Smart Home](https://drive.google.com/file/d/18lYXL48CJIC80BdmO6eojvxKjHDZoQDv/view?usp=sharing) - Learn more about the development process and implementation details of this project.


## Customization
Feel free to customize the code according to your specific needs. You can add new functionalities, modify voice commands, or integrate with other home automation systems.

## Troubleshooting
If you encounter any issues or have questions, please refer to the documentation or seek assistance from me.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments
- [pyttsx3](https://pypi.org/project/pyttsx3/) - Text-to-speech library for Python
- [SpeechRecognition](https://pypi.org/project/SpeechRecognition/) - Speech recognition library for Python
- [Arduino](https://www.arduino.cc/) - Open-source electronics platform

