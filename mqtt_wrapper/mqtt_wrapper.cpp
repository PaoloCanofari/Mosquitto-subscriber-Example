//
// Created by Paolo Canofari on 01/09/19.
//

#include "mqtt_wrapper.h"

mqtt_wrapper::mqtt_wrapper(const char *_id, const char *_topic, const char *_host, int _port, const char *_username,
                           const char *_password) {

    std::cout<<"Connecting"<<std::endl;

    this->id = _id;
    this->topic = _topic;
    this->host = _host;
    this->port = _port;
    this->username = _username;
    this->password = _password;
    this->keepalive = 20;

    mosquitto_lib_init();
    mosquitto_lib_cleanup();

    client = mosquitto_new(id, true, NULL);

    mosquitto_username_pw_set(client, username, password);
    mosquitto_connect_callback_set(client, on_connected);
    mosquitto_disconnect_callback_set(client, on_disconnected);
    mosquitto_subscribe_callback_set(client, on_subscribed);
    mosquitto_message_callback_set(client, on_messageReceived);


    mosquitto_connect_async(client, host, port, keepalive);
    mosquitto_loop_forever(client, -1, 1);


}

void mqtt_wrapper::on_connected(mosquitto *client, void *userdata, int result){

    if(result == 0){
        std::cout << "Connected to broker successfully" << std::endl;

        mosquitto_subscribe(client, NULL, "/test/device_one", 2);
    } else {
        std::cout << "Couldn't connect to broker. \nERROR CODE: " << result << std::endl;
        exit(1);
    }

}

void mqtt_wrapper::on_subscribed(struct mosquitto *client, void *userdata, int mid, int qos_count,
                                 const int *granted_qos) {
    int i;

    std::cout<<"Subscribed (" << mid << "): " << granted_qos[0];

    for(i=1; i<qos_count; i++){
        std::cout<<", " << granted_qos[i];
    }
    std::cout << std::endl;
}

void mqtt_wrapper::on_disconnected(struct mosquitto *client, void *userdata, int result){

    std::cout << "Disconnected from broker." << std::endl;

}

void mqtt_wrapper::on_messageReceived(struct mosquitto *client, void *userdata, const struct mosquitto_message *message) {

    if(message->payloadlen){
        std::cout<<message->topic << " " << (char*)message->payload;

    }else{
        std::cout << message->topic;
    }

    std::cout << std::endl;
}


const char* mqtt_wrapper::getTopic() {
    return this->topic;
}

mosquitto* mqtt_wrapper::getClient() {
    return this->client;
}