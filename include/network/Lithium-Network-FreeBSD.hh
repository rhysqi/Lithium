#ifndef LITHIUM_NETWORK_FREEBSD_HH
#define LITHIUM_NETWORK_FREEBSD_HH

namespace Lithium_Network {
    typedef struct {
        unsigned int uPort;
        void *pNet_Buffer;
    } Sock_Desc_t, *pSock_Desc_t;

}

#endif /* LITHIUM_NETWORK_FREEBSD_HH */