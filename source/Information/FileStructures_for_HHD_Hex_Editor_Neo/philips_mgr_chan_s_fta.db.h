#include <stddefs.h>

struct SHeader
{
  uint32 blockId;
  uint32 blockSize;
  uint16 u1;
  uint16 u2;
  uint32 numTvChannels;
  uint32 numRadioChannels;
  uint32 u3;
  uint32 channelBlockId;
  uint32 channelBlockSize;
};

struct SChannel
{
	uint32 curProgNr;
	uint32 u1;
	uint8 u2[8];
	uint32 favNr;
	union
	{
		char chName1[200];
#pragma byte_order (BigEndian)
		big_endian wchar_t chName2[100];
#pragma byte_order ()
		struct 
		{
			uint8 zero;
			wchar_t chName3[99];
			uint8 zero2;
		} chName4;
	} chName;
	uint16 u3;
	uint8 u3b[208];
	uint8 u3c[2];
	uint16 u3d;	
	uint8 u4[10];
	uint16 freqInMhz1;
	uint16 u5;
	uint16 u6;
	uint16 symRate;
	uint32 curProgNr2;
	uint32 prevProgNr;
	uint16 tsid;
	uint16 u7;
	uint16 sid;
	uint16 onid;
	uint16 freqInMhz2;
	uint16 u9;
	uint32 u10;
};

struct SFooter
{
	uint32 numDataBlocks;
	uint32 numDataBlockBytes;
	uint16 bytesumFrom0;
	uint16 u_zero;
};

#pragma script("get_doc_size.js")

public struct Philips_mgr_chan_s_fta
{
    var docSize = GetDocumentSize();

    char filename[32];
	
	SHeader header;

	var recordCount = header.channelBlockSize / sizeof(SChannel);
    SChannel channels[recordCount];
	
	SFooter footer;	
};