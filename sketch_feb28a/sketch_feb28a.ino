#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "zzzz";       // Replace with your Wi-Fi SSID
const char* password = "J8702143  "; // Replace with your Wi-Fi Password
const char* firmware_url = "http://t3bt.atwebpages.com/application.txt"; // Your hex file URL

WiFiClient client;  // Create a WiFiClient object

void setup() {
    Serial.begin(115200);  // Debug UART
    Serial1.begin(115200); // UART to STM32

    WiFi.begin(ssid, password);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to Wi-Fi");

    HTTPClient http;
    http.begin(client, firmware_url); // Use WiFiClient with URL
    
    int httpCode = http.GET(); // Send HTTP GET request

    if (httpCode == HTTP_CODE_OK) {
        WiFiClient *stream = http.getStreamPtr();
        Serial.println("Downloading firmware...");
        
        while (http.connected()) {
            char prev_char = 0;
            while (stream->available()) {
                char c = stream->read();
                Serial1.write(c);  // Send byte to STM32
                Serial.write(c);   // Debug output

                delay(5);  // Delay between bytes
                
                // Read STM32 response if available (non-blocking)
                if (Serial1.available()) {
                    String response = Serial1.readStringUntil('\n');
                    response.trim();
                    Serial.print("STM32 Response: ");
                    Serial.println(response);
                }

                // If the previous character was '\n', wait 15ms before sending the next line
                if (prev_char == '\n') {
                    delay(15);
                }
                prev_char = c;
            }
        }

        Serial.println("\nFirmware sent to STM32.");
    } else {
        Serial.println("Failed to download firmware.");
    }

    http.end();
}

void loop() {
    // No need for loop here, everything is handled in setup()
}
