# CEmbeddedCampGL

This repo contains home projects of Networking Essentials course.

Networking_hw#1 contains: 
1. dhcpd.conf                              // configuration file for dhcp-service
2. starterkit.pcapng                       // wireshark capture file of dhcp-packets
3. wired_settings.png, wired_settings1.png // ubuntu wired interface settings' screenshot
4. ping.png, wireshark_capture.pmg         // additional screenshots of ping and wireshark program usage, respectively  
5. starterkit.mp4                          // 10s overview of the LCD display


Subnet mask calculation task has been done via next algorithm:
1. Determine the number of avaliable hosts in network - $n = 2$ 
2. Calculate the quontity of bits $b(2) = 1$ needed to represets given number n
3. Calculate netmask prefix: $prx = 32 - b = 32 - 1 = 31$
4. Evaluate network mask:    $2^{8 * \lceil{b/_8}\rceil} - 2^b = 2^{8 *\lceil{1/8}\rceil} - 2^1 = 2^8 - 2^1 = 256 - 2 = 254$
   Network mask is represented as a continuous sequence of ones indicating the subnet address 
   and a continuous sequence of zeros indicating the number of hosts in the network. 
                                  $${255.255.255.254}$$
                                  $$11111111.11111111.11111111.11111110$$
