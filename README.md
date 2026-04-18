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
