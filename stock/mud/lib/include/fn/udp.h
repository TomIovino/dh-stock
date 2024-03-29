/* --- User Configuration. --- */
#ifndef INETD
#define INETD		"/secure/inet/inetd"
#endif

#ifndef UDP_CMD_DIR
#define UDP_CMD_DIR	"/secure/inet/udp/"
#endif

#define LOCAL_NAME "crimsonesti"
#define HOST_FILE	"/secure/inet/INETD_HOSTS"
#define INETD_LOG_FILE	"INETD"

#define REPLY_TIME_OUT	12
#define RETRIES		2


#define LOCAL_UDP_PORT	query_imp_port()

#define INETD_DIAGNOSTICS

/* --- End of config. --- */

#define INETD_VERSION	"0.61"

/* --- Standard header macros. --- */

#define RECIPIENT	"RCPNT"
#define REQUEST		"REQ"
#define SENDER		"SND"
/* The DATA field should be used to store the main body of any packet. */
#define DATA		"DATA"

/* These headers are reserved for system use only. */
#define HOST		"HST"
#define ID		"ID"
#define NAME		"NAME"
#define PACKET		"PKT"
#define UDP_PORT	"UDP"
#define SYSTEM		"SYS"

/* Reserved headers for diagnostics. */
#define PACKET_LOSS	"PKT_LOSS"
#define RESPONSE_TIME	"TIME"

/* --- Standard REQUEST macros. --- */

#define PING		"ping"
#define QUERY		"query"
#define REPLY		"reply"

/* --- Standard SYSTEM macros. --- */
#define TIME_OUT	"TO"

/* --- Index macros for host arrays. --- */

#define HOST_NAME	0
#define HOST_IP		1
#define HOST_UDP_PORT	2
#define LOCAL_COMMANDS	3
#define HOST_COMMANDS	4
#define HOST_STATUS	5

