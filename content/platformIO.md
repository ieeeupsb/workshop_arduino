# Getting started with PlatformIO
All information in this topic can be skiped if you are already proficient in PlatformIO.

# What is PlatformIO
PlatformIO is an extension of the popular coding IDE **Visual Studio Code**. The must known is ArduinoIDE but we want to be big boys and also be able to use our favorite IDE so we will go with PlatformIO.
With this extension you can upload code to your favorite microcontroller and manage your projects.

# How to create a project
To create a project, go to the PIO Home and select Create a Project. Then find the board you want to use and voilá. They have weird names most of the times so search online for what you should use ;). Buuuut, int the case of esp8266 you can select the on in the example:

![new_project](https://user-images.githubusercontent.com/71400611/219143727-b4eaa4e5-31fa-4b3a-b12f-6c713c3f411e.png)
![board_selection](https://user-images.githubusercontent.com/71400611/219143749-9f1b3561-49c2-4b6f-b5e3-d80a18e5d2a2.png)

# Workspace explained
So this is what a PIO workspace looks like.

![image](https://user-images.githubusercontent.com/71400611/219141806-0fbd50fb-e138-4091-a9f2-7ef6e4368daa.png)
## src
Source is where you will find the main program you will write. 
You have **setup()** that is where you reun your code that you only want to run once.
You also have **loop()** where you run the code that you want to execute to infinityyyyy, or until you run out of battery.

Arduino is the most know and go to microcontroller library. You can use it with 99% of microcontroller boards that you will come by.

## lib
Lib is where you put your libraries. Usually it is for sensors or some repetitive thing that you don't want in your main program. Good to keep the code cleaner and easy to debug.
You basically create a library like you would in c our c++, but in your main, you can call your libraries with **<>**.

## platformio.ini
Here you have the board and framework configuration. You can easily change this if you want to change your board. 
If you are using external libraries, the program will call 📲 them in here.

![image](https://user-images.githubusercontent.com/71400611/219142260-9a9f2b9d-0837-4a54-a888-b53170b8977e.png)

# Flash the code
Flashing the code to the board is the act of sending the compiled code to the microcontroller. Only need to click on the arrow!

![image](https://user-images.githubusercontent.com/71400611/219146008-ad9dde5c-9f52-44cd-8ae7-49c16275d692.png)

![image](https://user-images.githubusercontent.com/71400611/219146034-fa0a6678-f7b7-4b9f-8702-0b552a0c7af1.png)


# Libraries
Last topic is Libraries. With Arduino.h you already have a lot of tools, but there are open-source libraries that will remove you lots of headaches if you just use them! There are some ways to do this, but I will give an example through PIO:

![image](https://user-images.githubusercontent.com/71400611/219142786-e34bc3eb-5751-4de8-b3e1-8dca56e1db3c.png)

Just click install and the magic happens!



[Main Menu](../README.md) | [Next](./basicElectronics.md)
