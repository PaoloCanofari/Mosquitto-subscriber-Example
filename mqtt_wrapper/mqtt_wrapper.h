//
// Created by Paolo Canofari on 01/09/19.
//

#ifndef MOSQUITTO_SUBSCRIBER_MQTT_WRAPPER_H
#define MOSQUITTO_SUBSCRIBER_MQTT_WRAPPER_H

#include <mosquittopp.h>
#include <iostream>

class mqtt_wrapper {

private:
    const char *id ;
    const char *host;
    int port;
    const char *username;
    const char *password;
    int keepalive;
    const char *topic;

    struct mosquitto *client;

public:
    mqtt_wrapper(const char* _id, const char* _topic, const char* _host, int _port, const char* _username, const char* _password);
    static void on_connected(struct mosquitto *client, void *userdata, int result);
    static void on_disconnected(struct mosquitto *client, void *userdata, int result);
    static void on_subscribed(struct mosquitto *client, void *userdata, int mid, int qos_count, const int *granted_qos);
    static void on_messageReceived(struct mosquitto *client, void *userdata, const struct mosquitto_message *message);

    mosquitto *getClient();
    const char* getTopic();

};


#endif //MOSQUITTO_SUBSCRIBER_MQTT_WRAPPER_H
