# Extreme Temperature Monitoring System  

## Project Overview  
This project aims to monitor and alert on extreme object temperatures using STM32 microcontrollers. The system integrates distance and temperature sensors to determine when an object is close enough for temperature measurement. If the temperature is normal, an LED lights up; if it’s extreme, the LED blinks at different rates based on the severity (fast for hot, slow for cold).  

## Task Breakdown  

### 1. **Distance Measurement**  
- **Task:** `task_measure_distance`  
  - Periodically reads data from the HC-SR04 sensor to measure distance and updates a shared variable.  

### 2. **Temperature Measurement**  
- **Task:** `task_measure_temperature`  
  - Reads temperature data from the LM35 sensor and updates a global variable.  

### 3. **Extreme Temperature Alert**  
- **Task:** `task_alarm`  
  - Reads shared distance and temperature data.  
  - Activates an LED alert (blinking) based on the temperature readings.  
  - Uses a queue to receive temperature measurement requests.  

### 4. **LED Control**  
- **Task:** `task_blink_led`  
  - Receives requests from `task_alarm` and controls the LED accordingly (e.g., frequency and duration).  

### 5. **Message Printing**  
- **Task:** `task_print_message`  
  - Retrieves messages from the queue (including timestamps) and prints them to the screen.  

### 6. **Optional: LCD Display**  
- **Task:** `task_LED_message`  
  - Displays additional messages on an LCD screen.  

---

## Synchronization and Communication  

### Queues  
- **Distance Queue:** `queueMeasuredDistances` - Stores distance measurements.  
- **Message Queue:** `queueMessages` - Stores messages for printing.  

### Mutex and Semaphores  
- **Temperature Mutex:** Protects the global temperature variable.  
- **Semaphores:** Signal the presence of new messages in the queue.  

---

## Error Handling (Optional)  
To enhance reliability, the system can include error recovery mechanisms:  
- **Retry Mechanism:** Reattempt failed code execution.  
- **Hardware Reinitialization:** Reset timers and peripherals in case of persistent errors.  
- **User Alerts:** Print error messages to notify users.  

---

## System Modules  

### 1. **Task Management Module**  
Handles task creation and lifecycle.  
- **Functions:**  
  - `create_tasks` - Initializes all tasks.  
  - `create_measure_distance_task` - Creates the distance measurement task.  

### 2. **Synchronization and Queue Module**  
Manages initialization and operations for queues and mutexes.  
- **Functions:**  
  - Queue/mutex management (add, lock, release).  

### 3. **Distance Sensor Module**  
Manages the HC-SR04 sensor.  
- **Functions:**  
  - `init_distance_sensor` - Initializes the distance sensor.  
  - `read_distance` - Measures and updates the distance value.  

### 4. **Temperature Sensor Module**  
Manages the LM35 temperature sensor.  
- **Functions:**  
  - `init_temperature_sensor` - Initializes the temperature sensor.  
  - `get_temperature` - Reads temperature values and updates the global variable.  

### 5. **Alarm Module**  
Manages alerts based on temperature data.  
- **Functions:**  
  - `init_alarm` - Initializes the LED system.  
  - `alarm_temperature` - Activates alerts based on temperature levels.  

### 6. **LED Module**  
Controls LED behavior.  
- **Functions:**  
  - `init_led` - Initializes the LED.  
  - `led_on` - Turns on the LED.  
  - `led_off` - Turns off the LED.  
  - `led_blink` - Controls blinking frequency.  

---

## Development Steps  

### DCT Configuration  
1. **Timer Configuration:**  
   - Configure timers for PWM and sensor measurements.  

2. **FreeRTOS Integration:**  
   - Integrate FreeRTOS for task scheduling.  

3. **PWM Setup:**  
   - Configure timers for PWM control of the LED.  
   - Assign GPIO pins for PWM.  

4. **ADC Configuration:**  
   - Set up ADC for LM35 temperature sensor.  

5. **Pin Assignments:**  
   - Assign GPIO pins for HC-SR04 sensor (Trigger and Echo).  

---

## Sensor Specifics  

### LM35 Temperature Sensor  
- **Functionality:** Converts temperature to voltage (10mV per °C).  
- **Connection:** Requires an ADC pin for reading.  
- **Formula:**  
  ```plaintext
  Temperature (°C) = ADC_Value * (Voltage_Supply / Analog_Range) / 10
  ```  

### HC-SR04 Distance Sensor  
- **Functionality:** Measures distance using ultrasonic waves.  
- **Formula:**  
  ```plaintext
  Distance (cm) = (T2 - T1) * 0.0343
  ```  
  Where `T1` and `T2` are timer values before and after the ultrasonic wave returns.  

---

## Implementation Guidelines  

### ADC Initialization (LM35)  
1. **Start Measurement:**  
   ```c
   HAL_ADC_Start(adc);
   ```  
2. **Wait for Conversion:**  
   ```c
   HAL_ADC_PollForConversion(adc, timeout);
   ```  
3. **Retrieve Value:**  
   ```c
   adc_value = HAL_ADC_GetValue(adc);
   ```  

### Timer for HC-SR04  
1. **Trigger Signal:** Activate the Trigger pin for 10 microseconds.  
2. **Capture Echo:** Use a timer to record start and end times of the ultrasonic wave.  
3. **Calculate Distance:** Apply the formula for distance based on timer values.  

This structured approach ensures modularity, synchronization, and accurate measurements in the real-time system.