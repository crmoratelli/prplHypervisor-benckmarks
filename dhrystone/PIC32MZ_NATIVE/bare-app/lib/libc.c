#include <pic32mz.h>
#include <libc.h>

typedef unsigned long	size_t;

int8_t *strcpy(int8_t *dst, const int8_t *src){
	int8_t *dstSave=dst;
	int32_t c;

	do{
		c = *dst++ = *src++;
	} while(c);
	return dstSave;
}

int8_t *strncpy(int8_t *s1, int8_t *s2, int32_t n){
	int32_t i;
	int8_t *os1;

	os1 = s1;
	for (i = 0; i < n; i++)
		if ((*s1++ = *s2++) == '\0') {
			while (++i < n)
				*s1++ = '\0';
			return(os1);
		}
	return(os1);
}

int8_t *strcat(int8_t *dst, const int8_t *src){
	int32_t c;
	int8_t *dstSave=dst;

	while(*dst)
		++dst;
	do{
		c = *dst++ = *src++;
	} while(c);

	return dstSave;
}

int8_t *strncat(int8_t *s1, int8_t *s2, int32_t n){
	int8_t *os1;

	os1 = s1;
	while (*s1++);
	--s1;
	while ((*s1++ = *s2++))
		if (--n < 0) {
			*--s1 = '\0';
			break;
		}
	return(os1);
}

int32_t strcmp(const int8_t *s1, const int8_t *s2){
	while (*s1 == *s2++)
		if (*s1++ == '\0')
			return(0);

	return(*s1 - *--s2);
}

int32_t strncmp(int8_t *s1, int8_t *s2, int32_t n){
	while (--n >= 0 && *s1 == *s2++)
		if (*s1++ == '\0')
			return(0);

	return(n<0 ? 0 : *s1 - *--s2);
}

int8_t *strstr(const int8_t *string, const int8_t *find){
	int32_t i;
	for(;;){
		for(i = 0; string[i] == find[i] && find[i]; ++i);
		if(find[i] == 0)
			return (char*)string;
		if(*string++ == 0)
			return NULL;
	}
}

int32_t strlen(const int8_t *s){
	int32_t n;

	n = 0;
	while (*s++)
		n++;

	return(n);
}

int8_t *strchr(const int8_t *s, int32_t c){
	while (*s != (int8_t)c) 
		if (!*s++)
			return 0; 

	return (int8_t *)s; 
}

int8_t *strpbrk(int8_t *str, int8_t *set){
	while (*str != '\0'){
		if (strchr(set, *str) == 0)
			++str;
		else
			return (int8_t *) str;
		return 0;
	}
}

int8_t *strsep(int8_t **pp, int8_t *delim){
	int8_t *p, *q;

	if (!(p = *pp))
		return 0;
	if (q = strpbrk (p, delim)){
		*pp = q + 1;
		*q = '\0';
	}else	*pp = 0;

	return p;
}

int8_t *strtok(int8_t *s, const int8_t *delim){
	const int8_t *spanp;
	int32_t c, sc;
	int8_t *tok;
	static int8_t *last;

	if (s == NULL && (s = last) == NULL)
		return (NULL);

	cont:
	c = *s++;
	for (spanp = delim; (sc = *spanp++) != 0;){
		if (c == sc)
		goto cont;
	}

	if (c == 0){
		last = NULL;
		return (NULL);
	}
	tok = s - 1;

	for(;;){
		c = *s++;
		spanp = delim;
		do{
			if ((sc = *spanp++) == c){
				if (c == 0)
					s = NULL;
				else
					s[-1] = 0;
				last = s;
				return (tok);
			}
		}while (sc != 0);
	}
}

void *memcpy(void *dst, const void *src, uint32_t n){
	int8_t *r1 = dst;
	const int8_t *r2 = src;

	while (n--)
		*r1++ = *r2++;

	return dst;
}

void *memmove(void *dst, const void *src, uint32_t n){
	int8_t *s = (int8_t *)dst;
	const int8_t *p = (const int8_t *)src;

	if (p >= s){
		while (n--)
			*s++ = *p++;
	}else{
		s += n;
		p += n;
		while (n--)
			*--s = *--p;
	}

	return dst;
}

