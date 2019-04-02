/****************************************************************************/

/*
 *	m527xsim.h -- ColdFire 5270/5271 System Integration Module support.
 *
 *	(C) Copyright 2004, Greg Ungerer (gerg@snapgear.com)
 */

/****************************************************************************/
#ifndef	m527xsim_h
#define	m527xsim_h
/****************************************************************************/

#define	CPU_NAME		"COLDFIRE(m527x)"
#define	CPU_INSTR_PER_JIFFY	3
#define	MCF_BUSCLK		(MCF_CLK / 2)

#include <asm/m52xxacr.h>

/*
 *	Define the 5270/5271 SIM register set addresses.
 */
#define	MCFICM_INTC0		(MCF_IPSBAR + 0x0c00)	/* Base for Interrupt Ctrl 0 */
#define	MCFICM_INTC1		(MCF_IPSBAR + 0x0d00)	/* Base for Interrupt Ctrl 1 */

#define	MCFINTC_IPRH		0x00		/* Interrupt pending 32-63 */
#define	MCFINTC_IPRL		0x04		/* Interrupt pending 1-31 */
#define	MCFINTC_IMRH		0x08		/* Interrupt mask 32-63 */
#define	MCFINTC_IMRL		0x0c		/* Interrupt mask 1-31 */
#define	MCFINTC_INTFRCH		0x10		/* Interrupt force 32-63 */
#define	MCFINTC_INTFRCL		0x14		/* Interrupt force 1-31 */
#define	MCFINTC_IRLR		0x18		/* */
#define	MCFINTC_IACKL		0x19		/* */
#define	MCFINTC_ICR0		0x40		/* Base ICR register */

#define	MCFINT_VECBASE		64		/* Vector base number */
#define	MCFINT_UART0		13		/* Interrupt number for UART0 */
#define	MCFINT_UART1		14		/* Interrupt number for UART1 */
#define	MCFINT_UART2		15		/* Interrupt number for UART2 */
#define	MCFINT_I2C0		17		/* Interrupt number for I2C */
#define	MCFINT_QSPI		18		/* Interrupt number for QSPI */
#define	MCFINT_FECRX0		23		/* Interrupt number for FEC0 */
#define	MCFINT_FECTX0		27		/* Interrupt number for FEC0 */
#define	MCFINT_FECENTC0		29		/* Interrupt number for FEC0 */
#define	MCFINT_PIT1		36		/* Interrupt number for PIT1 */

#define	MCFINT2_VECBASE		128		/* Vector base number 2 */
#define	MCFINT2_FECRX1		23		/* Interrupt number for FEC1 */
#define	MCFINT2_FECTX1		27		/* Interrupt number for FEC1 */
#define	MCFINT2_FECENTC1	29		/* Interrupt number for FEC1 */

#define	MCF_IRQ_UART0	        (MCFINT_VECBASE + MCFINT_UART0)
#define	MCF_IRQ_UART1	        (MCFINT_VECBASE + MCFINT_UART1)
#define	MCF_IRQ_UART2	        (MCFINT_VECBASE + MCFINT_UART2)

#define	MCF_IRQ_FECRX0		(MCFINT_VECBASE + MCFINT_FECRX0)
#define	MCF_IRQ_FECTX0		(MCFINT_VECBASE + MCFINT_FECTX0)
#define	MCF_IRQ_FECENTC0	(MCFINT_VECBASE + MCFINT_FECENTC0)
#define	MCF_IRQ_FECRX1		(MCFINT2_VECBASE + MCFINT2_FECRX1)
#define	MCF_IRQ_FECTX1		(MCFINT2_VECBASE + MCFINT2_FECTX1)
#define	MCF_IRQ_FECENTC1	(MCFINT2_VECBASE + MCFINT2_FECENTC1)

#define	MCF_IRQ_QSPI		(MCFINT_VECBASE + MCFINT_QSPI)
#define MCF_IRQ_PIT1		(MCFINT_VECBASE + MCFINT_PIT1)
#define	MCF_IRQ_I2C0		(MCFINT_VECBASE + MCFINT_I2C0)

/*
 *	SDRAM configuration registers.
 */
