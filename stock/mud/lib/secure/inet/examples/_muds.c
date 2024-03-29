#include <defs.h>
#include <udp.h>

inherit "/sys/format";
inherit "/sys/stdlib";

int cmd_muds() {
    mapping hosts;
    int i;
    mixed muds;
    
    muds = lalign("Mudname", 20) + "  Status   Last access";
    write(muds + "\n" + BAR[0..strlen(muds)] + "\n");
    muds = a_sort(m_indices(hosts = INETD->query("hosts")));
    for(i = 0; i < sizeof(muds); i++) {
	write(lalign(hosts[muds[i]][HOST_NAME], 20) + "  " +
	(hosts[muds[i]][HOST_STATUS] ?
	    hosts[muds[i]][HOST_STATUS] > 0 ?
		"UP       " + ctime(hosts[muds[i]][HOST_STATUS])[4..15] :
		"DOWN     " + ctime(-hosts[muds[i]][HOST_STATUS])[4..15]
	    : "UNKNOWN  Never accessed.") +
	"\n");
    }
    return 1;
}

                          