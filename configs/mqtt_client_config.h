/******************************************************************************
* File Name: mqtt_client_config.h
*
* Description: This file contains all the configuration macros used by the 
*              MQTT client in this example.
*
* Related Document: See README.md
*
*******************************************************************************
* (c) 2020-2021, Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* ("Software"), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries ("Cypress") and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software ("EULA").
*
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress's integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer of such
* system or application assumes all risk of such use and in doing so agrees to
* indemnify Cypress against all liability.
*******************************************************************************/

#ifndef MQTT_CLIENT_CONFIG_H_
#define MQTT_CLIENT_CONFIG_H_

#define JAN
// #define ENRICO

#include "iot_mqtt.h"

/*******************************************************************************
* Macros
********************************************************************************/

/**
 * MQTT Broker/Server address used for the MQTT connection. This is the AWS
 * endpoint associated to the thing
 */
#ifdef ENRICO
#define MQTT_BROKER_ADDRESS               "URL"
#else
#ifdef JAN
#define MQTT_BROKER_ADDRESS               "URL"
#endif
#endif

/**
 * MQTT Broker/Server port used for the MQTT connection.
 */
#define MQTT_PORT                         8883

/**
 * Set this macro to 1 if the MQTT Broker being used is hosted by AWS IoT
 * Core service, else 0.
 */
#define AWS_IOT_MQTT_MODE                 ( 1 )

/**
 * Set this macro to 1 if a secure (TLS) connection to the MQTT Broker is
 * required to be established, else 0.
 */
#define MQTT_SECURE_CONNECTION            ( 1 )



/* Set the QoS that is associated with the MQTT publish, and subscribe messages.
 * Valid choices are 0, and 1. The MQTT library currently does not support 
 * QoS 2, and hence should not be used in this macro.
 */
#define MQTT_MESSAGES_QOS                 ( 1 )

/* Configure the user credentials to be sent as part of MQTT CONNECT packet */
#define MQTT_USERNAME                     "User"
#define MQTT_PASSWORD                     ""

/* The timeout in milliseconds for MQTT operations in this example. */
#define MQTT_TIMEOUT_MS                   ( 5000 )

/* The keep-alive interval in seconds used for MQTT ping request. */
#define MQTT_KEEP_ALIVE_SECONDS           ( 60 )

/* A unique client identifier to be used for every MQTT connection. */
#define MQTT_CLIENT_IDENTIFIER            "psoc6-mqtt-nanodrone2"

/* Every active MQTT connection must have a unique client identifier. If you 
 * are using the above 'MQTT_CLIENT_IDENTIFIER' as client ID for multiple MQTT 
 * connections simultaneously, set this macro to 1. The device will then
 * generate a unique client identifier by appending a timestamp to the 
 * 'MQTT_CLIENT_IDENTIFIER' string. Example: 'psoc6-mqtt-client5927'
 */
#define GENERATE_UNIQUE_CLIENT_ID         ( 1 )

/* The longest client identifier that an MQTT server must accept (as defined
 * by the MQTT 3.1.1 spec) is 23 characters. Add 1 to include the length of the
 * NULL terminator.
 */
#define MQTT_CLIENT_IDENTIFIER_MAX_LEN    ( 24 )


/* As per Internet Assigned Numbers Authority (IANA) the port numbers assigned 
 * for MQTT protocol are 1883 for non-secure connections and 8883 for secure
 * connections. In some cases there is a need to use other ports for MQTT like
 * port 443 (which is reserved for HTTPS). Application Layer Protocol 
 * Negotiation (ALPN) is an extension to TLS that allows many protocols to be 
 * used over a secure connection. The ALPN ProtocolNameList specifies the 
 * protocols that the client would like to use to communicate over TLS.
 * 
 * This macro specifies the ALPN Protocol Name to be used that is supported
 * by the MQTT broker in use.
 * Note: For AWS IoT, currently "x-amzn-mqtt-ca" is the only supported ALPN 
 *       ProtocolName and it is only supported on port 443.
 */
#define MQTT_ALPN_PROTOCOL_NAME           "x-amzn-mqtt-ca"



#ifdef ENRICO

/* Configure the below credentials in case of a secure MQTT connection. */
/* PEM-encoded client certificate */
#define CLIENT_CERTIFICATE      \
"-----BEGIN CERTIFICATE-----\n" \

"\n-----END CERTIFICATE-----"

/* PEM-encoded client private key */
#define CLIENT_PRIVATE_KEY          \
"-----BEGIN RSA PRIVATE KEY-----\n" \
"\n-----END RSA PRIVATE KEY-----"

#else
#ifdef JAN

/* Configure the below credentials in case of a secure MQTT connection. */
/* PEM-encoded client certificate */
#define CLIENT_CERTIFICATE      \
"-----BEGIN CERTIFICATE-----\n"\
"-----END CERTIFICATE-----\n"

/* PEM-encoded client private key */
#define CLIENT_PRIVATE_KEY          \
"-----BEGIN RSA PRIVATE KEY-----\n"\
"-----END RSA PRIVATE KEY-----\n"

#endif
#endif


/* PEM-encoded Root CA certificate */
#define ROOT_CA_CERTIFICATE     \
"-----BEGIN CERTIFICATE-----\n" \
"\n-----END CERTIFICATE-----"

/******************************************************************************
* Global Variables
*******************************************************************************/
extern IotMqttNetworkInfo_t networkInfo;
extern IotMqttConnectInfo_t connectionInfo;

#endif /* MQTT_CLIENT_CONFIG_H_ */
