
#include "asf.h"
#include "stdio_serial.h"
#include "conf_board.h"
#include "conf_clock.h"

/** IRQ priority for PIO (The lower the value, the greater the priority) */
#define IRQ_PRIOR_PIO    0
// [main_def_pio_irq_prior]

//Global g_ul_ms_ticks in milliseconds since start of application
volatile uint32_t g_ul_ms_ticks = 0;

#ifdef __cplusplus
extern "C" {
#endif


/**
 *  \brief Handler for System Tick interrupt.
 *
 *  Process System Tick Event
 *  Increments the g_ul_ms_ticks counter.
 */
void SysTick_Handler(void)
{
	g_ul_ms_ticks++;
}


/**
 *  Configure UART console.
 */
static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = 
	{
		.baudrate = CONF_UART_BAUDRATE,
#ifdef CONF_UART_CHAR_LENGTH
		.charlength = CONF_UART_CHAR_LENGTH,
#endif
		.paritytype = CONF_UART_PARITY,
#ifdef CONF_UART_STOP_BITS
		.stopbits = CONF_UART_STOP_BITS,
#endif
	};

	/* Configure console UART. */
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_UART, &uart_serial_options);
}


/**
 * \brief Wait for the given number of milliseconds
 */
static void mdelay(uint32_t ul_dly_ticks)
{
	uint32_t ul_cur_ticks;
	ul_cur_ticks = g_ul_ms_ticks;
	while ((g_ul_ms_ticks - ul_cur_ticks) < ul_dly_ticks);
}


//MAIN
int main(void)
{
	/* Initialize the SAM system */
	sysclk_init();
	board_init();
	/* Initialize the console uart */
	configure_console();
	/* Output example information */
	puts("HELLLLLOOOOOOOO");
	/* Configure systick for 1 ms */
	if (SysTick_Config(sysclk_get_cpu_hz() / 1000)) 
	{
		puts("-F- Systick configuration error\r");
		while (1);
	}

	while (1) 
	{
		/* Toggle LED state if active */
		ioport_toggle_pin_level(LED0_GPIO);
		printf("1 ");
		/* Wait for 500ms */
		mdelay(500);
	}
}


/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond
