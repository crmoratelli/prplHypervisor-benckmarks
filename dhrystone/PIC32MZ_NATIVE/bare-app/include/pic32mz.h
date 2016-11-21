/* C type extensions */
typedef unsigned char			uint8_t;
typedef char				int8_t;
typedef unsigned short int		uint16_t;
typedef short int			int16_t;
typedef unsigned int			uint32_t;
typedef int				int32_t;
typedef unsigned long long		uint64_t;
typedef long long			int64_t;

typedef void				(*funcptr)();

/* CP0 registers */
#define CP0_INDEX		0
#define CP0_RANDOM		1
#define CP0_ENTRYLO0		2
#define CP0_ENTRYLO1		3
#define CP0_CONTEXT		4
#define CP0_USERLOCAL		4
#define CP0_PAGEMASK		5
#define CP0_PAGEGRAIN		5
#define CP0_WIRED		6
#define CP0_HWRENA		7
#define CP0_BADVADDR		8
#define CP0_COUNT		9
#define CP0_ENTRYHI		10
#define CP0_COMPARE		11
#define CP0_STATUS		12
#define CP0_INTCTL		12
#define CP0_SRSCTL		12
#define CP0_SRSMAP		12
#define CP0_VIEW_IPL		12
#define CP0_SRSMAP2		12
#define CP0_CAUSE		13
#define CP0_NESTEDEXC		13
#define CP0_VIEW_RIPL		13
#define CP0_EPC			14
#define CP0_NESTEDEPC		14
#define CP0_PRID		15
#define CP0_EBASE		15
#define CP0_CDMMBASE		15
#define CP0_CONFIG		16
#define CP0_CONFIG1		16
#define CP0_CONFIG2		16
#define CP0_CONFIG3		16
#define CP0_CONFIG4		16
#define CP0_CONFIG5		16
#define CP0_CONFIG7		16
#define CP0_LLADDR		17
#define CP0_WATCHLO		18
#define CP0_WATCHHI		19
#define CP0_DEBUG		23
#define CP0_TRACECONTROL	23
#define CP0_TRACECONTROL2	23
#define CP0_USERTRACEDATA1	23
#define CP0_TRACEBPC		23
#define CP0_DEBUG2		23
#define CP0_DEPC		24
#define CP0_USERTRACEDATA2	24
#define CP0_PERFCTL0		25
#define CP0_PERFCNT0		25
#define CP0_PERFCTL1		25
#define CP0_PERFCNT1		25
#define CP0_ERRCTL		26
#define CP0_TAGLO		28
#define CP0_DATALO		28
#define CP0_ERROREPC		30
#define CP0_DESAVE		31

/* STATUS register */
#define STATUS_CU0		0x10000000
#define STATUS_RP		0x08000000
#define STATUS_RE		0x02000000
#define STATUS_BEV		0x00400000
#define STATUS_SR		0x00100000
#define STATUS_NMI		0x00080000
#define STATUS_IPL(x)		((x) << 10)
#define STATUS_UM		0x00000010
#define STATUS_ERL		0x00000004
#define STATUS_EXL		0x00000002
#define STATUS_IE		0x00000001

/* CAUSE register */
#define CAUSE_BD		0x80000000
#define CAUSE_TI		0x40000000
#define CAUSE_CE		0x30000000
#define CAUSE_DC		0x08000000
#define CAUSE_IV		0x00800000
#define CAUSE_RIPL(r)		((r)>>10 & 63)
#define CAUSE_IP1		0x00020000
#define CAUSE_IP0		0x00010000
#define CAUSE_EXC_CODE		0x0000007c

#define CAUSE_Int		0
#define CAUSE_AdEL		(4 << 2)
#define CAUSE_AdES		(5 << 2)
#define CAUSE_IBE		(6 << 2)
#define CAUSE_DBE		(7 << 2)
#define CAUSE_Sys		(8 << 2)
#define CAUSE_Bp		(9 << 2)
#define CAUSE_RI		(10 << 2)
#define CAUSE_CPU		(11 << 2)
#define CAUSE_Ov		(12 << 2)
#define CAUSE_Tr		(13 << 2)

/* Read from CP0 */
#define mfc0(reg, sel) ({ int32_t __value;			\
asm volatile (						\
"mfc0	%0, $%1, %2"					\
: "=r" (__value) : "K" (reg), "K" (sel));		\
__value; })

/* Write to CP0 */
#define mtc0(reg, sel, value) asm volatile (                    \
"mtc0	%z0, $%1, %2"                                   \
: : "r" ((uint32_t) (value)), "K" (reg), "K" (sel))


/* Peripheral base address */
#define PIC32MZ_PBASE(a)        *(volatile unsigned*) (0xbf800000 + (a))

/* Port registers */
#define ANSELA          PIC32MZ_PBASE (0x60000)
#define ANSELACLR       PIC32MZ_PBASE (0x60004)
#define ANSELASET       PIC32MZ_PBASE (0x60008)
#define ANSELAINV       PIC32MZ_PBASE (0x6000C)
#define TRISA           PIC32MZ_PBASE (0x60010)
#define TRISACLR        PIC32MZ_PBASE (0x60014)
#define TRISASET        PIC32MZ_PBASE (0x60018)
#define TRISAINV        PIC32MZ_PBASE (0x6001C)
#define PORTA           PIC32MZ_PBASE (0x60020)
#define PORTACLR        PIC32MZ_PBASE (0x60024)
#define PORTASET        PIC32MZ_PBASE (0x60028)
#define PORTAINV        PIC32MZ_PBASE (0x6002C)
#define LATA            PIC32MZ_PBASE (0x60030)
#define LATACLR         PIC32MZ_PBASE (0x60034)
#define LATASET         PIC32MZ_PBASE (0x60038)
#define LATAINV         PIC32MZ_PBASE (0x6003C)
#define ODCA            PIC32MZ_PBASE (0x60040)
#define ODCACLR         PIC32MZ_PBASE (0x60044)
#define ODCASET         PIC32MZ_PBASE (0x60048)
#define ODCAINV         PIC32MZ_PBASE (0x6004C)
#define CNPUA           PIC32MZ_PBASE (0x60050)
#define CNPUACLR        PIC32MZ_PBASE (0x60054)
#define CNPUASET        PIC32MZ_PBASE (0x60058)
#define CNPUAINV        PIC32MZ_PBASE (0x6005C)
#define CNPDA           PIC32MZ_PBASE (0x60060)
#define CNPDACLR        PIC32MZ_PBASE (0x60064)
#define CNPDASET        PIC32MZ_PBASE (0x60068)
#define CNPDAINV        PIC32MZ_PBASE (0x6006C)
#define CNCONA          PIC32MZ_PBASE (0x60070)
#define CNCONACLR       PIC32MZ_PBASE (0x60074)
#define CNCONASET       PIC32MZ_PBASE (0x60078)
#define CNCONAINV       PIC32MZ_PBASE (0x6007C)
#define CNENA           PIC32MZ_PBASE (0x60080)
#define CNENACLR        PIC32MZ_PBASE (0x60084)
#define CNENASET        PIC32MZ_PBASE (0x60088)
#define CNENAINV        PIC32MZ_PBASE (0x6008C)
#define CNSTATA         PIC32MZ_PBASE (0x60090)
#define CNSTATACLR      PIC32MZ_PBASE (0x60094)
#define CNSTATASET      PIC32MZ_PBASE (0x60098)
#define CNSTATAINV      PIC32MZ_PBASE (0x6009C)
#define PORTA_BASE      0xbf860000
#define PORTA_SIZE	0x9c

#define ANSELB          PIC32MZ_PBASE (0x60100)
#define ANSELBCLR       PIC32MZ_PBASE (0x60104)
#define ANSELBSET       PIC32MZ_PBASE (0x60108)
#define ANSELBINV       PIC32MZ_PBASE (0x6010C)
#define TRISB           PIC32MZ_PBASE (0x60110)
#define TRISBCLR        PIC32MZ_PBASE (0x60114)
#define TRISBSET        PIC32MZ_PBASE (0x60118)
#define TRISBINV        PIC32MZ_PBASE (0x6011C)
#define PORTB           PIC32MZ_PBASE (0x60120)
#define PORTBCLR        PIC32MZ_PBASE (0x60124)
#define PORTBSET        PIC32MZ_PBASE (0x60128)
#define PORTBINV        PIC32MZ_PBASE (0x6012C)
#define LATB            PIC32MZ_PBASE (0x60130)
#define LATBCLR         PIC32MZ_PBASE (0x60134)
#define LATBSET         PIC32MZ_PBASE (0x60138)
#define LATBINV         PIC32MZ_PBASE (0x6013C)
#define ODCB            PIC32MZ_PBASE (0x60140)
#define ODCBCLR         PIC32MZ_PBASE (0x60144)
#define ODCBSET         PIC32MZ_PBASE (0x60148)
#define ODCBINV         PIC32MZ_PBASE (0x6014C)
#define CNPUB           PIC32MZ_PBASE (0x60150)
#define CNPUBCLR        PIC32MZ_PBASE (0x60154)
#define CNPUBSET        PIC32MZ_PBASE (0x60158)
#define CNPUBINV        PIC32MZ_PBASE (0x6015C)
#define CNPDB           PIC32MZ_PBASE (0x60160)
#define CNPDBCLR        PIC32MZ_PBASE (0x60164)
#define CNPDBSET        PIC32MZ_PBASE (0x60168)
#define CNPDBINV        PIC32MZ_PBASE (0x6016C)
#define CNCONB          PIC32MZ_PBASE (0x60170)
#define CNCONBCLR       PIC32MZ_PBASE (0x60174)
#define CNCONBSET       PIC32MZ_PBASE (0x60178)
#define CNCONBINV       PIC32MZ_PBASE (0x6017C)
#define CNENB           PIC32MZ_PBASE (0x60180)
#define CNENBCLR        PIC32MZ_PBASE (0x60184)
#define CNENBSET        PIC32MZ_PBASE (0x60188)
#define CNENBINV        PIC32MZ_PBASE (0x6018C)
#define CNSTATB         PIC32MZ_PBASE (0x60190)
#define CNSTATBCLR      PIC32MZ_PBASE (0x60194)
#define CNSTATBSET      PIC32MZ_PBASE (0x60198)
#define CNSTATBINV      PIC32MZ_PBASE (0x6019C)
#define PORTB_BASE      0xbf860100
#define PORTB_SIZE	0x9C


#define ANSELC          PIC32MZ_PBASE (0x60200)
#define ANSELCCLR       PIC32MZ_PBASE (0x60204)
#define ANSELCSET       PIC32MZ_PBASE (0x60208)
#define ANSELCINV       PIC32MZ_PBASE (0x6020C)
#define TRISC           PIC32MZ_PBASE (0x60210)
#define TRISCCLR        PIC32MZ_PBASE (0x60214)
#define TRISCSET        PIC32MZ_PBASE (0x60218)
#define TRISCINV        PIC32MZ_PBASE (0x6021C)
#define PORTC           PIC32MZ_PBASE (0x60220)
#define PORTCCLR        PIC32MZ_PBASE (0x60224)
#define PORTCSET        PIC32MZ_PBASE (0x60228)
#define PORTCINV        PIC32MZ_PBASE (0x6022C)
#define LATC            PIC32MZ_PBASE (0x60230)
#define LATCCLR         PIC32MZ_PBASE (0x60234)
#define LATCSET         PIC32MZ_PBASE (0x60238)
#define LATCINV         PIC32MZ_PBASE (0x6023C)
#define ODCC            PIC32MZ_PBASE (0x60240)
#define ODCCCLR         PIC32MZ_PBASE (0x60244)
#define ODCCSET         PIC32MZ_PBASE (0x60248)
#define ODCCINV         PIC32MZ_PBASE (0x6024C)
#define CNPUC           PIC32MZ_PBASE (0x60250)
#define CNPUCCLR        PIC32MZ_PBASE (0x60254)
#define CNPUCSET        PIC32MZ_PBASE (0x60258)
#define CNPUCINV        PIC32MZ_PBASE (0x6025C)
#define CNPDC           PIC32MZ_PBASE (0x60260)
#define CNPDCCLR        PIC32MZ_PBASE (0x60264)
#define CNPDCSET        PIC32MZ_PBASE (0x60268)
#define CNPDCINV        PIC32MZ_PBASE (0x6026C)
#define CNCONC          PIC32MZ_PBASE (0x60270)
#define CNCONCCLR       PIC32MZ_PBASE (0x60274)
#define CNCONCSET       PIC32MZ_PBASE (0x60278)
#define CNCONCINV       PIC32MZ_PBASE (0x6027C)
#define CNENC           PIC32MZ_PBASE (0x60280)
#define CNENCCLR        PIC32MZ_PBASE (0x60284)
#define CNENCSET        PIC32MZ_PBASE (0x60288)
#define CNENCINV        PIC32MZ_PBASE (0x6028C)
#define CNSTATC         PIC32MZ_PBASE (0x60290)
#define CNSTATCCLR      PIC32MZ_PBASE (0x60294)
#define CNSTATCSET      PIC32MZ_PBASE (0x60298)
#define CNSTATCINV      PIC32MZ_PBASE (0x6029C)
#define PORTC_BASE	0xbf860200
#define PORTC_SIZE	0x9C

#define ANSELD          PIC32MZ_PBASE (0x60300)
#define ANSELDCLR       PIC32MZ_PBASE (0x60304)
#define ANSELDSET       PIC32MZ_PBASE (0x60308)
#define ANSELDINV       PIC32MZ_PBASE (0x6030C)
#define TRISD           PIC32MZ_PBASE (0x60310)
#define TRISDCLR        PIC32MZ_PBASE (0x60314)
#define TRISDSET        PIC32MZ_PBASE (0x60318)
#define TRISDINV        PIC32MZ_PBASE (0x6031C)
#define PORTD           PIC32MZ_PBASE (0x60320)
#define PORTDCLR        PIC32MZ_PBASE (0x60324)
#define PORTDSET        PIC32MZ_PBASE (0x60328)
#define PORTDINV        PIC32MZ_PBASE (0x6032C)
#define LATD            PIC32MZ_PBASE (0x60330)
#define LATDCLR         PIC32MZ_PBASE (0x60334)
#define LATDSET         PIC32MZ_PBASE (0x60338)
#define LATDINV         PIC32MZ_PBASE (0x6033C)
#define ODCD            PIC32MZ_PBASE (0x60340)
#define ODCDCLR         PIC32MZ_PBASE (0x60344)
#define ODCDSET         PIC32MZ_PBASE (0x60348)
#define ODCDINV         PIC32MZ_PBASE (0x6034C)
#define CNPUD           PIC32MZ_PBASE (0x60350)
#define CNPUDCLR        PIC32MZ_PBASE (0x60354)
#define CNPUDSET        PIC32MZ_PBASE (0x60358)
#define CNPUDINV        PIC32MZ_PBASE (0x6035C)
#define CNPDD           PIC32MZ_PBASE (0x60360)
#define CNPDDCLR        PIC32MZ_PBASE (0x60364)
#define CNPDDSET        PIC32MZ_PBASE (0x60368)
#define CNPDDINV        PIC32MZ_PBASE (0x6036C)
#define CNCOND          PIC32MZ_PBASE (0x60370)
#define CNCONDCLR       PIC32MZ_PBASE (0x60374)
#define CNCONDSET       PIC32MZ_PBASE (0x60378)
#define CNCONDINV       PIC32MZ_PBASE (0x6037C)
#define CNEND           PIC32MZ_PBASE (0x60380)
#define CNENDCLR        PIC32MZ_PBASE (0x60384)
#define CNENDSET        PIC32MZ_PBASE (0x60388)
#define CNENDINV        PIC32MZ_PBASE (0x6038C)
#define CNSTATD         PIC32MZ_PBASE (0x60390)
#define CNSTATDCLR      PIC32MZ_PBASE (0x60394)
#define CNSTATDSET      PIC32MZ_PBASE (0x60398)
#define CNSTATDINV      PIC32MZ_PBASE (0x6039C)
#define PORTD_BASE	0xbf860300
#define PORTD_SIZE	0x9C

#define ANSELE          PIC32MZ_PBASE (0x60400)
#define ANSELECLR       PIC32MZ_PBASE (0x60404)
#define ANSELESET       PIC32MZ_PBASE (0x60408)
#define ANSELEINV       PIC32MZ_PBASE (0x6040C)
#define TRISE           PIC32MZ_PBASE (0x60410)
#define TRISECLR        PIC32MZ_PBASE (0x60414)
#define TRISESET        PIC32MZ_PBASE (0x60418)
#define TRISEINV        PIC32MZ_PBASE (0x6041C)
#define PORTE           PIC32MZ_PBASE (0x60420)
#define PORTECLR        PIC32MZ_PBASE (0x60424)
#define PORTESET        PIC32MZ_PBASE (0x60428)
#define PORTEINV        PIC32MZ_PBASE (0x6042C)
#define LATE            PIC32MZ_PBASE (0x60430)
#define LATECLR         PIC32MZ_PBASE (0x60434)
#define LATESET         PIC32MZ_PBASE (0x60438)
#define LATEINV         PIC32MZ_PBASE (0x6043C)
#define ODCE            PIC32MZ_PBASE (0x60440)
#define ODCECLR         PIC32MZ_PBASE (0x60444)
#define ODCESET         PIC32MZ_PBASE (0x60448)
#define ODCEINV         PIC32MZ_PBASE (0x6044C)
#define CNPUE           PIC32MZ_PBASE (0x60450)
#define CNPUECLR        PIC32MZ_PBASE (0x60454)
#define CNPUESET        PIC32MZ_PBASE (0x60458)
#define CNPUEINV        PIC32MZ_PBASE (0x6045C)
#define CNPDE           PIC32MZ_PBASE (0x60460)
#define CNPDECLR        PIC32MZ_PBASE (0x60464)
#define CNPDESET        PIC32MZ_PBASE (0x60468)
#define CNPDEINV        PIC32MZ_PBASE (0x6046C)
#define CNCONE          PIC32MZ_PBASE (0x60470)
#define CNCONECLR       PIC32MZ_PBASE (0x60474)
#define CNCONESET       PIC32MZ_PBASE (0x60478)
#define CNCONEINV       PIC32MZ_PBASE (0x6047C)
#define CNENE           PIC32MZ_PBASE (0x60480)
#define CNENECLR        PIC32MZ_PBASE (0x60484)
#define CNENESET        PIC32MZ_PBASE (0x60488)
#define CNENEINV        PIC32MZ_PBASE (0x6048C)
#define CNSTATE         PIC32MZ_PBASE (0x60490)
#define CNSTATECLR      PIC32MZ_PBASE (0x60494)
#define CNSTATESET      PIC32MZ_PBASE (0x60498)
#define CNSTATEINV      PIC32MZ_PBASE (0x6049C)
#define PORTE_BASE	0xbf860400
#define PORTE_SIZE	0x9C

