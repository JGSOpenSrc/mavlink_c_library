// MESSAGE EAG_RAW PACKING

#define MAVLINK_MSG_ID_EAG_RAW 57

typedef struct __mavlink_eag_raw_t
{
 uint64_t time_stamp; /*< */
 uint8_t raw_data; /*<  Raw integer output from EAG ADC */
} mavlink_eag_raw_t;

#define MAVLINK_MSG_ID_EAG_RAW_LEN 9
#define MAVLINK_MSG_ID_57_LEN 9

#define MAVLINK_MSG_ID_EAG_RAW_CRC 171
#define MAVLINK_MSG_ID_57_CRC 171



#define MAVLINK_MESSAGE_INFO_EAG_RAW { \
	"EAG_RAW", \
	2, \
	{  { "time_stamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_eag_raw_t, time_stamp) }, \
         { "raw_data", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_eag_raw_t, raw_data) }, \
         } \
}


/**
 * @brief Pack a eag_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param raw_data  Raw integer output from EAG ADC 
 * @param time_stamp 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_eag_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t raw_data, uint64_t time_stamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_EAG_RAW_LEN];
	_mav_put_uint64_t(buf, 0, time_stamp);
	_mav_put_uint8_t(buf, 8, raw_data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EAG_RAW_LEN);
#else
	mavlink_eag_raw_t packet;
	packet.time_stamp = time_stamp;
	packet.raw_data = raw_data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EAG_RAW_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_EAG_RAW;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EAG_RAW_LEN, MAVLINK_MSG_ID_EAG_RAW_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EAG_RAW_LEN);
#endif
}

/**
 * @brief Pack a eag_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param raw_data  Raw integer output from EAG ADC 
 * @param time_stamp 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_eag_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t raw_data,uint64_t time_stamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_EAG_RAW_LEN];
	_mav_put_uint64_t(buf, 0, time_stamp);
	_mav_put_uint8_t(buf, 8, raw_data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EAG_RAW_LEN);
#else
	mavlink_eag_raw_t packet;
	packet.time_stamp = time_stamp;
	packet.raw_data = raw_data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EAG_RAW_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_EAG_RAW;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EAG_RAW_LEN, MAVLINK_MSG_ID_EAG_RAW_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EAG_RAW_LEN);
#endif
}

/**
 * @brief Encode a eag_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param eag_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_eag_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_eag_raw_t* eag_raw)
{
	return mavlink_msg_eag_raw_pack(system_id, component_id, msg, eag_raw->raw_data, eag_raw->time_stamp);
}

/**
 * @brief Encode a eag_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param eag_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_eag_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_eag_raw_t* eag_raw)
{
	return mavlink_msg_eag_raw_pack_chan(system_id, component_id, chan, msg, eag_raw->raw_data, eag_raw->time_stamp);
}

/**
 * @brief Send a eag_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param raw_data  Raw integer output from EAG ADC 
 * @param time_stamp 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_eag_raw_send(mavlink_channel_t chan, uint8_t raw_data, uint64_t time_stamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_EAG_RAW_LEN];
	_mav_put_uint64_t(buf, 0, time_stamp);
	_mav_put_uint8_t(buf, 8, raw_data);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EAG_RAW, buf, MAVLINK_MSG_ID_EAG_RAW_LEN, MAVLINK_MSG_ID_EAG_RAW_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EAG_RAW, buf, MAVLINK_MSG_ID_EAG_RAW_LEN);
#endif
#else
	mavlink_eag_raw_t packet;
	packet.time_stamp = time_stamp;
	packet.raw_data = raw_data;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EAG_RAW, (const char *)&packet, MAVLINK_MSG_ID_EAG_RAW_LEN, MAVLINK_MSG_ID_EAG_RAW_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EAG_RAW, (const char *)&packet, MAVLINK_MSG_ID_EAG_RAW_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_EAG_RAW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_eag_raw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t raw_data, uint64_t time_stamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_stamp);
	_mav_put_uint8_t(buf, 8, raw_data);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EAG_RAW, buf, MAVLINK_MSG_ID_EAG_RAW_LEN, MAVLINK_MSG_ID_EAG_RAW_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EAG_RAW, buf, MAVLINK_MSG_ID_EAG_RAW_LEN);
#endif
#else
	mavlink_eag_raw_t *packet = (mavlink_eag_raw_t *)msgbuf;
	packet->time_stamp = time_stamp;
	packet->raw_data = raw_data;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EAG_RAW, (const char *)packet, MAVLINK_MSG_ID_EAG_RAW_LEN, MAVLINK_MSG_ID_EAG_RAW_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EAG_RAW, (const char *)packet, MAVLINK_MSG_ID_EAG_RAW_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE EAG_RAW UNPACKING


/**
 * @brief Get field raw_data from eag_raw message
 *
 * @return  Raw integer output from EAG ADC 
 */
static inline uint8_t mavlink_msg_eag_raw_get_raw_data(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field time_stamp from eag_raw message
 *
 * @return 
 */
static inline uint64_t mavlink_msg_eag_raw_get_time_stamp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Decode a eag_raw message into a struct
 *
 * @param msg The message to decode
 * @param eag_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_eag_raw_decode(const mavlink_message_t* msg, mavlink_eag_raw_t* eag_raw)
{
#if MAVLINK_NEED_BYTE_SWAP
	eag_raw->time_stamp = mavlink_msg_eag_raw_get_time_stamp(msg);
	eag_raw->raw_data = mavlink_msg_eag_raw_get_raw_data(msg);
#else
	memcpy(eag_raw, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_EAG_RAW_LEN);
#endif
}