#ifdef CONFIG_M5271
#define	MCFSIM_DCR		(MCF_IPSBAR + 0x40)	/* Control */
#define	MCFSIM_DACR0		(MCF_IPSBAR + 0x48)	/* Base address 0 */
#define	MCFSIM_DMR0		(MCF_IPSBAR + 0x4c)	/* Address mask 0 */
#define	MCFSIM_DACR1		(MCF_IPSBAR + 0x50)	/* Base address 1 */
#define	MCFSIM_DMR1		(MCF_IPSBAR + 0x54)	/* Address mask 1 */
#endif
#ifdef CONFIG_M5275
#define	MCFSIM_DMR		(MCF_IPSBAR + 0x40)	/* Mode */
#define	MCFSIM_DCR		(MCF_IPSBAR + 0x44)	/* Control */
#define	MCFSIM_DCFG1		(MCF_IPSBAR + 0x48)	/* Configuration 1 */
#define	MCFSIM_DCFG2		(MCF_IPSBAR + 0x4c)	/* Configuration 2 */
#define	MCFSIM_DBAR0		(MCF_IPSBAR + 0x50)	/* Base address 0 */
#define	MCFSIM_DMR0		(MCF_IPSBAR + 0x54)	/* Address mask 0 */
#define	MCFSIM_DBAR1		(MCF_IPSBAR + 0x58)	/* Base address 1 */
#define	MCFSIM_DMR1		(MCF_IPSBAR + 0x5c)	/* Address mask 1 */
#endif

/*
 *	DMA unit base addresses.
 */
#define	MCFDMA_BASE0		(MCF_IPSBAR + 0x100)
#define	MCFDMA_BASE1		(MCF_IPSBAR + 0x140)
#define	MCFDMA_BASE2		(MCF_IPSBAR + 0x180)
#define	MCFDMA_BASE3		(MCF_IPSBAR + 0x1C0)

/*
 *	UART module.
 */
#define MCFUART_BASE0		(MCF_IPSBAR + 0x200)
#define MCFUART_BASE1		(MCF_IPSBAR + 0x240)
#define MCFUART_BASE2		(MCF_IPSBAR + 0x280)

/*
 *	FEC ethernet module.
 */
#define	MCFFEC_BASE0		(MCF_IPSBAR + 0x1000)
#define	MCFFEC_SIZE0		0x800
#ifdef CONFIG_M5275
#define	MCFFEC_BASE1		(MCF_IPSBAR + 0x1800)
#define	MCFFEC_SIZE1		0x800
#endif

/*
 *	QSPI module.
 */
#define	MCFQSPI_BASE		(MCF_IPSBAR + 0x340)
#define	MCFQSPI_SIZE		0x40

#ifdef CONFIG_M5271
#define	MCFQSPI_CS0		91
#define	MCFQSPI_CS1		92
#define	MCFQSPI_CS2		99
#define	MCFQSPI_CS3		103
#endif
#ifdef CONFIG_M5275
#define	MCFQSPI_CS0		59
#define	MCFQSPI_CS1		60
#define	MCFQSPI_CS2		61
#define	MCFQSPI_CS3		62
#endif

/*
 *	GPIO module.
 */
#ifdef CONFIG_M5271
#define MCFGPIO_PODR_ADDR	(MCF_IPSBAR + 0x100000)
#define MCFGPIO_PODR_DATAH	(MCF_IPSBAR + 0x100001)
#define MCFGPIO_PODR_DATAL	(MCF_IPSBAR + 0x100002)
#define MCFGPIO_PODR_BUSCTL	(MCF_IPSBAR + 0x100003)
#define MCFGPIO_PODR_BS		(MCF_IPSBAR + 0x100004)
#define MCFGPIO_PODR_CS		(MCF_IPSBAR + 0x100005)
#define MCFGPIO_PODR_SDRAM	(MCF_IPSBAR + 0x100006)
#define MCFGPIO_PODR_FECI2C	(MCF_IPSBAR + 0x100007)
#define MCFGPIO_PODR_UARTH	(MCF_IPSBAR + 0x100008)
#define MCFGPIO_PODR_UARTL	(MCF_IPSBAR + 0x100009)
#define MCFGPIO_PODR_QSPI	(MCF_IPSBAR + 0x10000A)
#define MCFGPIO_PODR_TIMER	(MCF_IPSBAR + 0x10000B)