#define ANSELF          PIC32MZ_PBASE (0x60500)
#define ANSELFCLR       PIC32MZ_PBASE (0x60504)
#define ANSELFSET       PIC32MZ_PBASE (0x60508)
#define ANSELFINV       PIC32MZ_PBASE (0x6050C)
#define TRISF           PIC32MZ_PBASE (0x60510)
#define TRISFCLR        PIC32MZ_PBASE (0x60514)
#define TRISFSET        PIC32MZ_PBASE (0x60518)
#define TRISFINV        PIC32MZ_PBASE (0x6051C)
#define PORTF           PIC32MZ_PBASE (0x60520)
#define PORTFCLR        PIC32MZ_PBASE (0x60524)
#define PORTFSET        PIC32MZ_PBASE (0x60528)
#define PORTFINV        PIC32MZ_PBASE (0x6052C)
#define LATF            PIC32MZ_PBASE (0x60530)
#define LATFCLR         PIC32MZ_PBASE (0x60534)
#define LATFSET         PIC32MZ_PBASE (0x60538)
#define LATFINV         PIC32MZ_PBASE (0x6053C)
#define ODCF            PIC32MZ_PBASE (0x60540)
#define ODCFCLR         PIC32MZ_PBASE (0x60544)
#define ODCFSET         PIC32MZ_PBASE (0x60548)
#define ODCFINV         PIC32MZ_PBASE (0x6054C)
#define CNPUF           PIC32MZ_PBASE (0x60550)
#define CNPUFCLR        PIC32MZ_PBASE (0x60554)
#define CNPUFSET        PIC32MZ_PBASE (0x60558)
#define CNPUFINV        PIC32MZ_PBASE (0x6055C)
#define CNPDF           PIC32MZ_PBASE (0x60560)
#define CNPDFCLR        PIC32MZ_PBASE (0x60564)
#define CNPDFSET        PIC32MZ_PBASE (0x60568)
#define CNPDFINV        PIC32MZ_PBASE (0x6056C)
#define CNCONF          PIC32MZ_PBASE (0x60570)
#define CNCONFCLR       PIC32MZ_PBASE (0x60574)
#define CNCONFSET       PIC32MZ_PBASE (0x60578)
#define CNCONFINV       PIC32MZ_PBASE (0x6057C)
#define CNENF           PIC32MZ_PBASE (0x60580)
#define CNENFCLR        PIC32MZ_PBASE (0x60584)
#define CNENFSET        PIC32MZ_PBASE (0x60588)
#define CNENFINV        PIC32MZ_PBASE (0x6058C)
#define CNSTATF         PIC32MZ_PBASE (0x60590)
#define CNSTATFCLR      PIC32MZ_PBASE (0x60594)
#define CNSTATFSET      PIC32MZ_PBASE (0x60598)
#define CNSTATFINV      PIC32MZ_PBASE (0x6059C)
#define PORTF_BASE	0xbf860500
#define PORTF_SIZE	0x9C

#define ANSELG          PIC32MZ_PBASE (0x60600)
#define ANSELGCLR       PIC32MZ_PBASE (0x60604)
#define ANSELGSET       PIC32MZ_PBASE (0x60608)
#define ANSELGINV       PIC32MZ_PBASE (0x6060C)
#define TRISG           PIC32MZ_PBASE (0x60610)
#define TRISGCLR        PIC32MZ_PBASE (0x60614)
#define TRISGSET        PIC32MZ_PBASE (0x60618)
#define TRISGINV        PIC32MZ_PBASE (0x6061C)
#define PORTG           PIC32MZ_PBASE (0x60620)
#define PORTGCLR        PIC32MZ_PBASE (0x60624)
#define PORTGSET        PIC32MZ_PBASE (0x60628)
#define PORTGINV        PIC32MZ_PBASE (0x6062C)
#define LATG            PIC32MZ_PBASE (0x60630)
#define LATGCLR         PIC32MZ_PBASE (0x60634)
#define LATGSET         PIC32MZ_PBASE (0x60638)
#define LATGINV         PIC32MZ_PBASE (0x6063C)
#define ODCG            PIC32MZ_PBASE (0x60640)
#define ODCGCLR         PIC32MZ_PBASE (0x60644)
#define ODCGSET         PIC32MZ_PBASE (0x60648)
#define ODCGINV         PIC32MZ_PBASE (0x6064C)
#define CNPUG           PIC32MZ_PBASE (0x60650)
#define CNPUGCLR        PIC32MZ_PBASE (0x60654)
#define CNPUGSET        PIC32MZ_PBASE (0x60658)
#define CNPUGINV        PIC32MZ_PBASE (0x6065C)
#define CNPDG           PIC32MZ_PBASE (0x60660)
#define CNPDGCLR        PIC32MZ_PBASE (0x60664)
#define CNPDGSET        PIC32MZ_PBASE (0x60668)
#define CNPDGINV        PIC32MZ_PBASE (0x6066C)
#define CNCONG          PIC32MZ_PBASE (0x60670)
#define CNCONGCLR       PIC32MZ_PBASE (0x60674)
#define CNCONGSET       PIC32MZ_PBASE (0x60678)
#define CNCONGINV       PIC32MZ_PBASE (0x6067C)
#define CNENG           PIC32MZ_PBASE (0x60680)
#define CNENGCLR        PIC32MZ_PBASE (0x60684)
#define CNENGSET        PIC32MZ_PBASE (0x60688)
#define CNENGINV        PIC32MZ_PBASE (0x6068C)
#define CNSTATG         PIC32MZ_PBASE (0x60690)
#define CNSTATGCLR      PIC32MZ_PBASE (0x60694)
#define CNSTATGSET      PIC32MZ_PBASE (0x60698)
#define CNSTATGINV      PIC32MZ_PBASE (0x6069C)
#define PORTG_BASE	0xbf860600
#define PORTG_SIZE	0x9C

#define ANSELH          PIC32MZ_PBASE (0x60700)
#define ANSELHCLR       PIC32MZ_PBASE (0x60704)
#define ANSELHSET       PIC32MZ_PBASE (0x60708)
#define ANSELHINV       PIC32MZ_PBASE (0x6070C)
#define TRISH           PIC32MZ_PBASE (0x60710)
#define TRISHCLR        PIC32MZ_PBASE (0x60714)
#define TRISHSET        PIC32MZ_PBASE (0x60718)
#define TRISHINV        PIC32MZ_PBASE (0x6071C)
#define PORTH           PIC32MZ_PBASE (0x60720)
#define PORTHCLR        PIC32MZ_PBASE (0x60724)
#define PORTHSET        PIC32MZ_PBASE (0x60728)
#define PORTHINV        PIC32MZ_PBASE (0x6072C)
#define LATH            PIC32MZ_PBASE (0x60730)
#define LATHCLR         PIC32MZ_PBASE (0x60734)
#define LATHSET         PIC32MZ_PBASE (0x60738)
#define LATHINV         PIC32MZ_PBASE (0x6073C)
#define ODCH            PIC32MZ_PBASE (0x60740)
#define ODCHCLR         PIC32MZ_PBASE (0x60744)
#define ODCHSET         PIC32MZ_PBASE (0x60748)
#define ODCHINV         PIC32MZ_PBASE (0x6074C)
#define CNPUH           PIC32MZ_PBASE (0x60750)
#define CNPUHCLR        PIC32MZ_PBASE (0x60754)
#define CNPUHSET        PIC32MZ_PBASE (0x60758)
#define CNPUHINV        PIC32MZ_PBASE (0x6075C)
#define CNPDH           PIC32MZ_PBASE (0x60760)
#define CNPDHCLR        PIC32MZ_PBASE (0x60764)
#define CNPDHSET        PIC32MZ_PBASE (0x60768)
#define CNPDHINV        PIC32MZ_PBASE (0x6076C)
#define CNCONH          PIC32MZ_PBASE (0x60770)
#define CNCONHCLR       PIC32MZ_PBASE (0x60774)
#define CNCONHSET       PIC32MZ_PBASE (0x60778)
#define CNCONHINV       PIC32MZ_PBASE (0x6077C)
#define CNENH           PIC32MZ_PBASE (0x60780)
#define CNENHCLR        PIC32MZ_PBASE (0x60784)
#define CNENHSET        PIC32MZ_PBASE (0x60788)
#define CNENHINV        PIC32MZ_PBASE (0x6078C)
#define CNSTATH         PIC32MZ_PBASE (0x60790)
#define CNSTATHCLR      PIC32MZ_PBASE (0x60794)
#define CNSTATHSET      PIC32MZ_PBASE (0x60798)
#define CNSTATHINV      PIC32MZ_PBASE (0x6079C)
#define PORTH_BASE 	0xbf860700
#define PORTH_SIZE	0x9c

#define ANSELJ          PIC32MZ_PBASE (0x60800)
#define ANSELJCLR       PIC32MZ_PBASE (0x60804)
#define ANSELJSET       PIC32MZ_PBASE (0x60808)
#define ANSELJINV       PIC32MZ_PBASE (0x6080C)
#define TRISJ           PIC32MZ_PBASE (0x60810)
#define TRISJCLR        PIC32MZ_PBASE (0x60814)
#define TRISJSET        PIC32MZ_PBASE (0x60818)
#define TRISJINV        PIC32MZ_PBASE (0x6081C)
#define PORTJ           PIC32MZ_PBASE (0x60820)
#define PORTJCLR        PIC32MZ_PBASE (0x60824)
#define PORTJSET        PIC32MZ_PBASE (0x60828)
#define PORTJINV        PIC32MZ_PBASE (0x6082C)
#define LATJ            PIC32MZ_PBASE (0x60830)
#define LATJCLR         PIC32MZ_PBASE (0x60834)
#define LATJSET         PIC32MZ_PBASE (0x60838)
#define LATJINV         PIC32MZ_PBASE (0x6083C)
#define ODCJ            PIC32MZ_PBASE (0x60840)
#define ODCJCLR         PIC32MZ_PBASE (0x60844)
#define ODCJSET         PIC32MZ_PBASE (0x60848)
#define ODCJINV         PIC32MZ_PBASE (0x6084C)
#define CNPUJ           PIC32MZ_PBASE (0x60850)
#define CNPUJCLR        PIC32MZ_PBASE (0x60854)
#define CNPUJSET        PIC32MZ_PBASE (0x60858)
#define CNPUJINV        PIC32MZ_PBASE (0x6085C)
#define CNPDJ           PIC32MZ_PBASE (0x60860)
#define CNPDJCLR        PIC32MZ_PBASE (0x60864)
#define CNPDJSET        PIC32MZ_PBASE (0x60868)
#define CNPDJINV        PIC32MZ_PBASE (0x6086C)
#define CNCONJ          PIC32MZ_PBASE (0x60870)
#define CNCONJCLR       PIC32MZ_PBASE (0x60874)
#define CNCONJSET       PIC32MZ_PBASE (0x60878)
#define CNCONJINV       PIC32MZ_PBASE (0x6087C)
#define CNENJ           PIC32MZ_PBASE (0x60880)
#define CNENJCLR        PIC32MZ_PBASE (0x60884)
#define CNENJSET        PIC32MZ_PBASE (0x60888)
#define CNENJINV        PIC32MZ_PBASE (0x6088C)
#define CNSTATJ         PIC32MZ_PBASE (0x60890)
#define CNSTATJCLR      PIC32MZ_PBASE (0x60894)
#define CNSTATJSET      PIC32MZ_PBASE (0x60898)
#define CNSTATJINV      PIC32MZ_PBASE (0x6089C)
#define PORTJ_BASE	0xbf860800
#define PORTJ_SIZE	0x9C

#define TRISK           PIC32MZ_PBASE (0x60910)
#define TRISKCLR        PIC32MZ_PBASE (0x60914)
#define TRISKSET        PIC32MZ_PBASE (0x60918)
#define TRISKINV        PIC32MZ_PBASE (0x6091C)
#define PORTK           PIC32MZ_PBASE (0x60920)
#define PORTKCLR        PIC32MZ_PBASE (0x60924)
#define PORTKSET        PIC32MZ_PBASE (0x60928)
#define PORTKINV        PIC32MZ_PBASE (0x6092C)
#define LATK            PIC32MZ_PBASE (0x60930)
#define LATKCLR         PIC32MZ_PBASE (0x60934)
#define LATKSET         PIC32MZ_PBASE (0x60938)
#define LATKINV         PIC32MZ_PBASE (0x6093C)
#define ODCK            PIC32MZ_PBASE (0x60940)
#define ODCKCLR         PIC32MZ_PBASE (0x60944)
#define ODCKSET         PIC32MZ_PBASE (0x60948)
#define ODCKINV         PIC32MZ_PBASE (0x6094C)
#define CNPUK           PIC32MZ_PBASE (0x60950)
#define CNPUKCLR        PIC32MZ_PBASE (0x60954)
#define CNPUKSET        PIC32MZ_PBASE (0x60958)
#define CNPUKINV        PIC32MZ_PBASE (0x6095C)
#define CNPDK           PIC32MZ_PBASE (0x60960)
#define CNPDKCLR        PIC32MZ_PBASE (0x60964)
#define CNPDKSET        PIC32MZ_PBASE (0x60968)
#define CNPDKINV        PIC32MZ_PBASE (0x6096C)
#define CNCONK          PIC32MZ_PBASE (0x60970)
#define CNCONKCLR       PIC32MZ_PBASE (0x60974)
#define CNCONKSET       PIC32MZ_PBASE (0x60978)
#define CNCONKINV       PIC32MZ_PBASE (0x6097C)
#define CNENK           PIC32MZ_PBASE (0x60980)
#define CNENKCLR        PIC32MZ_PBASE (0x60984)
#define CNENKSET        PIC32MZ_PBASE (0x60988)
#define CNENKINV        PIC32MZ_PBASE (0x6098C)
#define CNSTATK         PIC32MZ_PBASE (0x60990)
#define CNSTATKCLR      PIC32MZ_PBASE (0x60994)
#define CNSTATKSET      PIC32MZ_PBASE (0x60998)
#define CNSTATKINV      PIC32MZ_PBASE (0x6099C)
#define PORTK_BASE	0xbf860910
#define PORTK_SIZE	0x8C


/* Parallel master port registers */
#define PMCON           PIC32MZ_PBASE (0x2E000)
#define PMCONCLR        PIC32MZ_PBASE (0x2E004)
#define PMCONSET        PIC32MZ_PBASE (0x2E008)
#define PMCONINV        PIC32MZ_PBASE (0x2E00C)
#define PMMODE          PIC32MZ_PBASE (0x2E010)
#define PMMODECLR       PIC32MZ_PBASE (0x2E014)
#define PMMODESET       PIC32MZ_PBASE (0x2E018)
#define PMMODEINV       PIC32MZ_PBASE (0x2E01C)
#define PMADDR          PIC32MZ_PBASE (0x2E020)
#define PMADDRCLR       PIC32MZ_PBASE (0x2E024)
#define PMADDRSET       PIC32MZ_PBASE (0x2E028)
#define PMADDRINV       PIC32MZ_PBASE (0x2E02C)
#define PMDOUT          PIC32MZ_PBASE (0x2E030)
#define PMDOUTCLR       PIC32MZ_PBASE (0x2E034)
#define PMDOUTSET       PIC32MZ_PBASE (0x2E038)
#define PMDOUTINV       PIC32MZ_PBASE (0x2E03C)
#define PMDIN           PIC32MZ_PBASE (0x2E040)
#define PMDINCLR        PIC32MZ_PBASE (0x2E044)
#define PMDINSET        PIC32MZ_PBASE (0x2E048)
#define PMDININV        PIC32MZ_PBASE (0x2E04C)
#define PMAEN           PIC32MZ_PBASE (0x2E050)
#define PMAENCLR        PIC32MZ_PBASE (0x2E054)
#define PMAENSET        PIC32MZ_PBASE (0x2E058)
#define PMAENINV        PIC32MZ_PBASE (0x2E05C)
#define PMSTAT          PIC32MZ_PBASE (0x2E060)
#define PMSTATCLR       PIC32MZ_PBASE (0x2E064)
#define PMSTATSET       PIC32MZ_PBASE (0x2E068)
#define PMSTATINV       PIC32MZ_PBASE (0x2E06C)
#define PM_BASE		0xbf82e000
#define PM_SIZE		0x6c

/* Parallel master port control register */
#define PMCON_RDSP              0x0001
#define PMCON_WRSP              0x0002
#define PMCON_CS1P              0x0008
#define PMCON_CS2P              0x0010
#define PMCON_ALP               0x0020
#define PMCON_CSF               0x00C0
#define PMCON_CSF_NONE          0x0000
#define PMCON_CSF_CS2           0x0040
#define PMCON_CSF_CS21          0x0080
#define PMCON_PTRDEN            0x0100
#define PMCON_PTWREN            0x0200
#define PMCON_PMPTTL            0x0400
#define PMCON_ADRMUX            0x1800
#define PMCON_ADRMUX_NONE       0x0000
#define PMCON_ADRMUX_AD         0x0800
#define PMCON_ADRMUX_D8         0x1000
#define PMCON_ADRMUX_D16        0x1800
#define PMCON_SIDL              0x2000
#define PMCON_FRZ               0x4000
#define PMCON_ON                0x8000

/* Parallel master port mode register */
#define PMMODE_WAITE(x)         ((x)<<0)
#define PMMODE_WAITM(x)         ((x)<<2)
#define PMMODE_WAITB(x)         ((x)<<6)
#define PMMODE_MODE             0x0300
#define PMMODE_MODE_SLAVE       0x0000
#define PMMODE_MODE_SLENH       0x0100
#define PMMODE_MODE_MAST2       0x0200
#define PMMODE_MODE_MAST1       0x0300
#define PMMODE_MODE16           0x0400
#define PMMODE_INCM             0x1800
#define PMMODE_INCM_NONE        0x0000
#define PMMODE_INCM_INC         0x0800
#define PMMODE_INCM_DEC         0x1000
#define PMMODE_INCM_SLAVE       0x1800
#define PMMODE_IRQM             0x6000
#define PMMODE_IRQM_DIS         0x0000
#define PMMODE_IRQM_END         0x2000
#define PMMODE_IRQM_A3          0x4000
#define PMMODE_BUSY             0x8000

/* Parallel master port address register */
#define PMADDR_PADDR            0x3FFF
#define PMADDR_CS1              0x4000
#define PMADDR_CS2              0x8000

