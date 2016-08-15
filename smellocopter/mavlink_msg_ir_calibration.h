// MESSAGE IR_CALIBRATION PACKING

#define MAVLINK_MSG_ID_IR_CALIBRATION 58

typedef struct __mavlink_ir_calibration_t
{
 uint64_t timestamp; /*< */
 float data; /*<  Variable for exchanging sensor samples or estimator coefficients between GCS and FMU.*/
 uint8_t data_code; /*<  Code from IR_CAL_CODE_ENUM that puts the data into context.*/
} mavlink_ir_calibration_t;

#define MAVLINK_MSG_ID_IR_CALIBRATION_LEN 13
#define MAVLINK_MSG_ID_58_LEN 13

#define MAVLINK_MSG_ID_IR_CALIBRATION_CRC 157
#define MAVLINK_MSG_ID_58_CRC 157



#define MAVLINK_MESSAGE_INFO_IR_CALIBRATION { \
	"IR_CALIBRATION", \
	3, \
	{  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ir_calibration_t, timestamp) }, \
         { "data", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_ir_calibration_t, data) }, \
         { "data_code", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_ir_calibration_t, data_code) }, \
         } \
}


/**
 * @brief Pack a ir_calibration message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param data_code  Code from IR_CAL_CODE_ENUM that puts the data into context.
 * @param data  Variable for exchanging sensor samples or estimator coefficients between GCS and FMU.
 * @param timestamp 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ir_calibration_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t data_code, float data, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_IR_CALIBRATION_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, data);
	_mav_put_uint8_t(buf, 12, data_code);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IR_CALIBRATION_LEN);
#else
	mavlink_ir_calibration_t packet;
	packet.timestamp = timestamp;
	packet.data = data;
	packet.data_code = data_code;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IR_CALIBRATION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_IR_CALIBRATION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_IR_CALIBRATION_LEN, MAVLINK_MSG_ID_IR_CALIBRATION_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_IR_CALIBRATION_LEN);
#endif
}

/**
 * @brief Pack a ir_calibration message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param data_code  Code from IR_CAL_CODE_ENUM that puts the data into context.
 * @param data  Variable for exchanging sensor samples or estimator coefficients between GCS and FMU.
 * @param timestamp 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ir_calibration_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t data_code,float data,uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_IR_CALIBRATION_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, data);
	_mav_put_uint8_t(buf, 12, data_code);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IR_CALIBRATION_LEN);
#else
	mavlink_ir_calibration_t packet;
	packet.timestamp = timestamp;
	packet.data = data;
	packet.data_code = data_code;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IR_CALIBRATION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_IR_CALIBRATION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_IR_CALIBRATION_LEN, MAVLINK_MSG_ID_IR_CALIBRATION_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_IR_CALIBRATION_LEN);
#endif
}

/**
 * @brief Encode a ir_calibration struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ir_calibration C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ir_calibration_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ir_calibration_t* ir_calibration)
{
	return mavlink_msg_ir_calibration_pack(system_id, component_id, msg, ir_calibration->data_code, ir_calibration->data, ir_calibration->timestamp);
}

/**
 * @brief Encode a ir_calibration struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ir_calibration C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ir_calibration_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ir_calibration_t* ir_calibration)
{
	return mavlink_msg_ir_calibration_pack_chan(system_id, component_id, chan, msg, ir_calibration->data_code, ir_calibration->data, ir_calibration->timestamp);
}

/**
 * @brief Send a ir_calibration message
 * @param chan MAVLink channel to send the message
 *
 * @param data_code  Code from IR_CAL_CODE_ENUM that puts the data into context.
 * @param data  Variable for exchanging sensor samples or estimator coefficients between GCS and FMU.
 * @param timestamp 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ir_calibration_send(mavlink_channel_t chan, uint8_t data_code, float data, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_IR_CALIBRATION_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, data);
	_mav_put_uint8_t(buf, 12, data_code);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IR_CALIBRATION, buf, MAVLINK_MSG_ID_IR_CALIBRATION_LEN, MAVLINK_MSG_ID_IR_CALIBRATION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IR_CALIBRATION, buf, MAVLINK_MSG_ID_IR_CALIBRATION_LEN);
#endif
#else
	mavlink_ir_calibration_t packet;
	packet.timestamp = timestamp;
	packet.data = data;
	packet.data_code = data_code;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IR_CALIBRATION, (const char *)&packet, MAVLINK_MSG_ID_IR_CALIBRATION_LEN, MAVLINK_MSG_ID_IR_CALIBRATION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IR_CALIBRATION, (const char *)&packet, MAVLINK_MSG_ID_IR_CALIBRATION_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_IR_CALIBRATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ir_calibration_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t data_code, float data, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, data);
	_mav_put_uint8_t(buf, 12, data_code);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IR_CALIBRATION, buf, MAVLINK_MSG_ID_IR_CALIBRATION_LEN, MAVLINK_MSG_ID_IR_CALIBRATION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IR_CALIBRATION, buf, MAVLINK_MSG_ID_IR_CALIBRATION_LEN);
#endif
#else
	mavlink_ir_calibration_t *packet = (mavlink_ir_calibration_t *)msgbuf;
	packet->timestamp = timestamp;
	packet->data = data;
	packet->data_code = data_code;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IR_CALIBRATION, (const char *)packet, MAVLINK_MSG_ID_IR_CALIBRATION_LEN, MAVLINK_MSG_ID_IR_CALIBRATION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IR_CALIBRATION, (const char *)packet, MAVLINK_MSG_ID_IR_CALIBRATION_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE IR_CALIBRATION UNPACKING


/**
 * @brief Get field data_code from ir_calibration message
 *
 * @return  Code from IR_CAL_CODE_ENUM that puts the data into context.
 */
static inline uint8_t mavlink_msg_ir_calibration_get_data_code(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field data from ir_calibration message
 *
 * @return  Variable for exchanging sensor samples or estimator coefficients between GCS and FMU.
 */
static inline float mavlink_msg_ir_calibration_get_data(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field timestamp from ir_calibration message
 *
 * @return 
 */
static inline uint64_t mavlink_msg_ir_calibration_get_timestamp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Decode a ir_calibration message into a struct
 *
 * @param msg The message to decode
 * @param ir_calibration C-struct to decode the message contents into
 */
static inline void mavlink_msg_ir_calibration_decode(const mavlink_message_t* msg, mavlink_ir_calibration_t* ir_calibration)
{
#if MAVLINK_NEED_BYTE_SWAP
	ir_calibration->timestamp = mavlink_msg_ir_calibration_get_timestamp(msg);
	ir_calibration->data = mavlink_msg_ir_calibration_get_data(msg);
	ir_calibration->data_code = mavlink_msg_ir_calibration_get_data_code(msg);
#else
	memcpy(ir_calibration, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_IR_CALIBRATION_LEN);
#endif
}
