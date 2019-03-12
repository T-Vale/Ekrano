byte macAddress_[6] = {0, 0, 0, 0, 0, 0};

byte ipAddress_ [4]= {0, 0, 0, 0};
byte maskAddress_[4] = {0, 0, 0, 0};
byte gatewayAddress_[4] = {0, 0, 0, 0};
byte dnsAddress_[4] = {0, 0, 0, 0};

byte dataserverAddress_[4] = {0, 0, 0, 0};
int dataserverPort = 0;

EthernetServer serverServer(80);
EthernetClient serverClient;
