# GPIO - General-Purpose Input/Output (GPIO) peripheral
- we can use the generic API <drivers/gpio.h>
- use DT_ALIAS to access the node identifier
- gpio_dt_spec: get the device pointer --> GPIO_DT_SPEC_GET()
- check if the device is ready --> device_is_ready() 
- gpio_pin_configure_dt
- pio_pin_get_dt(): read status
- gpio_pin_set_dt(): set a value
- configure an interrupt associated with a button pin: gpio_pin_interrupt_configure_dt()

