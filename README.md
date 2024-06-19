# Temperature Sensor


## Project Overview
This project monitors extreme temperatures of objects using sensors. When a proximity sensor detects an object, it measures its temperature. If the temperature is within normal limits, an LED lights up. If the temperature is extreme (hot or cold), the LED blinks accordingly.

## Tasks Description
1. **Distance Measurement**
   - Periodically reads data from HC-SR04 sensor for distance measurement.

2. **Temperature Measurement**
   - Reads temperature data from LM35 sensor.

3. **Temperature Alarm**
   - Activates LED alarm based on measured temperature extremes.

4. **Control LED**
   - Controls LED based on temperature alarm status.

5. **Print Messages**
   - Prints messages to screen related to system operations.

6. **Optional: LCD Display**
   - Displays additional messages on an LCD screen.

## Synchronization and Communication
### Queues
- `queueMeasuredDistances`: Stores distance measurements.
- `queueMessages`: Stores messages for printing.

### Mutex/Semaphore
- **Temperature Mutex:** Protects temperature variable.
- **Semaphores:** Signal new messages in the queue.

## Modules
- **Task Management Module:** Handles task creation and management.
- **Sensor Modules:**
  - **Distance Sensor:** Manages HC-SR04 sensor operations.
  - **Temperature Sensor:** Manages LM35 sensor operations.
- **Alarm Module:** Controls LED based on temperature readings.
- **LED Module:** Handles LED control functions.

## DCT Settings
1. **Timer Configuration:** Setup timers as per project requirements.
2. **FreeRTOS Integration:** Integrate FreeRTOS for task scheduling.
3. **ADC Configuration:** Configure ADC for LM35 temperature sensor.
4. **Pin Configuration:** Setup GPIO pins for HC-SR04 sensor.

## LM35 Temperature Sensor
- Connects physically to ADC for temperature reading.
- Conversion formula provided in project details.

## HC-SR04 Distance Sensor
- Uses ultrasonic waves to measure distance.
- Calculation formula provided for distance measurement.