int32_t memcmp(const void *cs, const void *ct, uint32_t n){
	const uint8_t *r1 = (const uint8_t *)cs;
	const uint8_t *r2 = (const uint8_t *)ct;

	while (n && (*r1 == *r2)) {
		++r1;
		++r2;
		--n;
	}

	return (n == 0) ? 0 : ((*r1 < *r2) ? -1 : 1);
}

void *memset(void *s, int32_t c, uint32_t n){
	uint8_t *p = (uint8_t *)s;

	while (n--)
		*p++ = (uint8_t)c;

	return s;
}

int32_t strtol(const int8_t *s, int8_t **end, int32_t base){
	int32_t i;
	uint32_t ch, value=0, neg=0;

	if(s[0] == '-'){
		neg = 1;
		++s;
	}
	if(s[0] == '0' && s[1] == 'x'){
		base = 16;
		s += 2;
	}
	for(i = 0; i <= 8; ++i){
		ch = *s++;
		if('0' <= ch && ch <= '9')
			ch -= '0';
		else if('A' <= ch && ch <= 'Z')
			ch = ch - 'A' + 10;
		else if('a' <= ch && ch <= 'z')
			ch = ch - 'a' + 10;
		else
			break;
		value = value * base + ch;
	}
	if(end)
		*end = (char*)s - 1;
	if(neg)
		value = -(int32_t)value;
	return value;
}

int32_t atoi(const int8_t *s){
	int32_t n, f;

	n = 0;
	f = 0;
	for(;;s++){
		switch(*s){
		case ' ':
		case '\t':
			continue;
		case '-':
			f++;
		case '+':
			s++;
		}
		break;
	}
	while(*s >= '0' && *s <= '9')
		n = n*10 + *s++ - '0';
	return(f?-n:n);
}

int8_t *itoa(int32_t i, int8_t *s, int32_t base){
	int8_t *ptr = s, *ptr1 = s, tmp_char;
	int32_t tmp_value;

	if (base < 2 || base > 36) {
		*s = '\0';
		return s;
	}
	do {
		tmp_value = i;
		i /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - i * base)];
	} while (i);
	if (tmp_value < 0)
		*ptr++ = '-';
	*ptr-- = '\0';
	while(ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}
	return s;
}

int32_t puts(const int8_t *str){
	while(*str)
		putchar(*str++);
	putchar('\n');

	return 0;
}

int8_t *gets(int8_t *s){
	int32_t c;
	int8_t *cs;

	cs = s;
	while ((c = getchar()) != '\n' && c >= 0)
		*cs++ = c;
	if (c<0 && cs==s)
		return(NULL);
	*cs++ = '\0';
	return(s);
}

int32_t abs(int32_t n){
	return n>=0 ? n:-n;
}

static uint32_t rand1=0xbaadf00d;

int32_t random(void){
	rand1 = rand1 * 1103515245 + 12345;
	return (uint32_t)(rand1 >> 16) & 32767;
}

void srand(uint32_t seed){
	rand1 = seed;
}

/*
printf() and sprintf()
*/
#include <stdarg.h>
#define PAD_RIGHT 1
#define PAD_ZERO 2
#define PRINT_BUF_LEN 30

static void printchar(int8_t **str, int32_t c){
	if (str){
		**str = c;
		++(*str);
	} else
		(void)putchar(c);
}

static int32_t prints(int8_t **out, const int8_t *string, int32_t width, int32_t pad){
	int32_t pc = 0, padchar = ' ';

	if (width > 0){
		int32_t len = 0;
		const int8_t *ptr;
		for (ptr = string; *ptr; ++ptr) ++len;
		if (len >= width) width = 0;
		else width -= len;
		if (pad & PAD_ZERO) padchar = '0';
	}
	if (!(pad & PAD_RIGHT)){
		for ( ; width > 0; --width){
			printchar (out, padchar);
			++pc;
		}
	}
	for ( ; *string ; ++string){
		printchar (out, *string);
		++pc;
	}
	for ( ; width > 0; --width){
		printchar (out, padchar);
		++pc;
	}

	return pc;
}

