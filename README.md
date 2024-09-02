# S24-Smart_intercom

## Project Overview
The S24-Smart_intercom project is designed to create a smart intercom system using ESP32-CAM and a Flutter mobile application. This project is divided into three main components:

1. **ESP-code**: Contains the code for the ESP32 microcontroller.
2. **ESP32-CAM**: Contains the code and configurations specific to the ESP32-CAM module.
3. **Flutter-App**: Contains the Flutter application code for the mobile interface.

## Folder Structure

### ESP-code
This folder contains the firmware code for the ESP32 microcontroller. It includes:
- **main.cpp**: The main program file.
- **config.h**: Configuration settings for the ESP32.
- **lib/**: Libraries used in the project.

### ESP32-CAM
This folder contains the code and configurations specific to the ESP32-CAM module. It includes:
- **camera_config.h**: Configuration settings for the camera module.
- **camera_main.cpp**: The main program file for the camera.

### Flutter-App
This folder contains the Flutter application code for the mobile interface. It includes:
- **lib/**: Contains the Dart code for the application, including different pages and design elements
- **assets/**: Contains images, fonts, and other assets.
- **pubspec.yaml**: The Flutter project configuration file.

## Getting Started

### Prerequisites
- ESP32 microcontroller
- ESP32-CAM module
- Flutter SDK

### Installation

#### ESP-code
1. Connect your ESP32 to your computer.
2. Open the `ESP-code` folder in your preferred IDE.
3. Upload the code to the ESP32.

#### ESP32-CAM
1. Connect your ESP32-CAM to your computer.
2. Open the `ESP32-CAM` folder in your preferred IDE.
3. Upload the code to the ESP32-CAM.

#### Flutter-App
1. Ensure you have Flutter installed on your machine.
2. Navigate to the `Flutter-App` folder.
3. Run `flutter pub get` to install dependencies.
4. Run `flutter run` to start the application.



<p align="center" width="100%">
    <img width="50%" src="https://github.com/user-attachments/assets/fa1f627c-d43d-4c13-b4be-d6534c7db633"> 
</p>


#### Hardware

![hardware bird's-eye view](https://github.com/user-attachments/assets/45133843-9c47-439b-9370-621ee368ae39)

Full info of the hardware can be found here : https://docs.google.com/spreadsheets/d/1V-DETGFDWvvLv6orIYwIOxZJeek2C7KR-pbLn5BZ86k/edit?gid=1780832805#gid=1780832805

#### Physical Prototype





https://github.com/user-attachments/assets/098d624c-f1ff-4162-a625-86a816eff95d




<p align="center" width="100%">
  

</p>





#### App Renders




<p align="center" width="100%">
    <img width="20%" src="https://github.com/user-attachments/assets/b476d8bb-5e93-4e1f-b033-183e5bca9c8c"> 
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <img width="20%" src="https://github.com/user-attachments/assets/4d5f1e10-bca5-4ea6-a8fe-b2a9a4a51782">
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <img width="20%" src="https://github.com/user-attachments/assets/6d13956f-6488-44c4-9491-67477b874d60">

</p>


<p align="center" width="100%">
    <img width="20%" src="https://github.com/user-attachments/assets/bb7443dd-0edb-4cff-9437-c0aabc4b6d9d">
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <img width="20%" src="https://github.com/user-attachments/assets/de626a0a-9c35-4b41-96e3-76e5d1946185">
</p>






[IOT poster- smart doorbell.pptx](https://github.com/user-attachments/files/16841304/IOT.poster-.smart.doorbell.pptx)




#### Notes for developers: 

* Esp-cam is limited to 5fps or sometimes more, depends on the connectivity and bandwith of the internet and the responsivness of the firebase. But this is good enough for security camera.
* We didnt find any software solutions or references for using the cam globally (rather than just typing http and local ip address), all the solutions suggested connected to an app or server for forwarding the video stream via ports and other router related setting, which wasn't relevant for our project.
* Some hardware solutions suggested modifynig the board to work with external antenna, and some also suggested connecting the GND pin to aluminum foil, (https://www.reddit.com/r/esp32/comments/r9g5jc/fixing_ymmv_the_poor_frame_rate_on_the_esp32cam/), but we didnt want to risk damaging the board.
* We ran into some problems with the storage in the ESP and scheduling the tasks, in the final_code.ino inside the esp-code folder you will find the code which eventually worked for us!
* In the video we show an early build of the app hence why the live camera feature is not working.
* The flutter app design matches the renders, except the temporary password page design got changed and we added an invalidate button for each passsword. Everything else is straight forward, firebase get and set are used to unlock the door, and to maintain the temporary passwords.
* In our app we update a field named time, this serves the time epoch for the esp, this served as a clock instead of Technion's NTP server which was down at the time we wanted to present our project.



