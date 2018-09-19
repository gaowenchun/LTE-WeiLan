#include<iostream>
#include<cstring>
#include<vector>

class Cell_Reboot{
public:
	Cell_Reboot(char* str1,char* str2){
		strcpy(Reboot,str1);
		strcat(Reboot,str2);
	}
private:
	char Reboot[10];
};

//*************** weilan 主动上报消息 ***************************
class Msg_Common{
private:
public:
	char  startflag[4];
	char* getmsgtype(){return startflag;}

};

class responsehead:public Msg_Common
{
private:
public:
	responsehead(char* wstart);
	~responsehead(){}
};

class Msg_Imsi : public Msg_Common{
public:

	char  msgname[14];
	char  length[4];
	char  railname[24];
	char  cardid[13];
	char  ID[15];
	char  time[17];
	char  taType[15];
	char  rsrp[11];
	char  ulCqi[12];
	char  ulRssi[13];
	char  imsi[22];
	char  imei[22];
	Msg_Imsi(){};
	void bufferparse(char* getbuffer);
};


class ErrorIndi : public Msg_Common
{
private:

	char  msgname[10];
	char  length[3];
	char  railname[24];
	char  cardid[13];
	char  Info[37];

public:
	ErrorIndi(){};
	void bufferparse(char* getbuffer);

};

class SnifferRsltIndi:public Msg_Common
{
private:
	char  msgname[17];
public:
	SnifferRsltIndi(){};
	void bufparse(char* getbuffer);
};

class Msg_Heart:public Msg_Common
{
public:
	char  msgname[10];
	char  length[4];
	char  railname[24];
	char  cardid[13];
	char  time[17];
	char  version[27];
	char  build_date[23];
	char  tmp[9];
	char  gps[8];
	char  status[27];
	Msg_Heart(){};
	void bufferparse(char* getbuffer);
};