static int32_t printi(int8_t **out, int32_t i, int32_t b, int32_t sg, int32_t width, int32_t pad, int32_t letbase){
	int8_t print_buf[PRINT_BUF_LEN];
	int8_t *s;
	int32_t t, neg = 0, pc = 0;
	uint32_t u = i;

	if (i == 0){
		print_buf[0] = '0';
		print_buf[1] = '\0';
		return prints (out, print_buf, width, pad);
	}

	if (sg && b == 10 && i < 0){
		neg = 1;
		u = -i;
	}

	s = print_buf + PRINT_BUF_LEN-1;
	*s = '\0';

	while (u){
		t = u % b;
		if( t >= 10 )
			t += letbase - '0' - 10;
		*--s = t + '0';
		u /= b;
	}

	if (neg){
		if(width && (pad & PAD_ZERO)){
			printchar (out, '-');
			++pc;
			--width;
		}
		else {
			*--s = '-';
		}
	}

	return pc + prints (out, s, width, pad);
}

float atof(const int8_t *p){
	float val, power;
	int32_t i, sign;
	
	for (i = 0; isspace(p[i]); i++);
	
	sign = (p[i] == '-') ? -1 : 1;
	
	if (p[i] == '+' || p[i] == '-')
		i++;
	for (val = 0.0f; isdigit(p[i]); i++)
		val = 10.0f * val + (p[i] - '0');
	
	if (p[i] == '.')
		i++;
	for (power = 1.0f; isdigit(p[i]); i++){
		val = 10.0f * val + (p[i] - '0');
		power *= 10.0f;
	}
	
	return sign * val / power;
}

static int32_t print(int8_t **out, const int8_t *format, va_list args){
	int32_t width, pad;
	int32_t pc = 0;
	int8_t scr[2];
	int32_t i,j;
	int8_t buf[30];
	int32_t f1, precision_n = 6, precision_v = 1;
	float f;

	
	for (; *format != 0; ++format){
		if (*format == '%'){
			++format;
			width = pad = 0;
			if (*format == '\0') break;
			if (*format == '%') goto out;
			if (*format == '-'){
				++format;
				pad = PAD_RIGHT;
			}
			while (*format == '0'){
				++format;
				pad |= PAD_ZERO;
			}
			for (; *format >= '0' && *format <= '9'; ++format){
				width *= 10;
				width += *format - '0';
			}
			if(*format == 's'){
				int8_t *s = (int8_t *)va_arg(args, size_t);
				pc += prints(out, s?s:"(null)", width, pad);
				continue;
			}
			if(*format == 'd'){
				pc += printi(out, va_arg(args, size_t), 10, 1, width, pad, 'a');
				continue;
			}
			if(*format == 'x'){
				pc += printi(out, va_arg(args, size_t), 16, 0, width, pad, 'a');
				continue;
			}
			if(*format == 'X'){
				pc += printi(out, va_arg(args, size_t), 16, 0, width, pad, 'A');
				continue;
			}
			if(*format == 'u'){
				pc += printi(out, va_arg(args, size_t), 10, 0, width, pad, 'a');
				continue;
			}
			if(*format == 'c'){
				scr[0] = (int8_t)va_arg(args, size_t);
				scr[1] = '\0';
				pc += prints(out, scr, width, pad);
				continue;
			}
			switch(*format){
				case '.':
					// decimal point: 1 to 9 places max. single precision is only about 7 places anyway.
					i = *++format - '0';
					*format++;
					precision_n = i;
					precision_v = 1;
				case 'e':
				case 'E':
				case 'g':
				case 'G':
				case 'f':
					f = va_arg(args, double);
					if (f < 0.0f){
						putchar('-');
						f = -f;
					}
					itoa((int32_t)f,buf,10);
					j=0;
					while(buf[j]) putchar(buf[j++]);
					putchar('.');
					for(j=0; j<precision_n; j++)
						precision_v *= 10;
					f1 = (f - (int32_t)f) * precision_v;
					i = precision_v / 10;
					while(i > f1){
						printchar(out, '0');
						i /= 10;
					}
					itoa(f1,buf,10);
					j=0;
					if (f1 != 0)
						while(buf[j]) printchar(out, buf[j++]);
						precision_n = 6;
					precision_v = 1;
					break;
			}
		}
		else {
			out:
			printchar(out, *format);
			++pc;
		}
	}
	if (out) **out = '\0';
	va_end( args );
	return pc;
}


int printf(const int8_t *fmt, ...){
        va_list args;
        
        va_start(args, fmt);
        return print(0, fmt, args);
}

