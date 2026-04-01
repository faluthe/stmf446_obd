#ifndef STM32F446XX_H
#define STM32F446XX_H

#include <stdint.h>

#define PERIPH_BASE ((uint32_t)0x40000000U)
// slow peripheral bus (max 45MHz) - USART2 lives here, baud rate divides this clock
#define APB1_BASE   (PERIPH_BASE + 0x00000000U)
// faster peripheral bus (max 90MHz) - USART1 lives here
#define APB2_BASE   (PERIPH_BASE + 0x00010000U)
// full speed bus - GPIO and RCC live here
#define AHB1_BASE   (PERIPH_BASE + 0x00020000U)

// GPIO port A - PA2/PA3 OBD UART, PA9/PA10 debug UART, PA5 onboard LED
#define GPIOA_BASE  (AHB1_BASE + 0x0000U)
// USART1 - debug output via ST-Link virtual COM port
#define USART1_BASE (APB2_BASE + 0x1000U)
// USART2 - OBD UART, TX/RX to MC33290 K-Line transceiver
#define USART2_BASE (APB1_BASE + 0x4400U)
// Reset and Clock Control - must enable peripheral clocks here before touching any peripheral
#define RCC_BASE    (AHB1_BASE + 0x3800U)

typedef struct {
  // mode (input/output/alternate/analog)
  volatile uint32_t MODER;
  // output type (push pull or open drain)
  volatile uint32_t OTYPER;
  // output speed
  volatile uint32_t OSPEEDR;
  // pull up/pull down
  volatile uint32_t PUPDR;
  // input data
  volatile uint32_t IDR;
  // output data
  volatile uint32_t ODR;
  // bit set/reset
  volatile uint32_t BSRR;
  // lock
  volatile uint32_t LCKR;
  // alternate function low
  volatile uint32_t AFRL;
  // alternate function high
  volatile uint32_t AFRH;
} GPIO_t;

#define GPIOA ((GPIO_t *)GPIOA_BASE)

#endif /* STM32F446XX_H */