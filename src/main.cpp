#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid     = "EvilCorp";
const char *password = "helloworld";

ESP8266WebServer server(80);

void handleRoot() {
	server.send(200, "text/html",
		"<!DOCTYPE html>\n"
		"<html>\n"
		"\t<head>\n"
		"\t\t<title>Home | Smart city controller</title>\n"
		"\n"
		"\t\t<link rel='stylesheet prefetch' href='https://cdnjs.cloudflare.com/ajax/libs/meyer-reset/2.0/reset.min.css'>\n"
		"\t\t<style>\n"
		"\t\t\t@import url(https://fonts.googleapis.com/css?family=Open+Sans:400,300,700);\n"
		"\t\t\tbody {\n"
		"\t\t\t\tfont-family: 'Open Sans', sans-serif;\n"
		"\t\t\t\tfont-weight: 300;\n"
		"\t\t\t\tbackground: #54bded;\n"
		"\t\t\t\tcolor: #fff;\n"
		"\t\t\t\tpadding-top: 20px;\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\tform {\n"
		"\t\t\t\twidth: 80%;\n"
		"\t\t\t\tmargin: 0 auto;\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\th1 {\n"
		"\t\t\t\tfont-size: 30px;\n"
		"\t\t\t\tline-height: 3;\n"
		"\t\t\t\ttext-align: center;\n"
		"\t\t\t\tfont-weight: 700;\n"
		"\t\t\t\tline-height: 1;\n"
		"\t\t\t\tmargin-bottom: 30px;\n"
		"\t\t\t}\n"
		"\t\t\th1 span {\n"
		"\t\t\t\tmargin-top: 10px;\n"
		"\t\t\t\tdisplay: block;\n"
		"\t\t\t\tfont-weight: 300;\n"
		"\t\t\t\tfont-size: 70%;\n"
		"\t\t\t\tline-height: 1.2;\n"
		"\t\t\t}\n"
		"\t\t\th2 {\n"
		"\t\t\t\tline-height: 3;\n"
		"\t\t\t\ttext-align: center;\n"
		"\t\t\t\tfont-weight: 700;\n"
		"\t\t\t\tline-height: 1;\n"
		"\t\t\t\tmargin-bottom: 30px;\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\tdiv.controls {\n"
		"\t\t\t\tmargin-bottom: 12px;\n"
		"\t\t\t\tborder: 1px dotted #fafafa;\n"
		"\t\t\t\tpadding: 25px 20px;\n"
		"\t\t\t\tposition: relative;\n"
		"\t\t\t\tmargin-bottom: 20px;\n"
		"\t\t\t}\n"
		"\t\t\tdiv.controls h1 {\n"
		"\t\t\t\tfont-size: 18px;\n"
		"\t\t\t\tfont-weight: 400;\n"
		"\t\t\t\tline-height: 1;\n"
		"\t\t\t\ttext-transform: uppercase;\n"
		"\t\t\t\tdisplay: inline-block;\n"
		"\t\t\t\tposition: absolute;\n"
		"\t\t\t\tleft: 10px;\n"
		"\t\t\t\ttop: -10px;\n"
		"\t\t\t\tpadding: 0 10px;\n"
		"\t\t\t\tcolor: #fafafa;\n"
		"\t\t\t\tbackground-color: #54bded;\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\tinput[type='radio'],\n"
		"\t\t\tinput[type='checkbox'] {\n"
		"\t\t\t\tdisplay: none;\n"
		"\t\t\t\tcursor: pointer;\n"
		"\t\t\t}\n"
		"\t\t\tinput[type='radio']:focus, input[type='radio']:active,\n"
		"\t\t\tinput[type='checkbox']:focus,\n"
		"\t\t\tinput[type='checkbox']:active {\n"
		"\t\t\t\toutline: none;\n"
		"\t\t\t}\n"
		"\t\t\tinput[type='radio'] + label,\n"
		"\t\t\tinput[type='checkbox'] + label {\n"
		"\t\t\t\tcursor: pointer;\n"
		"\t\t\t\tdisplay: inline-block;\n"
		"\t\t\t\tposition: relative;\n"
		"\t\t\t\tpadding-left: 25px;\n"
		"\t\t\t\tmargin-right: 10px;\n"
		"\t\t\t\tcolor: #0b4c6a;\n"
		"\t\t\t}\n"
		"\t\t\tinput[type='radio'] + label:before, input[type='radio'] + label:after,\n"
		"\t\t\tinput[type='checkbox'] + label:before,\n"
		"\t\t\tinput[type='checkbox'] + label:after {\n"
		"\t\t\t\tcontent: '';\n"
		"\t\t\t\tfont-family: helvetica;\n"
		"\t\t\t\tdisplay: inline-block;\n"
		"\t\t\t\twidth: 18px;\n"
		"\t\t\t\theight: 18px;\n"
		"\t\t\t\tleft: 0;\n"
		"\t\t\t\tbottom: 0;\n"
		"\t\t\t\ttext-align: center;\n"
		"\t\t\t\tposition: absolute;\n"
		"\t\t\t}\n"
		"\t\t\tinput[type='radio'] + label:before,\n"
		"\t\t\tinput[type='checkbox'] + label:before {\n"
		"\t\t\t\tbackground-color: #fafafa;\n"
		"\t\t\t\t-moz-transition: all 0.3s ease-in-out;\n"
		"\t\t\t\t-o-transition: all 0.3s ease-in-out;\n"
		"\t\t\t\t-webkit-transition: all 0.3s ease-in-out;\n"
		"\t\t\t\ttransition: all 0.3s ease-in-out;\n"
		"\t\t\t}\n"
		"\t\t\tinput[type='radio'] + label:after,\n"
		"\t\t\tinput[type='checkbox'] + label:after {\n"
		"\t\t\t\tcolor: #fff;\n"
		"\t\t\t}\n"
		"\t\t\tinput[type='radio']:checked + label:before,\n"
		"\t\t\tinput[type='checkbox']:checked + label:before {\n"
		"\t\t\t\t-moz-box-shadow: inset 0 0 0 10px #158EC6;\n"
		"\t\t\t\t-webkit-box-shadow: inset 0 0 0 10px #158EC6;\n"
		"\t\t\t\tbox-shadow: inset 0 0 0 10px #158EC6;\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\t/*Radio Specific styles*/\n"
		"\t\t\tinput[type='radio'] + label:before {\n"
		"\t\t\t\t-moz-border-radius: 50%;\n"
		"\t\t\t\t-webkit-border-radius: 50%;\n"
		"\t\t\t\tborder-radius: 50%;\n"
		"\t\t\t}\n"
		"\t\t\tinput[type='radio'] + label:hover:after, input[type='radio']:checked + label:after {\n"
		"\t\t\t\tcontent: '\\2022';\n"
		"\t\t\t\tposition: absolute;\n"
		"\t\t\t\ttop: 0px;\n"
		"\t\t\t\tfont-size: 19px;\n"
		"\t\t\t\tline-height: 15px;\n"
		"\t\t\t}\n"
		"\t\t\tinput[type='radio'] + label:hover:after {\n"
		"\t\t\t\tcolor: #c7c7c7;\n"
		"\t\t\t}\n"
		"\t\t\tinput[type='radio']:checked + label:after, input[type='radio']:checked + label:hover:after {\n"
		"\t\t\t\tcolor: #fff;\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\t/*Checkbox Specific styles*/\n"
		"\t\t\tinput[type='checkbox'] + label:before {\n"
		"\t\t\t\t-moz-border-radius: 3px;\n"
		"\t\t\t\t-webkit-border-radius: 3px;\n"
		"\t\t\t\tborder-radius: 3px;\n"
		"\t\t\t}\n"
		"\t\t\tinput[type='checkbox'] + label:hover:after, input[type='checkbox']:checked + label:after {\n"
		"\t\t\t\tcontent: \"\\2713\";\n"
		"\t\t\t\tline-height: 18px;\n"
		"\t\t\t\tfont-size: 14px;\n"
		"\t\t\t}\n"
		"\t\t\tinput[type='checkbox'] + label:hover:after {\n"
		"\t\t\t\tcolor: #c7c7c7;\n"
		"\t\t\t}\n"
		"\t\t\tinput[type='checkbox']:checked + label:after, input[type='checkbox']:checked + label:hover:after {\n"
		"\t\t\t\tcolor: #fff;\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\t/*Toggle Specific styles*/\n"
		"\t\t\tinput[type='checkbox'].toggle {\n"
		"\t\t\t\tdisplay: inline-block;\n"
		"\t\t\t\t-webkit-appearance: none;\n"
		"\t\t\t\t-moz-appearance: none;\n"
		"\t\t\t\tappearance: none;\n"
		"\t\t\t\twidth: 55px;\n"
		"\t\t\t\theight: 28px;\n"
		"\t\t\t\tbackground-color: #fafafa;\n"
		"\t\t\t\tposition: relative;\n"
		"\t\t\t\t-moz-border-radius: 30px;\n"
		"\t\t\t\t-webkit-border-radius: 30px;\n"
		"\t\t\t\tborder-radius: 30px;\n"
		"\t\t\t\t@inlcude box-shadow(none);\n"
		"\t\t\t\t-moz-transition: all 0.2s ease-in-out;\n"
		"\t\t\t\t-o-transition: all 0.2s ease-in-out;\n"
		"\t\t\t\t-webkit-transition: all 0.2s ease-in-out;\n"
		"\t\t\t\ttransition: all 0.2s ease-in-out;\n"
		"\t\t\t}\n"
		"\t\t\tinput[type='checkbox'].toggle:hover:after {\n"
		"\t\t\t\tbackground-color: #c7c7c7;\n"
		"\t\t\t}\n"
		"\t\t\tinput[type='checkbox'].toggle:after {\n"
		"\t\t\t\tcontent: '';\n"
		"\t\t\t\tdisplay: inline-block;\n"
		"\t\t\t\tposition: absolute;\n"
		"\t\t\t\twidth: 24px;\n"
		"\t\t\t\theight: 24px;\n"
		"\t\t\t\tbackground-color: #aeaeae;\n"
		"\t\t\t\ttop: 2px;\n"
		"\t\t\t\tleft: 2px;\n"
		"\t\t\t\t-moz-border-radius: 50%;\n"
		"\t\t\t\t-webkit-border-radius: 50%;\n"
		"\t\t\t\tborder-radius: 50%;\n"
		"\t\t\t\t-moz-transition: all 0.2s ease-in-out;\n"
		"\t\t\t\t-o-transition: all 0.2s ease-in-out;\n"
		"\t\t\t\t-webkit-transition: all 0.2s ease-in-out;\n"
		"\t\t\t\ttransition: all 0.2s ease-in-out;\n"
		"\t\t\t}\n"
		"\t\t\tinput[type='checkbox']:checked.toggle {\n"
		"\t\t\t\t-moz-box-shadow: inset 0 0 0 15px #158EC6;\n"
		"\t\t\t\t-webkit-box-shadow: inset 0 0 0 15px #158EC6;\n"
		"\t\t\t\tbox-shadow: inset 0 0 0 15px #158EC6;\n"
		"\t\t\t}\n"
		"\t\t\tinput[type='checkbox']:checked.toggle:after {\n"
		"\t\t\t\tleft: 29px;\n"
		"\t\t\t\tbackground-color: #fff;\n"
		"\t\t\t}\n"
		"\t\t</style>\n"
		"\t</head>\n"
		"\t<body>\n"
		"\t\t<form> \n"
		"\t\t\t<h1>Smart city controll system\n"
		"\t\t\t<span>IoT Based smart city control panel</span>\n"
		"\t\t\t</h1>\n"
		"\t\t\t\n"
		"\t\t\t<div class=\"controls\">\n"
		"\t\t\t\t<h1>Trafic Light</h1>\n"
		"\t\t\t\t<input id='red' type=\"radio\" name='r-group-1' onclick=\"traficRadioClick(this)\" />\n"
		"\t\t\t\t<label for=\"red\">Red</label>\n"
		"\t\t\t\t\n"
		"\t\t\t\t<input id='orange' type=\"radio\" name='r-group-1' onclick=\"traficRadioClick(this)\" />\n"
		"\t\t\t\t<label for=\"orange\">Orange</label>\n"
		"\n"
		"\t\t\t\t<input id='green' type=\"radio\" name='r-group-1' onclick=\"traficRadioClick(this)\" />\n"
		"\t\t\t\t<label for=\"green\">Green</label>\n"
		"\t\t\t</div>\n"
		"\t\t\t\t\n"
		"\t\t\t<div class=\"controls\">\n"
		"\t\t\t\t<h1>Street Lights</h1>\n"
		"\t\t\t\t<input class='toggle' type=\"checkbox\" name='check-3' onclick=\"lightControl(this)\" />\n"
		"\t\t\t</div>\t\t\t\n"
		"\n"
		"\t\t\t<div class=\"controls\">\n"
		"\t\t\t\t<h1>Drainage valve </h1>\n"
		"\t\t\t\t<input class='toggle' type=\"checkbox\" name='check-4' onclick=\"drainControl(this)\" />\n"
		"\t\t\t</div>\n"
		"\n"
		"\t\t\t<div class=\"controls\">\n"
		"\t\t\t\t<h1>Railway gate</h1>\n"
		"\t\t\t\t<input class='toggle' type=\"checkbox\" name='check-5' onclick=\"railwayControll(this)\"/>\n"
		"\t\t\t</div>\n"
		"\t\t</form>\n"
		"\n"
		"\t\t<h2 id=\"status\"> </h2>\n"
		"\t\t<script type=\"text/javascript\">\n"
		"\n"
		"\t\t\tfunction traficRadioClick(rb){\n"
		"\t\t\t\tthis.path = \"trafic/\"+rb.id;\n"
		"\n"
		"\t\t\t\tvar xhttp = new XMLHttpRequest();\n"
		"\t\t\t\tif (this.readyState == 4 && this.status == 200) {\n"
		"\t\t\t\t\tdocument.getElementById(\"status\").innerHTML =\n"
		"\t\t\t\t\tthis.responseText;\n"
		"\t\t\t\t}\n"
		"\t\t\t\txhttp.open(\"GET\", this.path, true);\n"
		"\t\t\t\txhttp.send();\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\tfunction lightControl(cb) {\n"
		"\t\t\t\tif(cb.checked) {\n"
		"\t\t\t\t\tthis.path = \"street_light/on\";\n"
		"\t\t\t\t}\n"
		"\t\t\t\telse {\n"
		"\t\t\t\t\tthis.path = \"street_light/off\";\n"
		"\t\t\t\t}\n"
		"\t\t\t\tlet xhttp = new XMLHttpRequest();\n"
		"\t\t\t\txhttp.open(\"GET\", this.path, true);\n"
		"\t\t\t\txhttp.send();\n"
		"\t\t\t}\t\t\t\n"
		"\n"
		"\t\t\tfunction drainControl(cb) {\n"
		"\t\t\t\tif(cb.checked) {\n"
		"\t\t\t\t\tthis.path = \"drinage/on\";\n"
		"\t\t\t\t}\n"
		"\t\t\t\telse {\n"
		"\t\t\t\t\tthis.path = \"drinage/off\";\n"
		"\t\t\t\t}\n"
		"\t\t\t\tlet xhttp = new XMLHttpRequest();\n"
		"\t\t\t\txhttp.open(\"GET\", this.path, true);\n"
		"\t\t\t\txhttp.send();\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\tfunction railwayControll(cb) {\n"
		"\t\t\t\tif(cb.checked) {\n"
		"\t\t\t\t\tthis.path = \"railway_gate/up\";\n"
		"\t\t\t\t}\n"
		"\t\t\t\telse {\n"
		"\t\t\t\t\tthis.path = \"railway_gate/down\";\n"
		"\t\t\t\t}\n"
		"\t\t\t\tlet xhttp = new XMLHttpRequest();\n"
		"\t\t\t\txhttp.open(\"GET\", this.path, true);\n"
		"\t\t\t\txhttp.send();\n"
		"\t\t\t}\n"
		"\n"
		"\n"
		"\t\t</script>\t\n"
		"\t</body>\n"
		"</html>"
	);
}