int sprintf(int8_t *out, const int8_t *fmt, ...){
        va_list args;
        
        va_start(args, fmt);
        return print(&out, fmt, args);
}

void udelay(uint32_t usec){
	uint32_t now = mfc0 (CP0_COUNT, 0);
	uint32_t final = now + usec * (CPU_SPEED / 1000000) / 2;
	
	for (;;) {
		now = mfc0 (CP0_COUNT, 0);
		if ((int32_t) (now - final) >= 0) break;
	}
}

void putchar(int32_t value){
	while(U2STA & USTA_UTXBF);
	U2TXREG = value;	
}

int32_t kbhit(void){
	return (U2STA & USTA_URXDA);
}

int32_t getchar(void){
	while(!kbhit());
	return (uint8_t)U2RXREG;
}


void proc_init(){
	uint32_t temp_CP0;
	
	PRISS = 0;

	/* Configure the processor to vectored interrupt mode. */
	mtc0 (CP0_EBASE, 1, 0x9d000000);    /* Set an EBase value of 0x9D000000 */
	temp_CP0 = mfc0(CP0_CAUSE, 0);      /* Get Cause */
	temp_CP0 |= CAUSE_IV;               /* Set Cause IV */
	mtc0(CP0_CAUSE, 0, temp_CP0);       /* Update Cause */
	INTCONSET = INTCON_MVEC;            /* Set the MVEC bit - Vetored interrupt mode. */
	temp_CP0 = mfc0(CP0_STATUS, 0);     /* Get Status */
	temp_CP0 &= ~STATUS_BEV;            /* Clear Status IV */
	temp_CP0 &= ~STATUS_EXL; 
	mtc0(CP0_STATUS, 0, temp_CP0);      /* Update Status */
	
	/*press SW1 to reset the board by software */
	TRISBSET =  (1 << 12);     /* SW1 - RB12 (active low) */
	CNPUBSET =     (1 << 12);     /* enable pull-up */
	
}

void start_timer(){
	uint32_t temp_CP0;
	
	OFF(0) = 0x200;
	
	IPC(0) = 0x1f;
	IFSCLR(0) = 1;
	IECSET(0) = 1;
	
	temp_CP0 = mfc0(CP0_COUNT, 0);
	temp_CP0 += 10000;
	mtc0(CP0_COMPARE, 0, temp_CP0);
	

	asm volatile ("ei");    
}

void init_uart(uint32_t baudrate, uint32_t sysclk){
	uint32_t stat;
	
	U2MODE = 0;         // disable autobaud, TX and RX enabled only, 8N1, idle=HIGH
	U2STA = 0x1400;     // enable TX and RX
	U2BRG = ((int)( ((sysclk/2) / (16*baudrate)) -1)) + 1;
	U2MODESET = 0x8840;
	
}

void SoftReset(){
	
	printf("Reset button (sw1) pressed. Performing software reset.");
	
	/* Give time for message output before reset. */
	udelay(1000000);
	
	NVMKEY = 0x0;
	NVMKEY = 0xAA996655;
	NVMKEY = 0x556699AA;
	
	RSWRST |= 1;
	
	/* read RSWRST register to trigger reset */
	volatile uint32_t* p = (uint32_t*)&RSWRST;
	*p;
	
	/* prevent any unwanted code execution until reset occurs*/
	while(1) ;  
}


/*
 * software implementation of IEEE single-precision floating point
 */

#define FtoL(X)		(*(uint32_t *)&(X))
#define LtoF(X)		(*(float *)&(X))

