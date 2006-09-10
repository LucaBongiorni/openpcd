#ifndef _OPENPCD_H
#define _OPENPCD_H

#include <openpcd.h>

#define Hz
#define	kHz	*1000 Hz
#define MHz	*1000 kHz
#define MCLK	(48 MHz)


#ifdef OLIMEX
#define OPENPCD_PIO_LED2	AT91C_PIO_PA17
#define OPENPCD_PIO_LED1	AT91C_PIO_PA18
#define OPENPCD_PIO_UDP_CNX	AT91C_PIO_PA24
#define OPENPCD_PIO_UDP_PUP	AT91C_PIO_PA16
#else
#define OPENPCD_PIO_UDP_CNX	AT91C_PIO_PA15
#define OPENPCD_PIO_UDP_PUP	AT91C_PIO_PA22
#define OPENPCD_PIO_LED1	AT91C_PIO_PA25
#define OPENPCD_PIO_LED2	AT91C_PIO_PA26
#endif

#define OPENPCD_IRQ_RC632	AT91C_ID_IRQ1

/* PIO A mapping for OpenPCD v0.2
 *
 * PA0	TIOA0	B	O	CARRIER_DIV_HELP
 * PA1	TIOB1	B	O	CARRIER_DIV
 * PA2	PA2	P	I	N/C
 * PA3	TWD	A	I/O	I2C
 *
 * PA4	TWCK	A	O	I2C
 * PA5	PA5	P	O	RFID_RESET
 * PA6	PA6	P	I	N/C
 * PA7	PA7	P	I	N/C
 *
 * PA8	PA8	P	I	N/C
 * PA9	DRXD	A	I	Debug
 * PA10	DTXD	A	O	Debug
 * PA11	NPCS0	A	O	SPI Slave Select
 *
 * PA12	MISO	A	I	SPi Master In
 * PA13	MOSI	A	O	SPI Maste Out
 * PA14	SPCK	A	O	SPI Clock
 * PA15		P	I	N/C
 *
 * PA16	PA16	P	O	UDP_PUP (disabled)
 * PA17	TD	A	O	MFIN	*
 * PA18	RD	A	I	MFOUT
 * PA19	RK	A	I	CARRIER_DIV
 *
 * PA20	PA20	P	I	AB_DETECT
 * PA21	PA21	P	I	N/C
 * PA22	PA22	P	I	UDP_PUP
 * PA23	PWM0	B	O	MFIN 	*
 *
 * PA24		P	I	N/C
 * PA25	PA25	P	O	LED1
 * PA26	PA26	P	O	LED2
 * PA27	PA27	P	I	BOOTLDR_SW
 *
 * PA28	TCLK1	B	I	PIO_CARRIER
 * PA29	TCLK2	B	I	CARRIER_DIV_HELP
 * PA30	IRQ1	A	I	RC632_IRQ
 * PA31	PA31	P	O	TRIGGER
 *
 * => PIO_PSR = 0x8f7181e4 (= PIO_PER)
 * => PIO_OSR = 0x86010020 (= PIO_OER)
 * => PIO_ASR = 0x400e7e18 
 * => PIO_BSR = 0x30800003
 *
 * * MFIN connected to both SSC and PWM output !!!
 */

#define OPENPCD_PIO_CDIV_HELP_OUT	AT91C_PA0_TIOA0
#define OPENPCD_PIO_CDIV_HELP_IN	AT91C_PA29_TCLK2
#define OPENPCD_PIO_MFIN_PWM		AT91C_PA23_PWM0
#define OPENPCD_PIO_CARRIER_DIV_OUT	AT91C_PA1_TIOB0
#define OPENPCD_PIO_MFIN_SSC_TX		AT91C_PA17_TD
#define OPENPCD_PIO_MFOUT_SSC_RX	AT91C_PA18_RD
#define OPENPCD_PIO_SSP_CKIN		AT91C_PA19_RK
#define OPENPCD_PIO_RC632_RESET		AT91C_PIO_PA5
#define OPENPCD_PIO_TRIGGER		AT91C_PIO_PA31
#define OPENPCD_PIO_CARRIER_IN		AT91C_PA28_TCLK1