#define MCFGPIO_PDDR_ADDR	(MCF_IPSBAR + 0x100010)
#define MCFGPIO_PDDR_DATAH	(MCF_IPSBAR + 0x100011)
#define MCFGPIO_PDDR_DATAL	(MCF_IPSBAR + 0x100012)
#define MCFGPIO_PDDR_BUSCTL	(MCF_IPSBAR + 0x100013)
#define MCFGPIO_PDDR_BS		(MCF_IPSBAR + 0x100014)
#define MCFGPIO_PDDR_CS		(MCF_IPSBAR + 0x100015)
#define MCFGPIO_PDDR_SDRAM	(MCF_IPSBAR + 0x100016)
#define MCFGPIO_PDDR_FECI2C	(MCF_IPSBAR + 0x100017)
#define MCFGPIO_PDDR_UARTH	(MCF_IPSBAR + 0x100018)
#define MCFGPIO_PDDR_UARTL	(MCF_IPSBAR + 0x100019)
#define MCFGPIO_PDDR_QSPI	(MCF_IPSBAR + 0x10001A)
#define MCFGPIO_PDDR_TIMER	(MCF_IPSBAR + 0x10001B)

#define MCFGPIO_PPDSDR_ADDR	(MCF_IPSBAR + 0x100020)
#define MCFGPIO_PPDSDR_DATAH	(MCF_IPSBAR + 0x100021)
#define MCFGPIO_PPDSDR_DATAL	(MCF_IPSBAR + 0x100022)
#define MCFGPIO_PPDSDR_BUSCTL	(MCF_IPSBAR + 0x100023)
#define MCFGPIO_PPDSDR_BS	(MCF_IPSBAR + 0x100024)
#define MCFGPIO_PPDSDR_CS	(MCF_IPSBAR + 0x100025)
#define MCFGPIO_PPDSDR_SDRAM	(MCF_IPSBAR + 0x100026)
#define MCFGPIO_PPDSDR_FECI2C	(MCF_IPSBAR + 0x100027)
#define MCFGPIO_PPDSDR_UARTH	(MCF_IPSBAR + 0x100028)
#define MCFGPIO_PPDSDR_UARTL	(MCF_IPSBAR + 0x100029)
#define MCFGPIO_PPDSDR_QSPI	(MCF_IPSBAR + 0x10002A)
#define MCFGPIO_PPDSDR_TIMER	(MCF_IPSBAR + 0x10002B)

#define MCFGPIO_PCLRR_ADDR	(MCF_IPSBAR + 0x100030)
#define MCFGPIO_PCLRR_DATAH	(MCF_IPSBAR + 0x100031)
#define MCFGPIO_PCLRR_DATAL	(MCF_IPSBAR + 0x100032)
#define MCFGPIO_PCLRR_BUSCTL	(MCF_IPSBAR + 0x100033)
#define MCFGPIO_PCLRR_BS	(MCF_IPSBAR + 0x100034)
#define MCFGPIO_PCLRR_CS	(MCF_IPSBAR + 0x100035)
#define MCFGPIO_PCLRR_SDRAM	(MCF_IPSBAR + 0x100036)
#define MCFGPIO_PCLRR_FECI2C	(MCF_IPSBAR + 0x100037)
#define MCFGPIO_PCLRR_UARTH	(MCF_IPSBAR + 0x100038)
#define MCFGPIO_PCLRR_UARTL	(MCF_IPSBAR + 0x100039)
#define MCFGPIO_PCLRR_QSPI	(MCF_IPSBAR + 0x10003A)
#define MCFGPIO_PCLRR_TIMER	(MCF_IPSBAR + 0x10003B)

/*
 * Generic GPIO support
 */
#define MCFGPIO_PODR		MCFGPIO_PODR_ADDR
#define MCFGPIO_PDDR		MCFGPIO_PDDR_ADDR
#define MCFGPIO_PPDR		MCFGPIO_PPDSDR_ADDR
#define MCFGPIO_SETR		MCFGPIO_PPDSDR_ADDR
#define MCFGPIO_CLRR		MCFGPIO_PCLRR_ADDR