/* add two floats */
float __addsf3(float a1, float a2){
	int32_t mant1, mant2;
	union float_long fl1, fl2;
	int32_t exp1, exp2;
	int32_t sign = 0;
	
	fl1.f = a1;
	fl2.f = a2;
	
	/* check for zero args */
	if (!fl1.l){
		fl1.f = fl2.f;
		goto test_done;
	}
	if (!fl2.l)
		goto test_done;
	
	exp1 = EXP(fl1.l);
	exp2 = EXP(fl2.l);
	
	if (exp1 > exp2 + 25)
		goto test_done;
	if (exp2 > exp1 + 25){
		fl1.f = fl2.f;
		goto test_done;
	}
	
	/* do everything in excess precision so's we can round later */
	mant1 = MANT (fl1.l) << 6;
	mant2 = MANT (fl2.l) << 6;
	
	if (SIGN (fl1.l))
		mant1 = -mant1;
	if (SIGN (fl2.l))
		mant2 = -mant2;
	
	if (exp1 > exp2){
		mant2 >>= exp1 - exp2;
	}else{
		mant1 >>= exp2 - exp1;
		exp1 = exp2;
	}
	mant1 += mant2;
	
	if (mant1 < 0){
		mant1 = -mant1;
		sign = SIGNBIT;
	}else{
		if (!mant1){
			fl1.f = 0;
			goto test_done;
		}
	}
	
	/* normalize up */
	while (!(mant1 & 0xE0000000)){
		mant1 <<= 1;
		exp1--;
	}
	
	/* normalize down? */
	if (mant1 & (1 << 30)){
		mant1 >>= 1;
		exp1++;
	}
	
	/* round to even */
	mant1 += (mant1 & 0x40) ? 0x20 : 0x1F;
	
	/* normalize down? */
	if (mant1 & (1 << 30)){
		mant1 >>= 1;
		exp1++;
	}
	
	/* lose extra precision */
	mant1 >>= 6;
	
	/* turn off hidden bit */
	mant1 &= ~HIDDEN;
	
	/* pack up and go home */
	fl1.l = PACK (sign, exp1, mant1);
	test_done:
	return (fl1.f);
}

/* subtract two floats */
float __subsf3(float a1, float a2){
	union float_long fl1, fl2;
	
	fl1.f = a1;
	fl2.f = a2;
	
	/* check for zero args */
	if (!fl2.l)
		return (fl1.f);
	if (!fl1.l)
		return (-fl2.f);
	
	/* twiddle sign bit and add */
	fl2.l ^= SIGNBIT;
	return __addsf3(a1, fl2.f);
}

/* compare two floats */
int32_t __cmpsf2(float a1, float a2){
	union float_long fl1, fl2;
	int32_t i = 0;
	
	fl1.f = a1;
	fl2.f = a2;
	
	if (SIGN (fl1.l) && SIGN (fl2.l)){
		fl1.l ^= SIGNBIT;
		fl2.l ^= SIGNBIT;
		i = 1;
	}
	if (i == 0){
		if (fl1.l < fl2.l)
			return (-1);
		if (fl1.l > fl2.l)
			return (1);
		return (0);
	}else{
		if (fl1.l > fl2.l)
			return (-1);
		if (fl1.l < fl2.l)
			return (1);
		return (0);
	}
}

int32_t __ltsf2(float a, float b){
	return -(__cmpsf2 (a, b) < 0);
}

int32_t __lesf2(float a, float b){
	return __cmpsf2 (a, b) > 0;
}

int32_t __gtsf2(float a, float b){
	return __cmpsf2 (a, b) > 0;
}

int32_t __gesf2(float a, float b){
	return (__cmpsf2 (a, b) >= 0) - 1;
}

int32_t __eqsf2(float a, float b){
	return !(*(int32_t *) & a == *(int32_t *) & b);
}

int32_t __nesf2(float a, float b){
	return *(int32_t *) & a != *(int32_t *) & b;
}

/* multiply two floats */
float __mulsf3(float a1, float a2){
	union float_long fl1, fl2;
	uint32_t result;
	int32_t exp;
	int32_t sign;
	
	fl1.f = a1;
	fl2.f = a2;
	
	if (!fl1.l || !fl2.l){
		fl1.f = 0;
		goto test_done;
	}
	
	/* compute sign and exponent */
	sign = SIGN (fl1.l) ^ SIGN (fl2.l);
	exp = EXP(fl1.l) - EXCESS;
	exp += EXP(fl2.l);
	
	fl1.l = MANT (fl1.l);
	fl2.l = MANT (fl2.l);
	
	/* the multiply is done as one 16x16 multiply and two 16x8 multiplies */
	result = (fl1.l >> 8) * (fl2.l >> 8);
	result += ((fl1.l & 0xFF) * (fl2.l >> 8)) >> 8;
	result += ((fl2.l & 0xFF) * (fl1.l >> 8)) >> 8;
	
	result >>= 2;
	if (result & 0x20000000){
		/* round */
		result += 0x20;
		result >>= 6;
	}else{
		/* round */
		result += 0x10;
		result >>= 5;
		exp--;
	}
	if (result & (HIDDEN<<1)){
		result >>= 1;
		exp++;
	}
	
	result &= ~HIDDEN;
	
	/* pack up and go home */
	fl1.l = PACK(sign, exp, result);
	test_done:
	return (fl1.f);
}