void handleTraficRed() {
	server.send(200, "text/html", "Trafic light set to red successfully");
}

void handleTraficOrange() {
	server.send(200, "text/html", "Trafic light set to orange successfully");
}

void handleTraficGreen() {
	server.send(200, "text/html", "Trafic light set to green successfully");
}

void handleLightOn() {
	server.send(200, "text/html", "street light turned on successfully");
}

void handleLightOff() {
	server.send(200, "text/html", "street light turned off successfully");
}

void handleDrainOn() {
	server.send(200, "text/html", "drainage turned on successfully");
}

void handleDrainOff() {
	server.send(200, "text/html", "drainage turned off successfully");
}

void handleRailwayUp() {
	server.send(200, "text/html", "railway gate opened successfully");
}

void handleRailwayDown() {
	server.send(200, "text/html", "railway gate closed successfully");
}

void setupWiFi(){
	Serial.print("\nConnecting to ");
	Serial.println(ssid);
	WiFi.begin(ssid, password);
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}
	Serial.println("");
	Serial.println("WiFi connected");
}

void setup() {

	Serial.begin(115200);
	delay(1000);

	//Serial.print("Configuring access point...");
	//WiFi.softAP(ssid);
	//WiFi.softAP(ssid, password);
	setupWiFi();
	IPAddress myIP = WiFi.localIP();
	Serial.println(myIP);

	server.on("/", handleRoot);
	server.on("/trafic/red", handleTraficRed);
	server.on("/trafic/orange", handleTraficOrange);
	server.on("/trafic/green", handleTraficGreen);
	server.on("/street_light/on", handleLightOn);
	server.on("/street_light/off", handleLightOff);
	server.on("/drinage/on", handleDrainOn);
	server.on("/drinage/on", handleDrainOff);
	server.on("/railway_gate/up", handleRailwayUp);
	server.on("/railway_gate/down", handleRailwayDown);

	server.begin();
	Serial.println("HTTP server started");

}

void loop() {
	server.handleClient();
}