#define MCFGPIO_PIN_MAX		100
#define MCFGPIO_IRQ_MAX		8
#define MCFGPIO_IRQ_VECBASE	MCFINT_VECBASE

/*
 * Port Pin Assignment registers.
 */
#define MCFGPIO_PAR_AD		(MCF_IPSBAR + 0x100040)
#define MCFGPIO_PAR_BUSCTL	(MCF_IPSBAR + 0x100042)
#define MCFGPIO_PAR_BS		(MCF_IPSBAR + 0x100044)
#define MCFGPIO_PAR_CS		(MCF_IPSBAR + 0x100045)
#define MCFGPIO_PAR_SDRAM	(MCF_IPSBAR + 0x100046)
#define MCFGPIO_PAR_FECI2C	(MCF_IPSBAR + 0x100047)
#define MCFGPIO_PAR_UART	(MCF_IPSBAR + 0x100048)
#define MCFGPIO_PAR_QSPI	(MCF_IPSBAR + 0x10004A)
#define MCFGPIO_PAR_TIMER	(MCF_IPSBAR + 0x10004C)

#define UART0_ENABLE_MASK	0x000f
#define UART1_ENABLE_MASK	0x0ff0
#define UART2_ENABLE_MASK	0x3000
#endif /* CONFIG_M5271 */

#ifdef CONFIG_M5275
#define MCFGPIO_PODR_BUSCTL	(MCF_IPSBAR + 0x100004)
#define MCFGPIO_PODR_ADDR	(MCF_IPSBAR + 0x100005)
#define MCFGPIO_PODR_CS		(MCF_IPSBAR + 0x100008)
#define MCFGPIO_PODR_FEC0H	(MCF_IPSBAR + 0x10000A)
#define MCFGPIO_PODR_FEC0L	(MCF_IPSBAR + 0x10000B)
#define MCFGPIO_PODR_FECI2C	(MCF_IPSBAR + 0x10000C)
#define MCFGPIO_PODR_QSPI	(MCF_IPSBAR + 0x10000D)
#define MCFGPIO_PODR_SDRAM	(MCF_IPSBAR + 0x10000E)
#define MCFGPIO_PODR_TIMERH	(MCF_IPSBAR + 0x10000F)
#define MCFGPIO_PODR_TIMERL	(MCF_IPSBAR + 0x100010)
#define MCFGPIO_PODR_UARTL	(MCF_IPSBAR + 0x100011)
#define MCFGPIO_PODR_FEC1H	(MCF_IPSBAR + 0x100012)
#define MCFGPIO_PODR_FEC1L	(MCF_IPSBAR + 0x100013)
#define MCFGPIO_PODR_BS		(MCF_IPSBAR + 0x100014)
#define MCFGPIO_PODR_IRQ	(MCF_IPSBAR + 0x100015)
#define MCFGPIO_PODR_USBH	(MCF_IPSBAR + 0x100016)
#define MCFGPIO_PODR_USBL	(MCF_IPSBAR + 0x100017)
#define MCFGPIO_PODR_UARTH	(MCF_IPSBAR + 0x100018)

