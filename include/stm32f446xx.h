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
// USART1 - first of two USARTs used to separate distinct serial channels
#define USART1_BASE (APB2_BASE + 0x1000U)
// USART2 - second of two USARTs used to separate distinct serial channels
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

typedef struct {
  // status
  volatile uint32_t SR;
  // data
  volatile uint32_t DR;
  // baud rate
  volatile uint32_t BRR;
  // control 1
  volatile uint32_t CR1;
  // control 2
  volatile uint32_t CR2;
  // control 3
  volatile uint32_t CR3;
  // guard time and prescaler
  volatile uint32_t GTPR;
} USART_t;

#define USART1 ((USART_t *)USART1_BASE)
#define USART2 ((USART_t *)USART2_BASE)

// overrun error
#define USART_SR_ORE  (1UL << 3)
// read data register not empty
#define USART_SR_RXNE (1UL << 5)
// transmission complete
#define USART_SR_TCE  (1UL << 6)
// transmit data register empty
#define USART_SR_TXE  (1UL << 7)

// receiver
#define USART_CR1_RE     (1UL << 2)
// transmitter
#define USART_CR1_TE     (1UL << 3)
// RXNE interrupt
#define USART_CR1_RXNEIE (1UL << 5)
// USART
#define USART_CR1_UE     (1UL << 13)

typedef struct {
  // control
  volatile uint32_t CR;
  // PLL config
  volatile uint32_t PLLCFGR;
  // rcc clock config
  volatile uint32_t CFGR;
  // clock interupt
  volatile uint32_t CIR;
  // AHB1 peripheral reset
  volatile uint32_t AHB1RSTR;
  // AHB2 peripheral reset
  volatile uint32_t AHB2RSTR;
  // AHB3 peripheral reset
  volatile uint32_t AHB3RSTR;
  // APB1 perihperal reset
  volatile uint32_t APB1RSTR;
  // APB2 perihperal reset
  volatile uint32_t APB2RSTR;
  // 0xC reserved
  uint32_t RESERVED0[3];
  // AHB1 peripheral clock enable
  volatile uint32_t AHB1ENR;
  // AHB2 peripheral clock enable
  volatile uint32_t AHB2ENR;
  // AHB3 peripheral clock enable
  volatile uint32_t AHB3ENR;
  // 0x8 reserved
  uint32_t RESERVED1[2];
  // APB1 peripheral clock enable
  volatile uint32_t APB1ENR;
  // APB2 peripheral clock enable
  volatile uint32_t APB2ENR;
} RCC_t;

#define RCC ((RCC_t *)RCC_BASE)

#define RCC_AHB1ENR_GPIOAEN (1UL << 0)

#define RCC_APB1ENR_USART2EN (1UL << 17)

#define RCC_APB2ENR_USART1EN (1UL << 4)

#endif /* STM32F446XX_H */