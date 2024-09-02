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