#define MCFGPIO_PDDR_BUSCTL	(MCF_IPSBAR + 0x100020)
#define MCFGPIO_PDDR_ADDR	(MCF_IPSBAR + 0x100021)
#define MCFGPIO_PDDR_CS		(MCF_IPSBAR + 0x100024)
#define MCFGPIO_PDDR_FEC0H	(MCF_IPSBAR + 0x100026)
#define MCFGPIO_PDDR_FEC0L	(MCF_IPSBAR + 0x100027)
#define MCFGPIO_PDDR_FECI2C	(MCF_IPSBAR + 0x100028)
#define MCFGPIO_PDDR_QSPI	(MCF_IPSBAR + 0x100029)
#define MCFGPIO_PDDR_SDRAM	(MCF_IPSBAR + 0x10002A)
#define MCFGPIO_PDDR_TIMERH	(MCF_IPSBAR + 0x10002B)
#define MCFGPIO_PDDR_TIMERL	(MCF_IPSBAR + 0x10002C)
#define MCFGPIO_PDDR_UARTL	(MCF_IPSBAR + 0x10002D)
#define MCFGPIO_PDDR_FEC1H	(MCF_IPSBAR + 0x10002E)
#define MCFGPIO_PDDR_FEC1L	(MCF_IPSBAR + 0x10002F)
#define MCFGPIO_PDDR_BS		(MCF_IPSBAR + 0x100030)
#define MCFGPIO_PDDR_IRQ	(MCF_IPSBAR + 0x100031)
#define MCFGPIO_PDDR_USBH	(MCF_IPSBAR + 0x100032)
#define MCFGPIO_PDDR_USBL	(MCF_IPSBAR + 0x100033)
#define MCFGPIO_PDDR_UARTH	(MCF_IPSBAR + 0x100034)

#define MCFGPIO_PPDSDR_BUSCTL	(MCF_IPSBAR + 0x10003C)
#define MCFGPIO_PPDSDR_ADDR	(MCF_IPSBAR + 0x10003D)
#define MCFGPIO_PPDSDR_CS	(MCF_IPSBAR + 0x100040)
#define MCFGPIO_PPDSDR_FEC0H	(MCF_IPSBAR + 0x100042)
#define MCFGPIO_PPDSDR_FEC0L	(MCF_IPSBAR + 0x100043)
#define MCFGPIO_PPDSDR_FECI2C	(MCF_IPSBAR + 0x100044)
#define MCFGPIO_PPDSDR_QSPI	(MCF_IPSBAR + 0x100045)
#define MCFGPIO_PPDSDR_SDRAM	(MCF_IPSBAR + 0x100046)
#define MCFGPIO_PPDSDR_TIMERH	(MCF_IPSBAR + 0x100047)
#define MCFGPIO_PPDSDR_TIMERL	(MCF_IPSBAR + 0x100048)
#define MCFGPIO_PPDSDR_UARTL	(MCF_IPSBAR + 0x100049)
#define MCFGPIO_PPDSDR_FEC1H	(MCF_IPSBAR + 0x10004A)
#define MCFGPIO_PPDSDR_FEC1L	(MCF_IPSBAR + 0x10004B)
#define MCFGPIO_PPDSDR_BS	(MCF_IPSBAR + 0x10004C)
#define MCFGPIO_PPDSDR_IRQ	(MCF_IPSBAR + 0x10004D)
#define MCFGPIO_PPDSDR_USBH	(MCF_IPSBAR + 0x10004E)
#define MCFGPIO_PPDSDR_USBL	(MCF_IPSBAR + 0x10004F)
#define MCFGPIO_PPDSDR_UARTH	(MCF_IPSBAR + 0x100050)

#define MCFGPIO_PCLRR_BUSCTL	(MCF_IPSBAR + 0x100058)
#define MCFGPIO_PCLRR_ADDR	(MCF_IPSBAR + 0x100059)
#define MCFGPIO_PCLRR_CS	(MCF_IPSBAR + 0x10005C)
#define MCFGPIO_PCLRR_FEC0H	(MCF_IPSBAR + 0x10005E)
#define MCFGPIO_PCLRR_FEC0L	(MCF_IPSBAR + 0x10005F)
#define MCFGPIO_PCLRR_FECI2C	(MCF_IPSBAR + 0x100060)
#define MCFGPIO_PCLRR_QSPI	(MCF_IPSBAR + 0x100061)
#define MCFGPIO_PCLRR_SDRAM	(MCF_IPSBAR + 0x100062)
#define MCFGPIO_PCLRR_TIMERH	(MCF_IPSBAR + 0x100063)
#define MCFGPIO_PCLRR_TIMERL	(MCF_IPSBAR + 0x100064)
#define MCFGPIO_PCLRR_UARTL	(MCF_IPSBAR + 0x100065)
#define MCFGPIO_PCLRR_FEC1H	(MCF_IPSBAR + 0x100066)
#define MCFGPIO_PCLRR_FEC1L	(MCF_IPSBAR + 0x100067)
#define MCFGPIO_PCLRR_BS	(MCF_IPSBAR + 0x100068)
#define MCFGPIO_PCLRR_IRQ	(MCF_IPSBAR + 0x100069)
#define MCFGPIO_PCLRR_USBH	(MCF_IPSBAR + 0x10006A)
#define MCFGPIO_PCLRR_USBL	(MCF_IPSBAR + 0x10006B)
#define MCFGPIO_PCLRR_UARTH	(MCF_IPSBAR + 0x10006C)


