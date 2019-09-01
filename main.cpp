//
// Created by Paolo Canofari on 01/09/19.
//

#include <iostream>
#include "mqtt_wrapper/mqtt_wrapper.h"

int main(int argc, const char* argv[]) {
    
    const char *id = "device01";
    const char *topic = "/sensors/test";
    const char* host = "localhost";
    int port = 1883;
    const char* username = "username";
    const char* password = "password";

    mqtt_wrapper *wrapper = new mqtt_wrapper(id, topic, host, port, username, password);
    return 0;
}