/* divide two floats */
float __divsf3(float a1, float a2){
	union float_long fl1, fl2;
	int32_t result;
	int32_t mask;
	int32_t exp, sign;
	
	fl1.f = a1;
	fl2.f = a2;
	
	/* subtract exponents */
	exp = EXP(fl1.l) - EXP(fl2.l) + EXCESS;
	
	/* compute sign */
	sign = SIGN(fl1.l) ^ SIGN(fl2.l);
	
	/* divide by zero??? */
	if (!fl2.l)
		/* return NaN or -NaN */
		return (sign ? 0xFFFFFFFF : 0x7FFFFFFF);
	
	/* numerator zero??? */
	if (!fl1.l)
		return (0);
	
	/* now get mantissas */
	fl1.l = MANT (fl1.l);
	fl2.l = MANT (fl2.l);
	
	/* this assures we have 25 bits of precision in the end */
	if (fl1.l < fl2.l){
		fl1.l <<= 1;
		exp--;
	}
	
	/* now we perform repeated subtraction of fl2.l from fl1.l */
	mask = 0x1000000;
	result = 0;
	while (mask){
		if (fl1.l >= fl2.l){
			result |= mask;
			fl1.l -= fl2.l;
		}
		fl1.l <<= 1;
		mask >>= 1;
	}
	
	/* round */
	result += 1;
	
	/* normalize down */
	exp++;
	result >>= 1;
	
	result &= ~HIDDEN;
	
	/* pack up and go home */
	fl1.l = PACK(sign, exp, result);
	return (fl1.f);
}

/* negate a float */
float __negsf2(float a1){
	union float_long fl1;
	
	fl1.f = a1;
	if (!fl1.l)
		return (0);
	
	fl1.l ^= SIGNBIT;
	return (fl1.f);
}

/* convert float to int32_t */
int32_t __fixsfsi(float a_fp){
	uint32_t a;
	uint32_t as;
	int32_t ae;
	int32_t af, shift;
	
	a = FtoL(a_fp);
	as = a >> 31;
	ae = (a >> 23) & 0xff;
	af = 0x00800000 | (a & 0x007fffff);
	af <<= 7;
	shift = -(ae - 0x80 - 29);
	if(shift > 0){
		if(shift < 31) 
			af >>= shift;
		else 
			af = 0;
	}
	af = as ? -af: af;
	
	return af;
}

uint32_t __fixunssfsi(float a_fp){
	uint32_t a;
	uint32_t as;
	int32_t ae;
	int32_t af, shift;
	
	a = FtoL(a_fp);
	as = a >> 31;
	ae = (a >> 23) & 0xff;
	af = 0x00800000 | (a & 0x007fffff);
	af <<= 7;
	shift = -(ae - 0x80 - 29);
	if(shift > 0){
		if(shift < 31) 
			af >>= shift;
		else 
			af = 0;
	}
	af = as ? -af: af;
	
	return af;
}

/* convert int32_t to float */
float __floatsisf(int32_t af){
	uint32_t a;
	uint32_t as, ae;
	
	as = af>=0 ? 0: 1;
	af = af>=0 ? af: -af;
	ae = 0x80 + 22;
	if(af == 0) 
		return LtoF(af);
	while(af & 0xff000000){
		++ae;
		af >>= 1;
	}
	while((af & 0xff800000) == 0){
		--ae;
		af <<= 1;
	}
	a = (as << 31) | (ae << 23) | (af & 0x007fffff);
	
	return LtoF(a);
}

float __floatunsisf(uint32_t af){
	uint32_t a;
	uint32_t as, ae;
	
	as = af>=0 ? 0: 1;
	af = af>=0 ? af: -af;
	ae = 0x80 + 22;
	if(af == 0) 
		return LtoF(af);
	while(af & 0xff000000){
		++ae;
		af >>= 1;
	}
	while((af & 0xff800000) == 0){
		--ae;
		af <<= 1;
	}
	a = (as << 31) | (ae << 23) | (af & 0x007fffff);
	
	return LtoF(a);
}


