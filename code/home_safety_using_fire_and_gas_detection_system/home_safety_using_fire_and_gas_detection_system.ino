// #include <Arduino.h>

// #define MQ2 0
// #define Flame PB12
// #define Buzzer PB9
// #define Fan PB8
// #define built PC13

// const String PHONE = "+918766689590"; // Replace with your recipient's phone number

// void setup()
// {
//     // Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
//     Serial.begin(9600);

//     // Begin serial communication with Arduino and A9 GSM
//     Serial2.begin(115200);

//     pinMode(MQ2, INPUT);
//     pinMode(Flame, INPUT_PULLUP);
//     pinMode(Buzzer, OUTPUT);
//     pinMode(Fan, OUTPUT);
//     pinMode(built, OUTPUT);

//     Serial.println("Initializing...");

//     // Initialize A9 GSM
//     sendATCommand("AT");
//     sendATCommand("ATE1");
//     sendATCommand("AT+CMGF=1");
//     sendATCommand("AT+CNMI=1,2,0,0,0");
//     sendATCommand("AT+COPS=?");
//     sendATCommand("AT+COPS?");
//     sendATCommand("AT+CREG");
// }

// void loop()
// {
//     int gas = analogRead(MQ2);
//     int flame = digitalRead(Flame);

//     Serial.println("Gas Value: " + String(gas));
//     Serial.println("Flame Status: " + String(flame == LOW ? "Detected" : "Not Detected"));

//     if (flame == LOW || gas > 350)
//     {
//         sendSMS();
//         digitalWrite(Buzzer, HIGH);
//         digitalWrite(Fan, HIGH);
//         digitalWrite(built, LOW);
//         delay(5000);
//     }
//     else
//     {
//         digitalWrite(Buzzer, LOW);
//         digitalWrite(Fan, LOW);
//         digitalWrite(built, HIGH);
//         delay(5000);
//     }
// }

// void sendSMS()
// {
//     Serial2.println("AT+CMGS=\"" + PHONE + "\"\r");
//     delay(100);
//     Serial2.println("ALERT!\nThis is an emergency in your home.\nGas leakage or Flame detected?");
//     Serial2.write(0x1A);
//     delay(100);
// }

// void sendATCommand(String cmd)
// {
//     Serial2.println(cmd);
//     delay(100);
//     while (Serial2.available())
//     {
//         Serial.write(Serial2.read());
//     }
// }

#include <Arduino.h>

#define MQ2 0
#define Flame PB12
#define Buzzer PB9
#define Fan PB8
#define built PC13

const String PHONE = "+91xxxxxxxxxx"; // Replace with your recipient's phone number

void setup()
{
    // Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
    Serial.begin(9600);

    // Begin serial communication with Arduino and A9 GSM
    Serial2.begin(115200);

    pinMode(MQ2, INPUT);
    pinMode(Flame, INPUT_PULLUP);
    pinMode(Buzzer, OUTPUT);
    pinMode(Fan, OUTPUT);
    pinMode(built, OUTPUT);

    Serial.println("Initializing...");

    // Initialize A9 GSM
    sendATCommand("AT");
    sendATCommand("ATE1");
    sendATCommand("AT+CMGF=1");
    sendATCommand("AT+CNMI=1,2,0,0,0");
    sendATCommand("AT+COPS=?");
    sendATCommand("AT+COPS?");
    sendATCommand("AT+CREG");
}

void loop()
{
    int gas = analogRead(MQ2);
    int flame = digitalRead(Flame);

    Serial.println("Gas Value: " + String(gas));
    Serial.println("Flame Status: " + String(flame == LOW ? "Detected" : "Not Detected"));

    if (flame == LOW || gas > 250)
    {
        sendSMS();
        digitalWrite(Buzzer, HIGH);
        digitalWrite(Fan, HIGH);
        digitalWrite(built, LOW);
        Serial.println("SMS is Sending ");
        delay(5000);
    }
    else
    {
        digitalWrite(Buzzer, LOW);
        digitalWrite(Fan, LOW);
        digitalWrite(built, HIGH);
        delay(5000);
    }
}

void sendSMS()
{
    Serial2.println("AT+CMGS=\"" + PHONE + "\"\r");
    delay(100);
    Serial2.println("ALERT! \nThis is an emergency in your home.\nGas leakage or Flame detected");
    Serial2.write(0x1A);
    delay(100);
}

void sendATCommand(String cmd)
{
    Serial2.println(cmd);
    delay(100);
    while (Serial2.available())
    {
        Serial.write(Serial2.read());
    }
}
