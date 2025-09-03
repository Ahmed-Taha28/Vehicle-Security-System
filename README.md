## Brief of the Project Function

• The project involves the installation of a door and a light in the salon. 

• Door with Alarm. 

• Door controlled by remote control. 

• Door Control for Children.

• Door and Gaz beadle. 

## The system features four primary security mechanisms

-Door-Operated Salon Lighting: Four rocker switches control both individual door status LEDs and the main salon light, with an LCD display indicating which specific door has been opened.

-Bluetooth-Enabled Remote Control: Bluetooth-Enabled Remote Control: A HC-06 Bluetooth module enables wireless door operation through a dedicated mobile application.

-Child Safety Lock: A DPDT switch prevents all door openings when engaged, with salon LED illumination indicating unauthorized access attempts.

-RFID-Based Security: Implements RFID technology to detect unauthorized access attempts, triggering both local buzzer alarms and remote Node-RED notifications.

-Gas Pedal Safety Interlock: Prevents vehicle operation when doors are open, activating audible warnings and remote alerts.

## Project component

1-  Arduino Mega. 

2-  RFID (RC522). 

3-  Bluetooth Module (HC-06). 

4-  DPDT Push Button. 

5-  4 Rocker Switches. 

6-  I2C LCD (16x2). 

7-  8 LEDS. 

8-  Buzzer. 

9-  Push Button. 

10 - 14 Resistors 220 ohm. 

## Circuit Diagram

![image](https://github.com/Ahmed-Taha28/Vehicle-Security-System/blob/main/Images/Circuit_Diagram.jpg)

## Flow Chart

![image]([https://via.placeholder.com/800x400?text=Main+Interface](https://github.com/Ahmed-Taha28/Vehicle-Security-System/blob/main/Images/Flow_%20Chart.jpg))

## Detailed Project Functionality

### The system operates exclusively through two authentication methods: 

A. Unlocking the vehicle using the Bluetooth remote control (HC-06).

B. Unlocking the vehicle using an authorized RFID card.

-The LCD display will show "Scan Your Card" when awaiting authentication.

-Successful unlocking activates the green LED indicator.

-Engaging the lock system activates the red LED indicator.

### Security and Monitoring Features:

Unauthorized access attempts with invalid RFID cards trigger email notifications.

Opening any door activates both salon and car LEDs, with the LCD specifying which door was opened.

Engaging the child safety switch illuminates the blue LED and disables all door mechanisms until deactivated.

Pressing the gas pedal while any door is open triggers the audible buzzer alarm.

## Node Red Coding and Process Diagram

![image](https://github.com/Ahmed-Taha28/Vehicle-Security-System/blob/main/Images/Node_Red_Code.jpg)


![image](https://github.com/Ahmed-Taha28/Vehicle-Security-System/blob/main/Images/Process_Diagram.jpg)