/* Parallel master port status register (slave) */
#define PMSTAT_OB0E             0x0001
#define PMSTAT_OB1E             0x0002
#define PMSTAT_OB2E             0x0004
#define PMSTAT_OB3E             0x0008
#define PMSTAT_OBUF             0x0040
#define PMSTAT_OBE              0x0080
#define PMSTAT_IB0F             0x0100
#define PMSTAT_IB1F             0x0200
#define PMSTAT_IB2F             0x0400
#define PMSTAT_IB3F             0x0800
#define PMSTAT_IBOV             0x4000
#define PMSTAT_IBF              0x8000

/* UART registers */
#define U1MODE          PIC32MZ_PBASE (0x22000)
#define U1MODECLR       PIC32MZ_PBASE (0x22004)
#define U1MODESET       PIC32MZ_PBASE (0x22008)
#define U1MODEINV       PIC32MZ_PBASE (0x2200C)
#define U1STA           PIC32MZ_PBASE (0x22010)
#define U1STACLR        PIC32MZ_PBASE (0x22014)
#define U1STASET        PIC32MZ_PBASE (0x22018)
#define U1STAINV        PIC32MZ_PBASE (0x2201C)
#define U1TXREG         PIC32MZ_PBASE (0x22020)
#define U1RXREG         PIC32MZ_PBASE (0x22030)
#define U1BRG           PIC32MZ_PBASE (0x22040)
#define U1BRGCLR        PIC32MZ_PBASE (0x22044)
#define U1BRGSET        PIC32MZ_PBASE (0x22048)
#define U1BRGINV        PIC32MZ_PBASE (0x2204C)
#define UART1_BASE	0xbf822000
#define UART1_SIZE	0x4c

#define U2MODE          PIC32MZ_PBASE (0x22200)
#define U2MODECLR       PIC32MZ_PBASE (0x22204)
#define U2MODESET       PIC32MZ_PBASE (0x22208)
#define U2MODEINV       PIC32MZ_PBASE (0x2220C)
#define U2STA           PIC32MZ_PBASE (0x22210)
#define U2STACLR        PIC32MZ_PBASE (0x22214)
#define U2STASET        PIC32MZ_PBASE (0x22218)
#define U2STAINV        PIC32MZ_PBASE (0x2221C)
#define U2TXREG         PIC32MZ_PBASE (0x22220)
#define U2RXREG         PIC32MZ_PBASE (0x22230)
#define U2BRG           PIC32MZ_PBASE (0x22240)
#define U2BRGCLR        PIC32MZ_PBASE (0x22244)
#define U2BRGSET        PIC32MZ_PBASE (0x22248)
#define U2BRGINV        PIC32MZ_PBASE (0x2224C)
#define UART2_BASE	0xbf822200
#define UART2_SIZE	0x4c

#define U3MODE          PIC32MZ_PBASE (0x22400)
#define U3MODECLR       PIC32MZ_PBASE (0x22404)
#define U3MODESET       PIC32MZ_PBASE (0x22408)
#define U3MODEINV       PIC32MZ_PBASE (0x2240C)
#define U3STA           PIC32MZ_PBASE (0x22410)
#define U3STACLR        PIC32MZ_PBASE (0x22414)
#define U3STASET        PIC32MZ_PBASE (0x22418)
#define U3STAINV        PIC32MZ_PBASE (0x2241C)
#define U3TXREG         PIC32MZ_PBASE (0x22420)
#define U3RXREG         PIC32MZ_PBASE (0x22430)
#define U3BRG           PIC32MZ_PBASE (0x22440)
#define U3BRGCLR        PIC32MZ_PBASE (0x22444)
#define U3BRGSET        PIC32MZ_PBASE (0x22448)
#define U3BRGINV        PIC32MZ_PBASE (0x2244C)
#define UART3_BASE	0xbf822400
#define UART3_SIZE	0x4c

#define U4MODE          PIC32MZ_PBASE (0x22600)
#define U4MODECLR       PIC32MZ_PBASE (0x22604)
#define U4MODESET       PIC32MZ_PBASE (0x22608)
#define U4MODEINV       PIC32MZ_PBASE (0x2260C)
#define U4STA           PIC32MZ_PBASE (0x22610)
#define U4STACLR        PIC32MZ_PBASE (0x22614)
#define U4STASET        PIC32MZ_PBASE (0x22618)
#define U4STAINV        PIC32MZ_PBASE (0x2261C)
#define U4TXREG         PIC32MZ_PBASE (0x22620)
#define U4RXREG         PIC32MZ_PBASE (0x22630)
#define U4BRG           PIC32MZ_PBASE (0x22640)
#define U4BRGCLR        PIC32MZ_PBASE (0x22644)
#define U4BRGSET        PIC32MZ_PBASE (0x22648)
#define U4BRGINV        PIC32MZ_PBASE (0x2264C)
#define UART4_BASE	0xbf822600
#define UART4_SIZE	0x4c

#define U5MODE          PIC32MZ_PBASE (0x22800)
#define U5MODECLR       PIC32MZ_PBASE (0x22804)
#define U5MODESET       PIC32MZ_PBASE (0x22808)
#define U5MODEINV       PIC32MZ_PBASE (0x2280C)
#define U5STA           PIC32MZ_PBASE (0x22810)
#define U5STACLR        PIC32MZ_PBASE (0x22814)
#define U5STASET        PIC32MZ_PBASE (0x22818)
#define U5STAINV        PIC32MZ_PBASE (0x2281C)
#define U5TXREG         PIC32MZ_PBASE (0x22820)
#define U5RXREG         PIC32MZ_PBASE (0x22830)
#define U5BRG           PIC32MZ_PBASE (0x22840)
#define U5BRGCLR        PIC32MZ_PBASE (0x22844)
#define U5BRGSET        PIC32MZ_PBASE (0x22848)
#define U5BRGINV        PIC32MZ_PBASE (0x2284C)
#define UART5_BASE	0xbf822800
#define UART5_SIZE	0x4c

#define U6MODE          PIC32MZ_PBASE (0x22A00)
#define U6MODECLR       PIC32MZ_PBASE (0x22A04)
#define U6MODESET       PIC32MZ_PBASE (0x22A08)
#define U6MODEINV       PIC32MZ_PBASE (0x22A0C)
#define U6STA           PIC32MZ_PBASE (0x22A10)
#define U6STACLR        PIC32MZ_PBASE (0x22A14)
#define U6STASET        PIC32MZ_PBASE (0x22A18)
#define U6STAINV        PIC32MZ_PBASE (0x22A1C)
#define U6TXREG         PIC32MZ_PBASE (0x22A20)
#define U6RXREG         PIC32MZ_PBASE (0x22A30)
#define U6BRG           PIC32MZ_PBASE (0x22A40)
#define U6BRGCLR        PIC32MZ_PBASE (0x22A44)
#define U6BRGSET        PIC32MZ_PBASE (0x22A48)
#define U6BRGINV        PIC32MZ_PBASE (0x22A4C)
#define UART6_BASE	0xbf822A00
#define UART6_SIZE	0x4c


/* UART mode register */
#define UMODE_STSEL             0x0001
#define UMODE_PDSEL             0x0006
#define UMODE_PDSEL_8NPAR       0x0000
#define UMODE_PDSEL_8EVEN       0x0002
#define UMODE_PDSEL_8ODD        0x0004
#define UMODE_PDSEL_9NPAR       0x0006
#define UMODE_BRGH              0x0008
#define UMODE_RXINV             0x0010
#define UMODE_ABAUD             0x0020
#define UMODE_LPBACK            0x0040
#define UMODE_WAKE              0x0080
#define UMODE_UEN               0x0300
#define UMODE_UEN_RTS           0x0100
#define UMODE_UEN_RTSCTS        0x0200
#define UMODE_UEN_BCLK          0x0300
#define UMODE_RTSMD             0x0800
#define UMODE_IREN              0x1000
#define UMODE_SIDL              0x2000
#define UMODE_FRZ               0x4000
#define UMODE_ON                0x8000

/* UART control and status registers */
#define USTA_URXDA              0x00000001
#define USTA_OERR               0x00000002
#define USTA_FERR               0x00000004
#define USTA_PERR               0x00000008
#define USTA_RIDLE              0x00000010
#define USTA_ADDEN              0x00000020
#define USTA_URXISEL            0x000000C0
#define USTA_URXISEL_NEMP       0x00000000
#define USTA_URXISEL_HALF       0x00000040
#define USTA_URXISEL_3_4        0x00000080
#define USTA_TRMT               0x00000100
#define USTA_UTXBF              0x00000200
#define USTA_UTXEN              0x00000400
#define USTA_UTXBRK             0x00000800
#define USTA_URXEN              0x00001000
#define USTA_UTXINV             0x00002000
#define USTA_UTXISEL            0x0000C000
#define USTA_UTXISEL_1          0x00000000
#define USTA_UTXISEL_ALL        0x00004000
#define USTA_UTXISEL_EMP        0x00008000
#define USTA_ADDR               0x00FF0000
#define USTA_ADM_EN             0x01000000

#define BRG_BAUD(fr,bd) ((((fr)/8 + (bd)) / (bd) / 2) - 1)

/* Peripheral port select registers */
#define INT1R           PIC32MZ_PBASE (0x1404)
#define INT2R           PIC32MZ_PBASE (0x1408)
#define INT3R           PIC32MZ_PBASE (0x140C)
#define INT4R           PIC32MZ_PBASE (0x1410)
#define T2CKR           PIC32MZ_PBASE (0x1418)
#define T3CKR           PIC32MZ_PBASE (0x141C)
#define T4CKR           PIC32MZ_PBASE (0x1420)
#define T5CKR           PIC32MZ_PBASE (0x1424)
#define T6CKR           PIC32MZ_PBASE (0x1428)
#define T7CKR           PIC32MZ_PBASE (0x142C)
#define T8CKR           PIC32MZ_PBASE (0x1430)
#define T9CKR           PIC32MZ_PBASE (0x1434)
#define IC1R            PIC32MZ_PBASE (0x1438)
#define IC2R            PIC32MZ_PBASE (0x143C)
#define IC3R            PIC32MZ_PBASE (0x1440)
#define IC4R            PIC32MZ_PBASE (0x1444)
#define IC5R            PIC32MZ_PBASE (0x1448)
#define IC6R            PIC32MZ_PBASE (0x144C)
#define IC7R            PIC32MZ_PBASE (0x1450)
#define IC8R            PIC32MZ_PBASE (0x1454)
#define IC9R            PIC32MZ_PBASE (0x1458)
#define OCFAR           PIC32MZ_PBASE (0x1460)
#define U1RXR           PIC32MZ_PBASE (0x1468)
#define U1CTSR          PIC32MZ_PBASE (0x146C)
#define U2RXR           PIC32MZ_PBASE (0x1470)
#define U2CTSR          PIC32MZ_PBASE (0x1474)
#define U3RXR           PIC32MZ_PBASE (0x1478)
#define U3CTSR          PIC32MZ_PBASE (0x147C)
#define U4RXR           PIC32MZ_PBASE (0x1480)
#define U4CTSR          PIC32MZ_PBASE (0x1484)
#define U5RXR           PIC32MZ_PBASE (0x1488)
#define U5CTSR          PIC32MZ_PBASE (0x148C)
#define U6RXR           PIC32MZ_PBASE (0x1490)
#define U6CTSR          PIC32MZ_PBASE (0x1494)
#define SDI1R           PIC32MZ_PBASE (0x149C)
#define SS1R            PIC32MZ_PBASE (0x14A0)
#define SDI2R           PIC32MZ_PBASE (0x14A8)
#define SS2R            PIC32MZ_PBASE (0x14AC)
#define SDI3R           PIC32MZ_PBASE (0x14B4)
#define SS3R            PIC32MZ_PBASE (0x14B8)
#define SDI4R           PIC32MZ_PBASE (0x14C0)
#define SS4R            PIC32MZ_PBASE (0x14C4)
#define SDI5R           PIC32MZ_PBASE (0x14CC)
#define SS5R            PIC32MZ_PBASE (0x14D0)
#define SDI6R           PIC32MZ_PBASE (0x14D8)
#define SS6R            PIC32MZ_PBASE (0x14DC)
#define C1RXR           PIC32MZ_PBASE (0x14E0)
#define C2RXR           PIC32MZ_PBASE (0x14E4)
#define REFCLKI1R       PIC32MZ_PBASE (0x14E8)
#define REFCLKI3R       PIC32MZ_PBASE (0x14F0)
#define REFCLKI4R       PIC32MZ_PBASE (0x14F4)
#define RPA14R          PIC32MZ_PBASE (0x1538)
#define RPA15R          PIC32MZ_PBASE (0x153C)
#define RPB0R           PIC32MZ_PBASE (0x1540)
#define RPB1R           PIC32MZ_PBASE (0x1544)
#define RPB2R           PIC32MZ_PBASE (0x1548)
#define RPB3R           PIC32MZ_PBASE (0x154C)
#define RPB5R           PIC32MZ_PBASE (0x1554)
#define RPB6R           PIC32MZ_PBASE (0x1558)
#define RPB7R           PIC32MZ_PBASE (0x155C)
#define RPB8R           PIC32MZ_PBASE (0x1560)
#define RPB9R           PIC32MZ_PBASE (0x1564)
#define RPB10R          PIC32MZ_PBASE (0x1568)
#define RPB14R          PIC32MZ_PBASE (0x1578)
#define RPB15R          PIC32MZ_PBASE (0x157C)
#define RPC1R           PIC32MZ_PBASE (0x1584)
#define RPC2R           PIC32MZ_PBASE (0x1588)
#define RPC3R           PIC32MZ_PBASE (0x158C)
#define RPC4R           PIC32MZ_PBASE (0x1590)
#define RPC13R          PIC32MZ_PBASE (0x15B4)
#define RPC14R          PIC32MZ_PBASE (0x15B8)
#define RPD0R           PIC32MZ_PBASE (0x15C0)
#define RPD1R           PIC32MZ_PBASE (0x15C4)
#define RPD2R           PIC32MZ_PBASE (0x15C8)
#define RPD3R           PIC32MZ_PBASE (0x15CC)
#define RPD4R           PIC32MZ_PBASE (0x15D0)
#define RPD5R           PIC32MZ_PBASE (0x15D4)
#define RPD6R           PIC32MZ_PBASE (0x15D8)
#define RPD7R           PIC32MZ_PBASE (0x15DC)
#define RPD9R           PIC32MZ_PBASE (0x15E4)
#define RPD10R          PIC32MZ_PBASE (0x15E8)
#define RPD11R          PIC32MZ_PBASE (0x15EC)
#define RPD12R          PIC32MZ_PBASE (0x15F0)
#define RPD14R          PIC32MZ_PBASE (0x15F8)
#define RPD15R          PIC32MZ_PBASE (0x15FC)
#define RPE3R           PIC32MZ_PBASE (0x160C)
#define RPE5R           PIC32MZ_PBASE (0x1614)
#define RPE8R           PIC32MZ_PBASE (0x1620)
#define RPE9R           PIC32MZ_PBASE (0x1624)
#define RPF0R           PIC32MZ_PBASE (0x1640)
#define RPF1R           PIC32MZ_PBASE (0x1644)
#define RPF2R           PIC32MZ_PBASE (0x1648)
#define RPF3R           PIC32MZ_PBASE (0x164C)
#define RPF4R           PIC32MZ_PBASE (0x1650)
#define RPF5R           PIC32MZ_PBASE (0x1654)
#define RPF8R           PIC32MZ_PBASE (0x1660)
#define RPF12R          PIC32MZ_PBASE (0x1670)
#define RPF13R          PIC32MZ_PBASE (0x1674)
#define RPG0R           PIC32MZ_PBASE (0x1680)
#define RPG1R           PIC32MZ_PBASE (0x1684)
#define RPG6R           PIC32MZ_PBASE (0x1698)
#define RPG7R           PIC32MZ_PBASE (0x169C)
#define RPG8R           PIC32MZ_PBASE (0x16A0)
#define RPG9R           PIC32MZ_PBASE (0x16A4)

/* Prefetch cache controller registers */
#define PRECON          PIC32MZ_PBASE (0xe0000)
#define PRECONCLR       PIC32MZ_PBASE (0xe0004)
#define PRECONSET       PIC32MZ_PBASE (0xe0008)
#define PRECONINV       PIC32MZ_PBASE (0xe000C)
#define PRESTAT         PIC32MZ_PBASE (0xe0010)
#define PRESTATCLR      PIC32MZ_PBASE (0xe0014)
#define PRESTATSET      PIC32MZ_PBASE (0xe0018)
#define PRESTATINV      PIC32MZ_PBASE (0xe001C)

/* System controller registers */
#define CFGCON          PIC32MZ_PBASE (0x0000)
#define DEVID           PIC32MZ_PBASE (0x0020)
#define SYSKEY          PIC32MZ_PBASE (0x0030)
#define CFGEBIA         PIC32MZ_PBASE (0x00c0)
#define CFGEBIACLR      PIC32MZ_PBASE (0x00c4)
#define CFGEBIASET      PIC32MZ_PBASE (0x00c8)
#define CFGEBIAINV      PIC32MZ_PBASE (0x00cc)
#define CFGEBIC         PIC32MZ_PBASE (0x00d0)
#define CFGEBICCLR      PIC32MZ_PBASE (0x00d4)
#define CFGEBICSET      PIC32MZ_PBASE (0x00d8)
#define CFGEBICINV      PIC32MZ_PBASE (0x00dc)
#define CFGPG           PIC32MZ_PBASE (0x00e0)
#define OSCCON          PIC32MZ_PBASE (0x1200)
#define OSCTUN          PIC32MZ_PBASE (0x1210)
#define SPLLCON         PIC32MZ_PBASE (0x1220)
#define RCON            PIC32MZ_PBASE (0x1240)
#define RSWRST          PIC32MZ_PBASE (0x1250)
#define RNMICON         PIC32MZ_PBASE (0x1260)
#define PWRCON          PIC32MZ_PBASE (0x1270)
#define REFO1CON        PIC32MZ_PBASE (0x1280)
#define REFO1TRIM       PIC32MZ_PBASE (0x1290)
#define REFO2CON        PIC32MZ_PBASE (0x12A0)
#define REFO2TRIM       PIC32MZ_PBASE (0x12B0)
#define REFO3CON        PIC32MZ_PBASE (0x12C0)
#define REFO3TRIM       PIC32MZ_PBASE (0x12D0)
#define REFO4CON        PIC32MZ_PBASE (0x12E0)
#define REFO4TRIM       PIC32MZ_PBASE (0x12F0)
#define PB1DIV          PIC32MZ_PBASE (0x1300)
#define PB2DIV          PIC32MZ_PBASE (0x1310)
#define PB3DIV          PIC32MZ_PBASE (0x1320)
#define PB4DIV          PIC32MZ_PBASE (0x1330)
#define PB5DIV          PIC32MZ_PBASE (0x1340)
#define PB7DIV          PIC32MZ_PBASE (0x1360)
#define PB8DIV          PIC32MZ_PBASE (0x1370)

