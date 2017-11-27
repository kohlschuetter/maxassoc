#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <net/if.h>

// from linux/drivers/staging/brcm80211/include/wlioctl.h
/* Linux network driver ioctl encoding */
typedef struct wl_ioctl {
        uint cmd;               /* common ioctl definition */
        void *buf;              /* pointer to user buffer */
        uint len;               /* length of user buffer */
        uint8_t set;            /* get or set request (optional) */
        uint used;              /* bytes read or written (optional) */
        uint needed;            /* bytes needed (optional) */
} wl_ioctl_t;

int main(int argc, char** argv) {
    int skfd;
//    skfd = iw_sockets_open();
    skfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(skfd < 0) {
      perror("socket");
      return(-1);
    }
    
    char *name = "wlan0";
    fprintf(stdout, "Using interface %s\n", name);

    //int cmd = 1; // WLC_GET_VERSION
    int cmd = 263; // WLC_SET_VAR
    int value = 32; // maxassoc: number of maximum stations

    void *buf = calloc(1, 256);

    memcpy(buf, "maxassoc\0", 9);
    memcpy(buf+9, &value, 4);
    int len = 13;

    struct ifreq ifr;
    wl_ioctl_t ioc;
    
    ioc.cmd = cmd;
    ioc.buf = buf;
    ioc.len = len;
    strncpy(ifr.ifr_name, name, IFNAMSIZ);

    ifr.ifr_data = (void *) &ioc;
    int ret = ioctl(skfd, 0x89F0, &ifr);
    free(buf);
    
    if (ret) {
        fprintf(stderr, "Setting maxassoc failed with RC=%i\n", ret);
    } else {
        fprintf(stdout, "Setting maxassoc succeeded\n");
    }

    return ret;
}

void _start(int argc, char **argv) {
	exit (main (argc, argv));
}
