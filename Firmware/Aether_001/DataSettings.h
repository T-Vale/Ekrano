const byte INITPARAMSIZE = 27;
const byte DATAINPUTBODYSIZE = 79;
const byte DATAOUTPUTSIZE = 46;
const byte PHONEMESSAGESIZE = 80;
const byte DATAINPUTSIZE = DATAINPUTBODYSIZE + PHONEMESSAGESIZE + 2;

char dataInput_[DATAINPUTSIZE];
char initParam_[INITPARAMSIZE];
char dataOutput_[DATAOUTPUTSIZE];

int analogValues_[6];
int adcThreshold_[6][2] = {{0,1023},{0,1023},{0,1023},{0,1023},{0,1023},{0,1023}};

boolean actuationState_[12] = {false,false,false,false,false,false,false,false,false,false,false,false};
boolean actuationPinoutState_[7] = {false,false,false,false,false,false,false}; //2,3,5,6,7,8,9
int adcActValue_[6][3] = {{0,1023,10},{0,1023,10},{0,1023,10},{0,1023,10},{0,1023,10},{0,1023,10}};
byte adcActPinout_[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //A0m,A0M,A1m,A1M,A2m,A2M,A3m,A3M,A4m,A4M,A5m,A5M 

byte errorCode_[6] = {0, 0, 0, 0, 0, 0};

boolean commFailed = false;
boolean firstConnection = true;
boolean serverConnecting = false;

long ldatalines = 0;

int fails = 0;
int rails = 0;
