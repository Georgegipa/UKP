#include "settings.h"
#ifdef HID_ENABLED
#include "Consumer2.h"

Consumer2_ Consumer;

static const uint8_t _hidMultiReportDescriptorConsumer[] PROGMEM = {
	/* Consumer Control (Sound/Media keys) */
	0x05, 0x0C,									/* usage page (consumer device) */
	0x09, 0x01, 								/* usage -- consumer control */
	0xA1, 0x01, 								/* collection (application) */
	0x85, HID_REPORTID_CONSUMERCONTROL, 		/* report id */
	/* 4 Media Keys */
	0x15, 0x00, 								/* logical minimum */
	0x26, 0xFF, 0x03, 							/* logical maximum (3ff) */
	0x19, 0x00, 								/* usage minimum (0) */
	0x2A, 0xFF, 0x03, 							/* usage maximum (3ff) */
	0x95, 0x04, 								/* report count (4) */
	0x75, 0x10, 								/* report size (16) */
	0x81, 0x00, 								/* input */
	0xC0 /* end collection */
};

Consumer2_::Consumer2_(void) 
{
	static HIDSubDescriptor node(_hidMultiReportDescriptorConsumer, sizeof(_hidMultiReportDescriptorConsumer));
	HID().AppendDescriptor(&node);
}


void Consumer2_::SendReport(void* data, int length)
{
	HID().SendReport(HID_REPORTID_CONSUMERCONTROL, data, length);
}

#endif