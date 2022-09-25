<p align="center">
<img width="220" height="220" src="https://i.imgur.com/vYE79I9.png">
</p>

[![Build Status](https://travis-ci.com/guanicoe/ESPBug_PIO.svg?branch=master)](https://travis-ci.com/guanicoe/ESPBug_PIO)


# Restructure of the initial project [https://github.com/willmendil/ESPBug](https://github.com/willmendil/ESPBug) to use plateformIO
The idea is to make the development easier.

# ESPBug

ESPBug is a rogue captive portal program which runs on the ESP8266 dev board, such as the NodeMCU (clones included). It is a social engennering tool which generates a WiFi network of a given name alluring people to connect  to it and enter some credential.

# DISCLAIMER
The source code given in this public repo is for educational use only. Stealing credential might be illegal depending on where you live. I am not liable for any actions on your behalf. This code is given with no warranties and liabilities. **Just be responsible OK?**

# Some updates about the project

Life being as it is, I was not able to work on this project at all for the last 8 months, and maybe won't be able to for the next few. The project is not dead though, I am just unable to work on it now. Some issues have been submitted regarding the language.h library not being detected. I cannot say with certainty why that is, but if I remember it's just a question of checking your path. I hope to be able to come back to this project as soon as possible, thanks for your understanding.

# Demonstration & How tos

[![Pocket board for phishing passwords - ESPBUG](https://i.imgur.com/PYyQzfI.jpg)](https://www.youtube.com/watch?v=X95rtPqSzw4 "Pocket board for phishing passwords - ESPBUG - Click to Watch!")


Here are a few screenshots from my phone showing off the web interface, and what each settings do. The fist image is an example of a captive portal seen by the victim. **Would you enter you password?**

![Imgur0](https://i.imgur.com/FRVuEwBl.jpg)
![Imgur1](https://i.imgur.com/qYyqwnQl.jpg)

When you connect to the ESPBug, go to any domain name and to the **espportal** page (e.g. `http://espbug.com/espportal`)
You should be shown a pop up window asking you for the password. Defaults are `Username: espbug` and `Password: password`.
From there you are redirected to the home page.

![Imgur2](https://i.imgur.com/NgNZkYol.jpg)
![Imgur3](https://i.imgur.com/OgYxvRyl.jpg)


You want to go to the settings to prepare the hook. Let's go through all the settings to understand what they do.

![Imgur4](https://i.imgur.com/lxz6Apwl.jpg)
![Imgur5](https://i.imgur.com/LeBXPztl.jpg)

 - Hat colour (choices: **Black Hat** or **White Hat**): This gives you the object to be an arse or a crap arse. Basically the **White Hat** option redirects the victim to a webpage telling them what just happened and how to protect themselves against phishing attacks. The **Black Hat** immediately disconnects after the victim entered their credentials.
 - Enable portal (choices: **ON** or **OFF**): Basically enables the phishing portal.
 - SSID: Set up the SSID of the device. By default it is **espbug**. When a phishing attack occured, it defaults back to this name so you can connect and see the logs. You can name it what you want to lure victims.
 - Password: This is the WiFi's password. By default it is **password**, however, you want this blank when you are carrying an attack so victims can connect to the WiFi. Again, when an attack as succesfully happened, the password defaults back to **password**.
 **You can change these defalts in the source code - might add the option to change that in the settings if you ask for it.**
 - Channel (choices: **1** to **14**): This is the WiFi channel on the 2.4GHz so from 1 to 14.
 - Hidden (choices: **YES** or **NO**): **This is important!**  By default, the WiFi is hidden, that means to connect to the **espbug** you must manually enter the **ssid** and **password**. When an attack occured, the WiFi is hidden again, so you should connect to the device automatically with the same station. However, during an attack you want the WiFi to be visible, so set this to **NO**.
 - IP: This is the IP of the **espbug**. By default you can leave the `192.168.1.1`. However during an attack you might want to switch to `8.8.8.8`. This enables the victim's device to automatically show the sign up screen when they connect to the WiFi.
 - GateWay: Same as IP, keep these values the same.
 - Subnet: Do not change if you don't know what you're doing.
 - Username: Default is **espbug**. Put what you want. This is the username to enter when you connect to the webpage. To access the settings etc...
 - Password: Default is **password**. As the Username. Put what you want here.

 - FTP: **STILL UNDER DEV.**, commented out for the moment


# Installation

To get information on the installation you can either try to figure it out by yourself. I use atom and plateformIO. or you can look at the old version which you can compile using the arduino IDE. [https://github.com/willmendil/ESPBug](https://github.com/willmendil/ESPBug). There is also a binary available in `/bin` that you should be able to simply upload on the board using the arduino IDE.




# CREDITS where credit is due

Most of the code is strongly inspired by different repo from github, I just wanted to mention them here.
* [ESPortalV2] - https://github.com/exploitagency/ESPortalV2
* [github-ESPortal] - https://github.com/exploitagency/github-ESPortal
* [esp8266_deauther] - https://github.com/spacehuhn/esp8266_deauther
* and maybe more which I'll add if I remember



### Todos

 - Have FTP Working
 - Make more captive portal HTML pages

### Known bugs
- In white Hat mode, the explanation page is closed automatically when using `8.8.8.8`. Don't know yet how this can be fixed
- There might be an issue with the IPs showing from the connected devices, they are all identical and sometimes erroneous.

License
----

  GNU GENERAL PUBLIC LICENSE


**Free Software, Hell Yeah!**


   [ESPortalV2]: <https://github.com/exploitagency/ESPortalV2>
   [github-ESPortal]: <https://github.com/exploitagency/github-ESPortal>
   [esp8266_deauther]: <https://github.com/spacehuhn/esp8266_deauther>
   [esp8266]: https://rcl.lt/files/c59c2f4d86f239f67a86-128x128
   [Arduino IDE]: https://www.arduino.cc/en/main/software
