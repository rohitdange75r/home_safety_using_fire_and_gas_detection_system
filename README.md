🔥 Home Safety System using Fire & Gas Detection (STM32 + GSM)

This project is designed to detect fire and gas leakages in a home environment and provide instant alerts to ensure safety. It is built around the STM32F103C8T6 development board with supporting sensors and modules.

🛠️ Components Used

1. STM32F103C8T6 Development Board
2. MQ2 Gas Sensor
3. Flame Sensor
4. A9G GSM Module
6. 5V Buzzer
7. 5V Fan
8. KA7805 Voltage Regulator
9. PCB Board
10. 9V Adapter

⚙️ How It Works

1. The MQ2 gas sensor detects harmful gases (like LPG, smoke, CO). If leakage is found, the system immediately:
   * Sends an alert message via GSM module to the homeowner.
   * Activates the fan to remove the gas.
   * Automatically turns the fan off once the gas is cleared.

2. The Flame sensor detects fire. When triggered:
   * An alert message is sent to the homeowner.
   * The system can activate safety actions (fan, buzzer, etc.) to reduce danger.
   * The Buzzer is used to give a local alarm during gas leakage or fire detection.

🌐 Features

1. Real-time fire and gas leakage detection
2. Automatic fan activation for gas removal
3. Instant SMS alert to homeowner via GSM
4. Local alarm with buzzer
5. Simple and reliable home safety solution