/* Configuration control register */
#define CFGCON_DMAPRI           0x02000000
#define CFGCON_CPUPRI           0x01000000
#define CFGCON_ICACLK           0x00020000
#define CFGCON_OCACLK           0x00010000
#define CFGCON_IOLOCK           0x00002000
#define CFGCON_PMDLOCK          0x00001000
#define CFGCON_PGLOCK           0x00000800
#define CFGCON_USBSSEN          0x00000100
#define CFGCON_ECC_MASK         0x00000030
#define CFGCON_ECC_DISWR        0x00000030
#define CFGCON_ECC_DISRO        0x00000020
#define CFGCON_ECC_DYN          0x00000010
#define CFGCON_ECC_EN           0x00000000
#define CFGCON_JTAGEN           0x00000008
#define CFGCON_TROEN            0x00000004
#define CFGCON_TDOEN            0x00000001

/* A/D converter registers */
#define AD1CON1         PIC32MZ_PBASE (0x4b000)
#define AD1CON2         PIC32MZ_PBASE (0x4b004)
#define AD1CON3         PIC32MZ_PBASE (0x4b008)
#define AD1IMOD         PIC32MZ_PBASE (0x4b00c)
#define AD1GIRQEN1      PIC32MZ_PBASE (0x4b010)
#define AD1GIRQEN2      PIC32MZ_PBASE (0x4b014)
#define AD1CSS1         PIC32MZ_PBASE (0x4b018)
#define AD1CSS2         PIC32MZ_PBASE (0x4b01c)
#define AD1DSTAT1       PIC32MZ_PBASE (0x4b020)
#define AD1DSTAT2       PIC32MZ_PBASE (0x4b024)
#define AD1CMPEN1       PIC32MZ_PBASE (0x4b028)
#define AD1CMP1         PIC32MZ_PBASE (0x4b02c)
#define AD1CMPEN2       PIC32MZ_PBASE (0x4b030)
#define AD1CMP2         PIC32MZ_PBASE (0x4b034)
#define AD1CMPEN3       PIC32MZ_PBASE (0x4b038)
#define AD1CMP3         PIC32MZ_PBASE (0x4b03c)
#define AD1CMPEN4       PIC32MZ_PBASE (0x4b040)
#define AD1CMP4         PIC32MZ_PBASE (0x4b044)
#define AD1CMPEN5       PIC32MZ_PBASE (0x4b048)
#define AD1CMP5         PIC32MZ_PBASE (0x4b04c)
#define AD1CMPEN6       PIC32MZ_PBASE (0x4b050)
#define AD1CMP6         PIC32MZ_PBASE (0x4b054)
#define AD1FLTR1        PIC32MZ_PBASE (0x4b058)
#define AD1FLTR2        PIC32MZ_PBASE (0x4b05c)
#define AD1FLTR3        PIC32MZ_PBASE (0x4b060)
#define AD1FLTR4        PIC32MZ_PBASE (0x4b064)
#define AD1FLTR5        PIC32MZ_PBASE (0x4b068)
#define AD1FLTR6        PIC32MZ_PBASE (0x4b06c)
#define AD1TRG1         PIC32MZ_PBASE (0x4b070)
#define AD1TRG2         PIC32MZ_PBASE (0x4b074)
#define AD1TRG3         PIC32MZ_PBASE (0x4b078)
#define AD1CMPCON1      PIC32MZ_PBASE (0x4b090)
#define AD1CMPCON2      PIC32MZ_PBASE (0x4b094)
#define AD1CMPCON3      PIC32MZ_PBASE (0x4b098)
#define AD1CMPCON4      PIC32MZ_PBASE (0x4b09c)
#define AD1CMPCON5      PIC32MZ_PBASE (0x4b0a0)
#define AD1CMPCON6      PIC32MZ_PBASE (0x4b0a4)
#define AD1DATA0        PIC32MZ_PBASE (0x4b0b8)
#define AD1DATA1        PIC32MZ_PBASE (0x4b0bc)
#define AD1DATA2        PIC32MZ_PBASE (0x4b0c0)
#define AD1DATA3        PIC32MZ_PBASE (0x4b0c4)
#define AD1DATA4        PIC32MZ_PBASE (0x4b0c8)
#define AD1DATA5        PIC32MZ_PBASE (0x4b0cc)
#define AD1DATA6        PIC32MZ_PBASE (0x4b0d0)
#define AD1DATA7        PIC32MZ_PBASE (0x4b0d4)
#define AD1DATA8        PIC32MZ_PBASE (0x4b0d8)
#define AD1DATA9        PIC32MZ_PBASE (0x4b0dc)
#define AD1DATA10       PIC32MZ_PBASE (0x4b0e0)
#define AD1DATA11       PIC32MZ_PBASE (0x4b0e4)
#define AD1DATA12       PIC32MZ_PBASE (0x4b0e8)
#define AD1DATA13       PIC32MZ_PBASE (0x4b0ec)
#define AD1DATA14       PIC32MZ_PBASE (0x4b0f0)
#define AD1DATA15       PIC32MZ_PBASE (0x4b0f4)
#define AD1DATA16       PIC32MZ_PBASE (0x4b0f8)
#define AD1DATA17       PIC32MZ_PBASE (0x4b0fc)
#define AD1DATA18       PIC32MZ_PBASE (0x4b100)
#define AD1DATA19       PIC32MZ_PBASE (0x4b104)
#define AD1DATA20       PIC32MZ_PBASE (0x4b108)
#define AD1DATA21       PIC32MZ_PBASE (0x4b10c)
#define AD1DATA22       PIC32MZ_PBASE (0x4b110)
#define AD1DATA23       PIC32MZ_PBASE (0x4b114)
#define AD1DATA24       PIC32MZ_PBASE (0x4b118)
#define AD1DATA25       PIC32MZ_PBASE (0x4b11c)
#define AD1DATA26       PIC32MZ_PBASE (0x4b120)
#define AD1DATA27       PIC32MZ_PBASE (0x4b124)
#define AD1DATA28       PIC32MZ_PBASE (0x4b128)
#define AD1DATA29       PIC32MZ_PBASE (0x4b12c)
#define AD1DATA30       PIC32MZ_PBASE (0x4b130)
#define AD1DATA31       PIC32MZ_PBASE (0x4b134)
#define AD1DATA32       PIC32MZ_PBASE (0x4b138)
#define AD1DATA33       PIC32MZ_PBASE (0x4b13c)
#define AD1DATA34       PIC32MZ_PBASE (0x4b140)
#define AD1DATA35       PIC32MZ_PBASE (0x4b144)
#define AD1DATA36       PIC32MZ_PBASE (0x4b148)
#define AD1DATA37       PIC32MZ_PBASE (0x4b14c)
#define AD1DATA38       PIC32MZ_PBASE (0x4b150)
#define AD1DATA39       PIC32MZ_PBASE (0x4b154)
#define AD1DATA40       PIC32MZ_PBASE (0x4b158)
#define AD1DATA41       PIC32MZ_PBASE (0x4b15c)
#define AD1DATA42       PIC32MZ_PBASE (0x4b160)
#define AD1DATA43       PIC32MZ_PBASE (0x4b164)
#define AD1DATA44       PIC32MZ_PBASE (0x4b168)
#define AD1CAL1         PIC32MZ_PBASE (0x4b200)
#define AD1CAL2         PIC32MZ_PBASE (0x4b204)
#define AD1CAL3         PIC32MZ_PBASE (0x4b208)
#define AD1CAL4         PIC32MZ_PBASE (0x4b20c)
#define AD1CAL5         PIC32MZ_PBASE (0x4b210)
#define AD1_BASE	0xbf84b000
#define AD1_SIZE	0x210

/* SPI registers */
#define SPI1CON         PIC32MZ_PBASE (0x21000)
#define SPI1CONCLR      PIC32MZ_PBASE (0x21004)
#define SPI1CONSET      PIC32MZ_PBASE (0x21008)
#define SPI1CONINV      PIC32MZ_PBASE (0x2100c)
#define SPI1STAT        PIC32MZ_PBASE (0x21010)
#define SPI1STATCLR     PIC32MZ_PBASE (0x21014)
#define SPI1STATSET     PIC32MZ_PBASE (0x21018)
#define SPI1STATINV     PIC32MZ_PBASE (0x2101c)
#define SPI1BUF         PIC32MZ_PBASE (0x21020)
#define SPI1BRG         PIC32MZ_PBASE (0x21030)
#define SPI1BRGCLR      PIC32MZ_PBASE (0x21034)
#define SPI1BRGSET      PIC32MZ_PBASE (0x21038)
#define SPI1BRGINV      PIC32MZ_PBASE (0x2103c)
#define SPI1CON2        PIC32MZ_PBASE (0x21040)
#define SPI1CON2CLR     PIC32MZ_PBASE (0x21044)
#define SPI1CON2SET     PIC32MZ_PBASE (0x21048)
#define SPI1CON2INV     PIC32MZ_PBASE (0x2104c)
#define SPI1_BASE	0xbf821000
#define SPI1_SIZE	0x4c

#define SPI2CON         PIC32MZ_PBASE (0x21200)
#define SPI2CONCLR      PIC32MZ_PBASE (0x21204)
#define SPI2CONSET      PIC32MZ_PBASE (0x21208)
#define SPI2CONINV      PIC32MZ_PBASE (0x2120c)
#define SPI2STAT        PIC32MZ_PBASE (0x21210)
#define SPI2STATCLR     PIC32MZ_PBASE (0x21214)
#define SPI2STATSET     PIC32MZ_PBASE (0x21218)
#define SPI2STATINV     PIC32MZ_PBASE (0x2121c)
#define SPI2BUF         PIC32MZ_PBASE (0x21220)
#define SPI2BRG         PIC32MZ_PBASE (0x21230)
#define SPI2BRGCLR      PIC32MZ_PBASE (0x21234)
#define SPI2BRGSET      PIC32MZ_PBASE (0x21238)
#define SPI2BRGINV      PIC32MZ_PBASE (0x2123c)
#define SPI2CON2        PIC32MZ_PBASE (0x21240)
#define SPI2CON2CLR     PIC32MZ_PBASE (0x21244)
#define SPI2CON2SET     PIC32MZ_PBASE (0x21248)
#define SPI2CON2INV     PIC32MZ_PBASE (0x2124c)
#define SPI2_BASE	0xbf821200
#define SPI2_SIZE	0x4c


#define SPI3CON         PIC32MZ_PBASE (0x21400)
#define SPI3CONCLR      PIC32MZ_PBASE (0x21404)
#define SPI3CONSET      PIC32MZ_PBASE (0x21408)
#define SPI3CONINV      PIC32MZ_PBASE (0x2140c)
#define SPI3STAT        PIC32MZ_PBASE (0x21410)
#define SPI3STATCLR     PIC32MZ_PBASE (0x21414)
#define SPI3STATSET     PIC32MZ_PBASE (0x21418)
#define SPI3STATINV     PIC32MZ_PBASE (0x2141c)
#define SPI3BUF         PIC32MZ_PBASE (0x21420)
#define SPI3BRG         PIC32MZ_PBASE (0x21430)
#define SPI3BRGCLR      PIC32MZ_PBASE (0x21434)
#define SPI3BRGSET      PIC32MZ_PBASE (0x21438)
#define SPI3BRGINV      PIC32MZ_PBASE (0x2143c)
#define SPI3CON2        PIC32MZ_PBASE (0x21440)
#define SPI3CON2CLR     PIC32MZ_PBASE (0x21444)
#define SPI3CON2SET     PIC32MZ_PBASE (0x21448)
#define SPI3CON2INV     PIC32MZ_PBASE (0x2144c)
#define SPI3_BASE	0xbf821400
#define SPI3_SIZE	0x4c


#define SPI4CON         PIC32MZ_PBASE (0x21600)
#define SPI4CONCLR      PIC32MZ_PBASE (0x21604)
#define SPI4CONSET      PIC32MZ_PBASE (0x21608)
#define SPI4CONINV      PIC32MZ_PBASE (0x2160c)
#define SPI4STAT        PIC32MZ_PBASE (0x21610)
#define SPI4STATCLR     PIC32MZ_PBASE (0x21614)
#define SPI4STATSET     PIC32MZ_PBASE (0x21618)
#define SPI4STATINV     PIC32MZ_PBASE (0x2161c)
#define SPI4BUF         PIC32MZ_PBASE (0x21620)
#define SPI4BRG         PIC32MZ_PBASE (0x21630)
#define SPI4BRGCLR      PIC32MZ_PBASE (0x21634)
#define SPI4BRGSET      PIC32MZ_PBASE (0x21638)
#define SPI4BRGINV      PIC32MZ_PBASE (0x2163c)
#define SPI4CON2        PIC32MZ_PBASE (0x21640)
#define SPI4CON2CLR     PIC32MZ_PBASE (0x21644)
#define SPI4CON2SET     PIC32MZ_PBASE (0x21648)
#define SPI4CON2INV     PIC32MZ_PBASE (0x2164c)
#define SPI4_BASE	0xbf821600
#define SPI4_SIZE	0x4c


#define SPI5CON         PIC32MZ_PBASE (0x21800)
#define SPI5CONCLR      PIC32MZ_PBASE (0x21804)
#define SPI5CONSET      PIC32MZ_PBASE (0x21808)
#define SPI5CONINV      PIC32MZ_PBASE (0x2180c)
#define SPI5STAT        PIC32MZ_PBASE (0x21810)
#define SPI5STATCLR     PIC32MZ_PBASE (0x21814)
#define SPI5STATSET     PIC32MZ_PBASE (0x21818)
#define SPI5STATINV     PIC32MZ_PBASE (0x2181c)
#define SPI5BUF         PIC32MZ_PBASE (0x21820)
#define SPI5BRG         PIC32MZ_PBASE (0x21830)
#define SPI5BRGCLR      PIC32MZ_PBASE (0x21834)
#define SPI5BRGSET      PIC32MZ_PBASE (0x21838)
#define SPI5BRGINV      PIC32MZ_PBASE (0x2183c)
#define SPI5CON2        PIC32MZ_PBASE (0x21840)
#define SPI5CON2CLR     PIC32MZ_PBASE (0x21844)
#define SPI5CON2SET     PIC32MZ_PBASE (0x21848)
#define SPI5CON2INV     PIC32MZ_PBASE (0x2184c)
#define SPI5_BASE	0xbf821800
#define SPI5_SIZE	0x4c

#define SPI6CON         PIC32MZ_PBASE (0x21a00)
#define SPI6CONCLR      PIC32MZ_PBASE (0x21a04)
#define SPI6CONSET      PIC32MZ_PBASE (0x21a08)
#define SPI6CONINV      PIC32MZ_PBASE (0x21a0c)
#define SPI6STAT        PIC32MZ_PBASE (0x21a10)
#define SPI6STATCLR     PIC32MZ_PBASE (0x21a14)
#define SPI6STATSET     PIC32MZ_PBASE (0x21a18)
#define SPI6STATINV     PIC32MZ_PBASE (0x21a1c)
#define SPI6BUF         PIC32MZ_PBASE (0x21a20)
#define SPI6BRG         PIC32MZ_PBASE (0x21a30)
#define SPI6BRGCLR      PIC32MZ_PBASE (0x21a34)
#define SPI6BRGSET      PIC32MZ_PBASE (0x21a38)
#define SPI6BRGINV      PIC32MZ_PBASE (0x21a3c)
#define SPI6CON2        PIC32MZ_PBASE (0x21a40)
#define SPI6CON2CLR     PIC32MZ_PBASE (0x21a44)
#define SPI6CON2SET     PIC32MZ_PBASE (0x21a48)
#define SPI6CON2INV     PIC32MZ_PBASE (0x21a4c)
#define SPI6_BASE	0xbf821a00
#define SPI6_SIZE	0x4c


/* SPI control register */
#define SPICON_MSTEN            0x00000020
#define SPICON_CKP              0x00000040
#define SPICON_SSEN             0x00000080
#define SPICON_CKE              0x00000100
#define SPICON_SMP              0x00000200
#define SPICON_MODE16           0x00000400
#define SPICON_MODE32           0x00000800
#define SPICON_DISSDO           0x00001000
#define SPICON_SIDL             0x00002000
#define SPICON_FRZ              0x00004000
#define SPICON_ON               0x00008000
#define SPICON_ENHBUF           0x00010000
#define SPICON_SPIFE            0x00020000
#define SPICON_FRMPOL           0x20000000
#define SPICON_FRMSYNC          0x40000000
#define SPICON_FRMEN            0x80000000

/* SPI status register */
#define SPISTAT_SPIRBF          0x00000001
#define SPISTAT_SPITBF          0x00000002
#define SPISTAT_SPITBE          0x00000008
#define SPISTAT_SPIRBE          0x00000020
#define SPISTAT_SPIROV          0x00000040
#define SPISTAT_SPIBUSY         0x00000800