/*
 * Generic GPIO support
 */
#define MCFGPIO_PODR		MCFGPIO_PODR_BUSCTL
#define MCFGPIO_PDDR		MCFGPIO_PDDR_BUSCTL
#define MCFGPIO_PPDR		MCFGPIO_PPDSDR_BUSCTL
#define MCFGPIO_SETR		MCFGPIO_PPDSDR_BUSCTL
#define MCFGPIO_CLRR		MCFGPIO_PCLRR_BUSCTL

#define MCFGPIO_PIN_MAX		148
#define MCFGPIO_IRQ_MAX		8
#define MCFGPIO_IRQ_VECBASE	MCFINT_VECBASE

/*
 * Port Pin Assignment registers.
 */
#define MCFGPIO_PAR_AD		(MCF_IPSBAR + 0x100070)
#define MCFGPIO_PAR_CS		(MCF_IPSBAR + 0x100071)
#define MCFGPIO_PAR_BUSCTL	(MCF_IPSBAR + 0x100072)
#define MCFGPIO_PAR_USB		(MCF_IPSBAR + 0x100076)
#define MCFGPIO_PAR_FEC0HL	(MCF_IPSBAR + 0x100078)
#define MCFGPIO_PAR_FEC1HL	(MCF_IPSBAR + 0x100079)
#define MCFGPIO_PAR_TIMER	(MCF_IPSBAR + 0x10007A)
#define MCFGPIO_PAR_UART	(MCF_IPSBAR + 0x10007C)
#define MCFGPIO_PAR_QSPI	(MCF_IPSBAR + 0x10007E)
#define MCFGPIO_PAR_SDRAM	(MCF_IPSBAR + 0x100080)
#define MCFGPIO_PAR_FECI2C	(MCF_IPSBAR + 0x100082)
#define MCFGPIO_PAR_BS		(MCF_IPSBAR + 0x100084)

#define UART0_ENABLE_MASK	0x000f
#define UART1_ENABLE_MASK	0x00f0
#define UART2_ENABLE_MASK	0x3f00
#endif /* CONFIG_M5275 */

/*
 * PIT timer base addresses.
 */
#define	MCFPIT_BASE1		(MCF_IPSBAR + 0x150000)
#define	MCFPIT_BASE2		(MCF_IPSBAR + 0x160000)
#define	MCFPIT_BASE3		(MCF_IPSBAR + 0x170000)
#define	MCFPIT_BASE4		(MCF_IPSBAR + 0x180000)

/*
 * EPort
 */
#define MCFEPORT_EPPAR		(MCF_IPSBAR + 0x130000)
#define MCFEPORT_EPDDR		(MCF_IPSBAR + 0x130002)
#define MCFEPORT_EPIER		(MCF_IPSBAR + 0x130003)
#define MCFEPORT_EPDR		(MCF_IPSBAR + 0x130004)
#define MCFEPORT_EPPDR		(MCF_IPSBAR + 0x130005)
#define MCFEPORT_EPFR		(MCF_IPSBAR + 0x130006)

/*
 *  Reset Control Unit (relative to IPSBAR).
 */
#define	MCF_RCR			(MCF_IPSBAR + 0x110000)
#define	MCF_RSR			(MCF_IPSBAR + 0x110001)

#define	MCF_RCR_SWRESET		0x80		/* Software reset bit */
#define	MCF_RCR_FRCSTOUT	0x40		/* Force external reset */

/*
 * I2C module.
 */
#define	MCFI2C_BASE0		(MCF_IPSBAR + 0x300)
#define	MCFI2C_SIZE0		0x40

/****************************************************************************/
#endif	/* m527xsim_h */
