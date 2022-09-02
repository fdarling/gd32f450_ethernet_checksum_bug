#include <stdio.h> // for fprintf()
#include <stdlib.h> //
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

#define USE_THOUSANDS_SEPARATORS

#ifdef USE_THOUSANDS_SEPARATORS
#include <locale.h>
#endif // USE_THOUSANDS_SEPARATORS

#include <sys/socket.h> // for send(), recv(), and setsockopt()
#include <netinet/in.h> // for IPPROTO_UDP
#include <arpa/inet.h> // for inet_aton()

static const char UDP_SERVER_IP[] = "10.42.0.70";
static const uint16_t UDP_SERVER_PORT = 1025;
static const int MAX_PACKETS = 1000000; // million

int main(int argc, char **argv)
{
#ifdef USE_THOUSANDS_SEPARATORS
    // to get thousands separators working
    setlocale(LC_NUMERIC, "");
#endif // USE_THOUSANDS_SEPARATORS

    // print a message for the start of the program
    printf("info: creating UDP socket for communicating with device at: %s:%" PRIu16 "\n", UDP_SERVER_IP, UDP_SERVER_PORT);

    // create the UDP socket
    const int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0)
    {
        fprintf(stderr, "ERROR: failed to create UDP socket!\n");
        return EXIT_FAILURE;
    }

    // set the timeout to 50mS
    static const struct timeval timeout = {0, 50000}; // NOTE: for WinSock2 this must be milliseconds as a DWORD not a struct with seconds/microseconds
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) != 0)
    {
        fprintf(stderr, "WARNING: failed to set socket read timeout\n");
    }

    // fill the target IP address/port struct
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(UDP_SERVER_PORT);
    if (!inet_aton(UDP_SERVER_IP, &addr.sin_addr))
    {
        fprintf(stderr, "ERROR: failed to parse IP address!: \"%s\"\n", UDP_SERVER_IP);
        return EXIT_FAILURE;
    }

    // connect (really just binding for UDP)
    if (connect(sock, (const struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        fprintf(stderr, "ERROR: failed to connect to UDP server at IP address/port: \"%s:%" PRIu16 "\"\n", UDP_SERVER_IP, UDP_SERVER_PORT);
        return EXIT_FAILURE;
    }

    // set up buffers
    uint32_t request;
    uint32_t reply;

    // for tracking the distance between lost packets
    int last_lost_index = 0;

    // print a message for the start of the test
    printf("info: starting to send %'d packets...\n", MAX_PACKETS);

    // loop sending packets and waiting for responses
    for (int i = 0; i < MAX_PACKETS; i++)
    {
        // show the progress
        if (i % 10000 == 0 && i)
            printf("info: sent %'d packets...\n", i);

        // generate a sequential payload
        request = htonl(i);

        // send the packet
        const int sent_size = send(sock, &request, sizeof(request), 0);

        // make sure it sent the entire packet (no errors, no truncation)
        if (sent_size != sizeof(request))
        {
            fprintf(stderr, "ERROR: failed to send outgoing UDP packet!\n");
            return EXIT_FAILURE;
        }

        // receive reply
        const int reply_size = recv(sock, &reply, sizeof(reply), 0);

        // check to see if there was an error
        if (reply_size == -1)
        {
            const int delta = i - last_lost_index;
            last_lost_index = i;
            fprintf(stderr, "WARNING: no response to packet # %d (delta = %i); payload = 0x%08" PRIx32 " / 0x%08" PRIx32 "\n", i, delta, request, i);
            // return EXIT_FAILURE;
        }
        // make sure the reply is the expected size
        else if (reply_size != sizeof(reply))
        {
            fprintf(stderr, "ERROR: unexpected response size of %d\n", reply_size);
            return EXIT_FAILURE;
        }
        // make sure it has the expected contents
        else if (memcmp(&reply, &request, sizeof(reply)) != 0)
        {
            fprintf(stderr, "ERROR: data received did not match the data sent! sent 0x%08" PRIx32 " but received 0x%08" PRIx32 "\n", request, reply);
            return EXIT_FAILURE;
        }
    }

    // success!
    printf("info: finished successfully!\n");
    return EXIT_SUCCESS;
}