/* System bus registers */
#define SBFLAG          PIC32MZ_PBASE (0xF0510)
#define SBT0ELOG1       PIC32MZ_PBASE (0xF8020)
#define SBT0ELOG2       PIC32MZ_PBASE (0xF8024)
#define SBT0ECON        PIC32MZ_PBASE (0xF8028)
#define SBT0ECLRS       PIC32MZ_PBASE (0xF8030)
#define SBT0ECLRM       PIC32MZ_PBASE (0xF8038)
#define SBT0REG0        PIC32MZ_PBASE (0xF8040)
#define SBT0RD0         PIC32MZ_PBASE (0xF8050)
#define SBT0WR0         PIC32MZ_PBASE (0xF8058)
#define SBT0REG1        PIC32MZ_PBASE (0xF8060)
#define SBT0RD1         PIC32MZ_PBASE (0xF8070)
#define SBT0WR1         PIC32MZ_PBASE (0xF8078)
#define SBT1ELOG1       PIC32MZ_PBASE (0xF8420)
#define SBT1ELOG2       PIC32MZ_PBASE (0xF8424)
#define SBT1ECON        PIC32MZ_PBASE (0xF8428)
#define SBT1ECLRS       PIC32MZ_PBASE (0xF8430)
#define SBT1ECLRM       PIC32MZ_PBASE (0xF8438)
#define SBT1REG0        PIC32MZ_PBASE (0xF8440)
#define SBT1RD0         PIC32MZ_PBASE (0xF8450)
#define SBT1WR0         PIC32MZ_PBASE (0xF8458)
#define SBT1REG2        PIC32MZ_PBASE (0xF8480)
#define SBT1RD2         PIC32MZ_PBASE (0xF8490)
#define SBT1WR2         PIC32MZ_PBASE (0xF8498)
#define SBT1REG3        PIC32MZ_PBASE (0xF84A0)
#define SBT1RD3         PIC32MZ_PBASE (0xF84B0)
#define SBT1WR3         PIC32MZ_PBASE (0xF84B8)
#define SBT1REG4        PIC32MZ_PBASE (0xF84C0)
#define SBT1RD4         PIC32MZ_PBASE (0xF84D0)
#define SBT1WR4         PIC32MZ_PBASE (0xF84D8)
#define SBT1REG5        PIC32MZ_PBASE (0xF84E0)
#define SBT1RD5         PIC32MZ_PBASE (0xF84F0)
#define SBT1WR5         PIC32MZ_PBASE (0xF84F8)
#define SBT1REG6        PIC32MZ_PBASE (0xF8500)
#define SBT1RD6         PIC32MZ_PBASE (0xF8510)
#define SBT1WR6         PIC32MZ_PBASE (0xF8518)
#define SBT1REG7        PIC32MZ_PBASE (0xF8520)
#define SBT1RD7         PIC32MZ_PBASE (0xF8530)
#define SBT1WR7         PIC32MZ_PBASE (0xF8538)
#define SBT1REG8        PIC32MZ_PBASE (0xF8540)
#define SBT1RD8         PIC32MZ_PBASE (0xF8550)
#define SBT1WR8         PIC32MZ_PBASE (0xF8558)
#define SBT2ELOG1       PIC32MZ_PBASE (0xF8820)
#define SBT2ELOG2       PIC32MZ_PBASE (0xF8824)
#define SBT2ECON        PIC32MZ_PBASE (0xF8828)
#define SBT2ECLRS       PIC32MZ_PBASE (0xF8830)
#define SBT2ECLRM       PIC32MZ_PBASE (0xF8838)
#define SBT2REG0        PIC32MZ_PBASE (0xF8840)
#define SBT2RD0         PIC32MZ_PBASE (0xF8850)
#define SBT2WR0         PIC32MZ_PBASE (0xF8858)
#define SBT2REG1        PIC32MZ_PBASE (0xF8860)
#define SBT2RD1         PIC32MZ_PBASE (0xF8870)
#define SBT2WR1         PIC32MZ_PBASE (0xF8878)
#define SBT2REG2        PIC32MZ_PBASE (0xF8880)
#define SBT2RD2         PIC32MZ_PBASE (0xF8890)
#define SBT2WR2         PIC32MZ_PBASE (0xF8898)
#define SBT3ELOG1       PIC32MZ_PBASE (0xF8C20)
#define SBT3ELOG2       PIC32MZ_PBASE (0xF8C24)
#define SBT3ECON        PIC32MZ_PBASE (0xF8C28)
#define SBT3ECLRS       PIC32MZ_PBASE (0xF8C30)
#define SBT3ECLRM       PIC32MZ_PBASE (0xF8C38)
#define SBT3REG0        PIC32MZ_PBASE (0xF8C40)
#define SBT3RD0         PIC32MZ_PBASE (0xF8C50)
#define SBT3WR0         PIC32MZ_PBASE (0xF8C58)
#define SBT3REG1        PIC32MZ_PBASE (0xF8C60)
#define SBT3RD1         PIC32MZ_PBASE (0xF8C70)
#define SBT3WR1         PIC32MZ_PBASE (0xF8C78)
#define SBT3REG2        PIC32MZ_PBASE (0xF8C80)
#define SBT3RD2         PIC32MZ_PBASE (0xF8C90)
#define SBT3WR2         PIC32MZ_PBASE (0xF8C98)
#define SBT4ELOG1       PIC32MZ_PBASE (0xF9020)
#define SBT4ELOG2       PIC32MZ_PBASE (0xF9024)
#define SBT4ECON        PIC32MZ_PBASE (0xF9028)
#define SBT4ECLRS       PIC32MZ_PBASE (0xF9030)
#define SBT4ECLRM       PIC32MZ_PBASE (0xF9038)
#define SBT4REG0        PIC32MZ_PBASE (0xF9040)
#define SBT4RD0         PIC32MZ_PBASE (0xF9050)
#define SBT4WR0         PIC32MZ_PBASE (0xF9058)
#define SBT4REG2        PIC32MZ_PBASE (0xF9080)
#define SBT4RD2         PIC32MZ_PBASE (0xF9090)
#define SBT4WR2         PIC32MZ_PBASE (0xF9098)
#define SBT5ELOG1       PIC32MZ_PBASE (0xF9420)
#define SBT5ELOG2       PIC32MZ_PBASE (0xF9424)
#define SBT5ECON        PIC32MZ_PBASE (0xF9428)
#define SBT5ECLRS       PIC32MZ_PBASE (0xF9430)
#define SBT5ECLRM       PIC32MZ_PBASE (0xF9438)
#define SBT5REG0        PIC32MZ_PBASE (0xF9440)
#define SBT5RD0         PIC32MZ_PBASE (0xF9450)
#define SBT5WR0         PIC32MZ_PBASE (0xF9458)
#define SBT5REG1        PIC32MZ_PBASE (0xF9460)
#define SBT5RD1         PIC32MZ_PBASE (0xF9470)
#define SBT5WR1         PIC32MZ_PBASE (0xF9478)
#define SBT5REG2        PIC32MZ_PBASE (0xF9480)
#define SBT5RD2         PIC32MZ_PBASE (0xF9490)
#define SBT5WR2         PIC32MZ_PBASE (0xF9498)
#define SBT6ELOG1       PIC32MZ_PBASE (0xF9820)
#define SBT6ELOG2       PIC32MZ_PBASE (0xF9824)
#define SBT6ECON        PIC32MZ_PBASE (0xF9828)
#define SBT6ECLRS       PIC32MZ_PBASE (0xF9830)
#define SBT6ECLRM       PIC32MZ_PBASE (0xF9838)
#define SBT6REG0        PIC32MZ_PBASE (0xF9840)
#define SBT6RD0         PIC32MZ_PBASE (0xF9850)
#define SBT6WR0         PIC32MZ_PBASE (0xF9858)
#define SBT6REG1        PIC32MZ_PBASE (0xF9860)
#define SBT6RD1         PIC32MZ_PBASE (0xF9870)
#define SBT6WR1         PIC32MZ_PBASE (0xF9878)
#define SBT7ELOG1       PIC32MZ_PBASE (0xF9C20)
#define SBT7ELOG2       PIC32MZ_PBASE (0xF9C24)
#define SBT7ECON        PIC32MZ_PBASE (0xF9C28)
#define SBT7ECLRS       PIC32MZ_PBASE (0xF9C30)
#define SBT7ECLRM       PIC32MZ_PBASE (0xF9C38)
#define SBT7REG0        PIC32MZ_PBASE (0xF9C40)
#define SBT7RD0         PIC32MZ_PBASE (0xF9C50)
#define SBT7WR0         PIC32MZ_PBASE (0xF9C58)
#define SBT7REG1        PIC32MZ_PBASE (0xF9C60)
#define SBT7RD1         PIC32MZ_PBASE (0xF9C70)
#define SBT7WR1         PIC32MZ_PBASE (0xF9C78)
#define SBT8ELOG1       PIC32MZ_PBASE (0xFA020)
#define SBT8ELOG2       PIC32MZ_PBASE (0xFA024)
#define SBT8ECON        PIC32MZ_PBASE (0xFA028)
#define SBT8ECLRS       PIC32MZ_PBASE (0xFA030)
#define SBT8ECLRM       PIC32MZ_PBASE (0xFA038)
#define SBT8REG0        PIC32MZ_PBASE (0xFA040)
#define SBT8RD0         PIC32MZ_PBASE (0xFA050)
#define SBT8WR0         PIC32MZ_PBASE (0xFA058)
#define SBT8REG1        PIC32MZ_PBASE (0xFA060)
#define SBT8RD1         PIC32MZ_PBASE (0xFA070)
#define SBT8WR1         PIC32MZ_PBASE (0xFA078)
#define SBT9ELOG1       PIC32MZ_PBASE (0xFA420)
#define SBT9ELOG2       PIC32MZ_PBASE (0xFA424)
#define SBT9ECON        PIC32MZ_PBASE (0xFA428)
#define SBT9ECLRS       PIC32MZ_PBASE (0xFA430)
#define SBT9ECLRM       PIC32MZ_PBASE (0xFA438)
#define SBT9REG0        PIC32MZ_PBASE (0xFA440)
#define SBT9RD0         PIC32MZ_PBASE (0xFA450)
#define SBT9WR0         PIC32MZ_PBASE (0xFA458)
#define SBT9REG1        PIC32MZ_PBASE (0xFA460)
#define SBT9RD1         PIC32MZ_PBASE (0xFA470)
#define SBT9WR1         PIC32MZ_PBASE (0xFA478)
#define SBT10ELOG1      PIC32MZ_PBASE (0xFA820)
#define SBT10ELOG2      PIC32MZ_PBASE (0xFA824)
#define SBT10ECON       PIC32MZ_PBASE (0xFA828)
#define SBT10ECLRS      PIC32MZ_PBASE (0xFA830)
#define SBT10ECLRM      PIC32MZ_PBASE (0xFA838)
#define SBT10REG0       PIC32MZ_PBASE (0xFA840)
#define SBT10RD0        PIC32MZ_PBASE (0xFA850)
#define SBT10WR0        PIC32MZ_PBASE (0xFA858)
#define SBT11ELOG1      PIC32MZ_PBASE (0xFAC20)
#define SBT11ELOG2      PIC32MZ_PBASE (0xFAC24)
#define SBT11ECON       PIC32MZ_PBASE (0xFAC28)
#define SBT11ECLRS      PIC32MZ_PBASE (0xFAC30)
#define SBT11ECLRM      PIC32MZ_PBASE (0xFAC38)
#define SBT11REG0       PIC32MZ_PBASE (0xFAC40)
#define SBT11RD0        PIC32MZ_PBASE (0xFAC50)
#define SBT11WR0        PIC32MZ_PBASE (0xFAC58)
#define SBT11REG1       PIC32MZ_PBASE (0xFAC60)
#define SBT11RD1        PIC32MZ_PBASE (0xFAC70)
#define SBT11WR1        PIC32MZ_PBASE (0xFAC78)
#define SBT12ELOG1      PIC32MZ_PBASE (0xFB020)
#define SBT12ELOG2      PIC32MZ_PBASE (0xFB024)
#define SBT12ECON       PIC32MZ_PBASE (0xFB028)
#define SBT12ECLRS      PIC32MZ_PBASE (0xFB030)
#define SBT12ECLRM      PIC32MZ_PBASE (0xFB038)
#define SBT12REG0       PIC32MZ_PBASE (0xFB040)
#define SBT12RD0        PIC32MZ_PBASE (0xFB050)
#define SBT12WR0        PIC32MZ_PBASE (0xFB058)
#define SBT13ELOG1      PIC32MZ_PBASE (0xFB420)
#define SBT13ELOG2      PIC32MZ_PBASE (0xFB424)
#define SBT13ECON       PIC32MZ_PBASE (0xFB428)
#define SBT13ECLRS      PIC32MZ_PBASE (0xFB430)
#define SBT13ECLRM      PIC32MZ_PBASE (0xFB438)
#define SBT13REG0       PIC32MZ_PBASE (0xFB440)
#define SBT13RD0        PIC32MZ_PBASE (0xFB450)
#define SBT13WR0        PIC32MZ_PBASE (0xFB458)

/* Ethernet registers */
#define ETHCON1         PIC32MZ_PBASE (0x82000)
#define ETHCON1CLR      PIC32MZ_PBASE (0x82004)
#define ETHCON1SET      PIC32MZ_PBASE (0x82008)
#define ETHCON1INV      PIC32MZ_PBASE (0x8200c)
#define ETHCON2         PIC32MZ_PBASE (0x82010)
#define ETHTXST         PIC32MZ_PBASE (0x82020)
#define ETHRXST         PIC32MZ_PBASE (0x82030)
#define ETHHT0          PIC32MZ_PBASE (0x82040)
#define ETHHT0CLR       PIC32MZ_PBASE (0x82044)
#define ETHHT1          PIC32MZ_PBASE (0x82050)
#define ETHHT1CLR       PIC32MZ_PBASE (0x82054)
#define ETHPMM0         PIC32MZ_PBASE (0x82060)
#define ETHPMM1         PIC32MZ_PBASE (0x82070)
#define ETHPMM1CLR      PIC32MZ_PBASE (0x82074)
#define ETHPMCS         PIC32MZ_PBASE (0x82080)
#define ETHPMO          PIC32MZ_PBASE (0x82090)
#define ETHRXFC         PIC32MZ_PBASE (0x820a0)
#define ETHRXFCCLR      PIC32MZ_PBASE (0x820a4)
#define ETHRXWM         PIC32MZ_PBASE (0x820b0)
#define ETHIEN          PIC32MZ_PBASE (0x820c0)
#define ETHIENCLR       PIC32MZ_PBASE (0x820c4)
#define ETHIENSET       PIC32MZ_PBASE (0x820c8)
#define ETHIENINV       PIC32MZ_PBASE (0x820cc)
#define ETHIRQ          PIC32MZ_PBASE (0x820d0)
#define ETHIRQCLR       PIC32MZ_PBASE (0x820d4)
#define ETHIRQSET       PIC32MZ_PBASE (0x820d8)
#define ETHIRQINV       PIC32MZ_PBASE (0x820dc)
#define ETHSTAT         PIC32MZ_PBASE (0x820e0)
#define ETHRXOVFLOW     PIC32MZ_PBASE (0x82100)
#define ETHFRMTXOK      PIC32MZ_PBASE (0x82110)
#define ETHSCOLFRM      PIC32MZ_PBASE (0x82120)
#define ETHMCOLFRM      PIC32MZ_PBASE (0x82130)
#define ETHFRMRXOK      PIC32MZ_PBASE (0x82140)
#define ETHFCSERR       PIC32MZ_PBASE (0x82150)
#define ETHALGNERR      PIC32MZ_PBASE (0x82160)
#define EMAC1CFG1       PIC32MZ_PBASE (0x82200)
#define EMAC1CFG2       PIC32MZ_PBASE (0x82210)
#define EMAC1CFG2CLR    PIC32MZ_PBASE (0x82214)
#define EMAC1CFG2SET    PIC32MZ_PBASE (0x82218)
#define EMAC1CFG2INV    PIC32MZ_PBASE (0x8221c)
#define EMAC1IPGT       PIC32MZ_PBASE (0x82220)
#define EMAC1IPGR       PIC32MZ_PBASE (0x82230)
#define EMAC1CLRT       PIC32MZ_PBASE (0x82240)
#define EMAC1MAXF       PIC32MZ_PBASE (0x82250)
#define EMAC1SUPP       PIC32MZ_PBASE (0x82260)
#define EMAC1SUPPCLR    PIC32MZ_PBASE (0x82264)
#define EMAC1SUPPSET    PIC32MZ_PBASE (0x82268)
#define EMAC1SUPPINV    PIC32MZ_PBASE (0x8226c)
#define EMAC1TEST       PIC32MZ_PBASE (0x82270)
#define EMAC1MCFG       PIC32MZ_PBASE (0x82280)
#define EMAC1MCMD       PIC32MZ_PBASE (0x82290)
#define EMAC1MCMDCLR    PIC32MZ_PBASE (0x82294)
#define EMAC1MCMDSET    PIC32MZ_PBASE (0x82298)
#define EMAC1MCMDINV    PIC32MZ_PBASE (0x8229c)
#define EMAC1MADR       PIC32MZ_PBASE (0x822a0)
#define EMAC1MWTD       PIC32MZ_PBASE (0x822b0)
#define EMAC1MRDD       PIC32MZ_PBASE (0x822c0)
#define EMAC1MIND       PIC32MZ_PBASE (0x822d0)
#define EMAC1SA0        PIC32MZ_PBASE (0x82300)
#define EMAC1SA1        PIC32MZ_PBASE (0x82310)
#define EMAC1SA2        PIC32MZ_PBASE (0x82320)

/*
 * Ethernet Control register 1.
 */
#define PIC32_ETHCON1_PTV(n)    ((n)<<16)   /* Pause timer value */
#define PIC32_ETHCON1_ON            0x8000  /* Ethernet module enabled */
#define PIC32_ETHCON1_SIDL          0x2000  /* Stop in idle mode */
#define PIC32_ETHCON1_TXRTS         0x0200  /* Transmit request to send */
#define PIC32_ETHCON1_RXEN          0x0100  /* Receive enable */
#define PIC32_ETHCON1_AUTOFC        0x0080  /* Automatic flow control */
#define PIC32_ETHCON1_MANFC         0x0010  /* Manual flow control */
#define PIC32_ETHCON1_BUFCDEC       0x0001  /* Descriptor buffer count decrement */

/*
 * Ethernet Receive Filter Configuration register.
 */
#define PIC32_ETHRXFC_HTEN          0x8000  /* Enable hash table filtering */
#define PIC32_ETHRXFC_MPEN          0x4000  /* Enable Magic Packet filtering */
#define PIC32_ETHRXFC_NOTPM         0x1000  /* Pattern match inversion */
#define PIC32_ETHRXFC_PMMODE_MAGIC  0x0900  /* Packet = magic */
#define PIC32_ETHRXFC_PMMODE_HT     0x0800  /* Hash table filter match */
#define PIC32_ETHRXFC_PMMODE_BCAST  0x0600  /* Destination = broadcast address */
#define PIC32_ETHRXFC_PMMODE_UCAST  0x0400  /* Destination = unicast address */
#define PIC32_ETHRXFC_PMMODE_STN    0x0200  /* Destination = station address */
#define PIC32_ETHRXFC_PMMODE_CSUM   0x0100  /* Successful if checksum matches */
#define PIC32_ETHRXFC_CRCERREN      0x0080  /* CRC error collection enable */
#define PIC32_ETHRXFC_CRCOKEN       0x0040  /* CRC OK enable */
#define PIC32_ETHRXFC_RUNTERREN     0x0020  /* Runt error collection enable */
#define PIC32_ETHRXFC_RUNTEN        0x0010  /* Runt filter enable */
#define PIC32_ETHRXFC_UCEN          0x0008  /* Unicast filter enable */
#define PIC32_ETHRXFC_NOTMEEN       0x0004  /* Not Me unicast enable */
#define PIC32_ETHRXFC_MCEN          0x0002  /* Multicast filter enable */
#define PIC32_ETHRXFC_BCEN          0x0001  /* Broadcast filter enable */

/*
 * Ethernet Receive Watermarks register.
 */
#define PIC32_ETHRXWM_FWM(n)    ((n)<<16)   /* Receive Full Watermark */
#define PIC32_ETHRXWM_EWM(n)    (n)         /* Receive Empty Watermark */

/*
 * Ethernet Interrupt Request register.
 */
