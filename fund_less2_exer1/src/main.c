/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 * Note: 
 * Tested on nRF Connect SDK Version : 2.0
 */

#include <zephyr.h>
#include <drivers/gpio.h>

/*  Change the sleep time from 1000 ms to 100 ms */
// #define SLEEP_TIME_MS   100

/*  Sleep time 10 minuse */
#define SLEEP_TIME_MS   10*60*1000

/* Get the node identifier for button 1 through its alias sw0 */
#define SW0_NODE	DT_ALIAS(sw0)
/* Get the device pointer. pin number, and pin's configuration flags through gpio_dt_spec */
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(SW0_NODE, gpios);

/* LED0_NODE is the devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

/* Define the callback function */
void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
	gpio_pin_toggle_dt(&led);
}

/* Define a variable of type static struct gpio_callback */
static struct gpio_callback button_cb_data;

void main(void)
{
	int ret;

	if (!device_is_ready(led.port)) {
		return;
	}

	/* Verify that the device is ready for use */
	if (!device_is_ready(button.port)) {
		return;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return;
	}

	/* Configure the pin connected to the button to be an input pin and set its hardware specifications */
	ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
	if (ret < 0) {
		return;
	}

	/* Configure the interrupt on the button's pin */
	ret = gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);

	/* Initialize the static struct gpio_callback variable   */
	gpio_init_callback(&button_cb_data, button_pressed, BIT(button.pin));

	/* Add the callback function by calling gpio_add_callback()   */
	gpio_add_callback(button.port, &button_cb_data);

	while (1) {

		/*Polling part start 

		//Read the status of the button and store it 
		bool val = gpio_pin_get_dt(&button);
		// Update the LED to the status of the button
		gpio_pin_set_dt(&led,val);

		polling part end */

		k_msleep(SLEEP_TIME_MS); // Put the main thread to sleep for 100ms for power optimization
	}
}