/* PIO Definition PICCSIM v0.3
 *
 * PA0	TIOA0	B	O	CARRIER_DIV_HELP
 * PA1	TIOB1	B	O	SSC_CLOCK
 * PA2	PA2	P	O	LOAD1
 * PA3	PA3	P	O	LOAD2
 * PA4	PA4	P	I	N/C
 * PA5	PA5	P	O	nSLAVE_RESET
 * PA6	PA6	P	I	BOOTLOADER_SW
 * PA7	PA7	P	I	N/C
 * PA8	PA8	P	O	SPI_SS2 (Comparator)
 * PA9	DRXD	A	I	Debug
 * PA10	DTXD	A	O	Debug
 * PA11	NPCS0	A	O	SPI_SS1 (Gain)
 * PA12	PA12	P	I	N/C
 * PA13	MOSI	A	O	SPI Master Out
 * PA14	SPCK	A	O	SPI Clock
 * PA15	PA15	P	I	PLL_LOCK
 * PA16	PA16	P	O	UDP_PUP (old)
 * PA17	TD	A	O	SSC Tx Data (MOD)
 * PA18	RD	A	I	SSC Rx Data (SSC_DATA)
 * PA19	RK	A	I	SSC Rx Clock (SSC_CLOCK)
 * PA20	PA20	P	I	AB_DETECT
 * PA21	PA21	P	I	N/C
 * PA22	PA22	P	I	N/C 
 * PA23	PWM0	B	O	PWM Output * (MOD)
 * PA24	PA24	P	O	PLL_INHIBIT
 * PA25	PA25	P	O	LED1 green
 * PA26	PA26	P	O	LED2 red
 * PA27	TIOB2	B	I	DATA
 * PA28	TCLK1	B	I	CARRIER
 * PA29	TCLK2	B	I	CARRIER_DIV_HELP
 * PA30	PA30	P	I	N/C
 * PA31	PA31	P	I	N/C
 *
 */

#define OPENPICC_PIO_LOAD1		AT91C_PIO_PA2
#define OPENPICC_PIO_LOAD2		AT91C_PIO_PA3
#define OPENPICC_PIO_SLAVE_RESET	AT91C_PIO_PA5
#define OPENPICC_PIO_BOOTLDR		AT91C_PIO_PA6
#define OPENPICC_PIO_SS2_DT_THRESH	AT91C_PIO_PA8
#define OPENPICC_PIO_SS1_GAIN		AT91C_PIO_PA11
#define OPENPICC_PIO_PLL_LOCK		AT91C_PIO_PA15

#define OPENPICC_PIO_AB_DETECT		AT91C_PIO_PA20
#define OPENPICC_PIO_PLL_INHIBIT	AT91C_PIO_PA24

#define OPENPICC_ADC_FIELD_STRENGTH	AT91C_ADC_CH4
#define OPENPICC_ADC_PLL_DEM		AT91C_ADC_CH5
#define OPENPICC_ADC_AN1		AT91C_ADC_CH6
#define OPENPICC_ADC_AN2		AT91C_ADC_CH7

#define OPENPCD_IRQ_PRIO_SPI	AT91C_AIC_PRIOR_HIGHEST
#define OPENPCD_IRQ_PRIO_SSC	(AT91C_AIC_PRIOR_HIGHEST-1)
#define OPENPCD_IRQ_PRIO_UDP	(AT91C_AIC_PRIOR_LOWEST+2)
#define OPENPCD_IRQ_PRIO_PIT	(AT91C_AIC_PRIOR_LOWEST+1)
#define OPENPCD_IRQ_PRIO_RC632	AT91C_AIC_PRIOR_LOWEST

#endif /* _OPENPCD_H */