#define PIC32_ETHIRQ_TXBUSE         0x4000  /* Transmit Bus Error */
#define PIC32_ETHIRQ_RXBUSE         0x2000  /* Receive Bus Error */
#define PIC32_ETHIRQ_EWMARK         0x0200  /* Empty Watermark */
#define PIC32_ETHIRQ_FWMARK         0x0100  /* Full Watermark */
#define PIC32_ETHIRQ_RXDONE         0x0080  /* Receive Done */
#define PIC32_ETHIRQ_PKTPEND        0x0040  /* Packet Pending */
#define PIC32_ETHIRQ_RXACT          0x0020  /* Receive Activity */
#define PIC32_ETHIRQ_TXDONE         0x0008  /* Transmit Done */
#define PIC32_ETHIRQ_TXABORT        0x0004  /* Transmitter Abort */
#define PIC32_ETHIRQ_RXBUFNA        0x0002  /* Receive Buffer Not Available */
#define PIC32_ETHIRQ_RXOVFLW        0x0001  /* Receive FIFO Overflow */

/*
 * Ethernet Status register.
 */
#define PIC32_ETHSTAT_BUFCNT    0x00ff0000  /* Packet buffer count */
#define PIC32_ETHSTAT_ETHBUSY       0x0080  /* Ethernet logic is busy */
#define PIC32_ETHSTAT_TXBUSY        0x0040  /* TX logic is receiving data */
#define PIC32_ETHSTAT_RXBUSY        0x0020  /* RX logic is receiving data */

/*
 * Ethernet MAC configuration register 1.
 */
#define PIC32_EMAC1CFG1_SOFTRESET   0x8000  /* Soft reset */
#define PIC32_EMAC1CFG1_SIMRESET    0x4000  /* Reset TX random number generator */
#define PIC32_EMAC1CFG1_RESETRMCS   0x0800  /* Reset MCS/RX logic */
#define PIC32_EMAC1CFG1_RESETRFUN   0x0400  /* Reset RX function */
#define PIC32_EMAC1CFG1_RESETTMCS   0x0200  /* Reset MCS/TX logic */
#define PIC32_EMAC1CFG1_RESETTFUN   0x0100  /* Reset TX function */
#define PIC32_EMAC1CFG1_LOOPBACK    0x0010  /* MAC Loopback mode */
#define PIC32_EMAC1CFG1_TXPAUSE     0x0008  /* MAC TX flow control */
#define PIC32_EMAC1CFG1_RXPAUSE     0x0004  /* MAC RX flow control */
#define PIC32_EMAC1CFG1_PASSALL     0x0002  /* MAC accept control frames as well */
#define PIC32_EMAC1CFG1_RXENABLE    0x0001  /* MAC Receive Enable */

/*
 * Ethernet MAC configuration register 2.
 */
#define PIC32_EMAC1CFG2_EXCESSDER   0x4000  /* Defer to carrier indefinitely */
#define PIC32_EMAC1CFG2_BPNOBKOFF   0x2000  /* Backpressure/No Backoff */
#define PIC32_EMAC1CFG2_NOBKOFF     0x1000  /* No Backoff */
#define PIC32_EMAC1CFG2_LONGPRE     0x0200  /* Long preamble enforcement */
#define PIC32_EMAC1CFG2_PUREPRE     0x0100  /* Pure preamble enforcement */
#define PIC32_EMAC1CFG2_AUTOPAD     0x0080  /* Automatic detect pad enable */
#define PIC32_EMAC1CFG2_VLANPAD     0x0040  /* VLAN pad enable */
#define PIC32_EMAC1CFG2_PADENABLE   0x0020  /* Pad/CRC enable */
#define PIC32_EMAC1CFG2_CRCENABLE   0x0010  /* CRC enable */
#define PIC32_EMAC1CFG2_DELAYCRC    0x0008  /* Delayed CRC */
#define PIC32_EMAC1CFG2_HUGEFRM     0x0004  /* Huge frame enable */
#define PIC32_EMAC1CFG2_LENGTHCK    0x0002  /* Frame length checking */
#define PIC32_EMAC1CFG2_FULLDPLX    0x0001  /* Full-duplex operation */

/*
 * Ethernet MAC non-back-to-back interpacket gap register.
 */
#define PIC32_EMAC1IPGR(p1, p2)     ((p1)<<8 | (p2))

/*
 * Ethernet MAC collision window/retry limit register.
 */
#define PIC32_EMAC1CLRT(w, r)       ((w)<<8 | (r))

/*
 * Ethernet PHY support register.
 */
#define PIC32_EMAC1SUPP_RESETRMII   0x0800  /* Reset the RMII module */
#define PIC32_EMAC1SUPP_SPEEDRMII   0x0100  /* RMII speed: 1=100Mbps, 0=10Mbps */

/*
 * Ethernet MAC test register.
 */
#define PIC32_EMAC1TEST_TESTBP      0x0004  /* Test backpressure */
#define PIC32_EMAC1TEST_TESTPAUSE   0x0002  /* Test pause */
#define PIC32_EMAC1TEST_SHRTQNTA    0x0001  /* Shortcut pause quanta */

/*
 * Ethernet MII configuration register.
 */
#define PIC32_EMAC1MCFG_RESETMGMT   0x8000  /* Reset the MII module */
#define PIC32_EMAC1MCFG_CLKSEL_4    0x0000  /* Clock divide by 4 */
#define PIC32_EMAC1MCFG_CLKSEL_6    0x0008  /* Clock divide by 6 */
#define PIC32_EMAC1MCFG_CLKSEL_8    0x000c  /* Clock divide by 8 */
#define PIC32_EMAC1MCFG_CLKSEL_10   0x0010  /* Clock divide by 10 */
#define PIC32_EMAC1MCFG_CLKSEL_14   0x0014  /* Clock divide by 14 */
#define PIC32_EMAC1MCFG_CLKSEL_20   0x0018  /* Clock divide by 20 */
#define PIC32_EMAC1MCFG_CLKSEL_28   0x001c  /* Clock divide by 28 */
#define PIC32_EMAC1MCFG_CLKSEL_40   0x0020  /* Clock divide by 40 */
#define PIC32_EMAC1MCFG_CLKSEL_48   0x0024  /* Clock divide by 48 */
#define PIC32_EMAC1MCFG_CLKSEL_50   0x0028  /* Clock divide by 50 */
#define PIC32_EMAC1MCFG_NOPRE       0x0002  /* Suppress preamble */
#define PIC32_EMAC1MCFG_SCANINC     0x0001  /* Scan increment */

/*
 * Ethernet MII command register.
 */
#define PIC32_EMAC1MCMD_SCAN        0x0002  /* Continuous scan mode */
#define PIC32_EMAC1MCMD_READ        0x0001  /* Single read cycle */

/*
 * Ethernet MII address register.
 */
#define PIC32_EMAC1MADR(p, r)       ((p)<<8 | (r))

/*
 * Ethernet MII indicators register.
 */
#define PIC32_EMAC1MIND_LINKFAIL    0x0008  /* Link fail */
#define PIC32_EMAC1MIND_NOTVALID    0x0004  /* Read data not valid */
#define PIC32_EMAC1MIND_SCAN        0x0002  /* Scanning in progress */
#define PIC32_EMAC1MIND_MIIMBUSY    0x0001  /* Read/write cycle in progress */

/*
 * Ethernet MAC configuration register 2.
 */
#define PIC32_EMAC1CFG2_EXCESSDFR   0x4000  /* Defer to carrier indefinitely */
#define PIC32_EMAC1CFG2_BPNOBKOFF   0x2000  /* Backpressure/No Backoff */
#define PIC32_EMAC1CFG2_NOBKOFF     0x1000  /* No Backoff */
#define PIC32_EMAC1CFG2_LONGPRE     0x0200  /* Long preamble enforcement */
#define PIC32_EMAC1CFG2_PUREPRE     0x0100  /* Pure preamble enforcement */
#define PIC32_EMAC1CFG2_AUTOPAD     0x0080  /* Automatic detect pad enable */
#define PIC32_EMAC1CFG2_VLANPAD     0x0040  /* VLAN pad enable */
#define PIC32_EMAC1CFG2_PADENABLE   0x0020  /* Pad/CRC enable */
#define PIC32_EMAC1CFG2_CRCENABLE   0x0010  /* CRC enable */
#define PIC32_EMAC1CFG2_DELAYCRC    0x0008  /* Delayed CRC */
#define PIC32_EMAC1CFG2_HUGEFRM     0x0004  /* Huge frame enable */
#define PIC32_EMAC1CFG2_LENGTHCK    0x0002  /* Frame length checking */
#define PIC32_EMAC1CFG2_FULLDPLX    0x0001  /* Full-duplex operation */



/* Timer registers */
#define T2CON           PIC32MZ_PBASE (0x40200)
#define TMR2            PIC32MZ_PBASE (0x40210)
#define PR2             PIC32MZ_PBASE (0x40220)
#define T3CON           PIC32MZ_PBASE (0x40400)
#define TMR3            PIC32MZ_PBASE (0x40410)
#define PR3             PIC32MZ_PBASE (0x40420)
#define T4CON           PIC32MZ_PBASE (0x40600)
#define TMR4            PIC32MZ_PBASE (0x40610)
#define PR4             PIC32MZ_PBASE (0x40620)
#define T5CON           PIC32MZ_PBASE (0x40800)
#define TMR5            PIC32MZ_PBASE (0x40810)
#define PR5             PIC32MZ_PBASE (0x40820)
#define T6CON           PIC32MZ_PBASE (0x40A00)
#define TMR6            PIC32MZ_PBASE (0x40A10)
#define PR6             PIC32MZ_PBASE (0x40A20)
#define T7CON           PIC32MZ_PBASE (0x40C00)
#define TMR7            PIC32MZ_PBASE (0x40C10)
#define PR7             PIC32MZ_PBASE (0x40C20)
#define T8CON           PIC32MZ_PBASE (0x40E00)
#define TMR8            PIC32MZ_PBASE (0x40E10)
#define PR8             PIC32MZ_PBASE (0x40E20)
#define T9CON           PIC32MZ_PBASE (0x41000)
#define TMR9            PIC32MZ_PBASE (0x41010)
#define PR9             PIC32MZ_PBASE (0x41020)

/* Interrupt controller registers */
#define INTCON          PIC32MZ_PBASE (0x10000)
#define INTCONCLR       PIC32MZ_PBASE (0x10004)
#define INTCONSET       PIC32MZ_PBASE (0x10008)
#define INTCONINV       PIC32MZ_PBASE (0x1000C)
#define PRISS           PIC32MZ_PBASE (0x10010)
#define PRISSCLR        PIC32MZ_PBASE (0x10014)
#define PRISSSET        PIC32MZ_PBASE (0x10018)
#define PRISSINV        PIC32MZ_PBASE (0x1001C)
#define INTSTAT         PIC32MZ_PBASE (0x10020)
#define IPTMR           PIC32MZ_PBASE (0x10030)
#define IPTMRCLR        PIC32MZ_PBASE (0x10034)
#define IPTMRSET        PIC32MZ_PBASE (0x10038)
#define IPTMRINV        PIC32MZ_PBASE (0x1003C)
#define IFS(n)          PIC32MZ_PBASE (0x10040+((n)<<4))
#define IFSCLR(n)       PIC32MZ_PBASE (0x10044+((n)<<4))
#define IFSSET(n)       PIC32MZ_PBASE (0x10048+((n)<<4))
#define IFSINV(n)       PIC32MZ_PBASE (0x1004C+((n)<<4))
#define IFS0            IFS(0)
#define IFS1            IFS(1)
#define IFS2            IFS(2)
#define IFS3            IFS(3)
#define IFS4            IFS(4)
#define IFS5            IFS(5)
#define IEC(n)          PIC32MZ_PBASE (0x100c0+((n)<<4))
#define IECCLR(n)       PIC32MZ_PBASE (0x100c4+((n)<<4))
#define IECSET(n)       PIC32MZ_PBASE (0x100c8+((n)<<4))
#define IECINV(n)       PIC32MZ_PBASE (0x100cC+((n)<<4))
#define IEC0            IEC(0)
#define IEC1            IEC(1)
#define IEC2            IEC(2)
#define IEC3            IEC(3)
#define IEC4            IEC(4)
#define IEC5            IEC(5)
#define IPC(n)          PIC32MZ_PBASE (0x10140+((n)<<4))
#define IPCCLR(n)       PIC32MZ_PBASE (0x10144+((n)<<4))
#define IPCSET(n)       PIC32MZ_PBASE (0x10148+((n)<<4))
#define IPCINV(n)       PIC32MZ_PBASE (0x1014C+((n)<<4))
#define IPC0            IPC(0)
#define IPC1            IPC(1)
#define IPC2            IPC(2)
#define IPC3            IPC(3)
#define IPC4            IPC(4)
#define IPC5            IPC(5)
#define IPC6            IPC(6)
#define IPC7            IPC(7)
#define IPC8            IPC(8)
#define IPC9            IPC(9)
#define IPC10           IPC(10)
#define IPC11           IPC(11)
#define IPC12           IPC(12)
#define IPC13           IPC(13)
#define IPC14           IPC(14)
#define IPC15           IPC(15)
#define IPC16           IPC(16)
#define IPC17           IPC(17)
#define IPC18           IPC(18)
#define IPC19           IPC(19)
#define IPC20           IPC(20)
#define IPC21           IPC(21)
#define IPC22           IPC(22)
#define IPC23           IPC(23)
#define IPC24           IPC(24)
#define IPC25           IPC(25)
#define IPC26           IPC(26)
#define IPC27           IPC(27)
#define IPC28           IPC(28)
#define IPC29           IPC(29)
#define IPC30           IPC(30)
#define IPC31           IPC(31)
#define IPC32           IPC(32)
#define IPC33           IPC(33)
#define IPC34           IPC(34)
#define IPC35           IPC(35)
#define IPC36           IPC(36)
#define IPC37           IPC(37)
#define IPC38           IPC(38)
#define IPC39           IPC(39)
#define IPC40           IPC(40)
#define IPC41           IPC(41)
#define IPC42           IPC(42)
#define IPC43           IPC(43)
#define IPC44           IPC(44)
#define IPC45           IPC(45)
#define IPC46           IPC(46)
#define IPC47           IPC(47)
#define OFF(n)          PIC32MZ_PBASE (0x10540+((n)<<2))

/* Interrupt control register */
#define INTCON_INT0EP           0x00000001
#define INTCON_INT1EP           0x00000002
#define INTCON_INT2EP           0x00000004
#define INTCON_INT3EP           0x00000008
#define INTCON_INT4EP           0x00000010
#define INTCON_TPC(x)           ((x)<<8)
#define INTCON_MVEC             0x00001000
#define INTCON_SS0              0x00010000
#define INTCON_VS(x)            ((x)<<16)

/* Interrupt status register */
#define INTSTAT_VEC(s)          ((s) & 0x3f)
#define INTSTAT_SRIPL(s)        ((s) >> 8 & 7)
#define INTSTAT_SRIPL_MASK      0x0700

/* Interrupt priority control register */
#define IPC_IS0(x)      (x)
#define IPC_IP0(x)      ((x)<<2)
#define IPC_IS1(x)      ((x)<<8)
#define IPC_IP1(x)      ((x)<<10)
#define IPC_IS2(x)      ((x)<<16)
#define IPC_IP2(x)      ((x)<<18)
#define IPC_IS3(x)      ((x)<<24)
#define IPC_IP3(x)      ((x)<<26)

/* IRQs for PIC32MZ */
#define IRQ_CT        0
#define IRQ_CS0       1
#define IRQ_CS1       2
#define IRQ_INT0      3
#define IRQ_T1        4
#define IRQ_IC1E      5
#define IRQ_IC1       6
#define IRQ_OC1       7
#define IRQ_INT1      8
#define IRQ_T2        9
#define IRQ_IC2E      10
#define IRQ_IC2       11
#define IRQ_OC2       12
#define IRQ_INT2      13
#define IRQ_T3        14
#define IRQ_IC3E      15
#define IRQ_IC3       16
#define IRQ_OC3       17
#define IRQ_INT3      18
#define IRQ_T4        19
#define IRQ_IC4E      20
#define IRQ_IC4       21
#define IRQ_OC4       22
#define IRQ_INT4      23
#define IRQ_T5        24
#define IRQ_IC5E      25
#define IRQ_IC5       26
#define IRQ_OC5       27
#define IRQ_T6        28
#define IRQ_IC6E      29
#define IRQ_IC6       30
#define IRQ_OC6       31
#define IRQ_T7        32
#define IRQ_IC7E      33
#define IRQ_IC7       34
#define IRQ_OC7       35
#define IRQ_T8        36
#define IRQ_IC8E      37
#define IRQ_IC8       38
#define IRQ_OC8       39
#define IRQ_T9        40
#define IRQ_IC9E      41
#define IRQ_IC9       42
#define IRQ_OC9       43
#define IRQ_AD1       44
#define IRQ_AD1DC1    46
#define IRQ_AD1DC2    47
#define IRQ_AD1DC3    48
#define IRQ_AD1DC4    49
#define IRQ_AD1DC5    50
#define IRQ_AD1DC6    51
#define IRQ_AD1DF1    52
#define IRQ_AD1DF2    53
#define IRQ_AD1DF3    54
#define IRQ_AD1DF4    55
#define IRQ_AD1DF5    56
#define IRQ_AD1DF6    57
#define IRQ_AD1D0     59
#define IRQ_AD1D1     60
#define IRQ_AD1D2     61
#define IRQ_AD1D3     62
#define IRQ_AD1D4     63
#define IRQ_AD1D5     64
#define IRQ_AD1D6     65
#define IRQ_AD1D7     66
#define IRQ_AD1D8     67
#define IRQ_AD1D9     68
#define IRQ_AD1D10    69
#define IRQ_AD1D11    70
#define IRQ_AD1D12    71
#define IRQ_AD1D13    72
#define IRQ_AD1D14    73
#define IRQ_AD1D15    74
#define IRQ_AD1D16    75
#define IRQ_AD1D17    76
#define IRQ_AD1D18    77
#define IRQ_AD1D19    78
#define IRQ_AD1D20    79
#define IRQ_AD1D21    80
#define IRQ_AD1D22    81
#define IRQ_AD1D23    82
#define IRQ_AD1D24    83
#define IRQ_AD1D25    84
#define IRQ_AD1D26    85
#define IRQ_AD1D27    86
#define IRQ_AD1D28    87
#define IRQ_AD1D29    88
#define IRQ_AD1D30    89
#define IRQ_AD1D31    90
#define IRQ_AD1D32    91
#define IRQ_AD1D33    92
#define IRQ_AD1D34    93
#define IRQ_AD1D35    94
#define IRQ_AD1D36    95
#define IRQ_AD1D37    96
#define IRQ_AD1D38    97
#define IRQ_AD1D39    98
#define IRQ_AD1D40    99
#define IRQ_AD1D41    100
#define IRQ_AD1D42    101
#define IRQ_AD1D43    102
#define IRQ_AD1D44    103
#define IRQ_CPC       104
#define IRQ_CFDC      105
#define IRQ_SB        106
#define IRQ_CRPT      107
#define IRQ_SPI1E     109
#define IRQ_SPI1RX    110
#define IRQ_SPI1TX    111
#define IRQ_U1E       112
#define IRQ_U1RX      113
#define IRQ_U1TX      114
#define IRQ_I2C1B     115
#define IRQ_I2C1S     116
#define IRQ_I2C1M     117
#define IRQ_CNA       118
#define IRQ_CNB       119
#define IRQ_CNC       120
#define IRQ_CND       121
#define IRQ_CNE       122
#define IRQ_CNF       123
#define IRQ_CNG       124
#define IRQ_CNH       125
#define IRQ_CNJ       126
#define IRQ_CNK       127
#define IRQ_PMP       128
#define IRQ_PMPE      129
#define IRQ_CMP1      130
#define IRQ_CMP2      131
#define IRQ_USB       132
#define IRQ_USBDMA    133
#define IRQ_DMA0      134
#define IRQ_DMA1      135
#define IRQ_DMA2      136
#define IRQ_DMA3      137
#define IRQ_DMA4      138
#define IRQ_DMA5      139
#define IRQ_DMA6      140
#define IRQ_DMA7      141
#define IRQ_SPI2E     142
#define IRQ_SPI2RX    143
#define IRQ_SPI2TX    144
#define IRQ_U2E       145
#define IRQ_U2RX      146
#define IRQ_U2TX      147
#define IRQ_I2C2B     148
#define IRQ_I2C2S     149
#define IRQ_I2C2M     150
#define IRQ_CAN1      151
#define IRQ_CAN2      152
#define IRQ_ETH       153
#define IRQ_SPI3E     154
#define IRQ_SPI3RX    155
#define IRQ_SPI3TX    156
#define IRQ_U3E       157
#define IRQ_U3RX      158
#define IRQ_U3TX      159
#define IRQ_I2C3B     160
#define IRQ_I2C3S     161
#define IRQ_I2C3M     162
#define IRQ_SPI4E     163
#define IRQ_SPI4RX    164
#define IRQ_SPI4TX    165
#define IRQ_RTCC      166
#define IRQ_FCE       167
#define IRQ_PRE       168
#define IRQ_SQI1      169
#define IRQ_U4E       170
#define IRQ_U4RX      171
#define IRQ_U4TX      172
#define IRQ_I2C4B     173
#define IRQ_I2C4S     174
#define IRQ_I2C4M     175
#define IRQ_SPI5E     176
#define IRQ_SPI5RX    177
#define IRQ_SPI5TX    178
#define IRQ_U5E       179
#define IRQ_U5RX      180
#define IRQ_U5TX      181
#define IRQ_I2C5B     182
#define IRQ_I2C5S     183
#define IRQ_I2C5M     184
#define IRQ_SPI6E     185
#define IRQ_SPI6RX    186
#define IRQ_SPI6TX    187
#define IRQ_U6E       188
#define IRQ_U6RX      189
#define IRQ_U6TX      190

