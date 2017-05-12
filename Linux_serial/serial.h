#ifndef SERIAL_H
#define SERIAL_H

/* USART Flags */
#define ACK			0x01
#define NEED_ACK		0x02
#define	RESEND			0x03
#define RX_DONE 		0x04
#define RX_WAITING		0x05

/* USART Commands */
#define SERIAL_SEL		0x04
#define SERIAL_PLUS		0x05
#define SERIAL_MINUS		0x06
#define SERIAL_SINGLE		0x07
#define SERIAL_SEND_WF		0x08

#endif