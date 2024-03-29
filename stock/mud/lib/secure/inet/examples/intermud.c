/*
 * This command is actioned as:
 * add_action("intermud_channel_msg", "intermud", 1);
 */

#define CHANNEL		"channel"
#define COMMAND		"cmd"

static intermud_channel_msg(msg) {
    string channel, cmd;
    mapping data, hosts;
    string *muds;
    int i;

    if (!msg)
	return;
    channel = query_verb();
    switch(channel[strlen(channel)-1]) {
	case ':':
	    cmd = "emote";
	    channel = channel[0..strlen(channel)-2];
	    break;
	case '?':
	    cmd = "list";
	    channel = channel[0..strlen(channel)-2];
	    break;
	default:
	    cmd = 0;
	    break;
    }
    data = ([
	REQUEST: "channel",
	SENDER: name,
	CHANNEL: channel,
	DATA: msg
    ]);
    if (cmd)
	data[COMMAND] = cmd;
    for(i = sizeof(muds = m_indices(hosts = INETD->query("hosts"))); i--; ) {
	/* Don't send it to ourselves and check that the receiver
	 * recognizes "channel" requests. Normally this checking is done
	 * by the inetd, but we don't want it throwing out
	 * 'invalid command' messages for muds that don't use channels
	 * every time we send an intermud message. */
	if (muds[i] != lower_case(LOCAL_NAME) &&
	(member_array("*", hosts[muds[i]][HOST_COMMANDS]) != -1 ||
	member_array("channel", hosts[muds[i]][HOST_COMMANDS]) != -1))
	    INETD->send_udp(muds[i], data);
    }
    call_other(UDP_CMD_DIR + "channel", "udp_channel", data);
}
                                                   