/* 
 * Flash controller registers
 */

#define NVMCON          PIC32MZ_PBASE (0x0600)
#define NVMCONCLR       PIC32MZ_PBASE (0x0604)
#define NVMCONSET       PIC32MZ_PBASE (0x0608)
#define NVMCONINV       PIC32MZ_PBASE (0x060C)
#define NVMKEY          PIC32MZ_PBASE (0x0610)
#define NVMADDR         PIC32MZ_PBASE (0x0620)
#define NVMADDRCLR      PIC32MZ_PBASE (0x0624)
#define NVMADDRSET      PIC32MZ_PBASE (0x0628)
#define NVMADDRINV      PIC32MZ_PBASE (0x062C)
#define NVMDATA0        PIC32MZ_PBASE (0x0630)
#define NVMDATA1        PIC32MZ_PBASE (0x0640)
#define NVMDATA2        PIC32MZ_PBASE (0x0650)
#define NVMDATA3        PIC32MZ_PBASE (0x0660)
#define NVMSRCADDR      PIC32MZ_PBASE (0x0670)
#define NVMPWP          PIC32MZ_PBASE (0x0680)
#define NVMPWPCLR       PIC32MZ_PBASE (0x0684)
#define NVMPWPSET       PIC32MZ_PBASE (0x0688)
#define NVMPWPINV       PIC32MZ_PBASE (0x068C)
#define NVMBWP          PIC32MZ_PBASE (0x0690)
#define NVMBWPCLR       PIC32MZ_PBASE (0x0694)
#define NVMBWPSET       PIC32MZ_PBASE (0x0698)
#define NVMBWPINV       PIC32MZ_PBASE (0x069C)
#define NVMCON2         PIC32MZ_PBASE (0x06A0)
#define NVMCON2CLR      PIC32MZ_PBASE (0x06A4)
#define NVMCON2SET      PIC32MZ_PBASE (0x06A8)
#define NVMCON2INV      PIC32MZ_PBASE (0x06AC)

/* Device configuration registers */
#define _DEVCFG0                *(volatile uint32_t *) 0xbfc0ffcc
#define _DEVCFG1                *(volatile uint32_t *) 0xbfc0ffc8
#define _DEVCFG2                *(volatile uint32_t *) 0xbfc0ffc4
#define _DEVCFG3                *(volatile uint32_t *) 0xbfc0ffc0

#define PIC32MZ_DEVCFG(cfg0, cfg1, cfg2, cfg3) \
uint32_t ___DEVCFG0 __attribute__ ((section (".config0"))) = (cfg0) ^ 0x7fffffff; \
uint32_t ___DEVCFG1 __attribute__ ((section (".config1"))) = (cfg1) | _DEVCFG1_UNUSED; \
uint32_t ___DEVCFG2 __attribute__ ((section (".config2"))) = (cfg2) | _DEVCFG2_UNUSED; \
uint32_t ___DEVCFG3 __attribute__ ((section (".config3"))) = (cfg3) | _DEVCFG3_UNUSED

/* Config0 register, inverted */
#define _DEVCFG0_DEBUG_ENABLE    0x00000002
#define _DEVCFG0_JTAG_DISABLE    0x00000004
#define _DEVCFG0_ICESEL_PGE2     0x00000008
#define _DEVCFG0_TRC_DISABLE     0x00000020
#define _DEVCFG0_MICROMIPS       0x00000040
#define _DEVCFG0_ECC_MASK        0x00000300
#define _DEVCFG0_ECC_ENABLE      0x00000300
#define _DEVCFG0_DECC_ENABLE     0x00000200
#define _DEVCFG0_ECC_DIS_LOCK    0x00000100
#define _DEVCFG0_FSLEEP          0x00000400
#define _DEVCFG0_DBGPER0         0x00001000
#define _DEVCFG0_DBGPER1         0x00002000
#define _DEVCFG0_DBGPER2         0x00004000
#define _DEVCFG0_EJTAG_REDUCED   0x40000000

/* Config1 register */
#define _DEVCFG1_UNUSED          0x00003800
#define _DEVCFG1_FNOSC_MASK      0x00000007
#define _DEVCFG1_FNOSC_SPLL      0x00000001
#define _DEVCFG1_FNOSC_POSC      0x00000002
#define _DEVCFG1_FNOSC_SOSC      0x00000004
#define _DEVCFG1_FNOSC_LPRC      0x00000005
#define _DEVCFG1_FNOSC_FRCDIV    0x00000007
#define _DEVCFG1_DMTINV_MASK     0x00000038
#define _DEVCFG1_DMTINV_1_2      0x00000008
#define _DEVCFG1_DMTINV_3_4      0x00000010
#define _DEVCFG1_DMTINV_7_8      0x00000018
#define _DEVCFG1_DMTINV_15_16    0x00000020
#define _DEVCFG1_DMTINV_31_32    0x00000028
#define _DEVCFG1_DMTINV_63_64    0x00000030
#define _DEVCFG1_DMTINV_127_128  0x00000038
#define _DEVCFG1_FSOSCEN         0x00000040
#define _DEVCFG1_IESO            0x00000080
#define _DEVCFG1_POSCMOD_MASK    0x00000300
#define _DEVCFG1_POSCMOD_EXT     0x00000000
#define _DEVCFG1_POSCMOD_HS      0x00000200
#define _DEVCFG1_POSCMOD_DISABLE 0x00000300
#define _DEVCFG1_CLKO_DISABLE    0x00000400
#define _DEVCFG1_FCKS_ENABLE     0x00004000
#define _DEVCFG1_FCKM_ENABLE     0x00008000
#define _DEVCFG1_WDTPS_MASK      0x001f0000
#define _DEVCFG1_WDTPS_1         0x00000000
#define _DEVCFG1_WDTPS_2         0x00010000
#define _DEVCFG1_WDTPS_4         0x00020000
#define _DEVCFG1_WDTPS_8         0x00030000
#define _DEVCFG1_WDTPS_16        0x00040000
#define _DEVCFG1_WDTPS_32        0x00050000
#define _DEVCFG1_WDTPS_64        0x00060000
#define _DEVCFG1_WDTPS_128       0x00070000
#define _DEVCFG1_WDTPS_256       0x00080000
#define _DEVCFG1_WDTPS_512       0x00090000
#define _DEVCFG1_WDTPS_1024      0x000a0000
#define _DEVCFG1_WDTPS_2048      0x000b0000
#define _DEVCFG1_WDTPS_4096      0x000c0000
#define _DEVCFG1_WDTPS_8192      0x000d0000
#define _DEVCFG1_WDTPS_16384     0x000e0000
#define _DEVCFG1_WDTPS_32768     0x000f0000
#define _DEVCFG1_WDTPS_65536     0x00100000
#define _DEVCFG1_WDTPS_131072    0x00110000
#define _DEVCFG1_WDTPS_262144    0x00120000
#define _DEVCFG1_WDTPS_524288    0x00130000
#define _DEVCFG1_WDTPS_1048576   0x00140000
#define _DEVCFG1_WDTSPGM         0x00200000
#define _DEVCFG1_WINDIS          0x00400000
#define _DEVCFG1_FWDTEN          0x00800000
#define _DEVCFG1_FWDTWINSZ_75    0x00000000
#define _DEVCFG1_FWDTWINSZ_50    0x01000000
#define _DEVCFG1_FWDTWINSZ_375   0x02000000
#define _DEVCFG1_FWDTWINSZ_25    0x03000000
#define _DEVCFG1_DMTCNT(n)       ((n)<<26)
#define _DEVCFG1_FDMTEN          0x80000000

/* Config2 register */
#define _DEVCFG2_UNUSED          0x3ff88008
#define _DEVCFG2_FPLLIDIV_MASK   0x00000007
#define _DEVCFG2_FPLLIDIV_1      0x00000000
#define _DEVCFG2_FPLLIDIV_2      0x00000001
#define _DEVCFG2_FPLLIDIV_3      0x00000002
#define _DEVCFG2_FPLLIDIV_4      0x00000003
#define _DEVCFG2_FPLLIDIV_5      0x00000004
#define _DEVCFG2_FPLLIDIV_6      0x00000005
#define _DEVCFG2_FPLLIDIV_7      0x00000006
#define _DEVCFG2_FPLLIDIV_8      0x00000007
#define _DEVCFG2_FPLLRNG_MASK    0x00000070
#define _DEVCFG2_FPLLRNG_BYPASS  0x00000000
#define _DEVCFG2_FPLLRNG_5_10    0x00000010
#define _DEVCFG2_FPLLRNG_8_16    0x00000020
#define _DEVCFG2_FPLLRNG_13_26   0x00000030
#define _DEVCFG2_FPLLRNG_21_42   0x00000040
#define _DEVCFG2_FPLLRNG_34_64   0x00000050
#define _DEVCFG2_FPLLICLK_FRC    0x00000080
#define _DEVCFG2_FPLLMULT(n)     (((n)-1)<<8)
#define _DEVCFG2_FPLLODIV_MASK   0x00070000
#define _DEVCFG2_FPLLODIV_2      0x00000000
#define _DEVCFG2_FPLLODIV_4      0x00020000
#define _DEVCFG2_FPLLODIV_8      0x00030000
#define _DEVCFG2_FPLLODIV_16     0x00040000
#define _DEVCFG2_FPLLODIV_32     0x00050000
#define _DEVCFG2_UPLLFSEL_24     0x40000000
#define _DEVCFG2_UPLLEN          0x80000000

/* Config3 register */
#define _DEVCFG3_UNUSED          0x84ff0000
#define _DEVCFG3_USERID_MASK     0x0000ffff
#define _DEVCFG3_USERID(x)       ((x) & 0xffff)
#define _DEVCFG3_FMIIEN          0x01000000
#define _DEVCFG3_FETHIO          0x02000000
#define _DEVCFG3_PGL1WAY         0x08000000
#define _DEVCFG3_PMDL1WAY        0x10000000
#define _DEVCFG3_IOL1WAY         0x20000000
#define _DEVCFG3_FUSBIDIO        0x40000000

typedef union {
	struct {
		unsigned MIIMBUSY:1;
		unsigned SCAN:1;
		unsigned NOTVALID:1;
		unsigned LINKFAIL:1;
	};
	struct {
		unsigned w:32;
	};
} EMAC1MINDbits_t;
#define EMAC1MINDbits (*((volatile EMAC1MINDbits_t *) 0xbf8822d0))

typedef union {
	struct {
		unsigned REGADDR:5;
		unsigned :3;
		unsigned PHYADDR:5;
	};
	struct {
		unsigned w:32;
	};
} EMAC1MADRbits_t;
#define EMAC1MADRbits (*((volatile EMAC1MADRbits_t *) 0xbf8822a0))

typedef union {
	struct {
		unsigned READ:1;
		unsigned SCAN:1;
	};
	struct {
		unsigned w:32;
	};
} EMAC1MCMDbits_t;
#define EMAC1MCMDbits (*((volatile EMAC1MCMDbits_t *) 0xbf882290))

typedef union {
	struct {
		unsigned MRDD:16;
	};
	struct {
		unsigned w:32;
	};
} EMAC1MRDDbits_t;
#define EMAC1MRDDbits (*((volatile EMAC1MRDDbits_t *) 0xbf8822c0))

typedef union {
	struct {
		unsigned MWTD:16;
	};
	struct {
		unsigned w:32;
	};
} EMAC1MWTDbits_t;
#define EMAC1MWTDbits (*((volatile EMAC1MWTDbits_t *) 0xbf8822b0))

typedef union {
	struct {
		unsigned T7IE:1;
		unsigned IC7EIE:1;
		unsigned IC7IE:1;
		unsigned OC7IE:1;
		unsigned T8IE:1;
		unsigned IC8EIE:1;
		unsigned IC8IE:1;
		unsigned OC8IE:1;
		unsigned T9IE:1;
		unsigned IC9EIE:1;
		unsigned IC9IE:1;
		unsigned OC9IE:1;
		unsigned ADCIE:1;
		unsigned ADCFIFOIE:1;
		unsigned ADCDC1IE:1;
		unsigned ADCDC2IE:1;
		unsigned ADCDC3IE:1;
		unsigned ADCDC4IE:1;
		unsigned ADCDC5IE:1;
		unsigned ADCDC6IE:1;
		unsigned ADCDF1IE:1;
		unsigned ADCDF2IE:1;
		unsigned ADCDF3IE:1;
		unsigned ADCDF4IE:1;
		unsigned ADCDF5IE:1;
		unsigned ADCDF6IE:1;
		unsigned ADCFLTIE:1;
		unsigned ADCD0IE:1;
		unsigned ADCD1IE:1;
		unsigned ADCD2IE:1;
		unsigned ADCD3IE:1;
		unsigned ADCD4IE:1;
	};
	struct {
		unsigned w:32;
	};
} IEC1bits_t;
#define IEC1bits (*((volatile IEC1bits_t *) 0xbf8100d0))

typedef union {
	struct {
		unsigned BUFCDEC:1;
		unsigned :3;
		unsigned MANFC:1;
		unsigned :2;
		unsigned AUTOFC:1;
		unsigned RXEN:1;
		unsigned TXRTS:1;
		unsigned :3;
		unsigned SIDL:1;
		unsigned :1;
		unsigned ON:1;
		unsigned PTV:16;
	};
	struct {
		unsigned w:32;
	};
} ETHCON1bits_t;
#define ETHCON1bits (*((volatile ETHCON1bits_t *) 0xbf882000))

typedef union {
	struct {
		unsigned T7IF:1;
		unsigned IC7EIF:1;
		unsigned IC7IF:1;
		unsigned OC7IF:1;
		unsigned T8IF:1;
		unsigned IC8EIF:1;
		unsigned IC8IF:1;
		unsigned OC8IF:1;
		unsigned T9IF:1;
		unsigned IC9EIF:1;
		unsigned IC9IF:1;
		unsigned OC9IF:1;
		unsigned ADCIF:1;
		unsigned ADCFIFOIF:1;
		unsigned ADCDC1IF:1;
		unsigned ADCDC2IF:1;
		unsigned ADCDC3IF:1;
		unsigned ADCDC4IF:1;
		unsigned ADCDC5IF:1;
		unsigned ADCDC6IF:1;
		unsigned ADCDF1IF:1;
		unsigned ADCDF2IF:1;
		unsigned ADCDF3IF:1;
		unsigned ADCDF4IF:1;
		unsigned ADCDF5IF:1;
		unsigned ADCDF6IF:1;
		unsigned ADCFLTIF:1;
		unsigned ADCD0IF:1;
		unsigned ADCD1IF:1;
		unsigned ADCD2IF:1;
		unsigned ADCD3IF:1;
		unsigned ADCD4IF:1;
	};
	struct {
		unsigned w:32;
	};
} IFS1bits_t;
#define IFS1bits (*((volatile IFS1bits_t *) 0xbf810050))

typedef union {
	struct {
		unsigned RXEWM:8;
		unsigned :8;
		unsigned RXFWM:8;
	};
	struct {
		unsigned w:32;
	};
} ETHRXWMbits_t;
#define ETHRXWMbits (*((volatile ETHRXWMbits_t *) 0xbf8820b0))

typedef union {
	struct {
		unsigned :4;
		unsigned RXBUF_SZ:7;
	};
	struct {
		unsigned w:32;
	};
} ETHCON2bits_t;
#define ETHCON2bits (*((volatile ETHCON2bits_t *) 0xbf882010))

