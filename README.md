# MTSE CUSTOM INSTRUCTIONS

Forget trying to setup your mac to use qmk, use docker instead.

First, install the Docker Application online: https://docs.docker.com/desktop/install/mac-install/

Manually launch the Docker Desktop App if not already running.

run `./docker_setup.sh`

run `./docker_compile.sh`
This should have created a file called `handwired_dactyl_manuform_5x6_my_keymap.hex` at the root.

Install QMK toolbox
Flash by opening the hex file in QMK toolbox, resetting the keyboard bootloader, and clicking the Flash button.
