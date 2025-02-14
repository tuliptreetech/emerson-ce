# Community Edition
This is a set of project files for running the Community Edition of Emerson.
> This repo should be used as a reference and discussion platform. A cloned repo will not run on its own without the complete source code and license found on our website.

## Get your license
 Go to our [website](https://tuliptreetech.com) and click the `Download` button in the top right corner. Fill out the form and an email will give you the complete source code and key to install the Emerson docker image. After you install `lantern.tar` you can extract it using the command below

 ```
 tar xvf lantern.tar
 ```

## Install the necessary files
Navigate into `/Emerson-CE/Emerson-CE` and run the install script! It will prompt you for your license key.
```
./install
```

This will install some scripts, the license key, and our Arduino IDE plugin.

## Load a sketch into Emerson
In the ArduinoIDE, first, compile and export your sketch. From the file menu, select `Sketch` and then, `Export Compiled Binary`  (`Ctrl-Alt-S`).

Then, bring up the command pallette (`Ctrl-Shift-P`) and select `Emerson: Load Sketch`. This will start the emerson server and start a session runninng your application.

## Interact with your sketch
In your favorite web-browser, navigate to http://localhost:10314. This will bring up the Emerson Projects page. Selecting the active session at the top will attach to the already running emulation environment.

## Reload your sketch
If you make modifications to your sketch, you can reload them into Emerson. First, compile and export your sketch. Then in the command pallette select `Emerson: Reload Sketch`. This will stop the existing session, and create a new session. In your web-browser, merely refresh the page and you will see the new version of your application installed.

## Stop the Emerson server
When you are ready to be done with the emerson server, select `Emerson: Stop Server` from the command pallette.
> The Emerson server will not stop automatically when you exit the Arduino IDE. The only way to stop it is to run the stop server command, or use a docker command to stop the container.

## Notes:
* If you want to change the sketch you are interacting with, merely navigate to that sketch in the Arduino IDE, compile and export, and select `Emerson: Load Sketch` in the command pallette.
* If you close the Emerson terminal window, that's ok. The server will continue to run, but you cannot bring back the output from the terminal. You'll need to select `Emerson: Load Sketch` from the command pallette to restart the server.