typedef union {
	struct {
		unsigned BCEN:1;
		unsigned MCEN:1;
		unsigned NOTMEEN:1;
		unsigned UCEN:1;
		unsigned RUNTEN:1;
		unsigned RUNTERREN:1;
		unsigned CRCOKEN:1;
		unsigned CRCERREN:1;
		unsigned EPMMODE:4;
		unsigned NOTPM:1;
		unsigned :1;
		unsigned MPEN:1;
		unsigned HTEN:1;
	};
	struct {
		unsigned w:32;
	};
} ETHRXFCbits_t;
#define ETHRXFCbits (*((volatile ETHRXFCbits_t *) 0xbf8820a0))

typedef union {
	struct {
		unsigned PMCS:16;
	};
	struct {
		unsigned w:32;
	};
} ETHPMCSbits_t;
#define ETHPMCSbits (*((volatile ETHPMCSbits_t *) 0xbf882080))

typedef union {
	struct {
		unsigned RXENABLE:1;
		unsigned PASSALL:1;
		unsigned RXPAUSE:1;
		unsigned TXPAUSE:1;
		unsigned LOOPBACK:1;
		unsigned :3;
		unsigned RESETTFUN:1;
		unsigned RESETTMCS:1;
		unsigned RESETRFUN:1;
		unsigned RESETRMCS:1;
		unsigned :2;
		unsigned SIMRESET:1;
		unsigned SOFTRESET:1;
	};
	struct {
		unsigned w:32;
	};
} EMAC1CFG1bits_t;
#define EMAC1CFG1bits (*((volatile EMAC1CFG1bits_t *) 0xbf882200))

typedef union {
	struct {
		unsigned FULLDPLX:1;
		unsigned LENGTHCK:1;
		unsigned HUGEFRM:1;
		unsigned DELAYCRC:1;
		unsigned CRCENABLE:1;
		unsigned PADENABLE:1;
		unsigned VLANPAD:1;
		unsigned AUTOPAD:1;
		unsigned PUREPRE:1;
		unsigned LONGPRE:1;
		unsigned :2;
		unsigned NOBKOFF:1;
		unsigned BPNOBKOFF:1;
		unsigned EXCESSDFR:1;
	};
	struct {
		unsigned w:32;
	};
} EMAC1CFG2bits_t;
#define EMAC1CFG2bits (*((volatile EMAC1CFG2bits_t *) 0xbf882210))

typedef union {
	struct {
		unsigned NB2BIPKTGP2:7;
		unsigned :1;
		unsigned NB2BIPKTGP1:7;
	};
	struct {
		unsigned w:32;
	};
} EMAC1IPGRbits_t;
#define EMAC1IPGRbits (*((volatile EMAC1IPGRbits_t *) 0xbf882230))

typedef union {
	struct {
		unsigned STNADDR1:8;
		unsigned STNADDR2:8;
	};
	struct {
		unsigned w:32;
	};
} EMAC1SA2bits_t;
#define EMAC1SA2bits (*((volatile EMAC1SA2bits_t *) 0xbf882320))

typedef union {
	struct {
		unsigned STNADDR3:8;
		unsigned STNADDR4:8;
	};
	struct {
		unsigned w:32;
	};
} EMAC1SA1bits_t;
#define EMAC1SA1bits (*((volatile EMAC1SA1bits_t *) 0xbf882310))

typedef union {
	struct {
		unsigned STNADDR5:8;
		unsigned STNADDR6:8;
	};
	struct {
		unsigned w:32;
	};
} EMAC1SA0bits_t;
#define EMAC1SA0bits (*((volatile EMAC1SA0bits_t *) 0xbf882300))

typedef union {
	struct {
		unsigned :8;
		unsigned SPEEDRMII:1;
		unsigned :2;
		unsigned RESETRMII:1;
	};
	struct {
		unsigned w:32;
	};
} EMAC1SUPPbits_t;
#define EMAC1SUPPbits (*((volatile EMAC1SUPPbits_t *) 0xbf882260))

typedef union {
	struct {
		unsigned SCANINC:1;
		unsigned NOPRE:1;
		unsigned CLKSEL:4;
		unsigned :9;
		unsigned RESETMGMT:1;
	};
	struct {
		unsigned w:32;
	};
} EMAC1MCFGbits_t;
#define EMAC1MCFGbits (*((volatile EMAC1MCFGbits_t *) 0xbf882280))

typedef union {
	struct {
		unsigned USERID:16;
		unsigned :8;
		unsigned FMIIEN:1;
		unsigned FETHIO:1;
		unsigned :1;
		unsigned PGL1WAY:1;
		unsigned PMDL1WAY:1;
		unsigned IOL1WAY:1;
		unsigned FUSBIDIO:1;
	};
	struct {
		unsigned w:32;
	};
} DEVCFG3bits_t;
#define DEVCFG3bits (*((volatile DEVCFG3bits_t *) 0xbfc0ffc0))

typedef union {
	struct {
		unsigned B2BIPKTGP:7;
	};
	struct {
		unsigned w:32;
	};
} EMAC1IPGTbits_t;
#define EMAC1IPGTbits (*((volatile EMAC1IPGTbits_t *) 0xbf882220))

typedef union {
	struct {
		unsigned PMPIE:1;
		unsigned PMPEIE:1;
		unsigned CMP1IE:1;
		unsigned CMP2IE:1;
		unsigned USBIE:1;
		unsigned USBDMAIE:1;
		unsigned DMA0IE:1;
		unsigned DMA1IE:1;
		unsigned DMA2IE:1;
		unsigned DMA3IE:1;
		unsigned DMA4IE:1;
		unsigned DMA5IE:1;
		unsigned DMA6IE:1;
		unsigned DMA7IE:1;
		unsigned SPI2EIE:1;
		unsigned SPI2RXIE:1;
		unsigned SPI2TXIE:1;
		unsigned U2EIE:1;
		unsigned U2RXIE:1;
		unsigned U2TXIE:1;
		unsigned I2C2BIE:1;
		unsigned I2C2SIE:1;
		unsigned I2C2MIE:1;
		unsigned CAN1IE:1;
		unsigned CAN2IE:1;
		unsigned ETHIE:1;
		unsigned SPI3EIE:1;
		unsigned SPI3RXIE:1;
		unsigned SPI3TXIE:1;
		unsigned U3EIE:1;
		unsigned U3RXIE:1;
		unsigned U3TXIE:1;
	};
	struct {
		unsigned w:32;
	};
} IEC4bits_t;
#define IEC4bits (*((volatile IEC4bits_t *) 0xbf810100))

typedef union {
	struct {
		unsigned PMPIF:1;
		unsigned PMPEIF:1;
		unsigned CMP1IF:1;
		unsigned CMP2IF:1;
		unsigned USBIF:1;
		unsigned USBDMAIF:1;
		unsigned DMA0IF:1;
		unsigned DMA1IF:1;
		unsigned DMA2IF:1;
		unsigned DMA3IF:1;
		unsigned DMA4IF:1;
		unsigned DMA5IF:1;
		unsigned DMA6IF:1;
		unsigned DMA7IF:1;
		unsigned SPI2EIF:1;
		unsigned SPI2RXIF:1;
		unsigned SPI2TXIF:1;
		unsigned U2EIF:1;
		unsigned U2RXIF:1;
		unsigned U2TXIF:1;
		unsigned I2C2BIF:1;
		unsigned I2C2SIF:1;
		unsigned I2C2MIF:1;
		unsigned CAN1IF:1;
		unsigned CAN2IF:1;
		unsigned ETHIF:1;
		unsigned SPI3EIF:1;
		unsigned SPI3RXIF:1;
		unsigned SPI3TXIF:1;
		unsigned U3EIF:1;
		unsigned U3RXIF:1;
		unsigned U3TXIF:1;
	};
	struct {
		unsigned w:32;
	};
} IFS4bits_t;
#define IFS4bits (*((volatile IFS4bits_t *) 0xbf810080))

typedef union {
	struct {
		unsigned FUNC:7;
		unsigned :1;
		unsigned SUSPEN:1;
		unsigned SUSPMODE:1;
		unsigned RESUME:1;
		unsigned RESET:1;
		unsigned HSMODE:1;
		unsigned HSEN:1;
		unsigned SOFTCONN:1;
		unsigned ISOUPD:1;
		unsigned EP0IF:1;
		unsigned EP1TXIF:1;
		unsigned EP2TXIF:1;
		unsigned EP3TXIF:1;
		unsigned EP4TXIF:1;
		unsigned EP5TXIF:1;
		unsigned EP6TXIF:1;
		unsigned EP7TXIF:1;
	};
	struct {
		unsigned w:32;
	};
} USBCSR0bits_t;
#define USBCSR0bits (*((volatile USBCSR0bits_t *) 0xbf8e3000))

typedef struct {
	unsigned U1MD:1;
	unsigned U2MD:1;
	unsigned U3MD:1;
	unsigned U4MD:1;
	unsigned U5MD:1;
	unsigned U6MD:1;
	unsigned :2;
	unsigned SPI1MD:1;
	unsigned SPI2MD:1;
	unsigned SPI3MD:1;
	unsigned SPI4MD:1;
	unsigned SPI5MD:1;
	unsigned SPI6MD:1;
	unsigned :2;
	unsigned I2C1MD:1;
	unsigned I2C2MD:1;
	unsigned I2C3MD:1;
	unsigned I2C4MD:1;
	unsigned I2C5MD:1;
	unsigned :3;
	unsigned USBMD:1;
	unsigned :3;
	unsigned CAN1MD:1;
	unsigned CAN2MD:1;
} PMD5bits_t;
#define PMD5bits (*((volatile PMD5bits_t *) 0xbf800080))

typedef union {
	struct {
		unsigned SESSION:1;
		unsigned HOSTREQ:1;
		unsigned HOSTMODE:1;
		unsigned VBUS:2;
		unsigned LSDEV:1;
		unsigned FSDEV:1;
		unsigned BDEV:1;
		unsigned RXEDMA:1;
		unsigned TXEDMA:1;
		unsigned :6;
		unsigned TXFIFOSZ:4;
		unsigned TXDPB:1;
		unsigned :3;
		unsigned RXFIFOSZ:4;
		unsigned RXDPB:1;
	};
	struct {
		unsigned w:32;
	};
} USBOTGbits_t;
#define USBOTGbits (*((volatile USBOTGbits_t *) 0xbf8e3060))

typedef union {
	struct {
		unsigned USBWKUPEN:1;
		unsigned USBRIE:1;
		unsigned USBIE:1;
		unsigned SENDMONEN:1;
		unsigned BSVALMONEN:1;
		unsigned ASVALMONEN:1;
		unsigned VBUSMONEN:1;
		unsigned PHYIDEN:1;
		unsigned USBIDVAL:1;
		unsigned USBIDOVEN:1;
		unsigned :14;
		unsigned USBWKUP:1;
		unsigned USBRF:1;
		unsigned USBIF:1;
	};
	struct{
		unsigned w:32;
	};
} USBCRCONbits_t;
#define USBCRCONbits (*((volatile USBCRCONbits_t *) 0xbf884000))

typedef union {
	struct{
		unsigned :1;
		unsigned EP1RXIE:1;
		unsigned EP2RXIE:1;
		unsigned EP3RXIE:1;
		unsigned EP4RXIE:1;
		unsigned EP5RXIE:1;
		unsigned EP6RXIE:1;
		unsigned EP7RXIE:1;
		unsigned :8;
		unsigned SUSPIF:1;
		unsigned RESUMEIF:1;
		unsigned RESETIF:1;
		unsigned SOFIF:1;
		unsigned CONNIF:1;
		unsigned DISCONIF:1;
		unsigned SESSRQIF:1;
		unsigned VBUSERRIF:1;
		unsigned SUSPIE:1;
		unsigned RESUMEIE:1;
		unsigned RESETIE:1;
		unsigned SOFIE:1;
		unsigned CONNIE:1;
		unsigned DISCONIE:1;
		unsigned SESSRQIE:1;
		unsigned VBUSERRIE:1;
	};
	struct {
		unsigned RCVIE:8;
		unsigned :8;
		unsigned INTERRUPTS:8;
		unsigned GENIE:8;
	};
	struct{
		unsigned w:32;
	};
} USBCSR2bits_t;
#define USBCSR2bits (*((volatile USBCSR2bits_t *) 0xbf8e3008))

typedef union {
	struct{
		unsigned RFRMNUM:11;
		unsigned :5;
		unsigned ENDPOINT:4;
		unsigned :4;
		unsigned NAK:1;
		unsigned TESTJ:1;
		unsigned TESTK:1;
		unsigned PACKET:1;
		unsigned FORCEHS:1;
		unsigned FORCEFS:1;
		unsigned FIFOACC:1;
		unsigned FORCEHST:1;
	};
	struct{
		unsigned w:32;
	};
} USBCSR3bits_t;
#define USBCSR3bits (*((volatile USBCSR3bits_t *) 0xbf8e300c))

typedef union {
	struct {
		unsigned TXMAXP:11;
		unsigned MULT:5;
		unsigned TXPKTRDY:1;
		unsigned FIFONE:1;
		unsigned ENERROR:1;
		unsigned FLUSH:1;
		unsigned SETUPPKT:1;
		unsigned RXSTALL:1;
		unsigned CLRDT:1;
		unsigned NAKTMOUT:1;
		unsigned DATATGGL:1;
		unsigned DTWREN:1;
		unsigned DMAREQMD:1;
		unsigned FRCDATTG:1;
		unsigned DMAREQEN:1;
		unsigned MODE:1;
		unsigned :1;
		unsigned AUTOSET:1;
	};
	struct {
		unsigned :18;
		unsigned UNDERRUN:1;
		unsigned :1;
		unsigned SENDSTALL:1;
		unsigned SENTSTALL:1;
		unsigned :1;
		unsigned INCOMPTX:1;
		unsigned :6;
		unsigned ISO:1;
	};
	struct{
		unsigned w:32;
	};
} USBIENCSR0bits_t;
#define USBIENCSR0bits (*((volatile USBIENCSR0bits_t *) 0xbf8e300c))

typedef union {
	struct {
		unsigned :16;
		unsigned RXPKTRDY:1;
		unsigned TXPKTRDY:1;
		unsigned RXSTALL:1;
		unsigned SETUPPKT:1;
		unsigned ENERROR:1;
		unsigned REQPKT:1;
		unsigned STATPKT:1;
		unsigned NAKTMOUT:1;
		unsigned FLSHFIFO:1;
		unsigned DATATGGL:1;
		unsigned DTWREN:1;
		unsigned DISPING:1;
		unsigned :4;
	};
	struct{
		unsigned w:32;
	};
} USBENCTRL0bits_t;
#define USBENCTRL0bits (*((volatile USBENCTRL0bits_t *) 0xbf8e3010))


typedef union {
	struct {
		unsigned RXMAXP:11;
		unsigned MULT:5;
		unsigned RXPKTRDY:1;
		unsigned FIFOFULL:1;
		unsigned ENERROR:1;
		unsigned DERRNAKT:1;
		unsigned FLUSH:1;
		unsigned REQPKT:1;
		unsigned RXSTALL:1;
		unsigned CLRDT:1;
		unsigned INCOMPRX:1;
		unsigned DATATGGL:1;
		unsigned DATATWEN:1;
		unsigned DMAREQMD:1;
		unsigned PIDERR:1;
		unsigned DMAREQEN:1;
		unsigned AUTORQ:1;
		unsigned AUTOCLR:1;
	};
	struct {
		unsigned :18;
		unsigned OVERRUN:1;
		unsigned DATAERR:1;
		unsigned :1;
		unsigned SENDSTALL:1;
		unsigned SENTSTALL:1;
		unsigned :5;
		unsigned DISNYET:1;
		unsigned :1;
		unsigned ISO:1;
	};
	struct{
		unsigned w:32;
	};
} USBIENCSR1bits_t;
#define USBIENCSR1bits (*((volatile USBIENCSR1bits_t *) 0xbf8e3010))

typedef union {
	struct{
		unsigned DATA:32;
	};
	struct {
		unsigned byte:8;
		unsigned :24;
	};
} USBFIFO0bits_t;
#define USBFIFO0bits (*((volatile USBFIFO0bits_t *) 0xbf8e3020))

typedef union {
	struct {
		unsigned RXCNT:7;
		unsigned :15;
		unsigned SPEED:2;
		unsigned NAKLIM:5;
		unsigned :3;
	};
	struct {
		unsigned w:32;
	};
} USBIE0CSR2bits_t;
#define USBIE0CSR2bits (*((volatile USBIE0CSR2bits_t *) 0xbf8e3018))

typedef union {
	struct {
		unsigned :1;
		unsigned EP1RXIF:1;
		unsigned EP2RXIF:1;
		unsigned EP3RXIF:1;
		unsigned EP4RXIF:1;
		unsigned EP5RXIF:1;
		unsigned EP6RXIF:1;
		unsigned EP7RXIF:1;
		unsigned :8;
		unsigned EP0IE:1;
		unsigned EP1TXIE:1;
		unsigned EP2TXIE:1;
		unsigned EP3TXIE:1;
		unsigned EP4TXIE:1;
		unsigned EP5TXIE:1;
		unsigned EP6TXIE:1;
		unsigned EP7TXIE:1;
	};
	struct {
		unsigned : 8;
		unsigned : 8;
		unsigned TRXIE : 8;
	};
	struct {
		unsigned w:32;
	};
} USBCSR1bits_t;
#define USBCSR1bits (*((volatile USBCSR1bits_t *) 0xbf8e3004))

typedef union {
	struct{
		unsigned LNKSTATE:4;
		unsigned HIRD:4;
		unsigned RMTWAK:1;
		unsigned :3;
		unsigned ENDPOINT:4;
		unsigned LPMXMT:1;
		unsigned LPMRES:1;
		unsigned LPMEN:2;
		unsigned LPMNAK:1;
		unsigned :3;
		unsigned LPMTOIE:1;
		unsigned LPMSTIE:1;
		unsigned LPMNYIE:1;
		unsigned LPMACKIE:1;
		unsigned LPMRESIE:1;
		unsigned LPMERRIE:1;
	};
	struct{
		unsigned w:32;
	};
} USBLPMR1bits_t;
#define USBLPMR1bits (*((volatile USBLPMR1bits_t *) 0xbf8e3360))

typedef struct {
	unsigned HSEOF:8;
	unsigned FSEOF:8;
	unsigned LSEOF:8;
	unsigned SOFRST:8; /* NRST:1 NRSTX:1 */
} USBEOFRSTbits_t;
#define USBEOFRSTbits (*((volatile USBEOFRSTbits_t *) 0xbf8e307c))

typedef union {
	struct{
		unsigned exl:1;
		unsigned k:1;
		unsigned :1;
		unsigned u:1;
		unsigned ie:1;
		unsigned event:10;
		unsigned :8;
		unsigned ec:2;
		unsigned :6;
		unsigned m:1;
	};
	struct{
		unsigned w:32;
	};
} perf_control_t;
