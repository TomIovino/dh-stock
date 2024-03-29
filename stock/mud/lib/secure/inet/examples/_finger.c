#include <levels.h>
#include <paths.h>
#include <udp.h>

/* Character info. */

string		title;
string		al_title;
string		class;
int		age;
int		gender;
int		level;
int		last_on;

/* Mail info. */

string		*messages;

string get_finger_string(string str) {
    int i;
    object ob;
    string ret;

    if (!str)
	return "Finger who?\n";
    title = al_title = class = 0;
    age = gender = level = last_on = 0;
    messages = 0;
    str = lower_case(str);
    if (!restore_object("players/" + str[0..0] + "/" + str))
	return "No such player.\n";
    ret = capitalize(str);
    if (title && title != "")
	ret += " " + title;
    if (level < GOD)
	ret += " (" + al_title + ")";
    ret += " [" +
    (gender ? (gender == 1 ? "male" : "female") : "neuter") + "]";
    ret += "\n";
    if (level < DEMIGOD)
	ret += "Player ";
    else
	ret += capitalize(class) + " ";
    if ((ob = find_player(str)) && (level < GOD || !ob->query_invis())) {
	ret += "currently logged on.";
	if (!interactive(ob))
	    ret += " (linkdead)\n";
	else
	    ret += "\n";
	age = (int)ob->query_age();
    }
    else
	ret += "last logged on at " + ctime(last_on) + "\n";
    ret += "Age: ";
    if (age / 43200) {
	ret += " " + age / 43200 + " days";
	age %= 43200;
    }
    if (age / 1800) {
	ret += " " + age / 1800 + " hours";
	age %= 1800;
    }
    if (age / 30) {
	ret += " " + age / 30 + " minutes";
	age %= 30;
    }
    if (age)
	ret += " " + age * 2 + " seconds";
    ret += ".\n";
    if (ob && interactive(ob) && (i = query_idle(ob)) >= 60)
	ret += "Idle for " + (i / 60) + " minute(s).\n";
    if (!restore_object(POST_DIR + str) || !pointerp(messages))
	ret += "No mail.\n";
    else {
	string flag;
	for(i = 0, flag = " "; i < sizeof(messages); i += 5) {
	    if (messages[i] == "N") {
		flag = " new ";
		break;
	    }
	    if (messages[i] == "U")
		flag = " unread ";
	}
	ret += "There is" + flag + "mail.\n";
    }
    return ret;
}

int cmd_finger(string arg) {
    string who, mud;

    if (arg && sscanf(arg, "%s@%s", who, mud) == 2) {
	if (arg = INETD->send_udp(mud, ([
	    REQUEST: "finger",
	    SENDER: this_player()->query_real_name(),
	    DATA: who
	]), 1))
	    write(arg);
	else
	    write("Request transmitted.\n");
    }
    else
	write(get_finger_string(arg));
    return 1;
}
                                                                                                         