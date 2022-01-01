/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleCombo.h>

BleCombo BleCombo;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  BleCombo.begin();
}

void loop() {
  if(BleCombo.isConnected()) {
    Serial.println("Sending 'Hello world'...");
    BleCombo.print("Hello world");

    delay(1000);

    Serial.println("Sending Enter key...");
    BleCombo.write(KEY_RETURN);

    delay(1000);

    Serial.println("Sending Play/Pause media key...");
    BleCombo.write(KEY_MEDIA_PLAY_PAUSE);

    delay(1000);

    Serial.println("Sending Ctrl+Alt+Delete...");
    BleCombo.press(KEY_LEFT_CTRL);
    BleCombo.press(KEY_LEFT_ALT);
    BleCombo.press(KEY_DELETE);
    delay(100);
    BleCombo.releaseAll();
  }

  Serial.println("Waiting 5 seconds...");
  delay(5000);
}
