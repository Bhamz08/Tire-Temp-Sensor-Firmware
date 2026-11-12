cmake_minimum_required(VERSION 3.20.0)

# Finds the Zephyr install via the ZEPHYR_BASE environment variable.
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(tire_temp_app)

# "app" is the build target Zephyr creates for us.
target_sources(app PRIVATE
  src/main.c         # main loop: read -> pack -> send -> LED
  src/mlx90614.c     # sensor read over I2C with PEC check
  src/tire_frame.c   # CAN frame packing (pure, no hardware)
  src/can_tx.c       # CAN controller start + send
  src/status_led.c   # STATUS LED blink patterns
)
