# Raspberry Pi Driver Blocks 
----------------------------

Uncomment or copy into another Raspberry Pi model the blocks you wish to use.

# Usage

* You must open the S-Function driver block and click 'Build' to generate the
  embedded coder files otherwise you will receive an error 'sfcn\_.... does
  not exist'.
* If using the ADS1115 and MCP4725 you will require my fork of wiringPi:
  https://github.com/tuna-f1sh/wiringPi-mcp4725 see the README for
  installation instructions.
* If using the PWM block, you will need to enable SPI in Raspbian - see: http://uk.mathworks.com/help/supportpkg/raspberrypiio/examples/analog-input-using-spi.html or enable via SSH.
* The scopes work in real-time on the Pi to see the correct data is going
  to/coming from blocks.
* The discrete timestep is set to 'Ts' throughout the model. This is
  initialised as 1e-3s at model load - it seems to be the sweet spot for
  performance/usage. Remember to consider quantisation that this can create
  with signals driving the blocks.

# Notes

* wiringPi softPWM:
  https://projects.drogon.net/raspberry-pi/wiringpi/software-pwm-library/
* Do not sure both ADC blocks at once without changing the wiringPi 'pin'
  assignment - it won't work.

# Install wiringPi Fork

1. Login to the Pi via SSH.
2. `git clone https://github.com/tuna-f1sh/wiringPi-mcp4725`
3. `cd wiringPi-mcp4725`
4. `./build`

www.jbrengineering.co.uk - @j_whittington - 2015
