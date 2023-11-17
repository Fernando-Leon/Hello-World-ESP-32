#include <WiFi.h>

const char* ssid = "your-name-red";
const char* password = "your-password";

WiFiServer server(80); // Port 

void setup() {
  Serial.begin(115200);
  delay(100);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conecting to WiFi...");
  }
  
  Serial.println("Ip addres: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    String html = "<html><body><h1>Hello World!</h1></body></html>";

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    client.println(html);
  }
}
