#Millipedes Exhibit using Arduino

#Overview
This project uses an Arduino controller to allow a visitor in the museum to press a button and begin an informative show regarding Millipedes. 

## Description
This system is built using an Arduino Mega and uses four simple enumerated states; 'IDLE', 'PHASE 1', 'PHASE 2' and "PHASE 3". IDLE state allows for a new person to enjoy the experience in the exhibit. It starts the beginning of a new cycle of presentation. Once a push button is pressed internally, the Arduino begins a three phase presentation that controls lights and audio. The module uses a DFPLAYER Mini module to produce audio. The design was intended to be automatic and require little to no effort on the users end. The design was intended to withstand many operations as it will be used by many people. 

## Getting Started

### Dependencies

*Before running the project, ensure the following is met:
  -- ARDUINO IDE
  -- ARDUINO BOARD
  -- DF ROBOT MINI MODULE
  -- SPEAKER MODULE (ample enough for loud sound)
  -- PUSH BUTTON
  -- LEDs
  -- WIRING LONG ENOUGH TO REACH ALL AROUND EXHIBIT
  -- MICROSD CARD loaded with AUDIO FILES FAT 32 format. 
  -- WINDOWS / MAC OS UP TO DATE


##Key Components

Arduino Controller
The Arduino acts as the central controller for the exhibit. It manages state transitions, timing, button input, LED behavior, and communication with the audio module.

State Machine
The state machine defines the exhibit’s overall behavior. It ensures that the sequence always follows the same structure and prevents invalid transitions during operation.

Button Input
The button is the visitor’s only direct interaction with the system. It starts the presentation only when the system is in the idle state.

LED Outputs
The LEDs provide both visitor guidance and exhibit effects:

* Green LED indicates the exhibit is available
* Exterior Red LED indicates the presentation is active
* Interior Red LED is used during the early presentation phase
* UV LED is used during the fluorescence viewing phase

DFPlayer Mini Audio Module
The DFPlayer Mini handles playback of the audio tracks used during the exhibit. If it is not detected at startup, the system continues running the lighting sequence without audio.

### Installing

* Download this repo
* Open Arduino IDE
* Install "DFROBOTDFPLAYERMINI" library for audio
* Insert AUDIO files that must be formated FAT 32
* Wire compontents per given instructions.
* Connect to computer via USB

### Executing program
 Open project in IDE
 SElect the correct board
 Verify the code
 Upload the code
 Power the system 
 Look for visiual confirmation of light indicators on board
 Press the button to start sequence
 View debug messages
```

Design Notes
A few important things to know before editing the code----

* This version was built for one exhibit controller
* Only one presentation is meant to run at a time
* If the button is pressed again during an active presentation, nothing happens
* The current audio setup requires a board that supports Serial1
* The phase timings are hardcoded in the sketch right now




## Help

DF player not detected:
Check DF wiring is secure. Often times the issue.
Make sure SD card is inserted and files are formatted correctly (FAT32)

NO AUDIO PLAYS:
Check speaker connection
Check your board supports serial 1

BUTTON DOES NOT TRIGGER:
Check button wiring
Check INPUT_PULLUP logic is correct. PINS MUST MATCH!

LIGHTS ON, NO AUDIO:
If the DFplayer doesn't initialize it will not play audio. Check log to ensure DF player is detected. 
command to run if program contains helper info
```

## Authors

Valentino Cavaricci 
CONCORDIA UNIVERSITY IRVINE 



## License

This project is licensed under the [NAME HERE] License - see the LICENSE.md file for details
